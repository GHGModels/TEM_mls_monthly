/* **************************************************************
*****************************************************************
TMCRB45_lulc.CPP - object describing characteristics of soil
                 microbes used in the Terrestrial Ecosystem Model
                 (TEM)

*****************************************************************
************************************************************** */

#include<cstdio>

  using std::printf;

#include<iostream>

  using std::cout;
  using std::ios;
  using std::cerr;
  using std::endl;

#include<fstream>

  using std::ifstream;
  using std::ofstream;

#include<cstdlib>

  using std::exit;
  using std::atof;
  using std:: atoi;

#include<cmath>

  using std::exp;
  using std::log;
  using std::pow;

#include<vector>

  using std::vector;

#include<string>

  using std::string;
  
//#define RHMOIST_SECH
#define RHMOIST_WFPS

#include "tmcrb45_lulc.h"

/* **************************************************************
************************************************************** */

Tmcrb45::Tmcrb45() : ProcessXML45()
{

  // Initialize variables to MISSING values

  dq10 = MISSING;

  nuptake = MISSING;     
  /*
  nuptakefb = MISSING;
  nuptakeam = MISSING;
  nuptakemn = MISSING;
  */
   
  netnmin = MISSING;
  netnmin_active = MISSING;     
  netnmin_slow = MISSING;
  netnmin_passive = MISSING;

  rh = MISSING;
  rh_active = MISSING;         
  rh_slow = MISSING;
  rh_passive = MISSING;

  yrnmin = MISSING;
  yrnuptake = MISSING;

  yrrh = MISSING;

};

/* **************************************************************
************************************************************** */

/*
void Tmcrb45::kdfbxclm(    )
{
  //Calculate kdfb based on kdc parameter and soil temperature,
  //soil water, soil quality and soil texture information
  //at the correct horizon 

  double kdfb;
  double ftemp, fwater, fquality, ftexture;

  fquality = 1;
  ftexture = 1;
  fwater = 1;


  kdfb = kdc * ftemp * fwater * fquality * ftexture;

}
*/

/* **************************************************************
************************************************************** */

void Tmcrb45::getvegecd( const string& ecd )
{
  ifstream infile;
  int dcmnt;
  int comtype;


  infile.open( ecd.c_str(), ios::in );

  if( !infile )
  {
    cerr << endl << "Cannot open " << ecd;
    cerr << " for microbe ECD input" << endl;

    exit( -1 );
  }

  getXMLrootNode( infile, "microbeECD" );

  for( dcmnt = 1; dcmnt < MAXCMNT; ++dcmnt )
  { 
    comtype = getXMLcommunityNode( infile, "microbeECD" );
       

    if( comtype >= MAXCMNT )
    {
      cerr << endl << "comtype is >= MAXCMNT" << endl;
      cerr << "comtype cannot be greater than " << (MAXCMNT-1);
      cerr << " in microbeECD" << endl;
      exit( -1 );
    }


    rhalpha[comtype]= getXMLcmntArrayDouble( infile,
                                             "microbeECD",
                                             "rhalpha",
                                             comtype );

    rhbeta[comtype]= getXMLcmntArrayDouble( infile,
                                            "microbeECD",
                                            "rhbeta",
                                            comtype );

    rhgamma[comtype]= getXMLcmntArrayDouble( infile,
                                             "microbeECD",
                                             "rhgamma",
                                             comtype );

    rhqref[comtype]= getXMLcmntArrayDouble( infile,
                                            "microbeECD",
                                            "rhqref",
                                            comtype );

    rhtref[comtype]= getXMLcmntArrayDouble( infile,
                                            "microbeECD",
                                            "rhtref",
                                            comtype );

    kn2[comtype] = getXMLcmntArrayDouble( infile,
                                          "microbeECD",
                                          "kn2",
                                          comtype );

    moistmin[comtype] = getXMLcmntArrayDouble( infile,
                                               "microbeECD",
                                               "moistmin",
                                               comtype );

    moistopt[comtype] = getXMLcmntArrayDouble( infile,
                                               "microbeECD",
                                               "moistopt",
                                               comtype );

    moistmax[comtype] = getXMLcmntArrayDouble( infile,
                                               "microbeECD",
                                               "moistmax",
                                               comtype );

    docfr[comtype] = getXMLcmntArrayDouble( infile,
                                               "microbeECD",
                                               "docfr",
                                               comtype );

    docdon[comtype] = getXMLcmntArrayDouble( infile,
                                               "microbeECD",
                                               "docdon",
                                               comtype );


    endXMLcommunityNode( infile );
  }

  if( dcmnt < MAXCMNT )
  {
    cerr << endl << " Parameters found for only " << dcmnt;
    cerr << " community types out of a maximum of ";
    cerr << (MAXCMNT-1) << " types in microbeECD" << endl;

    exit( -1 );
  }

  infile.close();

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

double Tmcrb45::nminxclm( const int& pdcmnt,
                             const double& soilh2o,
                             const double& soilorgc,
                             const double& soilorgn,
                             const double& availn,
                             const double& ksoil,
                             const double& rh,
                             const int& nopen,
                             const double& cnsoil,
                             const double& nup )
{
  double gmin;
  double immb;
  double nmin;
  double tcnsoil;

//  tcnsoil = cnsoil[pdcmnt];
  tcnsoil = cnsoil;
  nuptake = ZERO;                             
  nmin = ZERO;

//  if ( soilorgc > ZERO && soilorgn > ZERO )
  if ( soilorgc > 0.01 && soilorgn > 0.01 ) //BSF COMBO
  {
    immb  = (availn * ksoil) / soilh2o;
    immb /= (kn2[pdcmnt] + immb);

    nuptake = nup * immb * decay * rh;

//    if (nuptake > availn)
//    {
//       nuptake = availn;
//    }

    gmin = (soilorgn / soilorgc) * rh;
  
    if(nopen == 1)
    {
     nmin = 0.99 * gmin - nuptake;
    }
    else
    {
    nmin   = gmin - nuptake;
    }

    if ( nmin >= ZERO )
    {
      nmin *= (soilorgn/soilorgc) * tcnsoil;
    }
    else
    {
      nmin *= (soilorgc/soilorgn) / tcnsoil;
      if(nmin+availn < ZERO)
      {
        nmin = -availn;
      }
    }

/*   if(nmin < soilorgn - ((soilorgc - rh)/(tcnsoil-.2*tcnsoil)))
     {  
       nmin = soilorgn - ((soilorgc - rh)/(tcnsoil-.2*tcnsoil));
     }
   else if (nmin > soilorgn - ((soilorgc - rh)/(tcnsoil+.2*tcnsoil)))
     {  
       nmin = soilorgn - ((soilorgc - rh)/(tcnsoil+.2*tcnsoil));
     } */

  }

  return nmin;

};


/* **************************************************************
************************************************************** */

void Tmcrb45::resetEcds( const int& pcmnt,
                            const double& psiplusc )
{
  kdc =  kdb[pcmnt];   

  if( kdc < ZERO ) { kdc = ZERO; }


//  nup =  nupb[pcmnt];

//  if( nup < ZERO ) { nup = ZERO; }


  // Determine the "decay" parameter

  decay = 0.26299
          + (1.14757 * propftos[pcmnt])
          - (0.42956 * pow( propftos[pcmnt], 2.0 ));

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::resetMonthlyFluxes( void )
{
  // Reset monthly fluxes to zero

  // Carbon fluxes

  rh = ZERO;     
  rh_active = ZERO;     
  rh_slow = ZERO;
  rh_passive = ZERO;


  // Nitrogen fluxes

  nuptake = ZERO;

  netnmin = ZERO;
  netnmin_active = ZERO;
  netnmin_slow = ZERO;
  netnmin_passive = ZERO;

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::resetYrFluxes( void )
{
  // Reset annual fluxes and summary variables to zero

  // Carbon fluxes

  yrrh = ZERO;

  // Nitrogen fluxes

  yrnuptake = ZERO;
  yrnmin = ZERO;
  yrnmin_active = ZERO;
  yrnmin_slow = ZERO;
  yrnmin_passive = ZERO;
  
};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

double Tmcrb45::rhxclm( const double& solorgc,
                           const double& kd,
                           const double& pdq10,
                           const double& moist,
                           const double& rltrc,
                           const int& pcmnt )     //this line of pdcmnt added for different quality pools MJ MLS;
{

//
//  Change to increase time to decomposition
//
//  Shree Update
//  double fsoil = 0.5;
  double fsoil = 0.0;
  rh = kd * solorgc * moist * pdq10;



//  cout << "rh = " << rh << " " << kd << " " << soilorgc << " " << moist << " " << pdq10 << endl;
//  cout << "rh = " << rh << " " << rltrc << " " << rrh << endl;
//  return rh += fsoil*(rltrc-rrh);    /commented out for now, replaced with the following line MJ MLS;
   return rh;

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::setDQ10LaRS( const int& pdcmnt,
                          const double& ptair )
{
  // setDQ10LaRS: effect of temperature on decomposition,
  //              as per LaRS respiration formula

  double rhbase;
  double rhexp;
  double rhdenm;
  double rhxT;

  rhbase = rhqref[pdcmnt]*exp(-rhalpha[pdcmnt]*(ptair - rhtref[pdcmnt]));
  rhexp = (ptair - rhtref[pdcmnt])/10.0;
  rhdenm = 1.0 + exp(rhbeta[pdcmnt] - ptair) + exp(ptair - rhgamma[pdcmnt]);

  rhxT = pow(rhbase, rhexp)/rhdenm;

  dq10 = rhxT;
//  rhTLaRS = pow( rhq10[pdcmnt], ptair / 10.0 );

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::setDQ10LT( const int& pdcmnt,
                         const double& ptair,
                         const double& ptopt )
{
  // setDQ10LT: effect of temperature on decomposition,
  //              as per Lloyd & Taylor (1994) respiration formula

  double rhxT,rhxtopt;

  rhxtopt = 1.0;

  rhxT = exp(308.56*(1.0/(273.15+25.0-227.13)-1.0/(273.15+ptair-227.13)));

//  rhxtopt = exp(308.56*(1.0/(273.15+25.0-227.13)-1.0/(273.15+ptopt-227.13)));

  dq10 = rhxT;

  dq10 /=  rhxtopt;

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

double Tmcrb45::setRHMOIST( const int& pdcmnt,
                               const double& pctfldcap,
                               const double& pctwiltpt,
                               const double& pctpor,
                               const double& vsm,
                               const int& moistlim )
{

/* rhxh2o: effect of moisture on decomposition */

  double rhxh2o;
  double vfc;
  double wfps;
  
  if( 0 == moistlim )
  {
    vfc = pctfldcap*0.01;

    rhxh2o = (vfc - moistmin[pdcmnt])
             * (vfc - moistmax[pdcmnt]);

    rhxh2o /= rhxh2o - pow( (vfc - moistopt[pdcmnt]), 2.0 );
  }
  else
  {
    rhxh2o = (vsm - moistmin[pdcmnt])
             * (vsm - moistmax[pdcmnt]);

    rhxh2o /= rhxh2o - pow( (vsm - moistopt[pdcmnt]), 2.0 );
    
    #ifdef RHMOIST_WFPS
      wfps = 100.0*vsm/pctpor;
      rhxh2o = 0.2+0.8*wfps*(1.0-wfps)/(wfps*(1.0-wfps) + (0.6-wfps)*(0.6-wfps));
    #endif  
    
    #ifdef RHMOIST_SECH
//      vsmopt = (pctpor - 15.0)/100.0;
//      vsmdenm = (pctpor - 15.0 - pctwiltpt)/100.0;
//      rhxh2o = 0.2 + 0.8 * exp( -((vsm-vsmopt)*(vsm-vsmopt))/(0.4809*vsmdenm*vsmdenm) );
      
      rhxh2o = 1.0 + 0.5*exp( 20.0*((pctwiltpt+pctfldcap)/200.0-vsm)) + 0.5*exp(20.0*(vsm-0.008*pctpor));
      rhxh2o = 1.0/rhxh2o;
//      cout << " vsmopt = " << vsmopt << " " << rhxh2o << " " << vsm << " " << pctwiltpt << " " << pctpor << endl;
//      exit(-1); 
    #endif  
  }

  if( rhxh2o < ZERO ) { rhxh2o = ZERO; }

  return rhxh2o;

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::showecd( const int& pdcmnt )
{

  cout << endl << "   MICROBIAL PARAMETERS INFLUENCED BY CLIMATE";
  cout << endl << endl;
  printf( "          KN2 = %6.4lf\n", kn2[pdcmnt] );
  printf( "     MOISTMIN = %8.6lf\n", moistmin[pdcmnt] );
  printf( "     MOISTOPT = %8.6lf\n", moistopt[pdcmnt] );
  printf( "     MOISTMAX = %8.6lf\n", moistmax[pdcmnt] );
  printf( "       CNSOIL = %5.2lf\n", cnsoil[pdcmnt] );
};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

void Tmcrb45::updateDynamics( const int& pdcmnt,
                                 const double& pctfldcap,
                                 const double& pctwiltpt,
                                 const double& pctpor,
                                 const double& soilorgc,
                                 const double& active_c,
                                 const double& slow_c,
                                 const double& passive_c,
                                 const double& soilorgn,
                                 const double& active_n,
                                 const double& slow_n,
                                 const double& passive_n,
                                 const double& soilh2o,
                                 const double& vsm,
                                 const double& availn,
                                 const int& moistlim,
                                 const int& tillflag,
                                 const double& tillfactor,
                                 const double& ksoil,
                                 const double& rltrc,
                                 const int& nopen )
{
  double rhmoist; /* effect of moisture on decomposition */

  rhmoist = setRHMOIST( pdcmnt, pctfldcap, pctwiltpt, pctpor, vsm, moistlim );

  decomp_active = rhxclm( active_c, kdc[pdcmnt], dq10, rhmoist, rltrc, pdcmnt );  
  decomp_slow = rhxclm( slow_c, kd_slow[pdcmnt], dq10, rhmoist, rltrc, pdcmnt );
  decomp_passive = rhxclm( passive_c, kd_passive[pdcmnt], dq10, rhmoist, rltrc, pdcmnt );

  if( decomp_active < ZERO ) { decomp_active = ZERO; } 
  if( decomp_slow < ZERO ) { decomp_slow = ZERO; }
  if( decomp_passive < ZERO ) { decomp_passive = ZERO; }

//  DOC production term
   docprod_active = docfr[pdcmnt] * decomp_active;
   docprod_slow = docfr[pdcmnt] * decomp_slow;
   docprod_passive = docfr[pdcmnt] * decomp_passive;

   docprod = docprod_active + docprod_slow + docprod_passive;

   rh_active = decomp_active - docprod_active;
   rh_slow = decomp_slow - docprod_slow;
   rh_passive = decomp_passive - docprod_passive;

   rh = rh_active + rh_slow + rh_passive;

//Adjust decomposition rate due to tillage effects

  if( 1 == tillflag )
  {
    rh *= tillfactor;
  }

   donprod_active = docprod_active * active_n/active_c;
   donprod_slow = docprod_slow * slow_n/slow_c;
   donprod_passive = docprod_passive * passive_n/passive_c;

   donprod = donprod_active + donprod_slow + donprod_passive;

//  cout << "finalrh = " << tillflag << " " << rh << endl;

  // Determine Net N Mineralization (microbe.netnmin)

  
  /* currently netnmin calculated separately for each pools, 
   * Next, try to combine them together as availn and nuptake is one value,
   * so does not need to split
   * MJ MLS
   */
  netnmin_active = nminxclm( pdcmnt,
                      soilh2o,
                      active_c,
                      active_n,
                      availn,
                      ksoil,
                      rh_active,
                      nopen,
                      cnsoil_active[pdcmnt],
                      nup[pdcmnt] );     
  gmin_active = gmin;                   
  nuptakefb = nuptake;

  netnmin_slow = nminxclm( pdcmnt,
                      soilh2o,
                      slow_c,
                      slow_n,
                      availn,
                      ksoil,
                      rh_sow,
                      nopen,
                      cnsoil_slow[pdcmnt],
                      nup[pdcmnt]/nupfbam[pdcmnt] );
  gmin_slow = gmin;
  nuptakeam = nuptake;

  netnmin_passive = nminxclm( pdcmnt,
                      soilh2o,
                      passive_c,
                      passive_n,
                      availn,
                      ksoil,
                      rh_passive,
                      nopen,
                      cnsoil_passive[pdcmnt],
                      nup[pdcmnt] );

  gmin_passive = gmin;
  nuptakemn = nuptake;

  netnmin = netnmin_active + netnmin_slow + netnmin_passive;
  gmin = gmin_active + gmin_slow + gmin_passive;
//  nuptake = nuptakefb + nuptakeam + nuptakemn;

};

/* **************************************************************
************************************************************** */


/* **************************************************************
************************************************************** */

double Tmcrb45::yrkd( const int& nfeed,
                         const double& yrltrc,
                         const double& yrltrn,
                         const double& kd,
                         const int& pdcmnt )
{

  double yrkd;

  if ( yrltrn <= 0.000000000000001 ) { return  yrkd = ZERO; }
  if ( yrltrc < ZERO )
  {
    cout << "YRLTRC is < 0.0 in microbe.yrkd()" << endl;

    exit( -1 );
  }
  
  if ( 0 == nfeed ) { yrkd = kd; }
  else
  {
    yrkd = kd * pow( (yrltrc/yrltrn), -0.784 )
           / pow( lcclnc[pdcmnt], -0.784 );
  }

  return yrkd;
};


/* *************************************************************
****************************************************************
TTEM45_ndep.H - Terrestrial Ecosystem Model Version TEM-MLS
****************************************************************

****************************************************************
************************************************************** */

#ifndef TTEM45_CWD_H
#define TTEM45_CWD_H

#include "temconsts45.hpp"
#include "tprocessXML45.h"

#ifdef CALIBRATE_TEM
  // Additional global constants
  const int DEBUG_ROW = 50;

  const int WSY = 8;
  const int ESY = 10;
  const int NEKEY = 127; // number of choices for output as "optional E fluxes"
  const int NWKEY = 41; // number of choices for output as "optional W fluxes"
#endif


// Objects describing basic components of the ecosystem

#include "bioms45.hpp"   // TTEM45 uses Biomass class


// Objects describing the structure of the ecosystem

#include "atms45_ndep.h"     // TTEM45 uses Atms45 class
#include "tveg45_equil.h"    // TTEM45 uses Tveg45 class
#include "tsoil45_lulc.h"    // TTEM45 uses Tsoil45 class
#include "tmcrb45_lulc.h"    // TTEM45 uses Tmcrb45 class
#include "penmon45_equil.h"
#include "ticdat.h"
#include "tbcdat.h"


// Objects describing the effects of human activities on the
//   ecosystem

#include "humnact45_cwd.h" // TTEM45 uses Humnact45 class


class Ttem45
{

  public:

     Ttem45();

     enum temkey
     {
       I_LEAFC,    I_SAPWOODC,     I_HEARTWOODC,      I_ROOTC,
       I_SEEDC,    I_LABILEC,      I_SOLC,            I_ACTIVE_C,      
       I_SLOW_C,   I_PASSIVE_C,    // 10

       I_LEAFN,    I_SAPWOODN,     I_HEARTWOODN,      I_ROOTN,
       I_SEEDN,    I_LABILEN,      I_SOLN,            I_ACTIVE_N, 
       I_SLOW_N,   I_PASSIVE_N,    I_AVLN,            I_AVLN_ACTIVE,   
       I_AVLN_SLOW,I_AVLN_PASSIVE,  // 14

       I_FOZONE,   I_DOC,          I_DOC_ACTIVE,      I_DOC_SLOW,     I_DOC_PASSIVE,
       I_DON,      I_DON_ACTIVE,   I_DON_SLOW,        I_DON_PASSIVE,    // 9
                 /* 10+14+9=33 C&N Pools (MAXESTAT)  */
                 /*##########################*/
 
       I_SM,       I_VSM,      I_PCTP,     I_RGRW,      I_SGRW,
                  /* 5 Water Pools (MAXWSTAT) */
                  /*##########################*/

       I_FPC,        I_ALLOCLC,    I_ALLOCSC,    I_ALLOCHC,    I_ALLOCRC,  
       I_ALLOCSEEDC, I_ALLOCILC,   I_ALLOCISC,   I_ALLOCIHC,   I_ALLOCIRC, 
       I_ALLOCISEEDC,I_INGPP,      I_GPP,        I_INNPP,      I_NPP,      
       I_GPR,        I_RVMNT,      I_RMLEAF,     I_RMSAPWOOD,  I_RMROOT,   
       I_RMSEED,     I_RMLABILE,   I_RVGRW,      I_LTRLC,      I_LTRSC,    
       I_LTRHC,      I_LTRRC,      I_LTRSEEDC,   I_RH,         I_RH_ACTIVE,    
       I_RH_SLOW,    I_RH_PASSIVE,

       I_ALLOCLN,         I_ALLOCSN,        I_ALLOCHN,        I_ALLOCRN,       I_ALLOCSEEDN,
       I_ALLOCILN,        I_ALLOCISN,       I_ALLOCIHN,       I_ALLOCIRN,      I_ALLOCISEEDN,
       I_NINP,            I_AGFRTN,         I_INNUP,          I_VNUP,          I_NRESORBL, 
       I_NRESORBS,        I_NRESORBR,       I_NRESORBSEED,    I_LTRLN,         I_LTRSN,    
       I_LTRHN,           I_LTRRN,          I_LTRSEEDN,       I_MNUP,          I_NMIN,   
       I_NMIN_ACTIVE,     I_NMIN_SLOW,      I_NMIN_PASSIVE,   I_NLST,          I_DOCPROD,  
       I_DOCPROD_ACTIVE,  I_DOCPROD_SLOW,   I_DOCPROD_PASSIVE,I_LCHDOC,        I_LCHDOC_ACTIVE,
       I_LCHDOC_SLOW,     I_LCHDOC_PASSIVE, I_DONPROD,        I_DONPROD_ACTIVE,I_DONPROD_SLOW,
       I_DONPROD_PASSIVE, I_LCHDON,         I_LCHDON_ACTIVE,  I_LCHDON_SLOW,   I_LCHDON_PASSIVE,
       I_NFIXS,           I_NFIXN,          I_FRDL,           I_FCO2,          I_FH2O,   
       I_TEMP,            I_FO3,            I_LCHDIN,   
                  /* 85 C&N Fluxes (NUMEEQ-MAXESTAT) */
                  /*#################################*/

       I_AGIRRIG,  I_INEET,    I_EET,      I_RPERC,     I_SPERC,
       I_RRUN,     I_SRUN,

       I_GC,       I_GS,       I_PECAN,    I_PESOIL, 
                  /* 11 Water Fluxes (NUMWEQ-MAXWSTAT) */
                  /*###################################*/

// 31+5+85+11 = 132 = NUMEQ; no variables below this point should appear in
//   the tem.y[NUMEQ] variable

       I_TOTEC,    I_TOTC,     I_VEGN,

       I_SNWPCK,   I_AVLW,

       I_NEP,      I_NCE,      I_LAI,

       I_PET,      I_SNWINF,   I_WYLD,

       I_AGPRDC,   I_PROD10C,  I_PROD100C, I_TOTPRDC,

       I_RESIDC,   I_AGSTUBC,

       I_AGPRDN,   I_PROD10N,  I_PROD100N, I_TOTPRDN,

       I_RESIDN,   I_AGSTUBN,

       I_CNVRTC,   I_VCNVRTC,  I_SCNVRTC,  I_SLASHC,    I_CFLX,

       I_CNVRTN,   I_VCNVRTN,  I_SCNVRTN,  I_SLASHN,    I_NRETNT,
       I_NVRTNT,   I_NSRTNT,   I_NSRTNT_ACTIVE, I_NSRTNT_SLOW,  I_NSRTNT_PASSIVE,
       I_SOLC,     I_SOLN,   

  //ok to here 40 
       I_AGFPRDC,  I_AGFPRDN,  I_FRESIDC,  I_FRESIDN,   I_AGPRDFC,
       I_AGPRDFN,  I_RESIDFC,  I_RESIDFN,

       I_PRDF10C,  I_PRDF10N,  I_PRD10FC,  I_PRD10FN,   I_PRDF100C,
       I_PRDF100N, I_PRD100FC, I_PRD100FN, I_TOTFPRDC,  I_TOTFPRDN,
       I_TOTPRDFC, I_TOTPRDFN,

       I_CROPC,    I_NATVEGC,  I_CROPN,    I_NATVEGN,   I_CSTRN,
       I_NATSTRN,  I_CSTON,    I_NATSTON,

       I_CROPLAI,  I_NATLAI,   I_CROPFPC,  I_NATFPC,

       I_AGINGPP,  I_NATINGPP, I_AGGPP,    I_NATGPP,    I_AGINNPP,
       I_NATINNPP, I_AGNPP,    I_NATNPP,   I_AGGPR,     I_NATGPR,
       I_AGRVMNT,  I_NATRVMNT, I_AGRVGRW,  I_NATRVGRW,  I_AGLTRC,
       I_NATLTRC,

       I_AGINNUP,  I_NATINNUP, I_AGVNUP,   I_NATVNUP,
       I_AGVNMBL,  I_NATVNMBL,
       I_AGVNRSRB, I_NVNRSRB,  I_AGLTRN,   I_NATLTRN,   I_CLIPPINGS
//  99 extra variables
     };

     #ifdef CALIBRATE_TEM
       enum seykey { NOEKEY,               //0        
                     GET_VEGC,             //1
                     GET_STRN,             //2
                     GET_SOILC,            //3
                     GET_SOILN,            //4
                     GET_AVALN,            //5
                     GET_LEAFC,            //6      
                     GET_SAPWOODC,         //7  
                     GET_HEARTWOODC,       //8
                     GET_ROOTC,            //9
                     GET_SEEDC,            //10   
                     GET_LABILEC,          //11
                     GET_LEAFN,            //12
                     GET_SAPWOODN,         //13
                     GET_HEARTWOODN,       //14
                     GET_ROOTN,            //15
                     GET_SEEDN,            //16          
                     GET_LABILEN,          //17
                     GET_FPC,              //18         
                     GET_ALLOCLC,          //19
                     GET_ALLOCSC,          //20
                     GET_ALLOCHC,          //21
                     GET_ALLOCRC,          //22
                     GET_ALLOCSEEDC,       //23
                     GET_ALLOCILC,         //24
                     GET_ALLOCISC,         //25
                     GET_ALLOCIHC,         //26
                     GET_ALLOCIRC,         //27
                     GET_ALLOCISEEDC,      //28
                     GET_INGPP,            //29
                     GET_GPP,              //30
                     GET_KPLANT,           //31
                     GET_D40,              //32
                     GET_FOZONE,           //33
                     GET_INNPP,            //34
                     GET_NPP,              //35
                     GET_GPR,              //36
                     GET_RVMNT,            //37
                     GET_RMLEAF,           //38
                     GET_RMSAPWOOD,        //39
                     GET_RMROOT,           //40
                     GET_RMSEED,           //41
                     GET_RMLABILE,         //42
                     GET_RVGRW,            //43
                     GET_LTRLC,            //44        
                     GET_LTRSC,            //45
                     GET_LTRHC,            //46
                     GET_LTRRC,            //47
                     GET_LTRSEEDC,         //48
                     GET_AGSTUBC,          //49
                     GET_RH,               //50
                     GET_NEP,              //51
                     GET_LAI,              //52
                     GET_ALLOCLN,          //53
                     GET_ALLOCSN,          //54
                     GET_ALLOCHN,          //55
                     GET_ALLOCRN,          //56
                     GET_ALLOCSEEDN,       //57
                     GET_ALLOCILN,         //58
                     GET_ALLOCISN,         //59
                     GET_ALLOCIHN,         //60
                     GET_ALLOCIRN,         //61
                     GET_ALLOCISEEDN,      //62
                     GET_NINP,             //63
                     GET_AGFRTN,           //64
                     GET_INNUP,            //65
                     GET_VNUP,             //66
                     GET_NRESORBL,         //67
                     GET_NRESORBS,         //68
                     GET_NRESORBR,         //69
                     GET_NRESORBSEED,      //70
                     GET_LTRLN,            //71
                     GET_LTRSN,            //72
                     GET_LTRHN,            //73
                     GET_LTRRN,            //74
                     GET_LTRSEEDN,         //75
                     GET_AGSTUBN,          //76
                     GET_MNUP,             //77
                     GET_NMIN,             //78
                     GET_NLST,             //79
                     GET_CNVRTC,           //80
                     GET_VCNVRTC,          //81
                     GET_SCNVRTC,          //82
                     GET_SLASHC,           //83
                     GET_CFLX,             //84
                     GET_NCE,              //85
                     GET_CNVRTN,           //86
                     GET_VCNVRTN,          //87
                     GET_SCNVRTN,          //88
                     GET_SLASHN,           //89
                     GET_NRETNT,           //90
                     GET_NVRTNT,           //91
                     GET_NSRTNT,           //92
                     GET_AGPRDC,           //93
                     GET_PROD10C,          //94
                     GET_PROD100C,         //95
                     GET_RESIDC,           //96
                     GET_AGPRDN,           //97
                     GET_PROD10N,          //98
                     GET_PROD100N,         //99
                     GET_RESIDN,           //100
                     GET_AGFPRDC,          //101
                     GET_PRDF10C,          //102
                     GET_PRDF100C,         //103
                     GET_FRESIDC,          //104
                     GET_AGPRDFC,          //105
                     GET_PRD10FC,          //106
                     GET_PRD100FC,         //107
                     GET_TOTPRDFC,         //108
                     GET_RESIDFC,          //109
                     GET_AGFPRDN,          //110
                     GET_PRDF10N,          //111
                     GET_PRDF100N,         //112
                     GET_FRESIDN,          //113
                     GET_AGPRDFN,          //114
                     GET_PRD10FN,          //115
                     GET_PRD100FN,         //116
                     GET_TOTPRDFN,         //117
                     GET_RESIDFN,          //118
                     GET_L2SN,             //119
                     GET_DOC,                //120
                     GET_CLIPPINGS,          //121
                     GET_DON,               //122
                     GET_DOCPROD,            //123
                     GET_LCHDOC,               //124
                     GET_DONPROD,             //125
                     GET_LCHDON,             //126
                     GET_LCHDIN,             //127
                     GET_NFIXS,               //128
                     GET_NFIXN,               //129
                     GET_NDEP               //130
                     };


       enum swykey { NOWKEY,               //0    
                     GET_SH2O,             //1
                     GET_PCTP,             //2
                     GET_VSM,              //3
                     GET_RAIN,             //4
                     GET_SNWFAL,           //5
                     GET_SNWINF,           //6
                     GET_AGIRRIG,          //7
                     GET_PET,              //8
                     GET_TAIR,             //9
                     GET_TAIRD,            //10
                     GET_TAIRN,            //11
                     GET_INEET,            //12
                     GET_EET,              //13
                     GET_GC,               //14
                     GET_GS,               //15
                     GET_RPERC,            //16
                     GET_SPERC,            //17
                     GET_RRUN,             //18
                     GET_SRUN,             //19
                     GET_WYLD,             //20
                     GET_PESOIL,           //21
                     GET_PECAN,            //22
                     GET_SHFLUX,           //23
                     GET_SWP,              //24
                     GET_VEGH,             //25
                     GET_USTAR,            //26
                     GET_ZD,               //27
                     GET_ZO,               //28
                     GET_R_AA,             //29
                     GET_R_AC,             //30
                     GET_R_AS,             //31
                     GET_R_SS,             //32
                     GET_VAPR,             //33
                     GET_VPDD,             //34
                     GET_VPDN,             //35
                     GET_AVLH2O,           //36
                     GET_RGRNDW,           //37
                     GET_SGRNDW,           //38
                     GET_GDD,              //39
                     GET_SNWPCK           //40
                     };

     #endif

/* **************************************************************
			Public Functions
************************************************************** */

     #ifdef CALIBRATE_TEM
       void displayOptionalEflx( const seykey& s );
       void displayOptionalWflx( const swykey& s );
     #endif

     int ecdqc( const int& dcmnt );

     void ECDsetODEstate( const int& pdcmnt,
                          const double& psiplusc );

     void getco2( void );

     #ifdef CALIBRATE_TEM
       double getOptionalEflx( const int& optflx );

       double getOptionalWflx( const int& optflx );
     #endif

     void getsitecd( const int& dv, const string& ecd );
     
     void initializeState( void );
     void initializecalibState( void );

     int monthlyTransient( const int& outyr,
                           const int& pdm,
                           const double& outtol );

     #ifdef CALIBRATE_TEM
       inline seykey& keyjump( const int& keyloc, seykey& s )
       {
         return s = seykey( keyloc );
       }

       inline swykey& keyjump( const int& keyloc, swykey& s )
       {
         return s = swykey( keyloc );
       }
       
       inline seykey& next( seykey& s )
       {
         //return s = (GET_L2SN == s) ? GET_LEAFC : seykey( s+1 );
         return s = seykey( (s+1)%NEKEY );
       }

       inline swykey& next( swykey& s )
       {
         //return s = (GET_R_SS == s) ? GET_SH2O : swykey( s+1 );
         return s = swykey( (s+1)%NWKEY );
       }

       inline seykey& prev( seykey& s )
       {
         //return s = (GET_LEAFC == s) ? GET_L2SN : seykey( s-1 );
         return s = seykey( (NEKEY+s-1)%NEKEY );
       }

       inline swykey& prev( swykey& s )
       {
         //return s = (GET_SH2O == s) ? GET_R_SS : swykey( s-1 );
         return s = swykey( (NWKEY+s-1)%NWKEY );
       }
     #endif

     void resetMonthlyELMNTFluxes( void );

     void resetYrFluxes( void );

     void setELMNTecd( const int& pdcmnt,
                       const double& psiplusc );

     void setEquilC2N( const int& pdcmnt,
                       const double& co2 );

     void setPrevState( void );

     int stepmonth( const int& pdyr,
                    const int& pdm,
                    int& intflag,
                    const double& ptol );

     int testEquilibrium( const int& pdyr,
                          const int& nyears,
                          const double& vegceq,
                          const double& soilceq,
                          const double& vegneq,
                          const double& soilneq );
                          

     void updateYearSummary( const int& pdm );

     void yearSummaryExtrapolate( void );

     // "Get" and "Set" private variables and parameters


     // avln **************************************************

     inline double getAVLN( const int& pcmnt )
     {
       return avln[pcmnt];
     }

     inline void setAVLN( const double& pavln,
                           const int& pcmnt )
     {
       avln[pcmnt] = pavln;
     } 

     
     // avln_active **************************************************    //MJ MLS;

     inline double getAVLN_ACTIVE( const int& pcmnt )
     {
       return avln_active[pcmnt];
     }

     inline void setAVLN_ACTIVE( const double& pavln_active,
                           const int& pcmnt )
     {
       avln_active[pcmnt] = pavln_active;
     }

     // avln_slow **************************************************

     inline double getAVLN_SLOW( const int& pcmnt )
     {
       return avln_slow[pcmnt];
     }

     inline void setAVLN_SLOW( const double& pavln_slow,
                           const int& pcmnt )
     {
       avln_slow[pcmnt] = pavln_slow;
     }

     // avln_passive **************************************************

     inline double getAVLN_PASSIVE( const int& pcmnt )
     {
       return avln_passive[pcmnt];
     }

     inline void setAVLN_PASSIVE( const double& pavln_passive,
                           const int& pcmnt )
     {
       avln_passive[pcmnt] = pavln_passive;
     }
     

     // nce ****************************************************

     inline double getNCE( void ) { return nce; }


     // nep ****************************************************

     inline double getNEP( void ) { return nep; }


     // prevy **************************************************

     inline double getPREVY( const int& i ) { return prevy[i]; }

     inline void setPREVY( const double& pprevy, const int& i )
     {
       prevy[i] = pprevy;
     }

     // solc **************************************************

     inline double getSOLC( const int& pcmnt )
     {
       return solc[pcmnt];
     }

     inline void setSOLC( const double& psolc,
                           const int& pcmnt )
     {
       solc[pcmnt] = psolc;
     }

     // soln **************************************************

     inline double getSOLN( const int& pcmnt )
     {
       return soln[pcmnt];
     }

     inline void setSOLN( const double& psoln,
                           const int& pcmnt )
     {
       soln[pcmnt] = psoln;
     } 

/*   comment out because solc etc are not the sum of active,slow,passive pools yet, check back
     inline double getSOLC( void ) { return solc; }
     inline double getSOLN( void ) { return soln; }
     inline double getDOC( void ) { return doc; }
     inline double getDON( void ) { return don; }
     inline double getDOCPROD( void ) { return docprod; }
     inline double getDONPROD( void ) { return donprod; }
     inline double getLCHDOC( void ) { return lchdoc; }
     inline double getLCHDON( void ) { return lchdon; }
 */

     // doc **************************************************

      inline double getDOC( const int& pcmnt )
      {
       return doc[pcmnt];
      }
     
     inline void setDOC( const double& pdoc,
                          const int& pcmnt )
     {
       doc[pcmnt] = pdoc;
     } 
     
     // don **************************************************
     
     inline double getDON( const int& pcmnt )
     {
       return don[pcmnt];
     }
     
     inline void setDON( const double& pdon,
                         const int& pcmnt )
     {
       don[pcmnt] = pdon;
     } 

    // active_c **************************************************
    
      inline double getACTIVE_C( const int& pcmnt )
     {
       return active_c[pcmnt];
     }

     inline void setACTIVE_C( const double& pactive_c,
                           const int& pcmnt )
     {
       active_c[pcmnt] = pactive_c;
     }


     //slow_c **************************************************

      inline double getSLOW_C( const int& pcmnt )
     {
       return slow_c[pcmnt];
     }

     inline void setSLOW_C( const double& pslow_c,
                           const int& pcmnt )
     {
       slow_c[pcmnt] = pslow_c;
     }

     //passive_c **************************************************

      inline double getPASSIVE_C( const int& pcmnt )
     {
       return passive_c[pcmnt];
     }

     inline void setPASSIVE_C( const double& ppassive_c,
                           const int& pcmnt )
     {
       passive_c[pcmnt] = ppassive_c;
     }


//    Vegetation Nitrogen Initial Pools


     // leafnb **************************************************

     inline double getLEAFNB( const int& pcmnt )
     {
       return leafnb[pcmnt];
     }

     inline void setLEAFNB( const double& pleafnb,
                           const int& pcmnt )
     {
       leafnb[pcmnt] = pleafnb;
     }

     // sapwoodnb **************************************************

     inline double getSAPWOODNB( const int& pcmnt )
     {
       return sapwoodnb[pcmnt];
     }

     inline void setSAPWOODNB( const double& psapwoodnb,
                           const int& pcmnt )
     {
       sapwoodnb[pcmnt] = psapwoodnb;
     }


     // heartwoodnb **************************************************

     inline double getHEARTWOODNB( const int& pcmnt )
     {
       return heartwoodnb[pcmnt];
     }

     inline void setHEARTWOODNB( const double& pheartwoodnb,
                           const int& pcmnt )
     {
       heartwoodnb[pcmnt] = pheartwoodnb;
     }


     // rootnb **************************************************

     inline double getROOTNB( const int& pcmnt )
     {
       return rootnb[pcmnt];
     }

     inline void setROOTNB( const double& prootnb,
                           const int& pcmnt )
     {
       rootnb[pcmnt] = prootnb;
     }


     // labilenb **************************************************

     inline double getLABILENB( const int& pcmnt )
     {
       return labilenb[pcmnt];
     }

     inline void setLABILENB( const double& plabilenb,
                           const int& pcmnt )
     {
       labilenb[pcmnt] = plabilenb;
     }


   // seednb **************************************************

    inline double getSEEDNB( const int& pcmnt )
    {
      return seednb[pcmnt];
    }

    inline void setSEEDNB( const double& pseednb,
                      const int& pcmnt )
   {
      seednb[pcmnt] = pseednb;
   }

     // totalc *************************************************

     inline double getTOTALC( void ) { return totalc; }

//   Vegetation Parameters


     // leafcb **************************************************

     inline double getLEAFCB( const int& pcmnt )
     {
       return leafcb[pcmnt];
     }

     inline void setLEAFCB( const double& pleafcb,
                           const int& pcmnt )
     {
       leafcb[pcmnt] = pleafcb;
     }


     // sapwoodcb **************************************************

     inline double getSAPWOODCB( const int& pcmnt )
     {
       return sapwoodcb[pcmnt];
     }

     inline void setSAPWOODCB( const double& psapwoodcb,
                           const int& pcmnt )
     {
       sapwoodcb[pcmnt] = psapwoodcb;
     }


    // heartwoodcb **************************************************

    inline double getHEARTWOODCB( const int& pcmnt )
    {
      return heartwoodcb[pcmnt];
    }

    inline void setHEARTWOODCB( const double& pheartwoodcb,
                      const int& pcmnt )
    {
      heartwoodcb[pcmnt] = pheartwoodcb;
    }


     // rootcb **************************************************

     inline double getROOTCB( const int& pcmnt )
     {
       return rootcb[pcmnt];
     }

     inline void setROOTCB( const double& prootcb,
                           const int& pcmnt )
     {
       rootcb[pcmnt] = prootcb;
     }


     // labilecb **************************************************

     inline double getLABILECB( const int& pcmnt )
     {
       return labilecb[pcmnt];
     }

     inline void setLABILECB( const double& plabilecb,
                           const int& pcmnt )
     {
       labilecb[pcmnt] = plabilecb;
     }


   // seedcb **************************************************

   inline double getSEEDCB( const int& pcmnt )
   {
    return seedcb[pcmnt];
   }

   inline void setSEEDCB( const double& pseedcb,
                      const int& pcmnt )
   {
   seedcb[pcmnt] = pseedcb;
   }

     // y ******************************************************

     inline double getY( const int& i ) { return y[i]; }

     inline void setY( const double& py, const int& i )
     {
       y[i] = py;
     }


/* **************************************************************
			 Public Variables
************************************************************** */

     // Input Ecd files with calibration data

     #ifdef CALIBRATE_TEM
       string soilfile;
       string rootfile;
       string vegfile;
       string mcrvfile;
       string agfile;
       string gcfile;
     #endif
       
     ifstream gofile;
     ifstream teminfile;
     string goname;
     ProcessXML45 goxml;
       
     #ifdef CALIBRATE_TEM
       int adapttol;
     #endif

     Humnact45 ag;

     Atms45 atms;

     Penmon45 pen;

     static int avlnflag;

     static int baseline;

     #ifdef CALIBRATE_TEM
       int calwind;
     #endif

     static double ctol;

     static int diffyr;

     int distmnthcnt;

     int disturbflag;

     int disturbmonth;

     double elev;              // elevation (m)

     static int endeq;

     static int endyr;

     static int equil;

     // index for vegetation type (ez = veg.temveg-1)
     int ez;

     int firemnthcnt;

     static int initbase;

     int initFlag;

     static double inittol;

     #ifdef CALIBRATE_TEM
       int intbomb;
     #endif

     static int intflag;
     
     static int maxit;
     
     static int maxitmon;

     static int maxnrun;

     static int maxyears;

     Tmcrb45 microbe;

     static int moistlim;

     int nattempt;

     static int nfeed;

     static double ntol;

     static int o3flag;

     int predflag;

     vector<string> predstr;

     double prvstempd[11];  //soil temperature at previous timestep day time
     double prvstempn[11];  //soil temperature at previous timestep night time

     double tsoild[11];
     double tsoiln[11];


     int qualcon[MAXRTIME];

     int retry;

     static int rheqflag;

     static int runsize;

     #ifdef CALIBRATE_TEM
       seykey sey[ESY];
       swykey swy[WSY];
     #endif

     Tsoil45 soil;

     static int startyr;

     static int strteq;

	 double tauavg;

     double tol;

     #ifdef CALIBRATE_TEM
       int tolbomb;
       int topwind;
     #endif

     int totyr;

     Tveg45 veg;

     Tmcrb45 mcrb;

     static int wrtyr;

     static double wtol;

     double yrnce;

     double yrnep;    // (g C / (sq. meter * year))

     double yrrsoil;  // (g C / (sq. meter * year))

     double yrtotalc;

     double mxeet;

     // Site ECD variables

     string version;
     string sitename;
     string developer;
     string sitecol;
     string siterow;
     string updated;
     string description;

     double wevapd[CYCLE];
     double wevapn[CYCLE];
     double rfrac[CYCLE];
     
     int harcnt;
/* **************************************************************
		     Protected Variables
************************************************************** */

  protected:

     int dbugflg;


  private:

/* **************************************************************
		 Private Functions
************************************************************** */

     int adapt( const int& numeq,
                double pstate[],
                const double& ptol,
                const int& pdm );

     void bkeu(const double prvstemp[],     
               const double& upcon,         //up boundary condition Temp;
               const double& downcon);      //boundary boundary condition temp; 

     int boundcon( double ptstate[],
                   double err[],
                   const double& ptol );

     void CopyMatrix(double MatrixInput[9][9],
                     double MatrixTarget[9][9],
                     int Row,
                     int Col);

     void delta( const int& dm,
                 double pstate[],
                 double pdstate[] );

     void cropDynamics( const int& dm, double pstate[] );

     void getenviron( void );

     void massbal( void );

     void natvegDynamics( const int& dm, double pstate[] );

     #ifdef CALIBRATE_TEM
       void pcdisplayDT( const double& tottime,
                         const double& deltat );

       void pcdisplayMonth( const int& dyr,
                            const int& dm );

       void pcdisplayODEerr( const int& test,
                             double pstate[] );
     #endif

     void resetODEflux( void );
     
     void rkbs( const int& numeq,
               double pstate[],
               double& pdt,
               const int& pdm );

     void rkf( const int& numeq,
               double pstate[],
               double& pdt,
               const int& pdm );

     void step( const int& numeq,
                double pstate[],
                double pdstate[],
                double ptstate[],
                double& pdt );
  
     void updateVegBiomass( double pstate[] );

/* **************************************************************
		     Private Variables
************************************************************** */

     ifstream fecd[MAXCMNT];
     
     long delta_count;

     // Net Carbon Exchange (NCE)
     double nce;

     // Net Ecosystem Production
     double nep;      // (g C / (sq. meter * month))

     // NINPUT needed for calibration
     double ninput;
     // Values of ODE state variables for carbon, nitrogen and
     //   water pools during the previous month
     double prevy[MAXSTATE];

     // Total carbon storage (veg.plant + soil.org)
     double totalc;   // (g C/sq. meter)

     // Values of ODE state variables for current month
     double y[NUMEQ];
     
     
     // Variables for displaying "optional fluxes" at the end of a year: sum, max, avg, min      
     #ifdef CALIBRATE_TEM
       double outevarsum[ESY], outevaravg[ESY], outevarmax[ESY], outevarmin[ESY]; 
       double outwvarsum[WSY], outwvaravg[WSY], outwvarmax[WSY], outwvarmin[WSY];
     #endif

     // Adaptive integrator variables

     int blackhol;

     int syint;
     int test;

     double dum4[NUMEQ];
     double error[NUMEQ];

     double dum5[NUMEQ];
     double dumy[NUMEQ];

     double ydum[NUMEQ];
     double dy[NUMEQ];
     double yprime[NUMEQ];
     double rk45[NUMEQ];

     double f11[NUMEQ];
     double f2[NUMEQ];
     double f13[NUMEQ];
     double f3[NUMEQ];
     double f14[NUMEQ];
     double f4[NUMEQ];
     double f15[NUMEQ];
     double f5[NUMEQ];
     double f16[NUMEQ];
     double f6[NUMEQ];
     
     double zstate[NUMEQ];
     double dum2[NUMEQ];
     double dum3[NUMEQ];
     double dp2[NUMEQ]; 
     double dp3[NUMEQ];
     double dz1[NUMEQ]; 
     double dz2[NUMEQ]; 
     double dz3[NUMEQ]; 
     double dz4[NUMEQ];

     static double  a1;

     static double  a3;
     static double a31;
     static double a32;

     static double  a4;
     static double a41;
     static double a42;
     static double a43;

     static double  a5;
     static double a51;
     static double a52;
     static double a53;
     static double a54;

     static double  b1;
     static double  b3;
     static double  b4;
     static double  b5;

     static double  b6;
     static double b61;
     static double b62;
     static double b63;
     static double b64;
     static double b65;

     double dummy;

     double nirrn;
     int dumcnt;
     double nprod;
     double nseed;

     //bkeu variables

//     double upd;     //soil temperature day time
     double downd;     //soil temperature day time
//     double upn;     //soil temperautre night time
     double downn;     //soil temperautre night time

//     double tsoild[11];  //final soil temperature at each depth during day time
//     double tsoiln[11];  //final soil temperature at each depth during night time
   
     double prvstemp[11];

     double mlsoiltempd[11];
     double mlsoiltempn[11];
     double mlsoiltemp[11];


/* **************************************************************
			Private Parameters
************************************************************** */

     double leafcb[MAXCMNT];

     double sapwoodcb[MAXCMNT];

     double heartwoodcb[MAXCMNT];

     double rootcb[MAXCMNT];

     double labilecb[MAXCMNT];

     double seedcb[MAXCMNT];

     double leafnb[MAXCMNT];

     double sapwoodnb[MAXCMNT];

     double heartwoodnb[MAXCMNT];

     double rootnb[MAXCMNT];

     double labilenb[MAXCMNT];

     double seednb[MAXCMNT];

     double avln[MAXCMNT];
     double avln_active[MAXCMNT];
     double avln_slow[MAXCMNT];
     double avln_passive[MAXCMNT];
     
     double active_c[MAXCMNT];
     double slow_c[MAXCMNT];
     double passive_c[MAXCMNT];

     double active_n[MAXCMNT];
     double slow_n[MAXCMNT];
     double passive_n[MAXCMNT];
     
     double solc[MAXCMNT];
     double soln[MAXCMNT];
     
     double doc[MAXCMNT];
     double don[MAXCMNT];
     
     double docprod[MAXCMNT];
     double donprod[MAXCMNT];
     
     double lchdoc[MAXCMNT];
     double lchdon[MAXCMNT];
 };

#endif

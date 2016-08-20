/* **************************************************************
*****************************************************************
TSOIL45_LULC.H - object describing characteristics of soil used by
	        the Terrestrial Ecosystem Model (TEM)

Modifications:

20060126 - DWK created by modifying tsoil50b5.h
20060126 - DWK changed include from temconts51.hpp to
           temconsts43.hpp
20060126 - DWK changed include from tprocessXML51.h to
           tprocessXML437.h
20060126 - DWK deleted include qsoiltemp50b5.h
20060126 - DWK changed class Tsoil50 to class Tsoilflux
20060126 - DWK changed inheritance from ProcessXML50 to
           ProcessXML43
20060126 - DWK deleted public function double
           updateActiveLayerRootZ(), inline double
           getACTLAYER(), inline double getDST10(), inline
           double getNEXTDST10(), inline double getPREVDST10()
           and inline double getTSOIL()
20060126 - DWK deleted  public Soilthermal50 stm, int stmflg,
           double yrdst10 and double yrtsoil
20060126 - DWK deleted private double activeLayer, double dst10,
           double nextdst10, double prevdst10 and double tsoil
20060129 - DWK added public inline getVSM() and setVSM()
20060320 - DWK added private double surfrun and double drainage
20070105 - TWC changed name to tsoil45
2007:  TWC/BSF
     setSWP public function
	 get/set: evap
	 Public var.: yrevap
	 Private var: evap

****************************************************************
************************************************************* */

#ifndef TSOIL45_LULC_H
#define TSOIL45_LULC_H

// Tsoil45 uses the global constant MAXCMNT
#include "temconsts45.hpp"

#include "tprocessXML45.h"

#include "bioms45.hpp"      // Tsoilflux uses Biomass class


class Tsoil45 : public ProcessXML45
{

  public:

     Tsoil45( void );

/* **************************************************************
		 Public Functions
************************************************************** */


     void getrootz( const string& ecd );

     void lake( const double& tair,
                const double& prec,
                double& rain,
                double& snowfall,
                const double& pet,
                double& eet );

     void resetMonthlyFluxes( void );

     void resetYrFluxes( void );

     void setKH2O( const double& vsm,
                   const int& moistlim );
                        
     void setSWP( void );

     void showecd( void );

     double snowmelt( const double& elev,
                      const double& tair,
                      const double& prevtair,
                      const double& snowpack );


     void updateHydrology( const double& elev,
                           const double& tair,
                           const double& prevtair,
                           const double& prev2tair,
                           const double& rain,
                           const double& pet,
                           const double& avlh2o,
                           const double& rgrndh2o,
                           const double& sgrndh2o,
                           const int& irrgflag,
                           double& irrigate,
                           const int& pdm );

     void updateDOCLEACH( const double& doc, 
                          const double& sh2o );

     void updateNLosses( const int& pdcmnt,
                         const double& h2oloss,
                         const double& availnfb,
                         const double& availnam,
                         const double& availnmn,
                         const double& soilh2o );


     double updateRootZ( const int& pdcmnt,
                         const double& sh2o,
                         const double& finerootc );



     void xtext( const int& pdcmnt,
                 const double& pctsilt,
                 const double& pctclay );


     // "Get" and "Set" private variables and parameters

     // availn *************************************************

     inline double getAVLN( void ) { return availn; }

     inline void setAVLN( const double& pavln )
     {
       availn = pavln;
     }


     // avlh2o *************************************************

     inline double getAVLH2O( void ) { return avlh2o; }

     inline void setAVLH2O( const double& pavlh2o )
     {
       avlh2o = pavlh2o;
     }


     // awcapmm ************************************************

     inline double getAWCAPMM( void ) { return awcapmm; }

     inline void setAWCAPMM( const double& pawcapmm )
     {
       awcapmm = pawcapmm;
     }

     // coefa & coefb ************************************************
/*
     inline double getCOEFA( const int& pcmnt )
     {
       return coefa[pcmnt];
     }

     inline void setCOEFA( const double& pcoefa,
                            const int& pcmnt )
     {
       coefa[pcmnt] = pcoefa;
     }

     inline double getCOEFB( const int& pcmnt )
     {
       return coefb[pcmnt];
     }

     inline void setCOEFB( const double& pcoefb,
                            const int& pcmnt )
     {
       coefb[pcmnt] = pcoefb;
     }
*/
     // lchdon ************************************************

     inline double getLCHDON( void ) { return lchdon; }

     inline void setLCHDON( const double& plchdon )
     {
       lchdon = plchdon;
     }

     inline double getLCHDONFB( void ) { return lchdonfb; }

     inline void setLCHDONFB( const double& plchdonfb )
     {
       lchdonfb = plchdonfb;
     }

     inline double getLCHDONAM( void ) { return lchdonam; }

     inline void setLCHDONAM( const double& plchdonam )
     {
       lchdonam = plchdonam;
     }

     inline double getLCHDONMN( void ) { return lchdonmn; }

     inline void setLCHDONMN( const double& plchdonmn )
     {
       lchdonmn = plchdonmn;
     }


     // lchdin ************************************************
     
           inline double getLCHDIN( void ) { return lchdin; }
     
           inline void setLCHDIN( const double& plchdin )
           {
               lchdin = plchdin;
           }
     

           inline double getLCHDINFB( void ) { return lchdinfb; }

           inline void setLCHDINFB( const double& plchdinfb )
           {
               lchdinfb = plchdinfb;
           }


           inline double getLCHDINAM( void ) { return lchdinam; }

           inline void setLCHDINAM( const double& plchdinam )
           {
               lchdinam = plchdinam;
           }


           inline double getLCHDINMN( void ) { return lchdinmn; }

           inline void setLCHDINMN( const double& plchdinmn )
           {
               lchdinmn = plchdinmn;
           }


     // drainage ***********************************************

     inline double getDRAINAGE( void ) { return drainage; }

     inline void setDRAINAGE( const double& pdrainage )
     {
       drainage = pdrainage;
     }


     // eet ****************************************************

     inline double getEET( void ) { return eet; }

     inline void setEET( const double& peet )
     {
       eet = peet;
     }

     // fldcap *************************************************

     inline double getFLDCAP( void ) { return fldcap; }


     // fldcapa ************************************************

     inline double getFLDCAPA( void ) { return fldcapa; }

     inline void setFLDCAPA( const double& pfldcapa )
     {
       fldcapa = pfldcapa;
     }


     // fldcapb ************************************************

     inline double getFLDCAPB( void ) { return fldcapb; }

     inline void setFLDCAPB( const double& pfldcapb )
     {
       fldcapb = pfldcapb;
     }

//for the following three parameters, read in from trotz45_lulc.ecd file,as they should be pft-specific
//check if the following get set is correct or not MJ MLS;     
     //  frrootc_fb*********************************************

     inline double getFRROOTC_FB( const int& pcmnt )
     {
       return frrootc_fb[pcmnt];
     }

     inline void setFRROOTC_FB( const double& pfrrootc_fb,
                            const int& pcmnt )
     {
       frrootc_fb[pcmnt] = pfrrootc_fb;
     }

    //  frrootc_am*********************************************

     inline double getFRROOTC_AM( const int& pcmnt )
     {
       return frrootc_am[pcmnt];
     }

     inline void setFRROOTC_AM( const double& pfrrootc_am,
                            const int& pcmnt )
     {
       frrootc_am[pcmnt] = pfrrootc_am;
     }

    //  frrootc_mn*********************************************

     inline double getFRROOTC_MN( const int& pcmnt )
     {
       return frrootc_mn[pcmnt];
     }

     inline void setFRROOTC_MN( const double& pfrrootc_mn,
                            const int& pcmnt )
     {
       frrootc_mn[pcmnt] = pfrrootc_mn;
     }

     // gm ***************************************************

     inline double getGM( void ) { return gm; }


     // h2oyld *************************************************

     inline double getH2OYLD( void ) { return h2oyld; }

     inline void setH2OYLD( const double& ph2oyld )
     {
       h2oyld = ph2oyld;
     }


     // ineet **************************************************

     inline double getINEET( void ) { return ineet; }

     inline void setINEET( const double& pineet )
     {
       ineet = pineet;
     }


     // kh2o ***************************************************

     inline double getKH2O( void ) { return kh2o; }

     // lchdoc *************************************************

     inline double getLCHDOC( void ) { return lchdoc; }

     inline void setLCHDOC( const double& plchdoc )
     {
       lchdoc = plchdoc;
     }

     inline double getLCHDOCFB( void ) { return lchdocfb; }

     inline void setLCHDOCFB( const double& plchdocfb )
     {
       lchdocfb = plchdocfb;
     }

     inline double getLCHDOCAM( void ) { return lchdocam; }

     inline void setLCHDOCAM( const double& plchdocam )
     {
       lchdocam = plchdocam;
     }

     inline double getLCHDOCMN( void ) { return lchdocmn; }

     inline void setLCHDOCMN( const double& plchdocmn )
     {
       lchdocmn = plchdocmn;
     }


     // minrootz ***********************************************

     inline double getMINROOTZ( const int& pcmnt )
     {
       return minrootz[pcmnt];
     }

     inline void setMINROOTZ( const double& pminrootz,
                              const int& pcmnt )
     {
       minrootz[pcmnt] = pminrootz;
     }

     // z0 ***********************************************

     inline double getZ0( const int& pcmnt )
     {
       return z0[pcmnt];
     }

     inline void setZ0( const double& pz0,
                              const int& pcmnt )
     {
       z0[pcmnt] = pz0;
     }



     // moist **************************************************

     inline double getMOIST( void ) { return moist; }

     inline void setMOIST( const double& psh2o )
     {
       moist = psh2o;
     }


     // ninput *************************************************

     inline double getNINPUT( void ) { return ninput; }

     inline void setNINPUT( const double& pninput )
     {
       ninput = pninput;
     }


     // nlossfb and horizon coefficients******

     inline double getNLOSSFB( const int& pcmnt )
     {
       return nlossfb[pcmnt];
     }

     inline void setNLOSSFB( const double& pnlossfb,
                           const int& pcmnt )
     {
       nlossfb[pcmnt] = pnlossfb;
     }

     inline double getNLOSSFBAM( const int& pcmnt )
     {
       return nlossfbam[pcmnt];
     }

     inline void setNLOSSFBAM( const double& pnlossfbam,
                           const int& pcmnt )
     {
       nlossfbam[pcmnt] = pnlossfbam;
     }

     inline double getNLOSSFBMN( const int& pcmnt )
     {
       return nlossfbmn[pcmnt];
     }

     inline void setNLOSSFBMN( const double& pnlossfbmn,
                           const int& pcmnt )
     {
       nlossfbmn[pcmnt] = pnlossfbmn;
     }




     // denitr **************************************************
    
     inline double getDENITR( const int& pcmnt )
     {
       return denitr[pcmnt];
     }

     inline void setDENITR( const double& pdenitr,
                           const int& pcmnt )
     {
       denitr[pcmnt] = pdenitr;
     }


    //c_den ****************************************************

     inline double getC_DENFB( const int& pcmnt )
     {
       return c_denfb[pcmnt];
     }

     inline void setC_DENFB( const double& pc_denfb,
                           const int& pcmnt )
     {
       c_denfb[pcmnt] = pc_denfb;
     }

     inline double getC_DENAM( const int& pcmnt )
     {
       return c_denam[pcmnt];
     }

     inline void setC_DENAM( const double& pc_denam,
                           const int& pcmnt )
     {
       c_denam[pcmnt] = pc_denam;
     }


     // nlost **************************************************

     inline double getNLOST( void ) { return nlost; }

     inline void setNLOST( const double& pnlst )
     {
       nlost = pnlst;
     }

     inline double getNLOSTFB( void ) { return nlostfb; }

     inline void setNLOSTFB( const double& pnlstfb )
     {
       nlostfb = pnlstfb;
     }

     inline double getNLOSTAM( void ) { return nlostam; }

     inline void setNLOSTAM( const double& pnlstam )
     {
       nlostam = pnlstam;
     }

     inline double getNLOSTMN( void ) { return nlostmn; }

     inline void setNLOSTMN( const double& pnlstmn )
     {
       nlostmn = pnlstmn;
     }


     // pctclay ************************************************

     inline double getPCTCLAY( void ) { return pctclay; }

     inline void setPCTCLAY( const double& ppctclay )
     {
       pctclay = ppctclay;
     }


     // pcfldcap ***********************************************

     inline double getPCTFLDCAP( void ) { return pcfldcap; }

     inline void setPCTFLDCAP( const double& ppctfldcap )
     {
       pcfldcap = ppctfldcap;
     }


     // pctp ***************************************************

     inline double getPCTP( void ) { return pctp; }

     inline void setPCTP( const double& ppctp )
     {
       pctp = ppctp;
     }

     // pctpor *************************************************

     inline double getPCTPOR( void ) { return pctpor; }


     // pctpora ************************************************

     inline double getPCTPORA( void ) { return pctpora; }

     inline void setPCTPORA( const double& ppctpora )
     {
       pctpora = ppctpora;
     }


     // pctporb ************************************************

     inline double getPCTPORB( void ) { return pctporb; }

     inline void setPCTPORB( const double& ppctporb )
     {
       pctporb = ppctporb;
     }


     // pctsand ************************************************

     inline double getPCTSAND( void ) { return pctsand; }

     inline void setPCTSAND( const double& ppctsand )
     {
       pctsand = ppctsand;
     }


     // pctsilt ************************************************

     inline double getPCTSILT( void ) { return pctsilt; }

     inline void setPCTSILT( const double& ppctsilt )
     {
       pctsilt = ppctsilt;
     }
     
     // pctwiltpt ************************************************

     inline double getPCTWILTPT( void ) { return pcwiltpt; }


     // prevspack **********************************************

     inline double getPREVSPACK( void ) { return prevspack; }

     inline void setPREVSPACK( const double& pprvspack )
     {
       prevspack = pprvspack;
     }


     // psiplusc ***********************************************

     inline double getPSIPLUSC( void ) { return psiplusc; }

     inline void setPSIPLUSC( const double& ppsiplusc )
     {
       psiplusc = ppsiplusc;
     }

     // reet **************************************************

     inline double getREET( void ) { return reet; }

     inline void setREET( const double& peet )
     {
       reet = peet;
     }


     // rootz **************************************************

     inline double getROOTZ( void ) { return rootz; }

     inline void setROOTZ( const double& prootz )
     {
       rootz = prootz;
     }


     // rootza *************************************************

     inline double getROOTZA( const int& pcmnt )
     {
       return rootza[pcmnt];
     }

     inline void setROOTZA( const double& prootza,
                            const int& pcmnt )
     {
       rootza[pcmnt] = prootza;
     }


     // rootzb *************************************************

     inline double getROOTZB( const int& pcmnt )
     {
       return rootzb[pcmnt];
     }

     inline void setROOTZB( const double& prootzb,
                            const int& pcmnt )
     {
       rootzb[pcmnt] = prootzb;
     }


     // rootzc *************************************************

     inline double getROOTZC( const int& pcmnt )
     {
       return rootzc[pcmnt];
     }

     inline void setROOTZC( const double& prootzc,
                            const int& pcmnt )
     {
       rootzc[pcmnt] = prootzc;
     }


     // rperc **************************************************

     inline double getRPERC( void ) { return rperc; }


     // rrun ***************************************************

     inline double getRRUN( void ) { return rrun; }

     inline void setRRUN( const double& prrun )
     {
       rrun = prrun;
     }
     
     // snowinf ************************************************

     inline double getSNOWINF( void ) { return snowinf; }

     inline void setSNOWINF( const double& psnwinf )
     {
       snowinf = psnwinf;
     }


     // snowpack ***********************************************

     inline double getSNOWPACK( void ) { return snowpack; }

     inline void setSNOWPACK( const double& psnwpck )
     {
       snowpack = psnwpck;
     }

     // SOLC
     inline double getSOLC( void ) { return solc; }

     inline void setSOLC( const double& psolc )
     {
       solc = psolc;
     }

/*     inline double getFBC( void ) { return fbc; }

     inline void setFBC( const double& pfbc )
     {
       fbc = pfbc;
     }

     inline double getAMC( void ) { return amc; }

     inline void setAMC( const double& pamc )
     {
       amc = pamc;
     }

     inline double getMNC( void ) { return mnc; }

     inline void setMNC( const double& pmnc )
     {
       mnc = pmnc;
     } */


     // SOLN
     inline double getSOLN( void ) { return soln; }

     inline void setSOLN( const double& psoln )
     {
       soln = psoln;
     }

/*     inline double getFBN( void ) { return fbn; }

     inline void setFBN( const double& pfbn )
     {
       fbn = pfbn;
     }

     inline double getAMN( void ) { return amn; }

     inline void setAMN( const double& pamn )
     {
       amn = pamn;
     }

     inline double getMNN( void ) { return mnn; }

     inline void setMNN( const double& pmnn )
     {
       mnn = pmnn;
     } */


     // sperc **************************************************

     inline double getSPERC( void ) { return sperc; }

     // Nonsymbiotic N fix ***************************************************

     
     inline double getSONINP( void ) { return soninp; }

     inline void setSONINP( const double& psoninp )
     {
       soninp = psoninp;
     }

/*     inline double getSONINPFB( void ) { return soninpfb; }

     inline void setSONINPFB( const double& psoninpfb )
     {
       soninpfb = psoninpfb;
     }

     inline double getSONINPAM( void ) { return soninpam; }

     inline void setSONINPAM( const double& psoninpam )
     {
       soninpam = psoninpam;
     }
*/

     // srun ***************************************************

     inline double getSRUN( void ) { return srun; }

     inline void setSRUN( const double& psrun )
     {
       srun = psrun;
     }


     // surfrun ************************************************

     inline double getSURFRUN( void ) { return surfrun; }

     inline void setSURFRUN( const double& psurfrun )
     {
       surfrun = psurfrun;
     }
     
     // swp ****************************************************
     
     inline double getSWP( void ) { return swp; }
     
     // totpor *************************************************

     inline double getTOTPOR( void ) { return totpor; }

     inline void setTOTPOR( const double& ptotpor )
     {
       totpor = ptotpor;
     }


     // vsm *************************************************

     inline double getVSM( void ) { return vsm; }

     inline void setVSM( const double& pvsm )
     {
       vsm = pvsm;
     }

     // wiltpt *************************************************

     inline double getWILTPT( void ) { return wiltpt; }

     inline void setWILTPT( const double& pwiltpt )
     {
       wiltpt = pwiltpt;
     }


     // wiltpta ************************************************

     inline double getWILTPTA( void ) { return wiltpta; }

     inline void setWILTPTA( const double& pwiltpta )
     {
       wiltpta = pwiltpta;
     }


     // wiltptb ************************************************

     inline double getWILTPTB( void ) { return wiltptb; }

     inline void setWILTPTB( const double& pwiltptb )
     {
       wiltptb = pwiltptb;
     }


     // wsoil **************************************************

     inline int getWSOIL( void ) { return wsoil; }

     inline void setWSOIL( const int& pwsoil )
     {
       wsoil = pwsoil;
     }

/* *************************************************************
		 Public Variables
************************************************************* */

     // Annual sum of avlh2o
     double yravlh2o;

     // Annual sum of availn
     double yravln;

     // Ratio of soil reactive organic carbon to
     //   soil reactive organic nitrogen
     double yrc2nfb;
     double yrc2nam;
     double yrc2nmn;

     // Annual estimated actual evapotranspiration (mm / year)
     double yreet;

     // Annual sum of h2oyld (mm / year)
     double yrh2oyld;

     // Annual initial estimated actual evapotranspiration
     //   (mm / year)
     double yrineet;

     // Annual sum of ninput
     double yrnin;     // (g N / (sq. meter * year))
     double yrninfb;     // (g N / (sq. meter * year))
     double yrninam;     // (g N / (sq. meter * year))
     double yrninmn;     // (g N / (sq. meter * year))

     // Annual sum of nlost
     double yrnlost;   // (g N / (sq. meter * year))
     double yrnlostfb;   // (g N / (sq. meter * year))
     double yrnlostam;   // (g N / (sq. meter * year))
     double yrnlostmn;   // (g N / (sq. meter * year))

     double yrlchdin;   // (g N / (sq. meter * year))

     // Annual sum of org.carbon
     double yrorgc;
     double yrorgcfb;
     double yrorgcam;
     double yrorgcmn;

     // Annual sum of org.nitrogen
     double yrorgn;
     double yrorgnfb;
     double yrorgnam;
     double yrorgnmn;

     // Annual sum of pctp
     double yrpctp;

     // Annual sum of rgrdnh2o
     double yrrgrndh2o;

     // Annual sum of rperc
     double yrrperc;   // (mm / year)

     // Annual sum of rrun
     double yrrrun;  // (mm / year)

     // Annual sum of sgrndh2o
     double yrsgrndh2o;

     // Annual sum of moist
     double yrsmoist;

     // Annual sum of snowinf
     double yrsnowinf;      // (mm / year)

     // Annual sum of snowpack
     double yrsnowpack;

     // Annual sum of sperc
     double yrsperc; // (mm / year)

     // Annual sum of srun
     double yrsrun;  // (mm / year)

     // Annual sum of vsm
     double yrvsm;


   private:

/* *************************************************************
		 Private Functions
************************************************************* */

     void percol( const double& rain );

     double rrunoff( const double& rgrndh2o );

     double srunoff( const double& elev,
                     const double& tair,
                     const double& prevtair,
                     const double& prev2tair,
		             const double& sgrndh2o );


/* **************************************************************
		 Private Variables
************************************************************** */

     // Available inorganic nitrogen (g N / sq. meter)
     double availn;

     // Available water (mm)
     double avlh2o;

     // Available water capacity (mm)
     double awcapmm;

     //coefficient to calculate rooting depth MJ MLS;
     double coefa;
     double coefb;

     // Dissolved Organic Nitrogen leaching
     double lchdon;
     double lchdonfb;
     double lchdonam;
     double lchdonmn;

     // Dissolved Inorganic Nitrogen leaching
     double lchdin;
     double lchdinfb;
     double lchdinam;
     double lchdinmn;
     
     // Monthly drainage (mm / month)
     double drainage;

     // Monthly estimated actual Evapotranspiration (mm / month)
     double eet;
     
     // Volume of water at field capacity (mm)
     double fldcap;

     // root fractions
     double frrootc_fb[MAXCMNT];       //MJ MLS
     double frrootc_am[MAXCMNT];       //MJ MLS
     double frrootc_mn[MAXCMNT];       //MJ MLS

     // Soil dryness function, similar in shape to soil water potential
     double gm;

      // Water yield (mm / month)
     double h2oyld;

     // Initial Estimated Actual Evapotranspiration (mm / month)
     double ineet;

     // Relative hydraulic conductivity through soil profile
     double kh2o;

    // DOC leaching flux
     double lchdoc;
     double lchdocfb;
     double lchdocam;
     double lchdocmn;

     // Mean annual volumetric soil moisture (%)
     double meanvsm;

     // Soil moisture (mm)
     double moist;

     double ndays[CYCLE];

     // Total nitrogen input to soils
     double ninput;    // (g N / (sq. meter * month))

     // Total nitrogen lost from soils
     double nlost;     // (g N / (sq. meter * month))
     double nlostfb, nlostam, nlostmn;

      // Reactive soil organic matter
     Biomass org;      //  (g C or g N / sq. meter)

     // Soil moisture as %field capacity
     double pcfc;

     // Percent clay in soil texture
     double pctclay;

     // Soil moisture as %total pore space
     double pctp;

     // Percent sand in soil texture
     double pctsand;

     // Percent silt in soil texture
     double pctsilt;

     // Previous month's snow pack
     double prevspack;

     // Proportion silt and clay in soil texture
     double psiplusc;

     // Rain runoff storage (mm / month)
     double rgrndh2o;

     // Rain percolation (excess)
     double rperc;   // (mm / month)

     // Rain Runoff (mm / month)
     double rrun;

     // Snowmelt runoff storage (mm)
     double sgrndh2o;

     // Snow melt infiltration (mm / month)
     double snowinf;

     // Snowpack (mm)
     double snowpack;

     // Snow melt percolation (excess)
     double sperc;   // (mm / month)

     // soilc and soiln
     double solc;
     double fbc;
     double amc;
     double mnc;

     double soln;
     double fbn;
     double amn;
     double mnn;

//     double avln;

     // Nonsymbiotic N fix
     double soninp;
//     double soninpfb;
//     double soninpam;

     // Snow runoff
     double srun;    // (mm / month)

     // Surface runoff (mm / month)
     double surfrun;
     
     // Soil water potential (MPa)
     double swp; 

     // Soil texture (categorical data)
     int text;

     // volume of total pore space (mm)
     double totpor;

     // Volumetric soil moisture (as %rooting depth)
     double vsm;

     // Volume of water at wilting point (mm)
     double wiltpt;

     // wetland soil type designation (categorical data)
     int wsoil;


/* *************************************************************
		 Private Parameters
************************************************************* */

     // Field capacity (%soil volume)

     double fldcapa;
     double fldcapb;
     double pcfldcap;


     // Proportion of available nitrogen lost from soil
     //   (g N / (square meter))

     double nlossfb[MAXCMNT];
     double nlossfbam[MAXCMNT];
     double nlossfbmn[MAXCMNT];
 
     double denitr[MAXCMNT];
//
//   c_den are in units gC/m2
//
     double c_denfb[MAXCMNT];
     double c_denam[MAXCMNT];


     // Porosity of soil (%soil volume)

     double pctpor;
     double pctpora;
     double pctporb;


     // Effective rooting depth (m)

     double minrootz[MAXCMNT];
     double z0[MAXCMNT];
     double rootz;
     double rootza[MAXCMNT];
     double rootzb[MAXCMNT];
     double rootzc[MAXCMNT];
     double effwiltpt;

     double reet;

     // Wilting point (%soil volume)

     double pcwiltpt;
     double wiltpta;
     double wiltptb;
     
     // Soil Surface resistance (s m^-1)
     
     double rssmin;
     double rssslope;

};

#endif

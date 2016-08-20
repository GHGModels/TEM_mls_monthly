/* **************************************************************
*****************************************************************
TMCRB45_lulc.H - object describing characteristics of soil microbes
	        used in the Terrestrial Ecosystem Model (TEM)

Modifications:

20060126 - DWK created by modifying tmcrb50b5.h
20060126 - DWK changed include from tprocessXML51.h
           to tprocessXML437.h
20060126 - DWK changed class Tmicrobe50 to class Tmicrobeflux
20060126 - DWK changed inheritance from ProcessXML50 to
           ProcessXML43
20060126 - DWK changed include from temconsts51.hpp to
           temconsts43.hpp
20060126 - DWK deleted const double& tsoil and
           const int& tsoilflg from function call to setDQ10()
20070105 - TWC changed name to tmcrb45
2007 - TWC/BSF
   New function setDQ10LaRS (remove setNEWDQ10)
   Public Functions and Private Parameters: remove alpha, beta,
        gamma, qref, tref
   Private Parameters: add rhalpha, rhbeta, rhgamma, rhqref,
        rhtref

*****************************************************************
************************************************************** */


#ifndef TMCRB45_LULC_H
#define TMCRB45_LULC_H

// Tmcrb45 uses the global constants NUMMSAC and MAXCMNT
#include "temconsts45.hpp"

#include "tprocessXML45.h"
#include "bioms45.hpp"

class Tmcrb45: public ProcessXML45
{

   public:

     Tmcrb45();

/* **************************************************************
		 Public Functions
************************************************************** */

     void kdxclm(                    );

     void getvegecd( const string& ecd );

     void resetEcds( const int& pcmnt, const double& psiplusc );

     void resetMonthlyFluxes( void );

     void resetYrFluxes( void );

     void setDQ10LaRS( const int& pdcmnt,
                       const double& ptair );
                       
     void setDQ10LT( const int& pdcmnt,
                     const double& ptair,
                     const double& ptopt );

     double setRHMOIST( const int& pdcmnt,
                        const double& pctfldcap,
                        const double& pctwiltpt,
                        const double& pctpor,
                        const double& vsm,
                        const int& moistlim );

     void setTEMPfb(const int&pdcmnt, const double& tair);

     void showecd( const int& pdcmnt );

     void updateDynamics( const int& pcmnt,
                          const double& pctfldcap,
                          const double& pctwiltpt,
                          const double& pctpor,
                          const double& solc,
                          const double& fbc,
                          const double& amc,
                          const double& mnc,
                          const double& soln,
                          const double& fbn,
                          const double& amn,
                          const double& mnn,
                          const double& soilh2o,
                          const double& vsm,
                          const double& availnfb,
                          const double& availnam,
                          const double& availnmn,
                          const int& moistlim,
                          const int& tillflag,
                          const double& tillfactor,
                          const double& ksoil,
                          const double& rltrc,
                          const int& nopen );

     double yrkd( const int& nfeed,
                  const double& yrltrc,
                  const double& yrltrn,
                  const double& kd,
                  const int& pdcmnt );


     // "Get" and "Set" private variables and parameters

     // cnsoil *************************************************

     inline double getCNSOILFB( const int& pcmnt )
     {
       return cnsoilfb[pcmnt];
     }

     inline void setCNSOILFB( const double& pcnsoilfb,
                            const int& pcmnt )
     {
       cnsoilfb[pcmnt] = pcnsoilfb;
     }

     inline double getCNSOILAM( const int& pcmnt )
     {
       return cnsoilam[pcmnt];
     }

     inline void setCNSOILAM( const double& pcnsoilam,
                            const int& pcmnt )
     {
       cnsoilam[pcmnt] = pcnsoilam;
     }

      inline double getCNSOILMN( const int& pcmnt )
     {
       return cnsoilmn[pcmnt];
     }

     inline void setCNSOILMN( const double& pcnsoilmn,
                            const int& pcmnt )
     {
       cnsoilmn[pcmnt] = pcnsoilmn;
     }


     // decay **************************************************

     inline double getDECAY( void ) { return decay; }

    //  docfr
     inline double getDOCFR( const int& pcmnt ) { return docfr[pcmnt]; }


     // docdon **************************************************

     inline double getDOCDON( const int& pcmnt ) { return docdon[pcmnt]; }

     // gmin **************************************************
     
          inline double getGMIN( void ) { return gmin; }
          inline double getGMINFB( void ) { return gminfb; }
          inline double getGMINAM( void ) { return gminam; }
          inline double getGMINMN( void ) { return gminmn; } 

     // kd *****************************************************     //what to do with KD? MJ MLS;
     
     inline double getKD( void ) { return kd; }

     inline void setKD( const double& pkd ) { kd = pkd; }

      // decomp **********************************************

     inline double getDECOMPFB( void ) { return decompfb; };
     inline double getDECOMPAM( void ) { return decompam; };
     inline double getDECOMPMN( void ) { return decompmn; };

      // docprod **********************************************

     inline double getDOCPROD( void ) { return docprod; };
     inline double getDOCPRODFB( void ) { return docprodfb; };
     inline double getDOCPRODAM( void ) { return docprodam; };
     inline double getDOCPRODMN( void ) { return docprodmn; };


      // donprod **********************************************

     inline double getDONPROD( void ) { return donprod; };
     inline double getDONPRODFB( void ) { return donprodfb; };
     inline double getDONPRODAM( void ) { return donprodam; };
     inline double getDONPRODMN( void ) { return donprodmn; };


     // kdb ****************************************************

     inline double getKDB( const int& pcmnt )
     {
       return kdb[pcmnt];
     }

     inline void setKDB( const double& pkdb,
                         const int& pcmnt )
     {
       kdb[pcmnt] = pkdb;
     }

      // kdfb ****************************************************
      
     inline double getKDFB( void ) { return kdfb; }

     // kdam ****************************************************

     inline double getKDAM( void ) { return kdam; }

     //kdmn ****************************************************

     inline double getKDMN( void ) { return kdmn; }

     // kdc ****************************************************

     inline double getKDC( void ) { return kdc; }

     inline void setKDC( const double& pkdc ) { kdc = pkdc; }


     // kn2 ****************************************************

     inline double getKN2( const int& pcmnt )
     {
       return kn2[pcmnt];
     }

     inline void setKN2( const double& pkn2,
                         const int& pcmnt )
     {
       kn2[pcmnt] = pkn2;
     }


     // lcclnc *************************************************

     inline double getLCCLNC( const int& pcmnt )
     {
       return lcclnc[pcmnt];
     }

     inline void setLCCLNC( const double& plcclnc,
                            const int& pcmnt )
     {
       lcclnc[pcmnt] = plcclnc;
     }


     // moistmax ***********************************************

     inline double getMOISTMAX( const int& pcmnt )
     {
       return moistmax[pcmnt];
     }

     inline void setMOISTMAX( const double& pmoistmax,
                              const int& pcmnt )
     {
       moistmax[pcmnt] = pmoistmax;
     }


     // moistmin ***********************************************

     inline double getMOISTMIN( const int& pcmnt )
     {
       return moistmin[pcmnt];
     }

     inline void setMOISTMIN( const double& pmoistmin,
                              const int& pcmnt )
     {
       moistmin[pcmnt] = pmoistmin;
     }


     // moistopt ***********************************************

     inline double getMOISTOPT( const int& pcmnt )
     {
       return moistopt[pcmnt];
     }

     inline void setMOISTOPT( const double& pmoistopt,
                              const int& pcmnt )
     {
       moistopt[pcmnt] = pmoistopt;
     }


     // netnmin ************************************************

     inline double getNETNMIN( void ) { return netnmin; }

     inline void setNETNMIN( const double& pnetnmin )
     {
       netnmin = pnetnmin;
     }

     inline double getNETNMINFB( void ) { return netnminfb; }

     inline void setNETNMINFB( const double& pnetnminfb )
     {
       netnminfb = pnetnminfb;
     }

     inline double getNETNMINAM( void ) { return netnminam; }

     inline void setNETNMINAM( const double& pnetnminam )
     {
       netnminam = pnetnminam;
     }

     inline double getNETNMINMN( void ) { return netnminmn; }

     inline void setNETNMINMN( const double& pnetnminmn )
     {
       netnminmn = pnetnminmn;
     }


     // nupfb ***************************************************

     inline double getNUPFB( const int& pcmnt )
     {
       return nupfb[pcmnt];
     }

     inline void setNUPFB( const double& pnupfb,
                          const int& pcmnt )
     {
       nupfb[pcmnt] = pnupfb;
     }

     inline double getNUPFBAM( const int& pcmnt )
     {
       return nupfbam[pcmnt];
     }

     inline void setNUPFBAM( const double& pnupfbam,
                          const int& pcmnt )
     {
       nupfbam[pcmnt] = pnupfbam;
     }

     inline double getNUPFBMN( const int& pcmnt )
     {
       return nupfbmn[pcmnt];
     }

     inline void setNUPFBMN( const double& pnupfbmn,
                          const int& pcmnt )
     {
       nupfbmn[pcmnt] = pnupfbmn;
     }


     // nuptake ************************************************

     inline double getNUPTAKE( void ) { return nuptake; }

     inline void setNUPTAKE( const double& pnuptake )
     {
       nuptake = pnuptake;
     }

     inline double getNUPTAKEFB( void ) { return nuptakefb; }

     inline double getNUPTAKEAM( void ) { return nuptakeam; }

     inline double getNUPTAKEMN( void ) { return nuptakemn; }

     // propftos ***********************************************

     inline double getPROPFTOS( const int& pcmnt )
     {
       return propftos[pcmnt];
     }

     inline void setPROPFTOS( const double& ppropftos,
                              const int& pcmnt )
     {
       propftos[pcmnt] = ppropftos;
     }


     // rh *****************************************************

     inline double getRH( void ) { return rh; }

     inline void setRH( const double& prh )
     {
       rh = prh;
     }

     inline double getRHFB( void ) { return rhfb; }
     inline double getRHAM( void ) { return rham; }
     inline double getRHMN( void ) { return rhmn; }


     // rrh **********************************************

     inline double getRRH( void ) { return rrh; };

     inline void setRRH( const double& prrh)
     {
       rrh = prrh;
     };


     // rhq10 **************************************************

     inline double getRHQ10( const int& pcmnt )
     {
       return rhq10[pcmnt];
     }

     inline void setRHQ10( const double& prhq10,
                           const int& pcmnt )
     {
       rhq10[pcmnt] = prhq10;
     }


/* **************************************************************
		 Public Variables
************************************************************** */


     // Annual sum of netnmin
     double yrnmin;         // (g N / (sq. meter * year))

     // Annual sum of nuptake
     double yrnuptake;      // (g N / (sq. meter * year))

     // Annual sum of rh
     double yrrh;       // (g C / (sq. meter * year))

     // Running mean of rh
     double rrh;       // (g C / (sq. meter * year))

     // docproc
     double docproc;


   private:

/* **************************************************************
		 Private Functions
************************************************************** */

     double nminxclm( const int& pdcmnt,
                      const double& soilh2o,
                      const double& soilorgc,
                      const double& soilorgn,
                      const double& availn,
                      const double& ksoil,       
                      const double& rh,
                      const int& nopen,
                      const double& cnsoil,
                      const double& nup );

     double rhxclm( const double& solorgc,
                    const double& kd,
                    const double& pdq10,
                    const double& moist,
                    const double& rltrc,
                    const int& pcmnt );


/* **************************************************************
		 Private Variables
************************************************************** */

     // Effect of temperature on decomposition
     double dq10;

     // Net nitrogen mineralization
     double netnmin; // (g N / (sq. meter * month))
     double netnminfb; // (g N / (sq. meter * month))
     double netnminam; // (g N / (sq. meter * month))
     double netnminmn; // (g N / (sq. meter * month))

     // Total nitrogen uptake or "immobilzation" by microbes
     double nuptake;  // (g N / (sq. meter * month))
     double nuptakefb;  // (g N / (sq. meter * month))
     double nuptakeam;  // (g N / (sq. meter * month))
     double nuptakemn;  // (g N / (sq. meter * month))


     // Heterotrophic respiration
     double rh;  // (g C / (sq. meter * month))
     double rhfb;  // (g C / (sq. meter * month))
     double rham;  // (g C / (sq. meter * month))
     double rhmn;  // (g C / (sq. meter * month))
     double docprod;
     double docprodfb;
     double docprodam;
     double docprodmn;
     double donprod;
     double donprodfb;
     double donprodam;
     double donprodmn;
     double decompfb;
     double decompam;
     double decompmn;

/* *************************************************************
		 Private Parameters
************************************************************* */

//     double cnsoil[MAXCMNT];
     double cnsoilfb[MAXCMNT];
     double cnsoilam[MAXCMNT];
     double cnsoilmn[MAXCMNT];

     // Parameter representing the quality of soil organic matter

     double decay;

     // Gross Mineralization
     double gmin;
     double gminfb;
     double gminam;
     double gminmn;

     // Biome-specific decomposition parameters for function rhxclm

     double kd;
     double kdb[MAXCMNT];
//     double kdfb[MAXCMNT];
//     double kdam[MAXCMNT];
//     double kdmn[MAXCMNT];

     double kdc;

     double kdin[NUMMSAC];     // kd values read in from file
     double kdsave[NUMMSAC];   // kd values saved to a file

     // Biome-specific half saturation parameter for function
     //   nminxclm describing the effect of available nitrogen
     //   on microbial nitrogen uptake

     double kn2[MAXCMNT];


     double lcclnc[MAXCMNT];

     // Biome-specific parameters describing the influence of
     //   soil moisture on decomposition (i.e., moist)

     double moistmin[MAXCMNT];
     double moistopt[MAXCMNT];
     double moistmax[MAXCMNT];

    // N fixation parameter


     double nupfb[MAXCMNT];
     double nupfbam[MAXCMNT];
     double nupfbmn[MAXCMNT];

     double propftos[MAXCMNT];

     double rhq10[MAXCMNT];

  double rhalpha[MAXCMNT];
  double rhbeta[MAXCMNT];
  double rhgamma[MAXCMNT];
  double rhqref[MAXCMNT];
  double rhtref[MAXCMNT];

  double docfr[MAXCMNT];
  double docdon[MAXCMNT];
};

#endif


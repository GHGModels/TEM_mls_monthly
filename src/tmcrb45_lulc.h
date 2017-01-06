/* **************************************************************
*****************************************************************
TMCRB45_lulc.H - object describing characteristics of soil microbes
	        used in the Terrestrial Ecosystem Model (TEM)

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

     void setTEMP(const int&pdcmnt, const double& tair);

     void showecd( const int& pdcmnt );

     void updateDynamics( const int& pcmnt,
                          const double& pctfldcap,
                          const double& pctwiltpt,
                          const double& pctpor,
                          const double& active_c,
                          const double& slow_c,
                          const double& passive_c,
                          const double& active_n,
                          const double& slow_n,
                          const double& passive_n,
                          const double& soilh2o,
                          const double& vsm,
                          const double& availn,
                          const double& availn_active,
                          const double& availn_slow,
                          const double& availn_passive,
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

     inline double getCNSOIL_ACTIVE( const int& pcmnt )
     {
       return cnsoil_active[pcmnt];
     }

     inline void setCNSOIL_ACTIVE( const double& pcnsoil_active,
                            const int& pcmnt )
     {
       cnsoil_active[pcmnt] = pcnsoil_active;
     }

     inline double getCNSOIL_SLOW( const int& pcmnt )
     {
       return cnsoil_slow[pcmnt];
     }

     inline void setCNSOIL_SLOW( const double& pcnsoil_slow,
                            const int& pcmnt )
     {
       cnsoil_slow[pcmnt] = pcnsoil_slow;
     }

      inline double getCNSOIL_PASSIVE( const int& pcmnt )
     {
       return cnsoil_passive[pcmnt];
     }

     inline void setCNSOIL_PASSIVE( const double& pcnsoil_passive,
                            const int& pcmnt )
     {
       cnsoil_passive[pcmnt] = pcnsoil_passive;
     }


     // decay **************************************************

     inline double getDECAY( void ) { return decay; }

    //  docfr
     inline double getDOCFR( const int& pcmnt ) { return docfr[pcmnt]; }


     // docdon **************************************************

     inline double getDOCDON( const int& pcmnt ) { return docdon[pcmnt]; }

     // gmin **************************************************
     
          inline double getGMIN( void ) { return gmin; }
          inline double getGMIN_ACTIVE( void ) { return gmin_active; }
          inline double getGMIN_SLOW( void ) { return gmin_slow; }
          inline double getGMIN_PASSIVE( void ) { return gmin_passive; } 

     // kd *****************************************************     
     
     inline double getKD( void ) { return kd; }

     inline void setKD( const double& pkd ) { kd = pkd; }

      // decomp **********************************************

     inline double getDECOMP_ACTIVE( void ) { return decomp_active; };
     inline double getDECOMP_SLOW( void ) { return decomp_slow; };
     inline double getDECOMP_PASSIVE( void ) { return decomp_passive; };

      // docprod **********************************************

     inline double getDOCPROD( void ) { return docprod; };
     inline double getDOCPROD_ACTIVE( void ) { return docprod_active; };
     inline double getDOCPROD_SLOW( void ) { return docprod_slow; };
     inline double getDOCPROD_PASSIVE( void ) { return docprod_passive; };


      // donprod **********************************************

     inline double getDONPROD( void ) { return donprod; };
     inline double getDONPROD_ACTIVE( void ) { return donprod_active; };
     inline double getDONPROD_SLOW( void ) { return donprod_slow; };
     inline double getDONPROD_PASSIVE( void ) { return donprod_passive; };


     // kdb ****************************************************
     
     // all kd are not done correctly at the moment, check back when updating calibration

     inline double getKDB( const int& pcmnt )
     {
       return kdb[pcmnt];
     }

     inline void setKDB( const double& pkdb,
                         const int& pcmnt )
     {
       kdb[pcmnt] = pkdb;
     }

      // kd_active ****************************************************
      
      inline double getKD_ACTIVE( const int& pcmnt )
      {
        return kd_active[pcmnt];
      }
     
     inline void setKD_ACTIVE( const double& pkd_active,
                         const int& pcmnt )
     {
       kd_active[pcmnt] = pkd_active;
     }
     
     // kd_slow ****************************************************

     inline double getKD_SLOW( const int& pcmnt )
     {
       return kd_slow[pcmnt];
     }
     
     inline void setKD_SLOW( const double& pkd_slow,
                               const int& pcmnt )
     {
       kd_slow[pcmnt] = pkd_slow;
     }

     //kd_passive ****************************************************

     inline double getKD_PASSIVE( const int& pcmnt )
     {
       return kd_passive[pcmnt];
     }
     
     inline void setKD_PASSIVE( const double& pkd_passive,
                             const int& pcmnt )
     {
       kd_passive[pcmnt] = pkd_passive;
     }

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

     inline double getNETNMIN_ACTIVE( void ) { return netnmin_active; }

     inline void setNETNMIN_ACTIVE( const double& pnetnmin_active )
     {
       netnmin_active = pnetnmin_active;
     }

     inline double getNETNMIN_SLOW( void ) { return netnmin_slow; }

     inline void setNETNMIN_SLOW( const double& pnetnmin_slow )
     {
       netnmin_slow = pnetnmin_slow;
     }

     inline double getNETNMIN_PASSIVE( void ) { return netnmin_passive; }

     inline void setNETNMIN_PASSIVE( const double& pnetnmin_passive )
     {
       netnmin_passive = pnetnmin_passive;
     }


     // nup ***************************************************

     inline double getNUP( const int& pcmnt )
     {
       return nup[pcmnt];
     }

     inline void setNUP( const double& pnup,
                          const int& pcmnt )
     {
       nup[pcmnt] = pnup;
     }
     

     // active
     inline double getNUP_ACTIVE( const int& pcmnt )
     {
       return nup_active[pcmnt];
     }

     inline void setNUP_ACTIVE( const double& pnup_active,
                          const int& pcmnt )
     {
       nup_active[pcmnt] = pnup_active;
     }

     // slow
     inline double getNUP_SLOW( const int& pcmnt )
     {
       return nup_slow[pcmnt];
     }
     
     inline void setNUP_SLOW( const double& pnup_slow,
                                const int& pcmnt )
     {
       nup_slow[pcmnt] = pnup_slow;
     }
     
     // passive
     inline double getNUP_PASSIVE( const int& pcmnt )
     {
       return nup_passive[pcmnt];
     }
     
     inline void setNUP_PASSIVE( const double& pnup_passive,
                                const int& pcmnt )
     {
       nup_passive[pcmnt] = pnup_passive;
     }

     // nuptake ************************************************

     inline double getNUPTAKE( void ) { return nuptake; }

     inline void setNUPTAKE( const double& pnuptake )
     {
       nuptake = pnuptake;
     }

     inline double getNUPTAKE_ACTIVE( void ) { return nuptake_active; }

     inline double getNUPTAKE_SLOW( void ) { return nuptake_slow; }

     inline double getNUPTAKE_PASSIVE( void ) { return nuptake_passive; }
     
      
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

     inline double getRH_ACTIVE( void ) { return rh_active; }
     inline double getRH_SLOW( void ) { return rh_slow; }
     inline double getRH_PASSIVE( void ) { return rh_passive; }


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
     double yrnmin_active;         // (g N / (sq. meter * year))
     double yrnmin_slow;         // (g N / (sq. meter * year))
     double yrnmin_passive;         // (g N / (sq. meter * year))
     

     // Annual sum of nuptake
     double yrnuptake;      // (g N / (sq. meter * year))
     double yrnuptake_active;      // (g N / (sq. meter * year))
     double yrnuptake_slow;      // (g N / (sq. meter * year))
     double yrnuptake_passive;      // (g N / (sq. meter * year))
     

     // Annual sum of rh
     double yrrh;       // (g C / (sq. meter * year))
     double yrrh_active;       // (g C / (sq. meter * year))
     double yrrh_slow;       // (g C / (sq. meter * year))
     double yrrh_passive;       // (g C / (sq. meter * year))
     

     // Running mean of rh
     double rrh;       // (g C / (sq. meter * year))

     /*
     // docproc
     double docproc;
     double docproc_active;
     double docproc_slow;
     double docproc_passive;
     */

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
     double netnmin;           // (g N / (sq. meter * month))
     double netnmin_active;    // (g N / (sq. meter * month))
     double netnmin_slow;      // (g N / (sq. meter * month))
     double netnmin_passive;   // (g N / (sq. meter * month))

     // Total nitrogen uptake or "immobilzation" by microbes
     double nuptake;    // (g N / (sq. meter * month))
     double nuptake_active;  // (g N / (sq. meter * month))
     double nuptake_slow;  // (g N / (sq. meter * month))
     double nuptake_passive;  // (g N / (sq. meter * month))
     

     // Heterotrophic respiration
     double rh;            // (g C / (sq. meter * month))
     double rh_active;     // (g C / (sq. meter * month))
     double rh_slow;       // (g C / (sq. meter * month))
     double rh_passive;    // (g C / (sq. meter * month))
     double docprod;
     double docprod_active;
     double docprod_slow;
     double docprod_passive;
     double donprod;
     double donprod_active;
     double donprod_slow;
     double donprod_passive;
     double decomp_active;
     double decomp_slow;
     double decomp_passive;

/* *************************************************************
		 Private Parameters
************************************************************* */

//     double cnsoil[MAXCMNT];
     double cnsoil_active[MAXCMNT];
     double cnsoil_slow[MAXCMNT];
     double cnsoil_passive[MAXCMNT];

     // Parameter representing the quality of soil organic matter

     double decay;

     // Gross Mineralization
     double gmin;
     double gmin_active;
     double gmin_slow;
     double gmin_passive;

     // Biome-specific decomposition parameters for function rhxclm

     double kd;
     double kdb[MAXCMNT];
     double kd_active[MAXCMNT];
     double kd_slow[MAXCMNT];
     double kd_passive[MAXCMNT];

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


     double nup[MAXCMNT];
     double nup_active[MAXCMNT];
     double nup_slow[MAXCMNT];
     double nup_passive[MAXCMNT];
     
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


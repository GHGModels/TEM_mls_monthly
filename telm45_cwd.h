/* **************************************************************
*****************************************************************
TELM45_cwd.H - Determines the interface among CLM, LCLUC and TEM
             modules


*****************************************************************
************************************************************** */

#ifndef TELM45_CWD_H
#define TELM45_CWD_H

const int TQCZEROFLAG = 31;

//Modules representing climate and TEM

#include "tatmdep.h"  // Tatmdep class
#include "tclm45_ndep.h"   // Telm45 uses the Tclm45 class

// Telm45 uses the Elmntcohort45
#include "telmntcohort45a.hpp"

#include "tlcluc45a.h" // Telm45 uses the Tlcluc45 class
#include "ttem45_cwd.h"   // Telm45 uses the Ttem45 class

// Modules describing the interface with spatially explicit
//   data sets

#include "tclmdat45.h"  //Telm45 uses the Clmdat45 class
#include "tsoldat45.h"  //Telm45 uses the Soildat45 class
#include "telvdat45.h"  //Telm45 uses the Elevdat45 class
#include "ttemdat45a.h"  //Telm45 uses the Temdat45 class

class Telm45
{

  public:

     Telm45();


/* *************************************************************
		 Public Function Declarations
************************************************************* */

     void atmswritemiss( ofstream fout[NUMATMS],
                         const vector<string>& predname,
                         const int& pdyr,
                         const int& atmspred,
                         const double value );

     void atmswritepred( ofstream fout[NUMATMS],
                         const int& pdyr,
                         const vector<string>& predname,
                         const int& atmspred );

     int coregerr( ofstream& rflog1,
                   const string& varname1,
                   const float& col1,
		           const float& row1,
                   const string& varname2,
                   const float& col2,
		           const float& row2 );

     int equilibrateTEM( const double& ptol,
                        const int& pichrt,
                        ofstream fout[NUMTEM],
                        const vector<string>& predname,
                        const int& spinoutfg,
                        int & year
                       );

     void getTEMCohortState( const int& pichrt );

     void initializeCohortTEMState( const int& pichrt );

     void outputTEMmonth( const int& pdm );

     void readCohortState( ifstream& ifstate,
                           const int& pichrt );

     void saveTEMCohortState( const int& pichrt );

     void setCohortTEMState( const ElmntCohort45& firstchrt,
                             ElmntCohort45& targetchrt );

     int setGIStopography( ofstream& flog1,
                           int& ftlerr,
                           FILE* fstxt,
                           FILE*felev );

     void setTEMequilState( ofstream& rflog1,
                            const int& equil,
                            const int& totsptime,
                            const int& pichrt,
                            ofstream fout[NUMTEM],
                            const vector<string>& predname,
                            const int& spinoutfg
      );

     void setTEMmiss( const int& pdyr,
                      const int& equil,
                      const int& totsptime,
                      const int& pichrt );

     void temwritepred( ofstream fout[NUMTEM],
                        const vector<string>& predname,
                        const int& pdyr,
                        const int& pichrt,
                        const int& ntempred,
                        const int& spinoutfg,
                        const int& equilflg );

     void updateTEMmonth( const int& equil,
                          const int& totsptime,
                          const int& outyr,
                          const int& pdm,
                          const int& pichrt );

     void writeCohortState( ofstream& ofstate,
                            const int& pichrt );

/* *************************************************************
		 Public Variables
************************************************************* */

     int atmstotyr[MAXRTIME];

     // Mean annual air temperature
     double avetair[MAXRTIME];

     long carea;

     double climate[NUMATMS][CYCLE][MAXRTIME];
     double adep[1][MAXRTIME];

     Tclm45 clm;

     ElmntCohort45 cohort[MAXCHRTS];

     float col;

     string contnent;
     
     int de_nyears;
     int de_startyear;

     int fatalerr;

     double lat;

     Tlcluc45 lcluc;

     Tatmdep atmdep;

     double lon;

     int lonlatflag;

     // Maximum number of cohorts in an element
     //   during the current year
     int maxcohorts;

     // Maximum monthly air temperature during the year
     double mxtair[MAXRTIME];

     // Maximum number of "natural" cohorts in an element
     int natcohorts;

     // Number of climate predicted variables
     int natmspred;

     // Number of TEM predicted variables
     int ntempred;

//     vector<string> predstr;

     double output[NUMTEM][CYCLE];

     int outyr;

     // Maximum number of cohorts in an element
     //   during the previous year
     int prvmxcohrts;

     string region;

     float row;

     long subarea;

     Ttem45 tem;

     int totpred;

     int ttotyr[MAXRTIME];

     int wrtyr;

     // Annual precipitation during the year
     double yrprec[MAXRTIME];

     int year;

     double vegceq[MAXRTIME];
     double soilceq[MAXRTIME];
     double vegneq[MAXRTIME];
     double soilneq[MAXRTIME];


/* *************************************************************
		 Private Function Declarations
************************************************************* */

  private:

     int temgisqc( const long& subarea,
		           const double& pctsand,
                   const double& pctsilt,
                   const double& pctclay,
                   const int& cmnt,
                   const double& elev,
                   const double& nirr,
                   const double& par,
		           const double& tair,
                   const double& mxtair,
                   const double& avtair,
                   const double& yrprec,
                   const double& rain,
                   const double& snowfall,
                   const double& co2,
                   const double& aot40,
                   const double& ndep,
				   const double& trange,
				   const double& vpd );

     int transqc( int& maxyears,
                  int& totyr,
                  double plantc[CYCLE] );

};

#endif

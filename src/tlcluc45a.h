/* *************************************************************
****************************************************************
TLCLUC45A.H - determines both potential and "actual" land
               cover, and identifies land uses within a grid
               cell

****************************************************************
************************************************************* */

#ifndef TLCLUC45A_H
#define TLCLUC45A_H

const int MXFRI = 2000;

// Tlcluc45 uses the MaxCohortdat45 class
#include "tmaxcohortdat45.h"

// Tcluc45 uses the Lulcdat45 class
#include "lulcdat45a.h"

// Tlcluc45 inherits the Biome45 class
#include "tbiome45.h"

class Tlcluc45 : public Biome45
{

  public:

     Tlcluc45();

 /* ************************************************************
		 Public Functions
************************************************************* */

     int getCohort( FILE* flulc );

     int getNumberOfCohorts( FILE* fnchrts );

/* *************************************************************
		 Public Variables
************************************************************* */

     int agcmnt;

     MaxCohortdat45 cohorts;

     int currentveg;

     int endyr;

     FILE* ifnumcohrts;

     FILE* iflulc;

     string ilulcend;
     string ilulcfname;

     string imxcohrtend;
     string imxcohrtfname;

     int lastyr;

     Lulcdat45 lulc;

     int maxtype;

     int potveg;

     int startyr;

     // portion of carea in a particular cohort, km^2
     long subarea;

     int tlulcflag;

};

#endif

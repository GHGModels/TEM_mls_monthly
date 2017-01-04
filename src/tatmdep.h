/* *************************************************************
****************************************************************
TATMDEP.H - determines both potential and "actual" land
               cover, and identifies land uses within a grid
               cell

****************************************************************
************************************************************* */

#ifndef TATMDEP_H
#define TATMDEP_H


// Tdisturb uses the MaxCohortdat45 class
#include "atmdepdat.h"


class Tatmdep
{

  public:

     Tatmdep();

 /* ************************************************************
		 Public Functions
************************************************************* */

     int getAtmdep( FILE* fatmdep );

/* *************************************************************
		 Public Variables
************************************************************* */

     FILE* ifatmdep;

     string ndepfname;
     string ndepend;

     Atmdepdat atmdep;

};

#endif

/* **************************************************************
*****************************************************************
TATMDEP.CPP - determines both potential and "actual" land
                 cover, and identifies land uses within a grid
                 cell

*****************************************************************
************************************************************** */

#include<cstdio>

  using std::fscanf;
  using std::FILE;

#include<iostream>

  using std::cout;
  using std::ios;
  using std::endl;

#include<fstream>

  using std::ifstream;
  using std::ofstream;

#include<iomanip>

  using std::setprecision;

#include<string>

  using std::string;


#include "tatmdep.h"

/* *************************************************************
************************************************************* */

Tatmdep::Tatmdep()
{

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

int Tatmdep::getAtmdep( FILE* fatmdep )
{

  int gisend = atmdep.getdel( fatmdep );

  if( -1 == gisend ) { return gisend; }

  return gisend;

};

/* *************************************************************
************************************************************* */

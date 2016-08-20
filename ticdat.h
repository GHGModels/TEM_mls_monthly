/* *************************************************************
TICDAT.H - object to read and write the structure of
                 elevation data from/to files used by the Water
                 Balance Model

Modifications:

20060114 - DWK created by modifying telvdat425.h
20060114 - DWK changed class Elevdata to class Elevdata43
20060114 - DWK deleted telvdat425.cpp from bottom of file
20070105 - TWC changed name to telvdat45

****************************************************************
************************************************************* */

#ifndef ICDAT45_H
#define ICDAT45_H

class Icdat45
{

  public:

     Icdat45( void );

/* *************************************************************
                      Public Functions
************************************************************* */

     // read data structure.

     int getdel( FILE* infile );


/* *************************************************************
                     Public Variables
************************************************************* */

     // column or longitude of grid cell (degrees)
     float ic;


};

#endif


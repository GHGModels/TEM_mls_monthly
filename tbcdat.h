/* *************************************************************
TBCDAT.H - object to read and write the structure of
                 elevation data from/to files used by the Water
                 Balance Model


****************************************************************
************************************************************* */

#ifndef BCDAT45_H
#define BCDAT45_H

class Bcdat45
{

  public:

     Bcdat45( void );

/* *************************************************************
                      Public Functions
************************************************************* */

     // read data structure.

     int getdel( FILE* infile );


/* *************************************************************
                     Public Variables
************************************************************* */

     // column or longitude of grid cell (degrees)
     float bctop,bcbot;


};

#endif


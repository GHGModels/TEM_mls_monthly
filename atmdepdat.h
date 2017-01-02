/* *************************************************************
ATMDEPDAT.H - object to read and write the structure of land
                  use / land cover cohort data from/to files

************************************************************* */

#ifndef ATMDEPDAT_H
#define ATMDEPDAT_H

class Atmdepdat
{

  public:

     Atmdepdat( void );

/* *************************************************************
                      Public Functions
************************************************************* */

// read data structure.
     int getdel( FILE* infile );


/* *************************************************************
                     Public Variables
************************************************************* */

     // column or longitude of grid cell (degrees)
     float col;

     // row or latitude of grid cell (degrees)
     float row;

     // year
     int year;

     // ndep value
     float adepval;


  private:

/* *************************************************************
                      Private Variables
************************************************************* */

     int atmdepend;
     long curpos;
     long lagpos;

};

#endif


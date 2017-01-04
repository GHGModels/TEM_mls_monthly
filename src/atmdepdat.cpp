/* *************************************************************
atmdepdat.CPP - object to read and write the structure of
                   land use/land cover data from/to files


************************************************************* */

#include<cstdio>

  using std::fscanf;
  using std::FILE;

#include<iostream>

  using std::ios;
  using std::endl;

#include<fstream>

  using std::ifstream;
  using std::ofstream;

#include<iomanip>

  using std::setprecision;

#include<string>

  using std::string;


#include "atmdepdat.h"


Atmdepdat::Atmdepdat( void )
{

  atmdepend = 1;
  lagpos = -99;
  curpos = 0;

};

/* **************************************************************
                    Public Functions
************************************************************** */

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

int Atmdepdat::getdel( FILE* infile )
{

  atmdepend = fscanf( infile,
                    "%f,%f,%d,%f",
                    &col,
                    &row,
                    &year,
                    &adepval );


  return atmdepend;

};

/* *************************************************************
************************************************************* */

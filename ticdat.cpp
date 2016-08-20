/* *************************************************************
TICDAT.CPP - object to read and write the structure of
                  elevation data from/to files used by the Water
                  Balance Model

Modifications:

20060114 - DWK created by modifying telvdat425.cpp
20060114 - DWK added include telvdat437.h and standard includes
20060114 - DWK changed Elevdata:: to Elevdata43::
20070105 - TWC changed name to telvdat45

****************************************************************
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


#include "ticdat.h"



Icdat::Icdat( void )
{
  icend = 1;
};



/* *************************************************************
************************************************************* */

int Icdat45::getdel( FILE* infile )
{

  icend = fscanf( infile,
                   "%f",
                   &ic)

  return icend;

};

/* *************************************************************
************************************************************* */


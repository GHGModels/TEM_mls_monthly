/* *************************************************************
TICDAT.CPP - object to read and write the structure of
                  elevation data from/to files used by the Water
                  Balance Model

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


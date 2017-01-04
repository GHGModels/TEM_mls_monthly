/* *************************************************************
TBCDAT.CPP - object to read and write the structure of
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


#include "tbcdat.h"



Bcdat::Bcdat( void )
{
  bcend = 1;
};



/* *************************************************************
************************************************************* */

int Bcdat45::getdel( FILE* infile )
{

  bcend = fscanf( infile,
                   "%f %f",
                   &bctop,
                   &bcbot)

  return bcend;

};

/* *************************************************************
************************************************************* */


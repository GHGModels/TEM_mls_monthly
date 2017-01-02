/* *************************************************************
TMAXCOHORTDAT45.CPP - object to read and write the structure
                          of maximum number of cohort grid cell
                          data from/to files used by the
                          Terrestrial Ecosystem Model


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

#include "tmaxcohortdat45.h"

/* *************************************************************
************************************************************* */

MaxCohortdat45::MaxCohortdat45( void )
{

  chrtend = 1;
  lagpos = -99;
  curpos = 0;

};

/* *************************************************************
************************************************************* */

int MaxCohortdat45::get( ifstream& infile )
{

  lagpos = infile.tellg();

  infile >> col;
  infile >> row;
  infile >> varname;
  infile >> carea;
  infile >> year;
  infile >> total;
  infile >> natchrts;
  infile >> contnent;

  infile.seekg( 0, ios::cur );

  curpos = infile.tellg();

  if( curpos < (lagpos + 10) ) { chrtend = -1; }

  return chrtend;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

int MaxCohortdat45::getdel( FILE* infile )
{
  char tmpvarname[40];
  char tmpcontnent[40];

  chrtend = fscanf( infile,"%f,%f, %s ,%ld,%d,%d,%d, %s",
                   &col,
                   &row,
                   tmpvarname,
                   &carea,
                   &year,
                   &total,
                   &natchrts,
                   tmpcontnent );

  varname = tmpvarname;
  contnent = tmpcontnent;

  return chrtend;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

void MaxCohortdat45::out( ofstream& ofile,
                           const float& col,
                           const float& row,
                           const string& varname,
                           const long& carea,
                           const int& year,
                           const int& total,
                           const int& natchrts,
                           const string& contnent )
{

  ofile.setf( ios::fixed,ios::floatfield );
  ofile.setf( ios::showpoint );
  ofile.precision( 1 );

  ofile << col << ' ';
  ofile << row << ' ';
  ofile << varname << ' ';
  ofile << setprecision( 0 ) << carea << ' ';
  ofile << setprecision( 0 ) << year << ' ';
  ofile << setprecision( 0 ) << total << ' ';
  ofile << setprecision( 0 ) << natchrts << ' ';
  ofile << contnent;
  ofile << endl;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

void MaxCohortdat45::outdel( ofstream& ofile,
                              const float& col,
                              const float& row,
                              const string& varname,
                              const long& carea,
                              const int& year,
                              const int& total,
                              const int& natchrts,
                              const string& contnent )
{

  ofile.setf( ios::fixed,ios::floatfield );
  ofile.setf( ios::showpoint );
  ofile.precision( 1 );

  ofile << col << ",";
  ofile << row << ", ";
  ofile << varname << " ,";
  ofile << setprecision( 0 ) << carea << ",";
  ofile << setprecision( 0 ) << year << ",";
  ofile << setprecision( 0 ) << total << ",";
  ofile << setprecision( 0 ) << natchrts << ", ";
  ofile << contnent;
  ofile << endl;

};


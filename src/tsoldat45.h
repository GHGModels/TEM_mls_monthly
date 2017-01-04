/* *************************************************************
TSOLDAT45.H - object to read and write the structure of soil
                 texture data from/to files used by the
                 Terrestrial Ecosystem Model (TEM)

************************************************************* */

#ifndef TSOLDAT45_H
#define TSOLDAT45_H

class Soildat45
{

  public:

     Soildat45( void );

/* *************************************************************
		    Public Functions
************************************************************* */

     int get( ifstream& infile );

     int getdel( FILE* infile );

     void out( ofstream& ofile,
               const float& col,
               const float& row,
               const string& varname,
               const long& carea,
               const double& pctsand,
               const double& pctsilt,
               const double& pctclay,
               const int& wsoil,
               const string& source,
               const string& contnent );

     void outdel( ofstream& ofile,
                  const float& col,
                  const float& row,
                  const string& varname,
                  const long& carea,
                  const double& pctsand,
                  const double& pctsilt,
                  const double& pctclay,
                  const int& wsoil,
                  const string& source,
                  const string& contnent );

/* *************************************************************
		     Public Variables
************************************************************* */

     // column or longitude of grid cell (degrees)
     float col;

     // row or latitude of grid cell (degrees)
     float row;

     // "TEXTURE"
     string varname;

     // area covered by grid cell (sq. km)
     long carea;

     // percent sand of grid cell's soil texture
     double pctsand;

     // percent silt of grid cell's soil texture
     double pctsilt;

     // percent clay of grid cell's soil texture
     double pctclay;

     // wetland soil type designation (categorical data)
     int wsoil;

     // reference to data source
     string source;

     // name of continent containing grid cell
     string contnent;


  private:

/* *************************************************************
		      Private Variables
************************************************************* */

     int soilend;
     long curpos;
     long lagpos;

};

#endif


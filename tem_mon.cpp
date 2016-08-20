#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int gisend,i,yr,icht;
double vjan,vfeb,vmar,vapr,vmay,vjun,vjul,vaug,vsep,voct,vnov,vdec,tarea;
char file[100];
string infile, chrtfname, outfile;
int startyr, lastyr, firstchrtyr, tlulcflag;

#include "ttemdat45a.h"
#include "tmaxcohortdat45.h"

        Temdat45 temdat;
        MaxCohortdat45 mxdat;
        FILE* ifile;
        FILE* itfile;

int main ()
{


   cout << endl << "Enter the name of the input file: ";

   cin >> infile;

   cout << endl << "Enter the name of the mxcohort file: ";

   cin >> chrtfname;

   cout << endl << "total area of grid cell: ";

   cin >> tarea;

    cout << "Enter the first year in the input file: ";

    cin >> startyr;

    cout << "Enter the last year in the input file: ";

    cin >> lastyr;

    cout << "Does land cover change over time in the output: ";
    cout << endl;
    cout << "Enter 0 for no changes in land cover: " << endl;
    cout << "Enter 1 for changing land cover: " << endl;

    cin >> tlulcflag;

    if( 1 == tlulcflag )
    {
      cout << "Enter the first year of the maximum number of ";
      cout << "cohorts data: " << endl;

      cin >> firstchrtyr;
    }

   cout << endl << "Enter the name of the output file: ";

   cin >> outfile;

//   tarea = 142.0;

//    ifile = fopen("/share/partition7/bfelzer/tem/msb_lulc/crumxcohrts1895_2011.hvd", "r");
    ifile = fopen(chrtfname.c_str(), "r");

        if (!ifile){
                cerr << "lulc file could not be opened\n";
                exit(1);
        }

//    itfile = fopen("/share/partition7/tem/temhydro_combo/temhydro_cwd/NEP_MONTR.HVD", "r");
    itfile = fopen( infile.c_str(), "r");

        if (!itfile){
                cerr << "tem file could not be opened\n";
                exit(1);
        }

        ofstream fout;
//        fout.open("/share/partition7/tem/temhydro_combo/temhydro_cwd/sum_mon_NEP_MONTR.HVD", ios::out);
        fout.open(outfile.c_str(), ios::out);

       if(tlulcflag == 1)
       {
        if(firstchrtyr < startyr)
        {
        gisend = mxdat.getdel(ifile);
        }
       }
       if(tlulcflag == 0)
       {
        gisend = mxdat.getdel(ifile);
       }

//        for(yr=1896; yr<2007; yr++) {
        for(yr=startyr; yr<lastyr + 1; yr++) {

        cout << "year = " << yr << endl;
          if(tlulcflag == 1)
          {
	   gisend = mxdat.getdel(ifile);
          }
         vjan = 0.0;
         vfeb = 0.0;
         vmar = 0.0;
         vapr = 0.0;
         vmay = 0.0;
         vjun = 0.0;
         vjul = 0.0;
         vaug = 0.0;
         vsep = 0.0;
         voct = 0.0;
         vnov = 0.0;
         vdec = 0.0;
         for(icht = 0; icht < mxdat.total; icht++) {
         gisend = temdat.getdel(itfile);
            vjan = vjan + temdat.mon[0] * temdat.subarea/tarea;
           cout << "diag = " << vjan << " " << temdat.mon[0] << " " << temdat.subarea << endl;
            vfeb = vfeb + temdat.mon[1] * temdat.subarea/tarea;
            vmar = vmar + temdat.mon[2] * temdat.subarea/tarea;
            vapr = vapr + temdat.mon[3] * temdat.subarea/tarea;
            vmay = vmay + temdat.mon[4] * temdat.subarea/tarea;
            vjun = vjun + temdat.mon[5] * temdat.subarea/tarea;
            vjul = vjul + temdat.mon[6] * temdat.subarea/tarea;
            vaug = vaug + temdat.mon[7] * temdat.subarea/tarea;
            vsep = vsep + temdat.mon[8] * temdat.subarea/tarea;
            voct = voct + temdat.mon[9] * temdat.subarea/tarea;
            vnov = vnov + temdat.mon[10] * temdat.subarea/tarea;
            vdec = vdec + temdat.mon[11] * temdat.subarea/tarea;

            }  // cohort loop

          fout << yr << " 1 " << vjan << endl;
          fout << yr << " 2 " << vfeb << endl;
          fout << yr << " 3 " << vmar << endl;
          fout << yr << " 4 " << vapr << endl;
          fout << yr << " 5 " << vmay << endl;
          fout << yr << " 6 " << vjun << endl;
          fout << yr << " 7 " << vjul << endl;
          fout << yr << " 8 " << vaug << endl;
          fout << yr << " 9 " << vsep << endl;
          fout << yr << " 10 " << voct << endl;
          fout << yr << " 11 " << vnov << endl;
          fout << yr << " 12 " << vdec << endl;

	  }  // year loop 

	fclose( ifile );
	fclose( itfile );
        fout.close();

};

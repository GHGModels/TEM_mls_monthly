# TEM_mls_monthly
The Terrestrial Ecosystem Model multi-layer soil (TEM-mls) monthly version
Version built based on TEM-Hydro (developed and maintained by Prof. Benjamin Felzer @ Lehigh). 

TEM history review
TEM was originally developed 20~30 years ago by the Marine Biological Lab. It is a process-based biogeochemical model with equation supported (not an empirical or statistical model). Prof. B. Felzer contributed towards the construction of the mid-latitude ozone in TEM. TEM has a spatial resolution of 0.5˚ × 0.5˚ in grid cell, and site level (eddy covariance site) is the smallest unit for TEM to operate.
TEM involves the carbon (short-term cycle), nitrogen (more complex in terms of organic – inorganic, open – close) and hydrology cycle. It calculates GPP and NPP cat canopy level by using parameters obtained for photosynthesis and respiration at individual plants. 
The soil pool in TEM is very limited in terms of soil layer and physical quality, as the soil layer is a single layer. TEM4.5 is the newest version of TEM. In 2005, Kicklighter added an open N cycle into TEM.

The TEM-Hydro version involves leafs, hardwoods, roots, sapwoods, seeds, labile pool, and shuttleworth Wallace water pools in the model. 
LULC types incorporated into TEM are separately summarized in excel files.
TEM is typically run in the GCM computer which is operated in LINUX language. GCM is a computer with 9 modes, each consists of 8 cores therefore making GCM a 72 core system. It has 56 hard drives and 7 raid controller. Raid controller 1, 2, 3 are grouped together with 24 hard drives allocated to them, raid controllers 4, and 5 are grouped together for 16 hard drives and 6 and 7 are grouped together for the rest 16 hard drives. 
There are in total 7 partitions in the shared folder in GCM. Partition 2 in GCM is used for storage of input files, and Partition 3 is used for storage of output files. 
In TEM, the so-called CTEM is the calibration mode, and the XTEM is the extrapolation mode. XTEM is able to run from a PC once isolated to small grids or in calibration run.
Potential vegetation in TEM is a cohort-based approach. That means any disturbances in the current date will create cohort for the upcoming year. Currently, on-going project is looking for methods to reduce number of cohorts created to reduce computing time.
Pools of stock:
➢	Vegetation carbon involves carbon on leaves, stems (sapwood and hardwood), roots, labile and seeds.
➢	Vegetation nitrogen
➢	Soil C
➢	Soil N
➢	Inorganic N

# TEM Input:

Transient datasets (site level or grid level):
1.	Cloud or radiation
2.	Temperature
3.	Precipitation
4.	Ozone (AOT40 – in order to convert to daily, change to CUO index [Pleijel et al. 2004, cumulative stomatal uptake of ozone])
5.	CO2 (a single value for the globe)
6.	Vapor pressure
7.	Vegetation cohorts

Static datasets
1.	Soil texture (sand/silt/clay)
2.	Elevation
3.	Wind speed at surface (to determine aerodynamic)

Parameter files (ecd files)
1.	Soil
2.	Rooting depth
3.	Vegetation
4.	Vegetation mosaic
5.	Leaf
6.	Microbe
7.	Agriculture
8.	Calibrated biome files
 
# Key References:

VERSION 4.1

Tian, H., J.M. Melillo, D.W. Kicklighter, A.D. McGuire and J.
  Helfrich.  1999. The sensitvity of terrestrial carbon storage to
  historical climate variability and atmospheric CO2 in the United
  States.  Tellus 51B: 414-452.

VERSION 4.2

McGuire, A.D., S. Sitch, J.S. Clein, R. Dargaville, G. Esser, J. Foley,
  M. Heimann, F. Joos, J. Kaplan, D.W. Kicklighter, R.A. Meier, J.M.
  Melillo, B. Moore III, I.C. Prentice, N. Ramankutty, T. Reichenau,
  A. Schloss, H. Tian, L.J. Williams and U. Wittenberg (2001) Carbon
  balance of the terrestrial biosphere in the twentieth century:
  analyses of CO2, climate and land use effects with four process-
  based ecosystem models.  Global Biogeochemical Cycles 15: 183-206.

Tian, H., J.M. Melillo, D.W. Kicklighter, S. Pan, J. Liu, A.D. McGuire
  and B. Moore III (2003) Regional carbon dynamics in monsoon Asia
  and its implications for the global carbon cycle. Global and
  Planetary Change 37: 201-217.

VERSION 4.3

Felzer, B., D. Kicklighter, J. Melillo, C. Wang, Q. Zhuang, and
  R. Prinn (2004) Effects of ozone on net primary production and
  carbon sequestration in the conterminous United States using a
  biogeochemistry model. Tellus 56B: 230-248.

Runge - Kutta - Fehlberg (RKF) adaptive integrator:

Cheney, W., and D. Kincaid.  1985.  Numerical mathematics and
  computing.  Second edition.  Brooks/ Col Publishing Co.  Monterey,
  CA.  pp. 325-328.
  
 Version TEM-Hydro
 
1. Felzer et al., 2009. Importance of carbon-nitrogen interactions and ozone on ecosystem hydrology during the 21st century. JGR: Biogeosciences.
2. Felzer et al., 2011. Nitrogen effect on carbon-water coupling in forests, grasslands, and shrublands in the arid western United States. JGR: Biogeosciences.
3. Felzer, 2012. Carbon, nitrogen, and water response to climate and land use changes in Pennsylvania during the 20th and 21st centuries. Ecological modeling. 
4. Jiang et al., 2015. Improved understanding of Climate Change Impact to Pennsylvania Dairy Pasture. Crop Science. 



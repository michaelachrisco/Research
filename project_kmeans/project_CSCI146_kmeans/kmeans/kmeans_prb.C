# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <complex>

using namespace std;

# include "kmeans.H"
# include "kmeans.C"

int main ( );

void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );


//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for KMEANS_PRB.
//
//  Discussion:
//
//    KMEANS_PRB calls the KMEANS tests.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "KMEANS_PRB\n";
  cout << "  C++ version\n";
  cout << "  Test the KMEANS library.\n";

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );

//
//  Terminate.
//
  cout << "\n";
  cout << "KMEANS_PRB\n";
  cout << "  Normal end of execution.\n";

  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tries out the HMEANS_01 routine.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  string center_filename = "AI/test01_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  string cluster_filename = "AI/test01_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  string point_filename = "AI/points_100.txt";
  int point_num;
  int seed;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Test the HMEANS_01 algorithm.\n";
//
//  Read the data points.
//
  cout << "\n";
  cout << "  Data points will be read from \"" << point_filename << "\".\n";

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  cout << "\n";
  cout << "  Point spatial dimension = " << dim_num << "\n";
  cout << "  Number of points = " << point_num << "\n";

  point = r8mat_data_read ( point_filename, dim_num, point_num );
//
//  Clustering parameters.
//
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cout << "\n";
  cout << "  Number of iterations allowed is " << it_max << "\n";
//
//  Initialize the centers.
//
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num, 
    point, &seed );

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = new double[cluster_num];
  cluster_population = new int[cluster_num];
  
  hmeans_01 ( dim_num, point_num, cluster_num, it_max, it_num, point, 
    cluster, cluster_center, cluster_population, cluster_energy );

  cout << "\n";
  cout << "  Number of iterations taken is " << it_num << "\n";

  cluster_variance = cluster_variance_compute ( dim_num, point_num, 
    cluster_num, point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, 
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  cout << "\n";
  cout << "  Cluster centers written to \"" << center_filename << "\".\n";

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  cout << "  Cluster assignments written to \"" << cluster_filename << "\".\n";

  delete [] cluster;
  delete [] cluster_center;
  delete [] cluster_energy;
  delete [] cluster_population;
  delete [] cluster_variance;
  delete [] point;

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tries out the HMEANS_02 routine.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  string center_filename = "AI/test02_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  string cluster_filename = "AI/test02_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  string point_filename = "AI/points_100.txt";
  int point_num;
  int seed;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Test the HMEANS_02 algorithm.\n";
//
//  Read the data points.
//
  cout << "\n";
  cout << "  Data points will be read from \"" << point_filename << "\".\n";

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  cout << "\n";
  cout << "  Point spatial dimension = " << dim_num << "\n";
  cout << "  Number of points = " << point_num << "\n";

  point = r8mat_data_read ( point_filename, dim_num, point_num );
//
//  Clustering parameters.
//
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cout << "\n";
  cout << "  Number of iterations allowed is " << it_max << "\n";
//
//  Initialize the centers.
//
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num, 
    point, &seed );

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = new double[cluster_num];
  cluster_population = new int[cluster_num];
  
  hmeans_02 ( dim_num, point_num, cluster_num, it_max, it_num, point, 
    cluster, cluster_center, cluster_population, cluster_energy, &seed );

  cout << "\n";
  cout << "  Number of iterations taken is " << it_num << "\n";

  cluster_variance = cluster_variance_compute ( dim_num, point_num, 
    cluster_num, point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, 
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  cout << "\n";
  cout << "  Cluster centers written to \"" << center_filename << "\".\n";

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  cout << "  Cluster assignments written to \"" << cluster_filename << "\".\n";

  delete [] cluster;
  delete [] cluster_center;
  delete [] cluster_energy;
  delete [] cluster_population;
  delete [] cluster_variance;
  delete [] point;

  return;
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tries out the KMEANS_01 routine.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  string center_filename = "AI/test03_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  string cluster_filename = "AI/test03_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  string point_filename = "AI/points_100.txt";
  int point_num;
  int seed;

  cout << "\n";
  cout << "TEST03\n";
  cout << "  Test the KMEANS_01 algorithm.\n";
  cout << "  (Applied Statistics Algorithm #58)\n";
//
//  Read the data points.
//
  cout << "\n";
  cout << "  Data points will be read from \"" << point_filename << "\".\n";

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  cout << "\n";
  cout << "  Point spatial dimension = " << dim_num << "\n";
  cout << "  Number of points = " << point_num << "\n";

  point = r8mat_data_read ( point_filename, dim_num, point_num );
//
//  Clustering parameters.
//
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = new double[cluster_num];
  cluster_population = new int[cluster_num];

  cout << "\n";
  cout << "  Number of iterations allowed is " << it_max << "\n";
//
//  Initialize the centers.
//
  cluster_center = cluster_initialize_5 ( dim_num, point_num, cluster_num, point, 
    &seed );

  kmeans_01 ( dim_num, point_num, cluster_num, it_max, it_num, point, 
    cluster, cluster_center, cluster_population, cluster_energy );

  cout << "\n";
  cout << "  Number of KMEANS_01 iterations taken is " << it_num << "\n";

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num, 
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population, 
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  cout << "\n";
  cout << "  Cluster centers written to \"" << center_filename << "\".\n";

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  cout << "  Cluster assignments written to \"" << cluster_filename << "\".\n";

  delete [] cluster;
  delete [] cluster_center;
  delete [] cluster_energy;
  delete [] cluster_population;
  delete [] cluster_variance;
  delete [] point;

  return;
}
//****************************************************************************80

void test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tries out the KMEANS_02 routine.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  string center_filename = "AI/test04_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  string cluster_filename = "AI/test04_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  string point_filename = "AI/points_100.txt";
  int point_num;
  int seed;

  cout << "\n";
  cout << "TEST04\n";
  cout << "  Test the KMEANS_02 algorithm.\n";
  cout << "  (Applied Statistics Algorithm #136)\n";
//
//  Read the data points.
//
  cout << "\n";
  cout << "  Data points will be read from \"" << point_filename << "\".\n";

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  cout << "\n";
  cout << "  Point spatial dimension = " << dim_num << "\n";
  cout << "  Number of points = " << point_num << "\n";

  point = r8mat_data_read ( point_filename, dim_num, point_num );
//
//  Clustering parameters.
//
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = new double[cluster_num];
  cluster_population = new int[cluster_num];

  cout << "\n";
  cout << "  Number of iterations allowed is " << it_max << "\n";
//
//  Initialize the centers.
//
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num, point );

  kmeans_02 ( dim_num, point_num, cluster_num, it_max, it_num, point, 
    cluster, cluster_center, cluster_population, cluster_energy );

  cout << "\n";
  cout << "  Number of iterations taken is " << it_num << "\n";

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num, 
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, 
    cluster_population, cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  cout << "\n";
  cout << "  Cluster centers written to \"" << center_filename << "\".\n";

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  cout << "  Cluster assignments written to \"" << cluster_filename << "\".\n";

  delete [] cluster;
  delete [] cluster_center;
  delete [] cluster_energy;
  delete [] cluster_population;
  delete [] cluster_variance;
  delete [] point;

  return;
}
//****************************************************************************80

void test05 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST05 tries out the KMEANS_03 routine.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  string center_filename = "AI/test05_centers.txt";
  int *cluster;
  double *cluster_center;
  double *cluster_energy;
  string cluster_filename = "AI/test05_clusters.txt";
  int cluster_num;
  int *cluster_population;
  double *cluster_variance;
  int dim_num;
  int it_max;
  int it_num;
  double *point;
  string point_filename = "AI/points_100.txt";
  int point_num;
  int seed;

  cout << "\n";
  cout << "TEST05\n";
  cout << "  Test the KMEANS_03 algorithm.\n";
//
//  Read the data points.
//
  cout << "\n";
  cout << "  Data points will be read from \"" << point_filename << "\".\n";

  r8mat_header_read ( point_filename, &dim_num, &point_num );

  cout << "\n";
  cout << "  Point spatial dimension = " << dim_num << "\n";
  cout << "  Number of points = " << point_num << "\n";

  point = r8mat_data_read ( point_filename, dim_num, point_num );
//
//  Clustering parameters.
//
  cluster_num = 5;
  it_max = 20;
  seed = 123456789;

  cluster = i4vec_negone_new ( point_num );
  cluster_energy = new double[cluster_num];
  cluster_population = new int[cluster_num];

  cout << "\n";
  cout << "  Number of iterations allowed is " << it_max << "\n";
//
//  Initialize the centers.
//
  cluster_center = cluster_initialize_1 ( dim_num, point_num, cluster_num,
    point );

  kmeans_03 ( dim_num, point_num, cluster_num, it_max, it_num, point, 
    cluster, cluster_center, cluster_population, cluster_energy );

  cout << "\n";
  cout << "  Number of iterations taken is " << it_num << "\n";

  cluster_variance = cluster_variance_compute ( dim_num, point_num, cluster_num, 
    point, cluster, cluster_center );

  cluster_print_summary ( point_num, cluster_num, cluster_population, 
    cluster_energy, cluster_variance );

  r8mat_write ( center_filename, dim_num, cluster_num, cluster_center );

  cout << "\n";
  cout << "  Cluster centers written to \"" << center_filename << "\".\n";

  i4mat_write ( cluster_filename, 1, point_num, cluster );

  cout << "  Cluster assignments written to \"" << cluster_filename << "\".\n";

  delete [] cluster;
  delete [] cluster_center;
  delete [] cluster_energy;
  delete [] cluster_population;
  delete [] cluster_variance;
  delete [] point;

  return;
}
//****************************************************************************80




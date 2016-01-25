#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
main (int argc, char** argv)
{

	// -----------------------------------------------------
	// -----Parse Command Line for the name of the file-----
	// -----------------------------------------------------
  std::cout << argv[0] << std::endl;     //Name of exe.
  std::cout << argv[1] << std::endl;     //Name of file.
  //To run: ./pcd_read myblah.txt
  //By default, assume the second string is the name of the file we load.
  std::string my_string = argv[1];


  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  //if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  if (pcl::io::loadPCDFile<pcl::PointXYZ> (my_string, *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
   //Show the data:
//  for (size_t i = 0; i < cloud->points.size (); ++i)
//    std::cout << "    " << cloud->points[i].x
//              << " "    << cloud->points[i].y
//              << " "    << cloud->points[i].z << std::endl;

  return (0);
}


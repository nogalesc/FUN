//Author: Chris Nogales

#include <iostream>
#include <pcl/io/pcd_io.h>     //Read point clouds
#include <pcl/point_types.h>  

#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>

boost::shared_ptr<pcl::visualization::PCLVisualizer> rgbVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}

boost::shared_ptr<pcl::visualization::PCLVisualizer> simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}


// --------------
// -----Main-----
// --------------
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

  // ----------------------------------------------------------
  // -----Create example point cloud pointer to store data-----
  // ----------------------------------------------------------
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);

  //if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  if (pcl::io::loadPCDFile<pcl::PointXYZRGB> (my_string, *cloud) == -1) //* load the file
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

  /*Load to simple 3D visualizer*/
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  viewer = rgbVis(cloud);

  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (100);
    boost::this_thread::sleep (boost::posix_time::microseconds (100000));
  }
  return (0);
}


#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vector>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



using namespace std;
using namespace cv;


int  main (int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    fstream file_name1;
    file_name1.open("/home/lqc/CLionProjects/sjtu_pointcloud1/pointcloud5.txt");
    if (!file_name1.is_open()){
        cout<<"check source files!"<<endl;
        return -1;
    }

    // Fill in the cloud data
    cloud->width    = 152000;
    cloud->height   = 1;
    cloud->is_dense = false;
    cloud->points.resize (cloud->width * cloud->height);

    Vec3d dd;

    for (size_t i = 0; i < cloud->points.size (); ++i)
    {
        file_name1>>dd[0];
        file_name1>>dd[1];
        file_name1>>dd[2];


        cloud->points[i].x = dd[0];
        cloud->points[i].y = dd[1];
        cloud->points[i].z = dd[2];
    }

    pcl::io::savePCDFileASCII ("/home/lqc/CLionProjects/sjtu_pointcloud1/test5_pcd.pcd", *cloud);
    std::cerr << "Saved " << cloud->points.size () << " data points to test_pcd4.pcd." << std::endl;
    for (size_t i = 0; i < cloud->points.size (); ++i)
        if  (cloud->points[i].x >0){
            std::cerr << "    " << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << std::endl;
    }


    pcl::visualization::PCLVisualizer viewer("3d part");
    viewer.setBackgroundColor(255,255,255);

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> singleColor(cloud,0,255,0);
    viewer.addPointCloud<pcl::PointXYZ>(cloud,singleColor,"sample");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,3,"sample");

    while(!viewer.wasStopped()){
        viewer.spinOnce();
    }

    return (0);
}
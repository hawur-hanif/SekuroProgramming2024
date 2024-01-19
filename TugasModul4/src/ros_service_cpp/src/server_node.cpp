#include "ros/ros.h"
#include "ros_service_cpp/magnitude.h"

bool vector_magnitude(ros_service_cpp::magnitude::Request &req, ros_service_cpp::magnitude::Response &resp){
    resp.magnitude = sqrt(req.komponenX*req.komponenX + req.komponenY*req.komponenY + req.komponenZ*req.komponenZ);
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "service_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("magnitude_cpp", vector_magnitude);
    ROS_INFO("siap perhitungan.");
    ros::spin();

    return 0;
}
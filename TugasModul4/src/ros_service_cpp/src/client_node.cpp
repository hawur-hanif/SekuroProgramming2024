#include "ros/ros.h"
#include "ros_service_cpp/magnitude.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "client_server");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<ros_service_cpp::magnitude>("magnitude_cpp");

    ros_service_cpp::magnitude vec;
    std::cout << "masukkan koordinat\nkomponen-x: ";
    std::cin >> vec.request.komponenX;
    std::cout << "komponen-y: ";
    std::cin >> vec.request.komponenY;
    std::cout << "komponen-z: ";
    std::cin >> vec.request.komponenZ;

    if(client.call(vec)){
        ROS_INFO("komponen x: %lf", vec.request.komponenX);
        ROS_INFO("komponen y: %lf", vec.request.komponenY);
        ROS_INFO("komponen z: %lf", vec.request.komponenZ);
        ROS_INFO("panjang vektor: %lf \n", vec.response.magnitude);
    } else{
        ROS_INFO("perhitungan gagal");
        return 1;
    }
    ros::spin();

    return 0;
}
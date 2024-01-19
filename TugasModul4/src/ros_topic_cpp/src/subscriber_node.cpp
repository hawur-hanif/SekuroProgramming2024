#include "ros/ros.h"
#include "ros_topic_cpp/topic.h"

void callbackHandler(const ros_topic_cpp::topic::ConstPtr& msg){
    ROS_INFO("topic cpp: ");
    ROS_INFO("usia: %ld", msg->usia);
    ROS_INFO("tinggi: %lf", msg->tinggi);
    ROS_INFO("nama: %s", msg->nama.c_str());
    if (msg->kehadiran){
        ROS_INFO("kehadiran: hadir\n");
    }else{
        ROS_INFO("kehadiran: tidak hadir\n");
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "Subscribe");
    ros::NodeHandle nh;

    ros::Subscriber topic_sub = nh.subscribe("topik_utama", 1000, callbackHandler);

    ros::spin();

    return 0;
}
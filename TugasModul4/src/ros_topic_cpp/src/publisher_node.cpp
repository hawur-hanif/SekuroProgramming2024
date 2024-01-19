#include "ros/ros.h"
#include "ros_topic_cpp/topic.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "Publisher_topic_cpp");
    ros::NodeHandle nh;

    ros::Publisher topic_publisher = nh.advertise<ros_topic_cpp::topic>("topik_utama", 1000);
    ros::Rate loop_rate(1);

    while(ros::ok()){
        ros_topic_cpp::topic topicVariable;

        topicVariable.usia = 23;
        topicVariable.tinggi = 173.34;
        topicVariable.nama = "tuan kil";
        topicVariable.kehadiran = false;

        topic_publisher.publish(topicVariable);
        ROS_INFO("pesan terkirim");

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

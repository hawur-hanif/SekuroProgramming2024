#!/usr/bin/env python3
import rospy
from ros_topic_python.msg import topic

def callback(data):
    rospy.loginfo("usia: %ld" % data.usia)
    rospy.loginfo("tinggi: %lf" % data.tinggi)
    rospy.loginfo("nama: %s" % data.nama)
    if data.kehadiran:
        rospy.loginfo("kehadiran: hadir\n")
    else:
        rospy.loginfo("kehadiran: hadir\n")

def listener():
    rospy.init_node("subscriber", anonymous=True)

    rospy.Subscriber("topik_utama_python", topic, callback)

    rospy.spin()

if __name__ =="__main__":
    listener()


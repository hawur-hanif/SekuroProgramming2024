#!/usr/bin/env python3
import rospy
from ros_topic_python.msg import topic

def talker():
    msg_publisher = rospy.Publisher("topik_utama_python", topic, queue_size=10)

    rospy.init_node("publisher", anonymous=True)

    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        topikVariabel = topic()

        topikVariabel.usia = 43
        topikVariabel.tinggi = 166.34
        topikVariabel.nama = "nona deb"
        topikVariabel.kehadiran = True

        msg_publisher.publish(topikVariabel)
        rospy.loginfo("pesan terkirim")

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
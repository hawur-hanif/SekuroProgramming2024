#!/usr/bin/env python3
import rospy
from ros_service_python.srv import magnitude, magnitudeResponse

def vector_magnitude_3d(x, y, z):
    rospy.init_node("client")

    rospy.wait_for_service('menghitung_magnitude_py')

    try:
        hitung_vektor = rospy.ServiceProxy('menghitung_magnitude_py', magnitude)
            
        response = hitung_vektor(x, y, z)

        rospy.loginfo("magnitude: %lf" % response.magnitude)

    except rospy.ServiceException as e:
        print("service call failed %s", e)

if __name__ == '__main__':
    print("masukkan koordinat")
    x = float(input("komponen-x: "))
    y = float(input("komponen-y: "))
    z = float(input("komponen-z: "))
    vector_magnitude_3d(x, y, z)
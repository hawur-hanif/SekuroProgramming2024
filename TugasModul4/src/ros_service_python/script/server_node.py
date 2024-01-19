#!/usr/bin/env python3
import rospy
import math as mt
from ros_service_python.srv import magnitude, magnitudeResponse

def vector_magnitude(req):
    return magnitudeResponse(mt.sqrt(req.komponenX**2 + req.komponenY**2 + req.komponenZ**2))

def server_node():
    rospy.init_node("server")

    s = rospy.Service('menghitung_magnitude_py', magnitude, vector_magnitude)
    rospy.loginfo("siap menghitung")
    rospy.spin()
    
if __name__ == '__main__':
    server_node()

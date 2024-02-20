#!/usr/bin/env python

import rospy
from python_examples.srv import SumaDosEnteros, SumaDosEnterosResponse

def suma_callback(req):
    rospy.loginfo("Primer numero: %d, Segundo numero: %d", req.a, req.b)
    return SumaDosEnterosResponse(req.a + req.b)

def service_server():
    rospy.init_node('service_server_suma')
    server_srv = rospy.Service('/SumaDosNumeros', SumaDosEnteros, suma_callback)  # Creación del servidor
    rospy.loginfo("Listo para mandar el resultado de la suma.")
    rospy.spin()

if __name__ == '__main__':
    service_server()
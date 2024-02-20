#!/usr/bin/env python

import rospy
from std_msgs.msg import String, Float32, UInt32

# Callback functions for subscribers
def nombre_callback(data):
    global nombre
    nombre = data.data

def edad_callback(data):
    global edad
    edad = data.data

def msg_callback(data):
    global mensaje_count
    mensaje_count = data.data

def listener():
    # Inicializar ROS y la creación del nodo
    rospy.init_node('listener', anonymous=True)

    # Declaración de los suscriptores
    rospy.Subscriber("/nombre", String, nombre_callback)
    rospy.Subscriber("/edad", Float32, edad_callback)
    rospy.Subscriber("/numero_de_mensaje", UInt32, msg_callback)

    # Frecuencia a la que correrá el nodo en Hz
    rate = rospy.Rate(1)  # 1Hz

    while not rospy.is_shutdown():
        print("Hola mi nombre es", nombre, "tengo", edad, "años y este es el mensaje número", mensaje_count, "que se envía.")
        rate.sleep()

if __name__ == '__main__':
    try:
        nombre = ""  # Inicialización de la variable nombre
        edad = 0.0   # Inicialización de la variable edad
        mensaje_count = 0  # Inicialización de la variable mensaje_count
        listener()
    except rospy.ROSInterruptException:
        pass

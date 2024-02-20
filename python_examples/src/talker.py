#!/usr/bin/env python

import rospy
from std_msgs.msg import String, Float32, UInt32

def talker():
    # Inicializar ROS y la creación del nodo
    rospy.init_node('talker', anonymous=True)
    
    # Declaración de los publishers
    nombre_pub = rospy.Publisher('/nombre', String, queue_size=10)
    edad_pub = rospy.Publisher('/edad', Float32, queue_size=10)
    msg_pub = rospy.Publisher('/numero_de_mensaje', UInt32, queue_size=10)
    
    # Frecuencia a la que correrá el nodo en Hz
    rate = rospy.Rate(1)  # 1Hz

    # Definición de las variables que identifican al mensaje de ROS
    nombre_var = String()
    edad_var = Float32()
    msg_var = UInt32()

    # Definición de las variables locales de nuestro código
    ss = "Armando"
    tiempo_de_vida = 32.0
    mensaje_count = 0

    while not rospy.is_shutdown():
        mensaje_count += 1

        # Definimos el contenido de los ROS Messages
        nombre_var.data = ss
        edad_var.data = tiempo_de_vida
        msg_var.data = mensaje_count

        # Mandar la publicación de los mensajes
        nombre_pub.publish(nombre_var)
        edad_pub.publish(edad_var)
        msg_pub.publish(msg_var)
        
        rospy.loginfo("TALKER HA INICIADO")

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

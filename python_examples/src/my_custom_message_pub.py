#!/usr/bin/env python

import rospy
from python_examples.msg import LM35

def custom_message_publisher():
    rospy.init_node('my_custom_message_pub')
    sensor_pub = rospy.Publisher('/temp_sensor_info', LM35, queue_size=10)
    rate = rospy.Rate(5)  # 5Hz

    while not rospy.is_shutdown():
        sensor_var = LM35()
        sensor_var.sensor_name = "Sensor_1"
        sensor_var.input_voltage = 5.0
        sensor_var.output_voltage = 0.45
        sensor_var.temperature = 45.0

        sensor_pub.publish(sensor_var)
        rate.sleep()

if __name__ == '__main__':
    try:
        custom_message_publisher()
    except rospy.ROSInterruptException:
        pass

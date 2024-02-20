#include <ros/ros.h>
#include <c_plus_plus_examples/LM35.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_custom_message_pub");
    ros::NodeHandle nh;

    ros::Publisher sensor_pub = nh.advertise<c_plus_plus_examples::LM35>("/temp_sensor_info", 10);

    ros::Rate loop_rate(5);

    while (ros::ok())
    {
        c_plus_plus_examples::LM35 sensor_var;
        sensor_var.sensor_name = "Sensor_1";
        sensor_var.input_voltage = 5.0;
        sensor_var.output_voltage = 0.45;
        sensor_var.temperature = 45.0;

        sensor_pub.publish(sensor_var);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
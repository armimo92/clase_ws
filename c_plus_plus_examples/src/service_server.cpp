#include <ros/ros.h>
#include <c_plus_plus_examples/SumaDosEnteros.h>

bool sumaCallback(c_plus_plus_examples::SumaDosEnteros::Request &req, c_plus_plus_examples::SumaDosEnteros::Response &res){
    ROS_INFO_STREAM("Primer numero: " << req.a << " Segundo numero: " << req.b);
    res.suma = req.a + req.b;

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_server_suma");
    ros::NodeHandle nh;

    ros::ServiceServer server_srv = nh.advertiseService("/SumaDosNumeros", sumaCallback); //Creacion del server

    ROS_INFO("Listo para mandar el resultado de la suma.");
    ros::spin();

    return 0;
}
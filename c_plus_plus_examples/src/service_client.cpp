#include <ros/ros.h>
#include <c_plus_plus_examples/SumaDosEnteros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client_suma");
    ros::NodeHandle nh;

    ros::service::waitForService("/SumaDosNumeros"); //Espera a que el servicio esté disponible
    ros::ServiceClient client_srv = nh.serviceClient<c_plus_plus_examples::SumaDosEnteros>("/SumaDosNumeros"); //Creacion del cliente

    c_plus_plus_examples::SumaDosEnteros datos_srv; //Variable que identifica los datos para el servicio
    datos_srv.request.a = 2;    //Dato 1 para la suma
    datos_srv.request.b = 5;    //Dato 2 para la suma
    

    ROS_INFO_STREAM("El cliente pide la suma de: " << datos_srv.request.a << " + " << datos_srv.request.b);

    client_srv.call(datos_srv); //Solicitar el servicio
    ROS_INFO_STREAM("Muestrame el resultado de la " << datos_srv.response);

    return 0;
}
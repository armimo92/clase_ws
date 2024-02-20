// Header files que llaman a las librerías de C++, ROS y ROS Messages.
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt32.h>
#include <string>
#include <iostream>

//Definición de las variables locales de nuestro código. Si se desea, también pueden ser globales
std::string nombre;
float edad;
uint32_t mensaje_count;

void nombreCallback(const std_msgs::String::ConstPtr& name)
{
    nombre = name->data;
    
}

void edadCallback(const std_msgs::Float32::ConstPtr& age)
{
    edad = age->data;
}

void msgCallback(const std_msgs::UInt32::ConstPtr& msj)
{
    mensaje_count = msj->data;
}


int main(int argc, char **argv)
{
    // Inicializar ROS y la creación del nodo
    ros::init(argc, argv, "listener"); // ros::init(argc, argv, "$<NOMBRE DEL ARCHIVO CPP>")
    ros::NodeHandle nh; //ros::NodeHandle $NOMBRE_DE_LA_VARIABLE_QUE_REPRESENTA_AL_NODO_EN_EL_CÓDIGO>
    
    // Declaración de los publishers
    //ros::Publisher <$PUBLISHER_NAME> = nh.advertise<$TIPO_DE_MENSAJE>("<$TÓPICO>", <$NÚMERO_DE_DATOS_A_GUARDAR_EN_CASO_DE_TERMINAR_EL_NODO>)
    ros::Subscriber nombre_sub = nh.subscribe("/nombre", 10, &nombreCallback); 
    ros::Subscriber edad_sub = nh.subscribe("/edad", 10, &edadCallback);
    ros::Subscriber msg_sub = nh.subscribe("/numero_de_mensaje", 10, &msgCallback);
    
    // Frecuencia a la que correrá el nodo en Hz
    ros::Rate loop_rate(1);    // ros::Rate <$NOMBRE DE LA VARIABLE>($<Hz>)


    while(ros::ok())
    {
        std::cout << "Hola mi nombre es " << nombre << " tengo " << edad << " años y este es el mensaje número " << mensaje_count << " que se envía." << std::endl;

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
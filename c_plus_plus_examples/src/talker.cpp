// Header files que llaman a las librerías de C++, ROS y ROS Messages.
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt32.h>
#include <string>

int main(int argc, char **argv)
{
    // Inicializar ROS y la creación del nodo
    ros::init(argc, argv, "talker"); // ros::init(argc, argv, "$<NOMBRE DEL ARCHIVO CPP>")
    ros::NodeHandle nh; //ros::NodeHandle $NOMBRE_DE_LA_VARIABLE_QUE_REPRESENTA_AL_NODO_EN_EL_CÓDIGO>
    
    // Declaración de los publishers
    //ros::Publisher <$PUBLISHER_NAME> = nh.advertise<$TIPO_DE_MENSAJE>("<$TÓPICO>", 
    //<$NÚMERO_DE_DATOS_A_GUARDAR_EN_CASO_DE_TERMINAR_EL_NODO>)
    ros::Publisher nombre_pub = nh.advertise<std_msgs::String>("/nombre", 10); 
    ros::Publisher edad_pub = nh.advertise<std_msgs::Float32>("/edad", 10);
    ros::Publisher msg_pub = nh.advertise<std_msgs::UInt32>("/numero_de_mensaje", 10);
    
    // Frecuencia a la que correrá el nodo en Hz
    ros::Rate loop_rate(1);    // ros::Rate <$NOMBRE DE LA VARIABLE>($<Hz>)

    // Definición de las variables que identifican al mensaje de ROS
    std_msgs::String nombre_var;
    std_msgs::Float32 edad_var;
    std_msgs::UInt32 msg_var;

    //Definición de las variables locales de nuestro código. Si se desea, también pueden ser globales.
    std::string ss = "Armando";
    float tiempo_de_vida = 32;
    uint32_t mensaje_count = 0;


    while(ros::ok())
    {
        mensaje_count++;

        // Definimos el contenido de los ROS Messages
        nombre_var.data = ss;
        edad_var.data = tiempo_de_vida;
        msg_var.data = mensaje_count;

        // Mandar la publicación de los mensajes
        nombre_pub.publish(nombre_var);
        edad_pub.publish(edad_var);
        msg_pub.publish(msg_var);
        
        ROS_INFO("TALKER HA INICIADO");

        loop_rate.sleep();
    }

    return 0;
}
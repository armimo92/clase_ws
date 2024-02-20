import rospy
from python_examples.srv import SumaDosEnteros

def service_client():
    rospy.init_node('service_client_suma')
    rospy.wait_for_service('/SumaDosNumeros')  # Espera a que el servicio esté disponible
    try:
        client_srv = rospy.ServiceProxy('/SumaDosNumeros', SumaDosEnteros)  # Creación del cliente
        datos_srv = SumaDosEnteros()  # Variable que identifica los datos para el servicio
        datos_srv.a = 2  # Dato 1 para la suma
        datos_srv.b = 5  # Dato 2 para la suma

        rospy.loginfo("El cliente pide la suma de: %d + %d", datos_srv.a, datos_srv.b)

        result = client_srv(datos_srv.a, datos_srv.b)  # Solicitar el servicio
        rospy.loginfo("El resultado de la suma es: %d", result.suma)

    except rospy.ServiceException as e:
        rospy.logerr("Error al llamar al servicio: %s", e)

if __name__ == '__main__':
    service_client()
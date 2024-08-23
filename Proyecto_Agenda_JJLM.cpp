#include <iostream>
#include <string>
#include <locale>
#include "Contacto.h"
#include "Lista.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	cout << "¡Hola y bienvenido a nuestro programa!\n\n";
	cout << "Nos alegra mucho tenerte con nosotros.\n";
	cout << "Aquí, te proporcionaremos todas las herramientas y el apoyo que necesitas para alcanzar tus objetivos.\nNo dudes en explorar todas las funciones y recursos disponibles.\nEstamos aquí para ayudarte en cada paso del camino.\n\n";
	cout << "¿Comenzamos? :D\n\n\n";
	//FIN BIENVENIDA


	cout << "|°|°|°|°|°|°|°|°|~MENÚ~|°|°|°|°|°|°|°|°|\n\n";
	cout << "1. Agregar Contacto\n";
	cout << "2. Editar Contacto\n";
	cout << "3. Eliminar Contacto\n";
	cout << "4. Buscar Contacto\n";
	cout << "5. Guardar Contactos\n";
	cout << "6. Cargar Contactos\n\n";
	cout << "7. Salir\n";
	cout << "Ingrese opción que desea efectuar. :)\n";
	int opcion ;
	cin >> opcion;
	string dni = "";
	string nombres = "";
	string apellidos = "";
	string direccion = "";
	unsigned int residencia = 0;
	unsigned int telefono = 0;
	int logrado=0;
	Lista agenda;
	Contacto *p;
	while (opcion!=7){
		switch (opcion){
		
		case 1:
			cin.ignore();
			cout << "Ingrese su número de identificación: ";
			getline(cin, dni);
			cout << endl;

			cout << "Ingrese sus nombres: ";
			getline(cin, nombres);
			cout << endl;

			cout << "Ingrese sus apellidos: ";
			getline(cin, apellidos);
			cout << endl;

			cout << "Ingrese su dirección: ";
			getline(cin, direccion);
			cout << endl;

			cout << "Ingrese su número de teléfono residencial: ";
			cin >> residencia;
			cout << endl;

			cout << "Ingrese su número de teléfono movil: ";
			cin >> telefono;
			cout << endl;

			p = new Contacto(dni, nombres, apellidos, direccion, residencia, telefono);

			agenda.Insert(p);
			
			break;//FIN DEL CASO 1

		case 2:

			break;//FIN DEL CASO 2

		case 3:

			break;//FIN DEL CASO 3

		case 4:

			break;//FIN DEL CASO 4

		case 5:
			agenda.guardarArchivo();
			break;//FIN DEL CASO 5

		case 6:

			break;//FIN DEL CASO 6

		case 8:
			agenda.Impresion();
			break;//FIN CASO 6

		default:
			cout << "Ingresó una opción no válida dentro del rango de 1 a 5 >:(\n\n";
			break;//FIN DEL CASO DEFAULT

		}//FIN DEL SWITCH

		cout << "|°|°|°|°|°|°|°|°|~MENÚ~|°|°|°|°|°|°|°|°|\n\n";
		cout << "1. Agregar Contacto\n";
		cout << "2. Editar Contacto\n";
		cout << "3. Eliminar Contacto\n";
		cout << "4. Buscar Contacto\n";
		cout << "5. Guardar Contactos\n";
		cout << "6. Cargar Contactos\n\n";
		cout << "7. Salir\n";
		cout << "Ingrese opción que desea efectuar. :)\n";
		cin >> opcion;

	}//FIN DEL WHILE

}

#include <iostream>
#include <string>
#include <locale>
#include <cctype>
#include "Contacto.h"
#include "Lista.h"
using namespace std;

bool entrada_num_valida(string entrada) {
	for (char c : entrada) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool nombre_valido(string nombres) {
	for (char c : nombres) {
		if (isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool num_valido(string movil) {
	if (movil.length()!=8)
	{
		return false;
	}
	for (char c : movil) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool dni_valido(string dni) {
	if (dni.length() != 13)
	{
		return false;
	}
	for (char c : dni) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main(){
	setlocale(LC_ALL, "spanish");
	cout << "¡Hola y bienvenido a nuestro programa!\n\n";
	cout << "Nos alegra mucho tenerte con nosotros.\n";
	cout << "Aquí, te proporcionaremos todas las herramientas y el apoyo que necesitas para alcanzar tus objetivos.\nNo dudes en explorar todas las funciones y recursos disponibles.\nEstamos aquí para ayudarte en cada paso del camino.\n\n";
	cout << "¿Comenzamos? :D\n\n\n";
	//FIN BIENVENIDA
	Lista agenda;

	cout << "|°|°|°|°|°|°|°|°|~MENÚ~|°|°|°|°|°|°|°|°|\n\n";
	cout << "1. Agregar Contacto\n";
	cout << "2. Editar Contacto\n";
	cout << "3. Eliminar Contacto\n";
	cout << "4. Buscar Contacto\n";
	cout << "5. Guardar Contactos\n";
	cout << "6. Listar Contactos\n\n";
	cout << "7. Salir\n\n";
	cout << "Contactos guardados actualmente: " << agenda.getSize()<<"\n\n";
	cout << "Ingrese opción que desea efectuar. :)\n";
	int opcion ;
	int flag;
	int editado;
	string e;
	getline(cin, e);
	bool c = entrada_num_valida(e);
	while (!c)
	{
		cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
		cout << "Ingrese opción que desea efectuar. :)\n";
		getline(cin, e);
		c = entrada_num_valida(e);
	}
	opcion = stoi(e);
	string dni = "";
	string nombres = "";
	string apellidos = "";
	string direccion = "";
	string x = "";
	unsigned int residencia = 0;
	unsigned int telefono = 0;
	bool valido;
	Contacto *p;
	Nodo* wanted;
	while (opcion!=7){
		switch (opcion){
		
		case 1:
			cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
			getline(cin, x);
			valido = dni_valido(x);
			while (!valido)
			{
				cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
				cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
				getline(cin, x);
				valido = dni_valido(x);
			}
			flag = agenda.getFlag();
			agenda.setFlag(2);
			while (agenda.Busqueda(x) != nullptr)
			{
				cout << "El nuevo DNI ya se encuentra registrado\n";
				cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
				getline(cin, x);
				valido = dni_valido(x);
				while (!valido)
				{
					cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
					cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
					getline(cin, x);
					valido = dni_valido(x);
				}
			}
			dni = x;
			cout << endl;
			agenda.setFlag(flag);

			cout << "Ingrese sus nombres: ";
			getline(cin, x);
			valido = nombre_valido(x);
			while (!valido)
			{
				cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
				cout << "Ingrese sus nombres: ";
				getline(cin, x);
				valido = nombre_valido(x);
			}
			nombres = x;
			cout << endl;

			cout << "Ingrese sus apellidos: ";
			getline(cin, x);
			valido = nombre_valido(x);
			while (!valido)
			{
				cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
				cout << "Ingrese sus apellidos: ";
				getline(cin, x);
				valido = nombre_valido(x);
			}
			flag = agenda.getFlag();
			agenda.setFlag(3);
			while (agenda.Busqueda(x) != nullptr)
			{
				cout << "El nuevo apellido ya se encuentra registrado\n";
				cout << "Ingrese sus apellidos: ";
				getline(cin, x);
				valido = nombre_valido(x);
				while (!valido)
				{
					cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
					cout << "Ingrese sus apellidos: ";
					getline(cin, x);
					valido = nombre_valido(x);
				}
			}
			apellidos = x;
			cout << endl;
			agenda.setFlag(flag);

			cout << "Ingrese su dirección: ";
			getline(cin, direccion);
			cout << endl;

			cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
			getline(cin, x);
			valido = num_valido(x);
			while (!valido)
			{
				cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
				cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
				getline(cin, x);
				valido = num_valido(x);
			}
			residencia = stoi(x);
			cout << endl;

			cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
			getline(cin, x);
			valido = num_valido(x);
			while (!valido)
			{
				cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
				cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
				getline(cin, x);
				valido = num_valido(x);
			}
			flag = agenda.getFlag();
			agenda.setFlag(1);
			while (agenda.Busqueda(x) != nullptr)
			{
				cout << "El nuevo teléfono ya se encuentra registrado\n";
				cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
				getline(cin, x);
				valido = num_valido(x);
				while (!valido)
				{
					cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
					cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
					getline(cin, x);
					valido = num_valido(x);
				}
			}
			telefono = stoi(x);
			cout << endl;
			agenda.setFlag(flag);

			p = new Contacto(dni, nombres, apellidos, direccion, residencia, telefono);

			agenda.Insert(p);

			break;//FIN DEL CASO 1

		case 2:
			cout << "1. Teléfono\n";
			cout << "2. DNI\n";
			cout << "3. Apellidos\n\n";
			cout << "4. Salir\n";
			cout << "Decida cuál campo usará para buscar.\n";
			cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
			cout << "Campo a seleccionar: ";
			int buscar;
			getline(cin, e);
			c = entrada_num_valida(e);
			while (!c)
			{
				cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
				cout << "Ingrese opción que desea efectuar. :)\n";
				getline(cin, e);
				c = entrada_num_valida(e);
			}
			buscar = stoi(e);
			while (buscar != 4)
			{
				if (buscar == 1)
				{
					agenda.setFlag(1);
					agenda.MergeSort();
					cout << "Ingrese el número de teléfono movil de la persona a buscar.(Los 8 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = num_valido(x);
					while (!valido)
					{
						cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
						cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = num_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante el Número Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";

						cout << "Campos Editables\n\n";
						cout << "1. Nombre\n";
						cout << "2. Apellido\n";
						cout << "3. DNI\n";
						cout << "4. Dirección\n";
						cout << "5. Residencia\n";
						cout << "6. Teléfono\n";
						cout << "7. Todos\n\n";
						cout << "8. Salir\n\n";
						cout << "¿Qué tipo de edición realizará?: ";
						getline(cin, x);
						c = entrada_num_valida(x);
						while (!c)
						{
							cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
							cout << "Ingrese opción que desea efectuar. :)\n";
							getline(cin, x);
							c = entrada_num_valida(x);
						}
						editado = stoi(x);
						while (editado!=8){
							switch (editado){

							case 1:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								break;

							case 2:
								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x)!=nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 3:
								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 4:
								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;
								break;

							case 5:
								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;
								break;

							case 6:
								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 7:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;

								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;

								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							default:
								cout << "Te reto a volverte a equivocar >:(\n";
								cout << "Vuelve a intentarlo\n\n";
								break;

							}//FIN SWITCH OPCIONES A EDITAR


							cout << "Campos Editables\n\n";
							cout << "1. Nombre\n";
							cout << "2. Apellido\n";
							cout << "3. DNI\n";
							cout << "4. Dirección\n";
							cout << "5. Residencia\n";
							cout << "6. Teléfono\n";
							cout << "7. Todos\n\n";
							cout << "8. Salir\n\n";
							cout << "¿Qué tipo de edición realizará?: ";
							getline(cin, x);
							c = entrada_num_valida(x);
							while (!c)
							{
								cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
								cout << "Ingrese opción que desea efectuar. :)\n";
								getline(cin, x);
								c = entrada_num_valida(x);
							}
							editado = stoi(x);
						}//FIN WHILE OPCIONES A EDITAR
					}
					else {
						cout << "El número ingresado fue equivocado o no existe tal contacto registrado con ese número\n\n";
					}
					agenda.MergeSort();
					agenda.guardarArchivo();
					agenda.guardarFlag();
				}
				else if (buscar == 3)
				{
					agenda.setFlag(3);
					agenda.MergeSort();
					cout << "Ingrese sus apellidos: ";
					getline(cin, x);
					valido = nombre_valido(x);
					while (!valido)
					{
						cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						cout << "Ingrese sus apellidos: ";
						getline(cin, x);
						valido = nombre_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante el Apellido Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";


						cout << "Campos Editables\n\n";
						cout << "1. Nombre\n";
						cout << "2. Apellido\n";
						cout << "3. DNI\n";
						cout << "4. Dirección\n";
						cout << "5. Residencia\n";
						cout << "6. Teléfono\n";
						cout << "7. Todos\n\n";
						cout << "8. Salir\n\n";
						cout << "¿Qué tipo de edición realizará?: ";
						getline(cin, x);
						c = entrada_num_valida(x);
						while (!c)
						{
							cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
							cout << "Ingrese opción que desea efectuar. :)\n";
							getline(cin, x);
							c = entrada_num_valida(x);
						}
						editado = stoi(x);
						while (editado != 8) {
							switch (editado) {

							case 1:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								break;

							case 2:
								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 3:
								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 4:
								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;
								break;

							case 5:
								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;
								break;

							case 6:
								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 7:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;

								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;

								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							default:
								cout << "Te reto a volverte a equivocar >:(\n";
								cout << "Vuelve a intentarlo\n\n";
								break;

							}//FIN SWITCH OPCIONES A EDITAR


							cout << "Campos Editables\n\n";
							cout << "1. Nombre\n";
							cout << "2. Apellido\n";
							cout << "3. DNI\n";
							cout << "4. Dirección\n";
							cout << "5. Residencia\n";
							cout << "6. Teléfono\n";
							cout << "7. Todos\n\n";
							cout << "8. Salir\n\n";
							cout << "¿Qué tipo de edición realizará?: ";
							getline(cin, x);
							c = entrada_num_valida(x);
							while (!c)
							{
								cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
								cout << "Ingrese opción que desea efectuar. :)\n";
								getline(cin, x);
								c = entrada_num_valida(x);
							}
							editado = stoi(x);
						}//FIN WHILE OPCIONES A EDITAR
					}
					else {
						cout << "El DNI ingresado fue equivocado o no existe tal contacto registrado con ese DNI\n\n";
					}
					agenda.MergeSort();
					agenda.guardarArchivo();
					agenda.guardarFlag();
				}
				else if (buscar == 2)
				{
					agenda.Bubble();
					cout << "Ingrese el número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = dni_valido(x);
					while (!valido)
					{
						cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
						cout << "Ingrese su número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = dni_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante los DNI Ingresados\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";


						cout << "Campos Editables\n\n";
						cout << "1. Nombre\n";
						cout << "2. Apellido\n";
						cout << "3. DNI\n";
						cout << "4. Dirección\n";
						cout << "5. Residencia\n";
						cout << "6. Teléfono\n";
						cout << "7. Todos\n\n";
						cout << "8. Salir\n\n";
						cout << "¿Qué tipo de edición realizará?: ";
						getline(cin, x);
						c = entrada_num_valida(x);
						while (!c)
						{
							cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
							cout << "Ingrese opción que desea efectuar. :)\n";
							getline(cin, x);
							c = entrada_num_valida(x);
						}
						editado = stoi(x);
						while (editado != 8) {
							switch (editado) {

							case 1:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								break;

							case 2:
								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 3:
								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 4:
								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;
								break;

							case 5:
								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;
								break;

							case 6:
								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							case 7:
								cout << "Ingrese sus nombres: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de nombre no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus nombres: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								nombres = x;
								wanted->getContacto()->setNombres(nombres);
								cout << endl;

								cout << "Ingrese sus apellidos: ";
								getline(cin, x);
								valido = nombre_valido(x);
								while (!valido)
								{
									cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(3);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo apellido ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = nombre_valido(x);
									while (!valido)
									{
										cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
										cout << "Ingrese sus apellidos: ";
										getline(cin, x);
										valido = nombre_valido(x);
									}
								}
								apellidos = x;
								wanted->getContacto()->setApellidos(apellidos);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = dni_valido(x);
								while (!valido)
								{
									cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = dni_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(2);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo DNI ya se encuentra registrado\n";
									cout << "Ingrese sus apellidos: ";
									getline(cin, x);
									valido = dni_valido(x);
									while (!valido)
									{
										cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
										cout << "Ingrese su número de identificación (Los 13 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = dni_valido(x);
									}
								}
								dni = x;
								wanted->getContacto()->setDNI(dni);
								cout << endl;
								agenda.setFlag(flag);

								cout << "Ingrese su dirección: ";
								getline(cin, direccion);
								wanted->getContacto()->setDireccion(direccion);
								cout << endl;

								cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono residencial no permitido, intente nuevamente. :(\n";
									cout << "Ingrese su número de teléfono residencial (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								residencia = stoi(x);
								wanted->getContacto()->setResidencia(residencia);
								cout << endl;

								cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
								getline(cin, x);
								valido = num_valido(x);
								while (!valido)
								{
									cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
								}
								flag = agenda.getFlag();
								agenda.setFlag(1);
								while (agenda.Busqueda(x) != nullptr)
								{
									cout << "El nuevo teléfono ya se encuentra registrado\n";
									cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
									getline(cin, x);
									valido = num_valido(x);
									while (!valido)
									{
										cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
										cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones): ";
										getline(cin, x);
										valido = num_valido(x);
									}
								}
								telefono = stoi(x);
								wanted->getContacto()->setTelefono(telefono);
								cout << endl;
								agenda.setFlag(flag);
								break;

							default:
								cout << "Te reto a volverte a equivocar >:(\n";
								cout << "Vuelve a intentarlo\n\n";
								break;

							}//FIN SWITCH OPCIONES A EDITAR


							cout << "Campos Editables\n\n";
							cout << "1. Nombre\n";
							cout << "2. Apellido\n";
							cout << "3. DNI\n";
							cout << "4. Dirección\n";
							cout << "5. Residencia\n";
							cout << "6. Teléfono\n";
							cout << "7. Todos\n\n";
							cout << "8. Salir\n\n";
							cout << "¿Qué tipo de edición realizará?: ";
							getline(cin, x);
							c = entrada_num_valida(x);
							while (!c)
							{
								cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
								cout << "Ingrese opción que desea efectuar. :)\n";
								getline(cin, x);
								c = entrada_num_valida(x);
							}
							editado = stoi(x);
						}//FIN WHILE OPCIONES A EDITAR
					}
					else {
						cout << "El Apellido ingresado fue equivocado o no existe tal contacto registrado con esos Apellidos\n\n";
					}
					agenda.Bubble();
					agenda.guardarArchivo();
					agenda.guardarFlag();
				}
				else {
					cout << "Ya me cansé de decirte que elijas bien tu opción  D:<\n\n";
				}


				cout << "1. Teléfono\n";
				cout << "2. DNI\n";
				cout << "3. Apellidos\n\n";
				cout << "4. Salir\n";
				cout << "Decida cuál campo usará para buscar.\n";
				cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
				cout << "Campo a seleccionar: ";
				getline(cin, e);
				c = entrada_num_valida(e);
				while (!c)
				{
					cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
					cout << "Ingrese opción que desea efectuar. :)\n";
					getline(cin, e);
					c = entrada_num_valida(e);
				}
				buscar = stoi(e);
				
			}
			break;//FIN DEL CASO 2 EDITAR

		case 3:
			cout << "1. Teléfono\n";
			cout << "2. DNI\n";
			cout << "3. Apellidos\n\n";
			cout << "4. Salir\n";
			cout << "Decida cuál campo usará para buscar.\n";
			cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
			cout << "Campo a seleccionar: ";
			getline(cin, e);
			c = entrada_num_valida(e);
			while (!c)
			{
				cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
				cout << "Ingrese opción que desea efectuar. :)\n";
				getline(cin, e);
				c = entrada_num_valida(e);
			}
			buscar = stoi(e);
			while (buscar != 4)
			{
				if (buscar == 1)
				{
					agenda.setFlag(1);
					agenda.MergeSort();
					cout << "Ingrese el número de teléfono movil de la persona a buscar.(Los 8 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = num_valido(x);
					while (!valido)
					{
						cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
						cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = num_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante el Número Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
						agenda.Eliminar(x);
						agenda.guardarArchivo();
						agenda.guardarFlag();
					}
					else {
						cout << "El número ingresado fue equivocado o no existe tal contacto registrado con ese número\n\n";
					}

				}
				else if (buscar == 3)
				{
					agenda.setFlag(3);
					agenda.MergeSort();
					cout << "Ingrese sus apellidos: ";
					getline(cin, x);
					valido = nombre_valido(x);
					while (!valido)
					{
						cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						cout << "Ingrese sus apellidos: ";
						getline(cin, x);
						valido = nombre_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante el DNI Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
						agenda.Eliminar(x);
						agenda.guardarArchivo();
						agenda.guardarFlag();
					}
					else {
						cout << "El DNI ingresado fue equivocado o no existe tal contacto registrado con ese DNI\n\n";
					}
				}
				else if (buscar == 2)
				{
					agenda.Bubble();
					cout << "Ingrese el número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = dni_valido(x);
					while (!valido)
					{
						cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
						cout << "Ingrese su número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = dni_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante los Apellidos Ingresados\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
						agenda.Eliminar(x);
						agenda.guardarArchivo();
						agenda.guardarFlag();
					}
					else {
						cout << "El Apellido ingresado fue equivocado o no existe tal contacto registrado con esos Apellidos\n\n";
					}
				}
				else {
					cout << "Ya me cansé de decirte que elijas bien tu opción  D:<\n\n";
				}


				cout << "1. Teléfono\n";
				cout << "2. DNI\n";
				cout << "3. Apellidos\n\n";
				cout << "4. Salir\n";
				cout << "Decida cuál campo usará para buscar.\n";
				cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
				cout << "Campo a seleccionar: ";
				getline(cin, e);
				c = entrada_num_valida(e);
				while (!c)
				{
					cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
					cout << "Ingrese opción que desea efectuar. :)\n";
					getline(cin, e);
					c = entrada_num_valida(e);
				}
				buscar = stoi(e);
			}
			break;//FIN DEL CASO 3 ELIMINAR

		case 4:
			cout << "1. Teléfono\n";
			cout << "2. DNI\n";
			cout << "3. Apellidos\n\n";
			cout << "4. Salir\n";
			cout << "Decida cuál campo usará para buscar.\n";
			cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
			cout << "Campo a seleccionar: ";
			getline(cin, e);
			c = entrada_num_valida(e);
			while (!c)
			{
				cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
				cout << "Ingrese opción que desea efectuar. :)\n";
				getline(cin, e);
				c = entrada_num_valida(e);
			}
			buscar = stoi(e);
			while (buscar!=4)
			{
				if (buscar==1)
				{
					agenda.setFlag(1);
					agenda.MergeSort();
					cout << "Ingrese el número de teléfono movil de la persona a buscar.(Los 8 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = num_valido(x);
					while (!valido)
					{
						cout << "Formato de teléfono móvil no permitido, intente nuevamente.\n";
						cout << "Ingrese su número de teléfono movil (Los 8 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = num_valido(x);
					}
					wanted=agenda.Busqueda(x);

					if (wanted!=nullptr){
						cout << "Nodo Encontrado Mediante el Número Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
					}
					else {
						cout << "El número ingresado fue equivocado o no existe tal contacto registrado con ese número\n\n";
					}
					
				}
				else if(buscar == 3)
				{
					agenda.setFlag(3);
					agenda.MergeSort();
					cout << "Ingrese sus apellidos: ";
					getline(cin, x);
					valido = nombre_valido(x);
					while (!valido)
					{
						cout << "Formato de apellido no permitido, intente nuevamente. :(\n";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						cout << "Ingrese sus apellidos: ";
						getline(cin, x);
						valido = nombre_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante el DNI Ingresado\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
					}
					else {
						cout << "El DNI ingresado fue equivocado o no existe tal contacto registrado con ese DNI\n\n";
					}
				}
				else if (buscar == 2)
				{
					agenda.Bubble();
					cout << "Ingrese el número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
					cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
					getline(cin, x);
					valido = dni_valido(x);
					while (!valido)
					{
						cout << "Formato de DNI no permitido, intente nuevamente. :(\n";
						cout << "Ingrese su número de identificación a buscar (Los 13 dígitos sin espacios ni guiones):\n ";
						cout << "Al tratarse de una búsqueda, sea preciso con el dato\n";
						getline(cin, x);
						valido = dni_valido(x);
					}
					wanted = agenda.Busqueda(x);

					if (wanted != nullptr) {
						cout << "Nodo Encontrado Mediante los Apellidos Ingresados\n\n";
						cout << "Nombre: " << wanted->getContacto()->getNombres() << "\n";
						cout << "Apellidos: " << wanted->getContacto()->getApellidos() << "\n";
						cout << "DNI: " << wanted->getContacto()->getDNI() << "\n";
						cout << "Dirección: " << wanted->getContacto()->getDireccion() << "\n";
						cout << "Teléfono Móvil: " << wanted->getContacto()->getTelefono() << "\n";
						cout << "Teléfono Residencial: " << wanted->getContacto()->getResidencia() << "\n\n";
					}
					else {
						cout << "El Apellido ingresado fue equivocado o no existe tal contacto registrado con esos Apellidos\n\n";
					}
				}
				else {
					cout << "Ya me cansé de decirte que elijas bien tu opción  D:<\n\n";
				}


				cout << "1. Teléfono\n";
				cout << "2. DNI\n";
				cout << "3. Apellidos\n\n";
				cout << "4. Salir\n";
				cout << "Decida cuál campo usará para buscar.\n";
				cout << "Cabe recalcar que el campo el cual elija será el nuevo criterio de ordenamiento por el cual estará regida la agenda\n\n";
				cout << "Campo a seleccionar: ";
				getline(cin, e);
				c = entrada_num_valida(e);
				while (!c)
				{
					cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
					cout << "Ingrese opción que desea efectuar. :)\n";
					getline(cin, e);
					c = entrada_num_valida(e);
				}
				buscar = stoi(e);
			}
			break;//FIN DEL CASO 4

		case 5:
			agenda.guardarArchivo();
			agenda.guardarFlag();
			break;//FIN DEL CASO 5


		case 6:
			agenda.Impresion();
			break;//FIN CASO 6

		default:
			cout << "Ingresó una opción no válida dentro del rango de 1 a 7 >:(\n\n";
			break;//FIN DEL CASO DEFAULT

		}//FIN DEL SWITCH

		cout << "|°|°|°|°|°|°|°|°|~MENÚ~|°|°|°|°|°|°|°|°|\n\n";
		cout << "1. Agregar Contacto\n";
		cout << "2. Editar Contacto\n";
		cout << "3. Eliminar Contacto\n";
		cout << "4. Buscar Contacto\n";
		cout << "5. Guardar Contactos\n";
		cout << "6. Listar Contactos\n\n";
		cout << "7. Salir\n";
		cout << "Ingrese opción que desea efectuar. :)\n";
		getline(cin, e);
		c = entrada_num_valida(e);
		while (!c)
		{
			cout << "Entrada debe ser un número entero, intente nuevamente. :(\n";
			cout << "Ingrese opción que desea efectuar. :)\n";
			getline(cin, e);
			c = entrada_num_valida(e);
		}
		opcion = stoi(e);
		
	}//FIN DEL WHILE
	
	agenda.guardarArchivo();
	agenda.guardarFlag();
}


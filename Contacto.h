#pragma once
#include <string>
using namespace std;

class Contacto{

	string dni="";
	string nombres="";
	string apellidos="";
	string direccion="";
	int residencia=0;
	int telefono=0;

public:

	Contacto(string dni, string nombres, string apellidos, string direccion, int residencia, int telefono);
	Contacto();
	void setDNI(string dni);
	void setNombres(string nombres);
	void setApellidos(string apellidos);
	void setDireccion(string direccion);
	void setResidencia(int residencia);
	void setTelefono(int telefono);
	string getDNI();
	string getNombres();
	string getApellidos();
	string getDireccion();
	int getResidencia();
	int getTelefono();
};


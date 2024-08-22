#pragma once
#include <string>
using namespace std;

class Contacto{

	int dni=0;
	string nombres="";
	string apellidos="";
	string direccion="";
	int residencia=0;
	int telefono=0;

public:

	Contacto(int dni, string nombres, string apellidos, string direccion, int residencia, int telefono);
	Contacto();
	void setDNI(int dni);
	void setNombres(string nombres);
	void setApellidos(string apellidos);
	void setDireccion(string direccion);
	void setResidencia(int residencia);
	void setTelefono(int telefono);
	int getDNI();
	string getNombres();
	string getApellidos();
	string getDireccion();
	int getResidencia();
	int getTelefono();
};


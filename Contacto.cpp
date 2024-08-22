#include "Contacto.h"
Contacto::Contacto(int dni, string nombres, string apellidos, string direccion, int residencia, int telefono) {
	this->dni = dni;
	this->nombres = nombres;
	this->apellidos = apellidos;
	this->direccion = direccion;
	this->residencia = residencia;
	this->telefono = telefono;
}

Contacto::Contacto() {
	this->dni = 0;
	this->nombres = "";
	this->apellidos = "";
	this->direccion = "";
	this->residencia = 0;
	this->telefono = 0;
}

void Contacto::setDNI(int dni) {
	this->dni = dni;
}

void Contacto::setNombres(string nombres) {
	this->nombres = nombres;
}

void Contacto::setApellidos(string apellidos) {
	this->apellidos = apellidos;
}

void Contacto::setDireccion(string direccion) {
	this->direccion = direccion;
}

void Contacto::setResidencia(int residencia) {
	this->residencia = residencia;
}

void Contacto::setTelefono(int telefono) {
	this->telefono = telefono;
}

int Contacto::getDNI() {
	return dni;
}

string Contacto::getNombres() {
	return nombres;
}

string Contacto::getApellidos() {
	return apellidos;
}

string Contacto::getDireccion() {
	return direccion;
}

int Contacto::getResidencia() {
	return residencia;
}

int Contacto::getTelefono() {
	return telefono;
}

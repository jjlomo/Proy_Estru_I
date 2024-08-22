#pragma once
#include <iostream>
#include "Contacto.h"
#include "Nodo.h"
using namespace std;

class Lista{
	Nodo** head=new Nodo*();
	int flag = 1;
	int size = 0;
public:
	void Insert(Contacto* persona);
	void Impresion();
	void Eliminar();
	void Editar();
	Nodo* Busqueda();
	int Member();
	int isEmpty();
	void guardarArchivo();
	void cargarArchivo();
};


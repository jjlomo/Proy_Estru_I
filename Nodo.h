#pragma once
#include "Contacto.h"
class Nodo{
	Contacto* persona;
	Nodo* next = nullptr;
	Nodo* pred = nullptr;
public:
	Nodo(Contacto* p);
	Nodo();
	Contacto* getContacto();
	Nodo* getNext();
	Nodo* getPred();
	void setNext(Nodo* siguiente);
	void setPred(Nodo* anterior);
};


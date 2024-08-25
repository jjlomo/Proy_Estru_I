#pragma once
#include <iostream>
#include "Contacto.h"
#include "Nodo.h"
#include <fstream>
#include <sstream>
using namespace std;

class Lista{
	Nodo** head = new Nodo * ();
	int flag = 1;
	int size = 0;
	void mergeSort(Nodo* arr[], int left, int right);
	void merge(Nodo* arr[], int left, int mid, int right);
public:
	Lista();
	void Insert(Contacto* persona);
	void Impresion();
	void Eliminar(string campo);
	void Editar(string campo, int x);
	Nodo* Busqueda(string campo);
	int isEmpty();
	void guardarArchivo();
	void cargarArchivo();
	int getSize();
	void Bubble();
	void MergeSort();
	void setFlag(int f);
	int getFlag();
};


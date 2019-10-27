#pragma once
#include "Nodo.h"
#include "Pokemon.h"
class Lista
{
public:
	Nodo* First;
	Nodo* Last;
	void Push(int valor);
	int Pop();
	int Size();
	void LimpiarLista();
	bool IsEmpty();
};

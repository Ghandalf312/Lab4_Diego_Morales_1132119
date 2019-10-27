#pragma once
#include "Nodo.h"
#include "Pokemon.h"
class Lista
{
public:
	Nodo* First;
	Nodo* Last;
	void Push(int valor);
	bool IsEmpty();
};

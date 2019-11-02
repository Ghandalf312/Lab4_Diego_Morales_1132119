#pragma once
#include "Nodo.h"
#include "Pokemon.h"
//#include <iostream>
//#include <string>
//using namespace std;
class Lista
{
public:
	Nodo* First;
	Nodo* Last;
	void Push(int value);
	int Pop();
	int Size();
	void LimpiarLista();
	bool IsEmpty();
};

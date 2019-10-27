#pragma once
#include "Pokemon.h"
class Nodo
{
public:
	Nodo();
	~Nodo();
	Nodo* siguiente;
	Nodo* anterior;
	Pokemon NatNumber;
	Pokemon GenNumber;

};


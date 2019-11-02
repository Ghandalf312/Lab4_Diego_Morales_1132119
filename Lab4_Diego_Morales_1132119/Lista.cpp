#include "Lista.h"
//#include <iostream>
//#include <string>
//using namespace std;
bool Lista::IsEmpty()
{
	return First == nullptr;
}
void Lista::Push(int value) {

	Nodo* NewValue = new Nodo;
	NewValue->NatNumber.NatNumber = value;
	if (IsEmpty())
	{
		First = NewValue;
		Last = NewValue;
		First->anterior = Last;
		Last->siguiente = First;
	}
	else
	{
		NewValue->anterior = Last;//nuevo nodo(anterior) esta apuntando al ultimo
		NewValue->siguiente = First;//nodo nuevo(siguiente) esta apuntando al primero
		First = NewValue;//el puntero 
		Last->siguiente = First;//El elemento agregado apunta al siguiente
		(First->siguiente)->anterior = First;//El elemento ingresado su vuelve el primero
	}
}
int Lista::Pop() {
	if (First != nullptr)
	{
		int x = First->NatNumber.NatNumber;
		Nodo* aux = First;
		First = aux->siguiente;
		delete aux;
		return x;
	}

}
int Lista::Size()
{
	Nodo* NewValue = new Nodo;
	NewValue = First;
	int Cant = 1;
	while (NewValue->siguiente != First)
	{
		Cant++;
		NewValue = NewValue->siguiente;
	}
	return Cant;
}
void Lista::LimpiarLista() 
{
	Nodo* aux = new Nodo();
	First = aux;
	Last = aux;
}
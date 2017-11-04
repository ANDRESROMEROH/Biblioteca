#pragma once
#include "Nodo.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class AVL {
public:
	AVL();
	Nodo<T>* getRaiz();
	int altura(Nodo<T>*);
	int factorEquilibrio(Nodo<T>*);
	Nodo<T>* rotacionDerecha(Nodo<T>*);
	Nodo<T>* rotacionIzquierda(Nodo<T>*);
	Nodo<T>* rotacionDobDerecha(Nodo<T>*);
	Nodo<T>* rotacionDobIzquierda(Nodo<T>*);
	Nodo<T>* balancear(Nodo<T>*);
	Nodo<T>* insertar(Nodo<T>*, T*);
	void preOrden(Nodo<T>*);
	void inOrden(Nodo<T>*);
	void postOrden(Nodo<T>*);

private:
	Nodo<T>* raiz;
};



/////////////////////////| IMPLEMENTACION |/////////////////////////

template<class T>
AVL<T>::AVL() {
	raiz = NULL;
}

template<class T>
Nodo<T>* AVL<T>::getRaiz() { return raiz; }

template<class T>
int AVL<T>::altura(Nodo<T>* nodo) { // i: Izquierda, d: Derecha, h: height "Altura"
	int h = 0;
	if (nodo != NULL)
	{
		int altura_i = altura(nodo->izquierdo);
		int altura_d = altura(nodo->derecho);
		int max_altura = std::max(altura_i, altura_d);
		h = max_altura + 1;
	}
	return h;
}

template<class T>
int AVL<T>::factorEquilibrio(Nodo<T>* nodo) {
	int altura_d = altura(nodo->derecho);
	int altura_i = altura(nodo->izquierdo);
	int factor = altura_d - altura_i;
	return factor;
}

template<class T>
Nodo<T>* AVL<T>::rotacionDerecha(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->izquierdo;
	nodo->izquierdo = aux->derecho;
	aux->derecho = nodo;

	return aux;
}

template<class T>
Nodo<T>* AVL<T>::rotacionIzquierda(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->derecho;
	nodo->derecho = aux->izquierdo;
	aux->izquierdo = nodo;

	return aux;
}

template<class T>
Nodo<T>* AVL<T>::rotacionDobDerecha(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->derecho;
	nodo->derecho = rotacionDerecha(aux);

	return rotacionIzquierda(nodo);
}

template<class T>
Nodo<T>* AVL<T>::rotacionDobIzquierda(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->izquierdo;
	nodo->derecho = rotacionIzquierda(aux);

	return rotacionDerecha(nodo);
}

template<class T>
Nodo<T>* AVL<T>::balancear(Nodo<T>* temp) {
	int bal_factor = this->factorEquilibrio(temp);
	if (bal_factor > 1)//DD IS
	{
		if (factorEquilibrio(temp->derecho) > 0)//IS
			temp = this->rotacionIzquierda(temp);
		else
			temp = this->rotacionDobDerecha(temp);//DD
	}
	else if (bal_factor < -1)//DS DI
	{
		if (factorEquilibrio(temp->izquierdo) > 0)//DI
			temp = this->rotacionDobIzquierda(temp);
		else
			temp = this->rotacionDerecha(temp);//DS
	}
	return temp;
}

template<class T>
Nodo<T>* AVL<T>::insertar(Nodo<T>* nodo, T* dato)
{
	if (raiz == NULL) {
		raiz = new Nodo<T>(dato, NULL, NULL);
		return nodo;
	}
	else {

		if (nodo == NULL)//si no hay nada
		{
			cout << "si es null" << endl;
			nodo = new Nodo<T>(dato, NULL, NULL);
			return nodo;
		}

		else if (*dato < *(nodo->getContenido()))//si es menor
		{
			cout << "si es menor" << endl;
			nodo->izquierdo = insertar(nodo->izquierdo, dato);
			nodo = this->balancear(nodo);
		}
		else if (*dato >= *(nodo->getContenido()))//si es mayor
		{
			cout << "si es mayor" << endl;
			nodo->derecho = insertar(nodo->derecho, dato);
			nodo = this->balancear(nodo);
		}
	}
		return nodo;
	}


/*OPERADOR << SOBRECARGADO*/

template<class T>
void AVL<T>::preOrden(Nodo<T>* nodo) { // raiz, izquierda, Derecha
	if (nodo != NULL) {
		cout << nodo->getContenido()->getTipo() << ",";
		preOrden(nodo->izquierdo);
		preOrden(nodo->derecho);
	}
}


template<class T>
void AVL<T>::inOrden(Nodo<T>* nodo) {// Izquierdo, raiz, derecha
	if (nodo != NULL) {
		inOrden(nodo->izquierdo);
		cout << nodo->getContenido()->getTipo() << ",";
		inOrden(nodo->derecho);
	}
}


template<class T>
void AVL<T>::postOrden(Nodo<T>* nodo) {//izquierda,derecha,raiz
	if (nodo != NULL) {
		postOrden(nodo->izquierdo);
		postOrden(nodo->derecho);
		cout << nodo->getContenido()->getTipo() << ",";
	}
}

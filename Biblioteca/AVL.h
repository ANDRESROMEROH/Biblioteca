#pragma once
#include "Nodo.h"

template<class T>
class AVL {
public:
	AVL();
	int altura(Nodo<T>*);
	int factorEquilibrio(Nodo<T>*);
	Nodo<T>* rotacionDerecha(Nodo<T>*);
	Nodo<T>* rotacionIzquierda(Nodo<T>*);
	Nodo<T>* rotacionDobDerecha(Nodo<T>*);
private:
	Nodo<T> raiz;
};

/////////////////////////| IMPLEMENTACION |/////////////////////////

template<class T>
AVL<T>::AVL() {
	
}

template<class T>
int AVL<T>::altura(Nodo<T>* nodo) { // i: Izquierda, d: Derecha, h: height "Altura"
	int h = 0;
	if (nodo != NULL)
	{
		int altura_i = altura(nodo->izquierdo);
		int altura_d = altura(nodo->derecho);
		int max_altura = max(altura_i, altura_d);
		h = max_altura + 1;
	}
	return h;
}

template<class T>
int AVL<T>::factorEquilibrio(Nodo<T>* nodo) {
	int altura_i = altura(nodo->izquierdo);
	int altura_d = altura(nodo->derecho);
	int factor = altura_i - altura_d;

	return factor;
}

template<class T>
Nodo<T>* AVL<T>::rotacionDerecha(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->derecho;
	nodo->derecho = aux->izquierdo;
	aux->izquierdo = nodo;

	return aux;
}

template<class T>
Nodo<T>* AVL<T>::rotacionIzquierda(Nodo<T>* nodo) {
	Nodo<T>* aux;
	aux = nodo->izquierdo;
	nodo->izquierdo = aux->derecho;
	aux->derecho = nodo;

	return aux;
}


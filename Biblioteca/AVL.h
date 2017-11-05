#pragma once
#include "Nodo.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

template <class T>
class AVL {
public:
	AVL();
	bool insertar(T*);
	void borrar(const T*);
	Nodo<T>* getRaiz();

	Nodo<T>* rotacionIzquierda(Nodo<T>*);
	Nodo<T>* rotacionDerecha(Nodo<T>*);
	Nodo<T>* rotacionDobDerecha(Nodo<T>*);
	Nodo<T>* rotacionDobIzquierda(Nodo<T>*);

	void rebalancear(Nodo<T>*);
	int altura(Nodo<T>*);
	void setBalance(Nodo<T>*);

	void AVL<T>::preOrden(Nodo<T>* nodo);
	void AVL<T>::inOrden(Nodo<T>* nodo);
	void AVL<T>::postOrden(Nodo<T>* nodo);

	//Funciones no genericas:

	list<T*> busquedaTipo(Nodo<T>*,list<T*>,int);
	list<T*> busquedaAutor(Nodo<T>*, list<T*>, string);
	list<T*> busquedaNombre(Nodo<T>*, list<T*>, string);
	list<T*> busquedaCodigo(Nodo<T>*, list<T*>, int);

	bool completo(Nodo<T>*);
	bool perfecto();
	bool lleno();
	int nivel();
	int peso();

private:
	Nodo<T> *raiz;
};



/////////////////////////| IMPLEMENTACION |/////////////////////////

template<class T>
AVL<T>::AVL() {
	raiz = NULL;
}

template<class T>
Nodo<T>* AVL<T>::getRaiz() { return raiz; }

template <class T>
void AVL<T>::rebalancear(Nodo<T> *nodo) {
	setBalance(nodo);

	if (nodo->getFactorEquilibrio() == -2) {
		if (altura(nodo->izquierda->izquierda) >= altura(nodo->izquierda->derecho))
			nodo = this->rotacionDerecha(nodo);
		else
			nodo = this->rotacionDobIzquierda(nodo);
	}
	else if (nodo->getFactorEquilibrio() == 2) {
		if (altura(nodo->derecho->derecho) >= altura(nodo->derecho->izquierda))
			nodo = this->rotacionIzquierda(nodo);
		else
			nodo = this->rotacionDobDerecha(nodo);
	}

	if (nodo->padre != NULL) {
		this->rebalancear(nodo->padre);
	}
	else {
		raiz = nodo;
	}
}


template <class T>
Nodo<T>* AVL<T>::rotacionIzquierda(Nodo<T> *nodo) {
	Nodo<T> *aux = nodo->derecho;
	aux->padre = nodo->padre;
	nodo->derecho = aux->izquierda;

	if (nodo->derecho != NULL)
		nodo->derecho->padre = nodo;

	aux->izquierda = nodo;
	nodo->padre = aux;

	if (aux->padre != NULL) {
		if (aux->padre->derecho == nodo) {
			aux->padre->derecho = aux;
		}
		else {
			aux->padre->izquierda = aux;
		}
	}

	setBalance(nodo);
	setBalance(aux);
	return aux;
}

template <class T>
Nodo<T>* AVL<T>::rotacionDerecha(Nodo<T> *nodo) {
	Nodo<T> *aux = nodo->izquierda;
	aux->padre = nodo->padre;
	nodo->izquierda = aux->derecho;

	if (nodo->izquierda != NULL)
		nodo->izquierda->padre = nodo;

	aux->derecho = nodo;
	nodo->padre = aux;

	if (aux->padre != NULL) {
		if (aux->padre->derecho == nodo) {
			aux->padre->derecho = aux;
		}
		else {
			aux->padre->izquierda = aux;
		}
	}

	setBalance(nodo);
	setBalance(aux);
	return aux;
}

template <class T>
Nodo<T>* AVL<T>::rotacionDobIzquierda(Nodo<T> *nodo) {
	nodo->izquierda = rotacionIzquierda(nodo->izquierda);
	return rotacionDerecha(nodo);
}

template <class T>
Nodo<T>* AVL<T>::rotacionDobDerecha(Nodo<T> *nodo) {
	nodo->derecho = rotacionDerecha(nodo->derecho);
	return rotacionIzquierda(nodo);
}

template <class T>
int AVL<T>::altura(Nodo<T> *nodo) {
	if (nodo == NULL)
		return -1;
	return 1 + std::max(altura(nodo->izquierda), altura(nodo->derecho));
}

template <class T>
void AVL<T>::setBalance(Nodo<T> *nodo) {
	nodo->setFactorEquilibrio(altura(nodo->derecho) - altura(nodo->izquierda));
}

template <class T>
bool AVL<T>::insertar(T* dato) {
	if (raiz == NULL) {
		raiz = new Nodo<T>(dato, NULL,NULL,NULL);
	}
	else {
		Nodo<T> * n = raiz,*padre;
		while (true) {
			if (*(n->getContenido()) == *dato)
				return false;
			padre = n;

			bool izquierda = *(n->getContenido()) > *dato;
			n = izquierda ? n->izquierda : n->derecho;

			if (n == NULL) {
				if (izquierda) {
					padre->izquierda = new Nodo<T>(dato, padre,NULL,NULL);
				}
				else {
					padre->derecho = new Nodo<T>(dato, padre,NULL,NULL);
				}

this->rebalancear(padre);
break;
			}
		}
	}

	return true;
}

template <class T>
void AVL<T>::borrar(const T* dato) {
	if (raiz == NULL)
		return;

	Nodo<T>* n = raiz;
	Nodo<T>* padre = raiz;
	Nodo<T>* borrarNodo = NULL;
	Nodo<T>* hijo = raiz;

	while (hijo != NULL) {
		padre = n;
		n = hijo;
		hijo = dato >= n->getContenido() ? n->derecho : n->izquierda;
		if (dato == n->getContenido())
			borrarNodo = n;
	}

	if (dato != NULL) {
		borrarNodo->getContenido() = n->getContenido();

		hijo = n->izquierda != NULL ? n->izquierda : n->derecho;

		if (raiz->getContenido() == dato) {
			raiz = hijo;
		}
		else {
			if (padre->izquieda == n) {
				padre->izquierda = hijo;
			}
			else {
				padre->derecho = hijo;
			}
			this->rebalancear(padre);
		}
	}
}

template<class T>
list<T*> AVL<T>::busquedaTipo(Nodo<T>* nodo, list<T*> list, int tipo) {
	if (nodo != NULL) {
		if (nodo->getContenido()->getTipo() == tipo) {
			list.push_back(nodo->getContenido());
		}
		list = busquedaTipo(nodo->izquierda, list, tipo);
		list = busquedaTipo(nodo->derecho, list, tipo);
	}
	return list;
}

template<class T>
list<T*> AVL<T>::busquedaAutor(Nodo<T>* nodo, list<T*> list, string autor) {
	if (nodo != NULL) {
		if (autor.compare(nodo->getContenido()->getAutor()) == 0) {
			list.push_back(nodo->getContenido());
		}
		list = busquedaAutor(nodo->izquierda, list, autor);
		list = busquedaAutor(nodo->derecho, list, autor);
	}
	return list;
}

template<class T>
list<T*> AVL<T>::busquedaNombre(Nodo<T>* nodo, list<T*> list, string nombre) {
	if (nodo != NULL) {
		if (nombre.compare(nodo->getContenido()->getNombre()) == 0) {
			list.push_back(nodo->getContenido());
		}
		list = busquedaNombre(nodo->izquierda, list, nombre);
		list = busquedaNombre(nodo->derecho, list, nombre);
	}
	return list;
}

template<class T>
list<T*> AVL<T>::busquedaCodigo(Nodo<T>* nodo, list<T*> list, int codigo) {
	if (nodo != NULL) {
		if (stoi(nodo->getContenido()->getCodigo()) == codigo) {
			list.push_back(nodo->getContenido());
		}
		list = busquedaCodigo(nodo->izquierda, list, codigo);
		list = busquedaCodigo(nodo->derecho, list, codigo);
	}
	return list;
}


template <class T>
bool AVL<T>::completo(Nodo<T> *nodo) {
	if (nodo == NULL) {
		return true;
	}
	if (altura(nodo->izquierda) != altura(nodo->derecho)){
		return false;
	}
	else {
		return completo(nodo->izquierda) == completo(nodo->izquierda);
	}
}


template<class T>
void AVL<T>::preOrden(Nodo<T>* nodo) { // raiz, izquierda, Derecha
	if (nodo != NULL) {
		cout << *nodo <<endl;
		preOrden(nodo->izquierda);
		preOrden(nodo->derecho);
	}
}


template<class T>
void AVL<T>::inOrden(Nodo<T>* nodo) {// Izquierdo, raiz, derecha
	if (nodo != NULL) {
		inOrden(nodo->izquierda);
		cout << nodo->getContenido()->getTipo() << ",";
		inOrden(nodo->derecho);
	}
}


template<class T>
void AVL<T>::postOrden(Nodo<T>* nodo) {//izquierda,derecha,raiz
	if (nodo != NULL) {
		postOrden(nodo->izquierda);
		postOrden(nodo->derecho);
		cout << *nodo->getContenido() << ",";
	}
}

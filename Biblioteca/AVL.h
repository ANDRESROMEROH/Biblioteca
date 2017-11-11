#pragma once
#include "Nodo.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include "Libro.h"
using namespace std;

template <class T>
class AVL {
public:
	AVL();
	AVL(istream&);
	void guardar(ostream&, Nodo<T>*);
	bool insertar(T*);
	Nodo<T>* getRaiz();
	int cantidad(Nodo<T>*); // Cantidadd de nodos total.

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
	T* busquedaCodigo(Nodo<T>*, int);

	bool esPerfecto(Nodo<T>*);
	bool esCompleto(Nodo<T>*);
	bool esLleno(Nodo<T>*);
	int nivel(T*, Nodo<T>*);
	int peso();

	void eliminarCodigo(string); //Elimina por codigo.
	void eliminarLibrosTipo(Nodo<T>*, int); //Elimina todos los libros de un mismo tipo

private:
	Nodo<T> *raiz;
};



/////////////////////////| IMPLEMENTACION |/////////////////////////

template<class T>
AVL<T>::AVL() {
	raiz = NULL;
}

template<class T>
AVL<T>::AVL(istream& entrada) {
	raiz = NULL;
	string numaux = " ";getline(entrada, numaux);
	int n = 1;
	int total = atoi(numaux.c_str());
	while (n != total) {
		Libro *l = new Libro(entrada);
		insertar(l);
		n++;
	}
}

template<class T>
Nodo<T>* AVL<T>::getRaiz() {
	return raiz;
}

template<class T>
int AVL<T>::cantidad(Nodo<T>* nodo) {
	if (nodo == NULL) {
		return (0);
	}
	return (1 + cantidad(nodo->izquierdo) + cantidad(nodo->derecho));
}

template <class T>
void AVL<T>::rebalancear(Nodo<T> *nodo) {
	setBalance(nodo);

	if (nodo->getFactorEquilibrio() == -2) {
		if (altura(nodo->izquierdo->izquierdo) >= altura(nodo->izquierdo->derecho))
			nodo = this->rotacionDerecha(nodo);
		else
			nodo = this->rotacionDobIzquierda(nodo);
	}
	else if (nodo->getFactorEquilibrio() == 2) {
		if (altura(nodo->derecho->derecho) >= altura(nodo->derecho->izquierdo))
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
	nodo->derecho = aux->izquierdo;

	if (nodo->derecho != NULL)
		nodo->derecho->padre = nodo;

	aux->izquierdo = nodo;
	nodo->padre = aux;

	if (aux->padre != NULL) {
		if (aux->padre->derecho == nodo) {
			aux->padre->derecho = aux;
		}
		else {
			aux->padre->izquierdo = aux;
		}
	}

	setBalance(nodo);
	setBalance(aux);
	return aux;
}

template <class T>
Nodo<T>* AVL<T>::rotacionDerecha(Nodo<T> *nodo) {
	Nodo<T> *aux = nodo->izquierdo;
	aux->padre = nodo->padre;
	nodo->izquierdo = aux->derecho;

	if (nodo->izquierdo != NULL)
		nodo->izquierdo->padre = nodo;

	aux->derecho = nodo;
	nodo->padre = aux;

	if (aux->padre != NULL) {
		if (aux->padre->derecho == nodo) {
			aux->padre->derecho = aux;
		}
		else {
			aux->padre->izquierdo = aux;
		}
	}

	setBalance(nodo);
	setBalance(aux);
	return aux;
}

template <class T>
Nodo<T>* AVL<T>::rotacionDobIzquierda(Nodo<T> *nodo) {
	nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
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
	return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));
}

template <class T>
void AVL<T>::setBalance(Nodo<T> *nodo) {
	nodo->setFactorEquilibrio(altura(nodo->derecho) - altura(nodo->izquierdo));
}

template <class T>
bool AVL<T>::insertar(T* dato) {
	if (raiz == NULL) {
		raiz = new Nodo<T>(dato, NULL,NULL,NULL);
	}
	else {
		Nodo<T> * n = raiz,*padre;
		while (true) {
			if (*(n->getContenido()) == *dato) {
				return false;
			}
			padre = n;

			bool izquierda = *(n->getContenido()) > *dato;
			n = izquierda ? n->izquierdo : n->derecho;

			if (n == NULL) {
				if (izquierda) {
					padre->izquierdo = new Nodo<T>(dato, padre,NULL,NULL);
				}
				else {
					padre->derecho = new Nodo<T>(dato, padre,NULL,NULL);
				}
				rebalancear(padre);
				break;
			}
		}
	}
	return true;
}

template <class T>
void AVL<T>::eliminarCodigo(string codigo) {
	if (raiz == NULL)
		return;

		Nodo<T> *n = raiz;
		Nodo<T> *padre = raiz;
		Nodo<T> *borrarNodo = NULL;
		Nodo<T> *hijo = raiz;

	while (hijo != NULL) {
		padre = n;
		n = hijo;
		hijo = stoi(codigo) >= stoi(n->getContenido()->getCodigo()) ? n->derecho : n->izquierdo;
		if (stoi(codigo) == stoi(n->getContenido()->getCodigo()))
			borrarNodo = n;
	}

	if (borrarNodo != NULL) {
		borrarNodo->getContenido()->setCodigo(n->getContenido()->getCodigo());

		hijo = n->izquierdo != NULL ? n->izquierdo : n->derecho;

		if (stoi(raiz->getContenido()->getCodigo()) == stoi(codigo)) {
			raiz = hijo;
		}
		else {
			if (padre->izquierdo == n) {
				padre->izquierdo = hijo;
			}
			else {
				padre->derecho = hijo;
			}

			rebalancear(padre);
		}
	}
}

template<class T>
void AVL<T>::eliminarLibrosTipo(Nodo<T>* nodo, int tipo) {
	if (nodo != NULL) {
		if (nodo->getContenido()->getTipo() == tipo) {
			eliminarCodigo(nodo->getContenido()->getCodigo());
		}
			eliminarLibrosTipo(nodo->izquierdo, tipo);
			eliminarLibrosTipo(nodo->derecho, tipo);
	}
	return;
}

template<class T>
list<T*> AVL<T>::busquedaTipo(Nodo<T>* nodo, list<T*> list, int tipo) {
	if (nodo != NULL) {
		if (nodo->getContenido()->getTipo() == tipo) {
			list.push_back(nodo->getContenido());
		}
		list = busquedaTipo(nodo->izquierdo, list, tipo);
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
		list = busquedaAutor(nodo->izquierdo, list, autor);
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
		list = busquedaNombre(nodo->izquierdo, list, nombre);
		list = busquedaNombre(nodo->derecho, list, nombre);
	}
	return list;
}

template<class T>
T* AVL<T>::busquedaCodigo(Nodo<T>* nodo, int codigo) {
	if (nodo != NULL) {
		if (stoi(nodo->getContenido()->getCodigo()) == codigo) {
			return nodo->getContenido();
		}
		busquedaCodigo(nodo->izquierdo, codigo);
		busquedaCodigo(nodo->derecho, codigo);
	}
	if (nodo == NULL)
		return NULL;
}


template <class T>
bool AVL<T>::esPerfecto(Nodo<T> *nodo) {
	if (nodo == NULL) {
		return true;
	}
	if (altura(nodo->izquierdo) != altura(nodo->derecho)){
		return false;
	}
	else {
		return esPerfecto(nodo->izquierdo) == esPerfecto(nodo->izquierdo);
	}
}


template <class T>
bool AVL<T>::esCompleto(Nodo<T>* nodo) {
	if (nodo == NULL) {
		return true;
	}
	// Si los hijos son "NULL"
	if (nodo->izquierdo == NULL && nodo->derecho == NULL) {
		return true;
	}
	// Si los hijos izquierdos y derechos no son "NULL" verifica el resto de subArboles
	if ((nodo->izquierdo) && (nodo->derecho)) {
		return (esCompleto(nodo->izquierdo) && esCompleto(nodo->derecho));
	}

	return false;
}

template<class T>
int AVL<T>::peso() {
	return altura(raiz) - 1;
}


template<class T>
void AVL<T>::preOrden(Nodo<T>* nodo) { // raiz, izquierda, Derecha
	if (nodo != NULL) {
		cout << *nodo <<endl;
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
		cout << *nodo->getContenido() << ",";
	}
}

template<class T>
void AVL<T>::guardar(ostream& salida, Nodo<T>* nodo) {
	//recorrer todo el arbol y guardar la informacion
	if (nodo != NULL) {
		nodo->getContenido()->guardar(salida);
		guardar(salida, nodo->izquierdo);
		guardar(salida, nodo->derecho);
	}
}

template<class T>
bool AVL<T>::esLleno(Nodo<T>* nodo) {
	bool _bool = true;
	if (raiz->derecho == NULL && raiz->izquierdo == NULL) { return true; }
	if (nodo->derecho == NULL && nodo->izquierdo == NULL) { return true; }
	if (nodo->derecho != NULL && nodo->izquierdo != NULL) {
		return esLleno(nodo->derecho) && esLleno(nodo->izquierdo);
	}
	else {
		return false;
	}
}

template<class T>
int AVL<T>::nivel(T* buscar,Nodo<T>* nodo) {//nodo a buscar, nodo iterador
	if (buscar == raiz->getContenido()) { return 0; }
	if (nodo == NULL) { return 0; }
	if (nodo->getContenido() == buscar) { return 0; }
	if (buscar < nodo->getContenido()) {
		return 1 + nivel(buscar, nodo->izquierdo);
	}
	else {
		return 1 + nivel(buscar, nodo->derecho);
	}
}

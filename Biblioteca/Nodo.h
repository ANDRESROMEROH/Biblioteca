#pragma once

template<class T>

class Nodo {
public:
	Nodo(T*, Nodo<T>*, Nodo<T>*);//dato, hijo izquierdo, hijo derecho
	T* getContenido();
	Nodo<T>* getIzquierdo();
	Nodo<T>* getDerecho();
	void setIzquierdo(Nodo<T>*);
	void setDerecho(Nodo<T>*);
private:
	T* contenido;
	Nodo<T>* izquierdo;
	Nodo<T>* derecho;
};

/////////////////////////| IMPLEMENTACION |/////////////////////////
template<class T>
Nodo<T>::Nodo(T* _contenido, Nodo<T>* iz, Nodo<T>* der):contenido(_contenido),
izquierdo(iz),derecho(der){}

template<class T>
T* Nodo<T>::getContenido() { return contenido; }

template<class T>
Nodo<T>* Nodo<T>::getIzquierdo() { return izquierdo; }

template<class T>
Nodo<T>* Nodo<T>::getDerecho() { return derecho; }

template<class T>
void Nodo<T>::setIzquierdo(Nodo<T>* _iz) { izquierdo = _iz; }

template<class T>
void Nodo<T>::setDerecho(Nodo<T>* der) { derecho = der; }

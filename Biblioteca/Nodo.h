#pragma once
using namespace std;

template<class T>
class Nodo {
public:
	Nodo();
	Nodo(T*, Nodo<T>*, Nodo<T>*); // Dato, hijo izquierdo, hijo derecho.
	T* getContenido();
	
	Nodo<T>* izquierdo;
	Nodo<T>* derecho;

private:
	T* contenido;
};

/////////////////////////| IMPLEMENTACION |//////////////////////////

template<class T>
ostream& operator<<(ostream& os, Nodo<T>& t) {
	os << t.getContenido()->toString();
	return os;
}

template<class T>
Nodo<T>::Nodo() {}

template<class T>
Nodo<T>::Nodo(T* _contenido, Nodo<T>* iz, Nodo<T>* der):contenido(_contenido),
izquierdo(iz),derecho(der){}

template<class T>
T* Nodo<T>::getContenido() { return contenido; }

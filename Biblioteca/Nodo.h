#pragma once
using namespace std;

template <class T>
class Nodo {
public:
	Nodo(T*,Nodo<T>*,Nodo<T>*,Nodo<T>*);
	Nodo<T>* izquierda;
	Nodo<T>* derecho;
	Nodo<T>* padre;
	T* getContenido();
	int getFactorEquilibrio();
	void setFactorEquilibrio(int);
private:
	T* contenido;
	int factorEquilibrio;
};

/////////////////////////| IMPLEMENTACION |//////////////////////////

template<class T>
ostream& operator<<(ostream& os, Nodo<T>& t) {
	os << t.getContenido()->toString();
	return os;
}

template<class T>
Nodo<T>::Nodo(T* _contenido, Nodo<T>* _papa, Nodo<T>* _izquierda, Nodo<T>* _derecho):
	contenido(_contenido),izquierda(_izquierda),
	derecho(_derecho),padre(_papa),factorEquilibrio(0){}

template<class T>
T* Nodo<T>::getContenido() { return contenido; }

template<class T>
int Nodo<T>::getFactorEquilibrio() { return this->factorEquilibrio; }

template<class T>
void Nodo<T>::setFactorEquilibrio(int n) { this->factorEquilibrio = n; }

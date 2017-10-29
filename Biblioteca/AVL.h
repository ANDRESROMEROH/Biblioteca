#pragma once
#include "Nodo.h"
/**
Tomado de: http://www.sanfoundry.com/cpp-program-implement-avl-trees/
*/

template<classT>
class AVL {
public:
	AVL();
	int altura(Nodo<T>*);
	int factorEquilibrio(Nodo<T>*);
	Nodo<T>* 
private:
	Nodo<T> raiz;
};

/////////////////////////| IMPLEMENTACION |/////////////////////////

template<class T>
AVL<T>::AVL() {}

template<class T>
int AVL<T>::altura(Nodo<T>* nodo) {
	int h = 0;
	if (nodo != NULL)
	{
		int l_height = height(nodo->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}


#include<iostream>
#include<string>
#include"Libro.h"
#include "Nodo.h"
using namespace std;

void main() {

	string isbn = "9780194129558";

	if (Libro::validarIsbn13(isbn)) {
		cout << "Es un ISBN valido..." << endl << endl;
	}
	else {
		cout << "No es un ISBN valido..." << endl << endl;
	}

	Nodo<Libro>* n = new Nodo<Libro>(new Libro("iT","001","YO","PAYAZO",1),NULL,NULL);
	cout<<n->getContenido()->getAutor() << endl;

	system("pause");
}
#include<iostream>
#include<string>
#include"Libro.h"
#include "Nodo.h"
#include "AVL.h"
using namespace std;

void main() {
	
	AVL<Libro>* avl = new AVL<Libro>();

	string isbn = "9780194129558";

	if (Libro::validarIsbn13(isbn)) {
		cout << "Es un ISBN valido..." << endl << endl;
	}
	else {
		cout << "No es un ISBN valido..." << endl << endl;
	}

	/*Nodo<Libro>* n = new Nodo<Libro>(new Libro("iT","001","YO","PAYAZO",1),NULL,NULL);/*
	Nodo<Libro>* n1 = new Nodo<Libro>(new Libro("iT", "002", "YO", "PAYAZO", 2), NULL, NULL);*/

	Libro* l1 = new Libro("iT", "001", "YO", "PAYAZO", 4);
	Libro* l2 = new Libro("iT", "001", "YO", "PAYAZO", 3);
	Libro* l3 = new Libro("iT", "001", "YO", "PAYAZO", 1);
	avl->insertar(avl->getRaiz(), l1);
	avl->insertar(avl->getRaiz(), l2);
	avl->insertar(avl->getRaiz(), l3);
	avl->postOrden(avl->getRaiz());
	//cout<< *(n->getContenido()) <<" operador<< "<< endl;

	system("pause");
}
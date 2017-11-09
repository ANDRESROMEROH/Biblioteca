#include<iostream>
#include<string>
#include<list>
#include <fstream>
#include"Libro.h"
#include "Nodo.h"
#include "AVL.h"
using namespace std;

void main() {
	
	AVL<Libro> t;

	Libro l1("The Maze Runner","10","James Dashner","Empty",Libro::DE_TEXTO);
	Libro l2("Caperucita", "5", "Justin Toto", "Empty", Libro::DE_TEXTO);
	Libro l3("Cronicas de Narnia", "13", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l4("Matematicas1", "1", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l5("Scorpion", "6", "James Dashner", "Empty", Libro::DE_TEXTO);
	//Libro l6("Mortal Kombat", "17", "James Dashner", "Empty", Libro::DE_TEXTO);
	//Libro l7("Programacion para Noobs", "16", "James Dashner", "Empty", Libro::BIOGRAFIA);

	t.insertar(&l1);
	t.insertar(&l2);
	t.insertar(&l3);
	t.insertar(&l4);
	t.insertar(&l5);
	//t.insertar(&l6);
	//t.insertar(&l7);
	cout << "NIVEL: " << t.nivel(&l5, t.getRaiz()) << endl;
	////t.eliminarLibrosTipo(t.getRaiz(),Libro::DE_TEXTO);
	//t.preOrden(t.getRaiz());

	//try {
	//	ofstream salida("LIBROS.TXT");
	//	salida << t.cantidad(t.getRaiz())<<"\n";
	//	t.guardar(salida, t.getRaiz());
	//	salida.close();
	//}
	//catch (...) {
	//	cerr << "ME DIO ERROR QHE MADRE" << endl;	
	//}
	
	/*AVL<Libro> *a = NULL;
	try {
		ifstream entrada("LIBROS.TXT");
		 t = AVL<Libro>(entrada);
		entrada.close();
	}catch(...) {
		cerr << "ERROR ENTRADA";
	}

	t.preOrden(t.getRaiz());*/

	/*list<Libro*> libros;

	libros = t.busquedaCodigo(t.getRaiz(),libros,13);

	for each (Libro* var in libros)
	{
		cout << *var;
		cout << " - ";
	}*/
		
	system("pause");
}
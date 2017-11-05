#include<iostream>
#include<string>
#include"Libro.h"
#include "Nodo.h"
#include "AVL.h"
using namespace std;

void main() {
	
	AVL<Libro> t;

	Libro l1("The Maze Runner","10","James Dashner","Empty",Libro::DE_TEXTO);
	Libro l2("The Maze Runner", "5", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l3("The Maze Runner", "13", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l4("The Maze Runner", "1", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l5("The Maze Runner", "6", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l6("The Maze Runner", "17", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l7("The Maze Runner", "16", "James Dashner", "Empty", Libro::DE_TEXTO);

	t.insertar(&l1);
	t.insertar(&l2);
	t.insertar(&l3);
	t.insertar(&l4);
	t.insertar(&l5);
	t.insertar(&l6);
	t.insertar(&l7);

	t.preOrden(t.getRaiz());

	system("pause");
}
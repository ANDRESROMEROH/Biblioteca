#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"Libro.h"
#include"Nodo.h"
#include"AVL.h"
using namespace std;

void main() {
	
	AVL<Libro> t;

	bool running = true;
	string funcion = "0";
	bool funciones;
	char opcion;

	/*Libro l1("The Maze Runner","10","James Dashner","Empty",Libro::DE_TEXTO);
	Libro l2("Caperucita", "5", "Justin Toto", "Empty", Libro::DE_TEXTO);
	Libro l3("Cronicas de Narnia", "13", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l4("Matematicas1", "1", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l5("Scorpion", "6", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l6("Mortal Kombat", "17", "James Dashner", "Empty", Libro::DE_TEXTO);
	Libro l7("Programacion para Noobs", "16", "James Dashner", "Empty", Libro::BIOGRAFIA);*/

	//t.insertar(&l1);
	//t.insertar(&l2);
	//t.insertar(&l3);
	//t.insertar(&l4);
	//t.insertar(&l5);
	//t.insertar(&l6);
	//t.insertar(&l7);


	while (running) {
		cout << "-----> SISTEMA DE BIBLIOTECA <------" << endl << endl;

		cout << "A continuacion digite la opcion en la flecha inferior:" << endl << endl;
		cout << "[1] Cargar Archivo Maestro." << endl;
		cout << "[2] Funciones." << endl;
		cout << "[3] Grabar informacion en disco." << endl;
		cout << "[4] Salir." << endl << endl;
		cout << "Opcion -> ";

		try {
			cin >> opcion;
			if (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4') throw std::exception();
		}
		catch (const std::exception &e) {
			cerr << " No es una opcion valida, por favor inserte una opcion valida.";
			cin.get(); cin.get(); opcion = '0';
		}

		switch (opcion)
		{
		case '0':
			break;

		case '1':
			try {
				ifstream entrada("LIBROS.TXT");
				t = AVL<Libro>(entrada);
				entrada.close();
			}
			catch (...) {
				cerr << "ERROR CARGANDO ARCHIVOS...";
			}
			break;

		case '2':
			funciones = true;

			while (funciones) {
				system("cls"); cout << endl << endl;
				cout << "-----> FUNCIONES <------" << endl << endl;
				cout << "[1] Para incluir un nuevo libro en el arbol." << endl;
				cout << "[2] Para buscar libros por tipo de libro." << endl;
				cout << "[3] Para buscar libros por autor." << endl;
				cout << "[4] Para buscar libros por nombre." << endl;
				cout << "[5] Para buscar libros por codigo ISBN." << endl;
				cout << "[6] Para validar si el arbol es completo." << endl;
				cout << "[7] Para validar si el arbol es perfecto." << endl;
				cout << "[8] Para validar si el arbol es lleno." << endl;
				cout << "[9] Para mostrar la altura del arbol." << endl;
				cout << "[10] Para mostrar la altura del arbol." << endl;
				cout << "[11] Para buscar el nivel de un libro." << endl;
				cout << "[12] Para mostrar el peso del arbol." << endl;
				cout << "[13] Para mostrar la altura del arbol." << endl;
				cout << "[14] Para eliminar un libro por codigo ISBN." << endl;
				cout << "[15] Para eliminar todos los libros de un tipo." << endl << endl;
				cout << "[16] Retroceder." << endl << endl;


				cout << "Funcion ->";

				try {
					cin >> funcion;
					if (funcion != "1" && funcion != "2" && funcion != "3" && funcion != "4" && funcion != "5" && funcion != "6"
						&& funcion != "7" && funcion != "8" && funcion != "9" && funcion != "10" && funcion != "11" && funcion != "12"
						&& funcion != "13" && funcion != "14" && funcion != "15" && funcion != "16") throw std::exception();
				}
				catch (const std::exception &e) {
					cerr << " No es una opcion valida, por favor inserte una opcion valida.";
					cin.get(); cin.get(); opcion = '0';
				}

					if (funcion == "1") {

					}else

					if (funcion == "2") {

					}else

					if (funcion == "3") {

					}else

					if (funcion == "4") {

					}else

					if (funcion == "5") {

					}else

					if (funcion == "6") {

					}else

					if (funcion == "7") {

					}else

					if (funcion == "8") {

					}else

					if (funcion == "9") {

					}else

					if (funcion == "10") {

					}else

					if (funcion == "11") {

					}else

					if (funcion == "12") {

					}else

					if (funcion == "13") {

					}else

					if (funcion == "14") {

					}else

					if (funcion == "15") {

					}else

					if (funcion == "16") {

					}

			}

			break;

		case '3':
			try {
				ofstream salida("LIBROS.TXT");
				salida << t.cantidad(t.getRaiz())<<"\n";
				t.guardar(salida, t.getRaiz());
				salida.close();
			}
			catch (...) {
				cerr << "ERROR GUARDANDO ARCHIVOS..." << endl;	
			}

		case '4':
			cout << endl << "Finalizando...";
			running = false;
			break;
	
		}

	}
		
	system("pause");
}
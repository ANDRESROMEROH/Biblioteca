#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include <algorithm>
#include"Libro.h"
#include"Nodo.h"
#include"AVL.h"
using namespace std;

void mostrar(list<Libro*> l) {
	for each (Libro* var in l)
	{
		cout << *var << endl;
	}
}

void main() {
	
	AVL<Libro> t;

	bool running = true;
	string funcion = "0";
	bool funciones;
	char opcion;

	//Inclusion de Libro:
	string nombre, codigo, autor, descripcion;
	int tipo;

	//Busquedas:
	list<Libro*> resultados;
	Libro* resultado;
	int cod;

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
				cout << "[10] Para buscar el nivel de un libro." << endl;
				cout << "[11] Para mostrar el peso del arbol." << endl;
				cout << "[12] Para mostrar la altura del arbol." << endl;
				cout << "[13] Para eliminar un libro por codigo ISBN." << endl;
				cout << "[14] Para eliminar todos los libros de un tipo." << endl << endl;
				cout << "[15] Retroceder." << endl << endl;


				cout << "Funcion ->";

				try {
					cin >> funcion;
					if (funcion != "1" && funcion != "2" && funcion != "3" && funcion != "4" && funcion != "5" && funcion != "6"
						&& funcion != "7" && funcion != "8" && funcion != "9" && funcion != "10" && funcion != "11" && funcion != "12"
						&& funcion != "13" && funcion != "14" && funcion != "15") throw std::exception();
				}
				catch (const std::exception &e) {
					cerr << " No es una opcion valida, por favor inserte una opcion valida.";
					cin.get(); cin.get(); opcion = '0';
				}

					if (funcion == "1") {
						system("cls");
						cout << "Digite el nombre del libro: "; cin >> nombre; cout << endl;
						cout << "Digite el codigo ISBN del libro: "; cin >> codigo; cout << endl;

						while (!Libro::validarIsbn13(codigo)) {
							system("cls");
							cout << "No es un codigo ISBN valido, por favor utilice un ISBN valido: "; cin >> codigo;
						}

						cout << "Digite el nombre del autor: "; cin >> autor; cout << endl;
						cout << "Digite una descripcion breve: "; cin >> descripcion; cout << endl;
						cout << "A continuacion seleccione el tipo de libro: " << endl << endl;
						cout << "[0] Cientifico." << endl;
						cout << "[1] Literatura." << endl;
						cout << "[2] Biografia." << endl;
						cout << "[3] De Texto." << endl;
						cout << "[4] De Referencia." << endl;
						cout << "[5] Monografia." << endl;
						cout << "[6] Recreativo." << endl;
						cout << "[7] Poetico." << endl << endl;
						cout << "Tipo -> "; cin >> tipo;

						t.insertar(&Libro(nombre,codigo,autor,descripcion,tipo));
						cout << "Se ha insertado el libro!..." << endl; system("pause");

					}else

					if (funcion == "2") {
						system("cls");
						cout << "A continuacion seleccione el tipo de libro que desea buscar: " << endl << endl;
						cout << "[0] Cientifico." << endl;
						cout << "[1] Literatura." << endl;
						cout << "[2] Biografia." << endl;
						cout << "[3] De Texto." << endl;
						cout << "[4] De Referencia." << endl;
						cout << "[5] Monografia." << endl;
						cout << "[6] Recreativo." << endl;
						cout << "[6] Poetico." << endl << endl;
						cout << "Tipo -> "; cin >> tipo;

						resultados = t.busquedaTipo(t.getRaiz(),resultados,tipo); system("cls");
						mostrar(resultados); cout << endl; system("pause");

					}else

					if (funcion == "3") {
						system("cls");
						cout << "Digite el nombre del autor: "; cin >> autor; system("cls");

						resultados = t.busquedaAutor(t.getRaiz(), resultados, autor); system("cls");
						mostrar(resultados); cout << endl; system("pause");

					}else

					if (funcion == "4") {
						system("cls");
						cout << "Digite el nombre del libro: "; cin >> nombre; system("cls");

						resultados = t.busquedaNombre(t.getRaiz(), resultados, nombre); system("cls");
						mostrar(resultados); cout << endl; system("pause");
					}else

					if (funcion == "5") {
						system("cls");
						cout << "Digite el codigo ISBN del libro: "; cin >> cod; system("cls");

						resultado = t.busquedaCodigo(t.getRaiz(),  cod); system("cls");
						cout << resultado << endl; system("pause");
					}else

					if (funcion == "6") {
						system("cls");
						if (t.esCompleto(t.getRaiz())) {
							cout << "El arbol es completo!" << endl;
						}
						else {
							cout << "El arbol NO es completo!" << endl;
						}system("pause");
					}else

					if (funcion == "7") {
						system("cls");
						if (t.esPerfecto(t.getRaiz())) {
							cout << "El arbol es perfecto!" << endl;
						}
						else {
							cout << "El arbol NO es perfecto!" << endl;
						}system("pause");
					}else

					if (funcion == "8") {
						system("cls");
						if (t.esLleno(t.getRaiz())) {
							cout << "El arbol es lleno!" << endl;
						}
						else {
							cout << "El arbol NO es lleno!" << endl;
						}system("pause");
					}else

					if (funcion == "9") {
						system("cls");
						cout << "La altura del arbol es: " << t.altura(t.getRaiz()); system("pause");
					}else

					if (funcion == "10") {
						system("cls");
						cout << "Digite el codigo del libro: "; cin >> cod;
						cout << "El nivel es " << t.nivel(t.busquedaCodigo(t.getRaiz(), cod), t.getRaiz());
					}else

					if (funcion == "11") {
						system("cls");
						cout << "El peso del arbol es "<<t.peso(); cin >> cod;
					}else

					if (funcion == "12") {
						system("cls");
						cout << "No implementado...." << t.peso(); cin >> cod;
					}else

					if (funcion == "13") {
						system("cls");
						cout << "Digite el codigo del libro: "; cin >> codigo;
						t.eliminarCodigo(codigo);
						cout << "Se ha eliminado el libro!..." << endl;
					}else

					if (funcion == "14") {
						cout << "A continuacion seleccione el tipo de libro que desea eliminar: " << endl << endl;
						cout << "[0] Cientifico." << endl;
						cout << "[1] Literatura." << endl;
						cout << "[2] Biografia." << endl;
						cout << "[3] De Texto." << endl;
						cout << "[4] De Referencia." << endl;
						cout << "[5] Monografia." << endl;
						cout << "[6] Recreativo." << endl;
						cout << "[6] Poetico." << endl << endl;
						cout << "Tipo -> "; cin >> tipo;

						t.eliminarLibrosTipo(t.getRaiz(),tipo);
						cout << "Se han eliminado todos los libros de su tipo...." << endl;
					}else

					if (funcion == "15") {
						funciones = false;
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
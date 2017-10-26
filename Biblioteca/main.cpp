#include<iostream>
#include<string>
#include"Libro.h"

using namespace std;

void main() {

	string isbn = "9780194129558";

	if (Libro::validarIsbn13(isbn)) {
		cout << "Es un ISBN valido..." << endl << endl;
	}
	else {
		cout << "No es un ISBN valido..." << endl << endl;
	}

	system("pause");
}
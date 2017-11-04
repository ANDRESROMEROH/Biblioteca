#include<iostream>
#include<string>
#include"Libro.h"
#include "Nodo.h"
#include "AVL.h"
using namespace std;

void main() {
	
	AVL<int> t;
	int num = 0;
	std::cout << "Inserting integer values 1 to 10" << std::endl;
	for (int i = 1; i <= 3; ++i) {
		std::cout << "INGRESE NUMERO" << std::endl;
		std::cin >> num;
		t.insertar(new int(num));
	}
	std::cout << "Printing balance: ";
	t.postOrden(t.getRaiz());
	system("pause");

	system("pause");
}
#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Libro {

public:
	Libro(string, string, string, string, int);

	void setNombre(string);
	void setCodigo(string);
	void setAutor(string);
	void setDescripcion(string);
	void setTipo(int);

	string getNombre();
	string getCodigo();
	string getAutor();
	string getDescripcion();
	string toString();
	int getTipo();

	bool operator<(Libro&);
	bool operator>(Libro&);
	bool operator==(Libro&);

	static bool validarIsbn13(string);

	static const int CIENTIFICO = 0;
	static const int LITERATURA = 1;
	static const int BIOGRAFIA = 2;
	static const int DE_TEXTO = 3;
	static const int DE_REFERENCIA = 4;
	static const int MONOGRAFIA = 5;
	static const int RECREATIVO = 6;
	static const int POETICO = 7;

private:
	string nombre;
	string codigo;
	string autor;
	string descripcion;
	int tipo;
};


ostream& operator<<(ostream& os, Libro& libro);
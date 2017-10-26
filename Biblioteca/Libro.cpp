#include"Libro.h"

Libro::Libro(string nb, string cod, string aut, string dcp, int tip):nombre(nb),codigo(cod),autor(aut),descripcion(dcp),tipo(tip) {
	
}


void Libro::setNombre(string nb) {
	this->nombre = nb;
}


void Libro::setCodigo(string cod) {
	this->codigo = cod;
}


void Libro::setAutor(string aut) {
	this->autor = aut;
}


void Libro::setDescripcion(string dcp) {
	this->descripcion = dcp;
}


void Libro::setTipo(int tip) {
	this->tipo = tip;
}


string Libro::getNombre() {
	return this->nombre;
}


string Libro::getCodigo() {
	return this->codigo;
}


string Libro::getAutor() {
	return this->autor;
}


string Libro::getDescripcion() {
	return this->descripcion;
}


int Libro::getTipo() {
	return this->tipo;
}


bool Libro::validarIsbn13(string isbn) {

	//Debe ser un codigo ISBN de 13 digitos.
	if (isbn.length() != 13)
	{
		return false;
	}

	
		int total = 0;
		for (int i = 0; i < 12; i++)
		{
			int digito = stoi(isbn.substr(i, i + 1));
			total += (i % 2 == 0) ? digito * 1 : digito * 3;
		}

		//check debe estar entre 0-9. Si se calcula un 10 entonces debe ser = 0
		int check = 10 - (total % 10);
		if (check == 10)
		{
			check = 0;
		}

		return check == stoi(isbn.substr(12));

}
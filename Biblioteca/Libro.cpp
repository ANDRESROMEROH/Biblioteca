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

string Libro::toString() {
	stringstream s;
	s << "Autor: " << autor<<" Nombre "<<nombre<<" codigo: "<<codigo<<" descripcion: "<<descripcion<<" tipo: "<<tipo<<endl;
	return s.str();
}

bool Libro::validarIsbn13(string isbn) {

	//Debe ser un codigo ISBN de 13 digitos.
	if (isbn.length() != 13)
	{
		return false;
	}

	int impar = 0;
	int par = 0;
	
		int total = 0;
		for (int i = 0; i < 12; i++)
		{
			int digito = stoi(isbn.substr(i, 1));
			(i % 2 == 0) ? par = par + digito : impar = impar + digito;
		}

		total = par + (impar * 3);

		//check debe estar entre 0-9. Si se calcula un 10 entonces debe ser = 0
		int check = 10 - (total % 10);

		if (check == 10)
		{
			check = 0;
		}

		return check == stoi(isbn.substr(12));
}


bool Libro::operator<(Libro& libro) {
	return  stoi(this->codigo) < stoi(libro.codigo);
}

ostream& operator<<(ostream& os, Libro& libro) {
	os << libro.getCodigo();
	return os;
}

bool Libro::operator>(Libro& libro) {
	return  stoi(this->codigo) > stoi(libro.codigo);
}

bool Libro::operator==(Libro& libro) {
	return stoi(this->codigo) == stoi(libro.codigo);
}
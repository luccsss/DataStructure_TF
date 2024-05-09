#pragma once
#include <iostream>
#include <string>
using namespace std;
class Certificados{
private:
	int n;
	int size;
	string tipo;
public:
	Certificados() { 
		n = 0;
	};
	~Certificados() { };
	void setTipos(string tipos) {
		tipo = tipos;
	}
	void setCantCertificados(int _cant) {
		n = _cant;
	}
	string getTipo() { return tipo; }

};


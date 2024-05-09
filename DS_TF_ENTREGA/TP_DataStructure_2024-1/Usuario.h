#pragma once
#include <iostream>
#include "Certificados.h"

using namespace std;
class Usuario
{
private:
	short tipoUsuario;
protected:
	int identificador=0;
	string prenombres;
	string apellidoPaterno;
	string apellidoMaterno; 
	string sexo;
	string fechaNacimiento;
	string cui; //dni
	string direccion;
	string fechaEmision;
	string fechaCaduc;
	string nacionalidad;
	string ubigeoNacimiento;
	string CantCertificados;
	Certificados certificados;
public:
	Usuario(short tipoUsuario): tipoUsuario(tipoUsuario) {
		prenombres = "";
		apellidoPaterno = "";
		apellidoMaterno = "";
		cui = "";
		sexo = "";
		fechaNacimiento = "";
		direccion = "";
		fechaEmision = "";
		fechaCaduc = "";
		nacionalidad = "";
		ubigeoNacimiento = "";
		CantCertificados = "0";
		//certificados.setCantCertificados(int(CantCertificados));
	};
	~Usuario() {};
	virtual void mostrarUsuarios(int i) =0;
	virtual void modificarUsuario(int i) = 0;
	virtual void agregarUsuario(int i) = 0;
	virtual void setDatos(int i) = 0;
	int getTipoUsuario() { return tipoUsuario; }
	void setIdentificador(int _id) {
		identificador=_id;
	}
	int getIdentificador() {
		return identificador;
	}
};


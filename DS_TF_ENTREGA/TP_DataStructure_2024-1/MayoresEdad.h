#pragma once
#include "Usuario.h"
#include <fstream>
#include <vector>
#include <string>
#include "ListaSimple.h"

class MayoresEdad : public Usuario
{
private:
	string departProvinciaDistrito;
	string ruta;
public:
	MayoresEdad() : Usuario(2) {
		departProvinciaDistrito = "";
	}
	~MayoresEdad() {};

	void agregarUsuario(int i) override  {

		string ruta = "UsuariosCarpeta/MayoresCarp/user" + to_string(i+1) + ".txt";
		ofstream archivo1(ruta);
        cout << "\t\tPrenombres: ";
        cin >> ws; // Consumir cualquier espacio en blanco residual en el búfer de entrada
        getline(cin, prenombres);        archivo1 << prenombres << "\n";

        cout << "\t\tApellido Paterno: ";
        getline(cin, apellidoPaterno); archivo1 << apellidoPaterno << "\n";

        cout << "\t\tApellido Materno: ";
        getline(cin, apellidoMaterno); archivo1 << apellidoMaterno << "\n";

        cout << "\t\tSexo: ";
        getline(cin, sexo); archivo1 << sexo << "\n";

        cout << "\t\tFecha de Nacimiento: ";
        getline(cin, fechaNacimiento); archivo1 << fechaNacimiento << "\n";

        cout << "\t\tNumero de dni: ";
        cin >> cui;
        archivo1 << cui << "\n";

        cout << "\t\tDireccion: ";
        cin >> ws; // Consumir cualquier espacio en blanco residual en el búfer de entrada
        getline(cin, direccion); archivo1 << direccion << "\n";

        cout << "\t\tFecha de emision: ";
        getline(cin, fechaEmision); archivo1 << fechaEmision << "\n";

        cout << "\t\tFecha de caducidad: ";
        getline(cin, fechaCaduc); archivo1 << fechaCaduc << "\n";

        cout << "\t\tNacionalidad: ";
        getline(cin, nacionalidad); archivo1 << nacionalidad << "\n";

        cout << "\t\tUbigeo de Nacimiento: ";
        getline(cin, ubigeoNacimiento); archivo1 << ubigeoNacimiento << "\n";

        cout << "\t\tCertificados Disponibles: ";
        cin >> CantCertificados;
        archivo1 << CantCertificados << "\n";

        cout << "\t\tDepartamento/Provincia/Distrito: ";
        cin >> ws;
        getline(cin, departProvinciaDistrito); archivo1 << departProvinciaDistrito << "\n";

        archivo1.close();
		cout << "\t\tSu usuario fue registrado exitosamente en el archivo"<<ruta;
	}
	void modificarUsuario(int i) override {

        string ruta = "UsuariosCarpeta/MayoresCarp/user" + to_string(i + 1) + ".txt";
        ofstream archivo1(ruta);
        cout << "\t\tPrenombres: ";
        cin >> ws; // Consumir cualquier espacio en blanco residual en el búfer de entrada
        getline(cin, prenombres);        archivo1 << prenombres << "\n";

        cout << "\t\tApellido Paterno: ";
        getline(cin, apellidoPaterno); archivo1 << apellidoPaterno << "\n";

        cout << "\t\tApellido Materno: ";
        getline(cin, apellidoMaterno); archivo1 << apellidoMaterno << "\n";

        cout << "\t\tSexo: ";
        getline(cin, sexo); archivo1 << sexo << "\n";

        cout << "\t\tFecha de Nacimiento: ";
        getline(cin, fechaNacimiento); archivo1 << fechaNacimiento << "\n";

        cout << "\t\tNumero de dni: ";
        cin >> cui;
        archivo1 << cui << "\n";

        cout << "\t\tDireccion: ";
        cin >> ws; // Consumir cualquier espacio en blanco residual en el búfer de entrada
        getline(cin, direccion); archivo1 << direccion << "\n";

        cout << "\t\tFecha de emision: ";
        getline(cin, fechaEmision); archivo1 << fechaEmision << "\n";

        cout << "\t\tFecha de caducidad: ";
        getline(cin, fechaCaduc); archivo1 << fechaCaduc << "\n";

        cout << "\t\tNacionalidad: ";
        getline(cin, nacionalidad); archivo1 << nacionalidad << "\n";

        cout << "\t\tUbigeo de Nacimiento: ";
        getline(cin, ubigeoNacimiento); archivo1 << ubigeoNacimiento << "\n";

        cout << "\t\tCertificados Disponibles: ";
        cin >> CantCertificados;
        archivo1 << CantCertificados << "\n";

        cout << "\t\tDepartamento/Provincia/Distrito: ";
        cin >> ws;
        getline(cin, departProvinciaDistrito); archivo1 << departProvinciaDistrito << "\n";

        archivo1.close();
        cout << "\t\tSu usuario fue registrado exitosamente en el archivo" << ruta;
    }
	void mostrarUsuarios(int i) override  {
			ruta = "UsuariosCarpeta/MayoresCarp/user" + to_string(i + 1) + ".txt";
			ifstream archivo(ruta);
			getline(archivo, prenombres); cout << "\t\tPrenombres: " << prenombres << endl;
			getline(archivo, apellidoPaterno); cout << "\t\tApellido Paterno: " << apellidoPaterno << endl;
			getline(archivo, apellidoMaterno); cout << "\t\tApellido Materno: " << apellidoMaterno << endl;
			getline(archivo, sexo); cout << "\t\tSexo: " << sexo << endl;
			getline(archivo, fechaNacimiento); cout << "\t\tFecha de Nacimiento: " << fechaNacimiento << endl;
			getline(archivo, cui); cout << "\t\tNumero de dni: " << cui << endl;
			getline(archivo, direccion); cout << "\t\tDireccion: " << direccion << endl;
			getline(archivo, fechaEmision); cout << "\t\tFecha de emision: " << fechaEmision << endl;
			getline(archivo, fechaCaduc); cout << "\t\tFecha de caducidad: " << fechaCaduc << endl;
			getline(archivo, nacionalidad); cout << "\t\tNacionalidad: " << nacionalidad << endl;
			getline(archivo, ubigeoNacimiento); cout << "\t\tUbigeo de Nacimiento: " << ubigeoNacimiento << endl;
			getline(archivo, CantCertificados); cout << "\t\tCertificados Disponibles: " << CantCertificados << endl;
			getline(archivo, departProvinciaDistrito); cout << "\t\tDepartamento/Provincia/Distrito: " << departProvinciaDistrito << endl;
			archivo.close();
	}
	void setDatos(int i) override {
		string ruta = "UsuariosCarpeta/MayoresCarp/user" + to_string(i + 1) + ".txt";
		ifstream archivo(ruta);
		getline(archivo, prenombres);
		getline(archivo, apellidoPaterno);
		getline(archivo, apellidoMaterno);
		getline(archivo, sexo);
		getline(archivo, fechaNacimiento);
		getline(archivo, cui);
		getline(archivo, direccion);
		getline(archivo, fechaEmision);
		getline(archivo, fechaCaduc);
		getline(archivo, nacionalidad);
		getline(archivo, ubigeoNacimiento);
		getline(archivo, CantCertificados);
		getline(archivo, departProvinciaDistrito);
		archivo.close();
	}
};

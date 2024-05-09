#pragma once
#include "Usuario.h"
#include "MenoresEdad.h"
#include "MayoresEdad.h"
#include "ListaSimple.h"
#include "Certificados.h"
#include "ListaDoblEnlazada.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;
using namespace System;


class Controladora
{
private:
	ListaDoblementeEnlazada<Usuario*>* objetoListaDoblementeEnlazada;
	ListaSimple<Usuario*>* objetoListaSimpleEnlazadaMayores;
	ListaSimple<Usuario*>* objetoListaSimpleEnlazadaMenores;
	Pila<Certificados*>* pila;
	Cola<Certificados*>* cola;
	Certificados* certif;
	int numUsuarios, rpta;
	Usuario* objmenores;
	Usuario* objmayores;
public:
	Controladora() {
		objetoListaDoblementeEnlazada = new ListaDoblementeEnlazada<Usuario*>();
		objetoListaSimpleEnlazadaMayores= new ListaSimple<Usuario*>;
		objetoListaSimpleEnlazadaMenores= new ListaSimple<Usuario*>;
		pila = new Pila<Certificados*>(); 
		cola = new Cola<Certificados*>();
		certif = new Certificados(); 
		objmenores = new MenoresEdad();
		objmayores = new MayoresEdad();
		numUsuarios = 4;
	};
	~Controladora() {
		delete objetoListaDoblementeEnlazada;
		delete objetoListaSimpleEnlazadaMayores;
		delete objetoListaSimpleEnlazadaMenores;
		delete objmenores;
		delete objmayores;
		delete pila;
		delete cola;
	};
	void insertarUsuariosPreestablecidos() {
		for (int i = 0; i < 4; i++) {
			Usuario* nuevoMenor = new MenoresEdad(); // Crear nueva instancia 
			nuevoMenor->setDatos(i); 
			objetoListaSimpleEnlazadaMenores->push_front(nuevoMenor);
			objetoListaDoblementeEnlazada->insertarFinal(nuevoMenor); 
			objetoListaDoblementeEnlazada->getNodoEnPosicion(i)->valor->setIdentificador(i);

		}
		for (int i = 0; i < 4; i++) {
			Usuario* nuevoMayor = new MayoresEdad(); // Crear nueva instancia 
			nuevoMayor->setDatos(i); 
			objetoListaSimpleEnlazadaMayores->push_front(nuevoMayor);
			objetoListaDoblementeEnlazada->insertarFinal(nuevoMayor); 
			objetoListaDoblementeEnlazada->getNodoEnPosicion(i+4)->valor->setIdentificador(i+4);
		}
	}
	void mostrarUsuarioConjunto(int n, int indice) {
		//FORMA RECURSIVA
		switch (n)
		{
		case 1:
			if (indice >= objetoListaSimpleEnlazadaMenores->getLongitud())
			{
				return;
			}
			else {
				cout << endl << "\t\t++++++++++++++++++ Usuario N: " << indice + 1 << " +++++++++++++++++++" << endl << endl;
				objetoListaSimpleEnlazadaMenores->getNodoEnPosicion(indice)->elemento->mostrarUsuarios(indice);
				mostrarUsuarioConjunto(n, indice + 1);
				break;
			}
		case 2:		
			if (indice >= objetoListaSimpleEnlazadaMayores->getLongitud())
			{
				return;
			}
			else {
				cout << endl << "\t\t++++++++++++++++++ Usuario N: " << indice + 1 << " +++++++++++++++++++" << endl << endl;
				objetoListaSimpleEnlazadaMayores->getNodoEnPosicion(indice)->elemento->mostrarUsuarios(indice);
				mostrarUsuarioConjunto(n, indice + 1);
				break;
			}
		case 3:
			if (indice >= objetoListaDoblementeEnlazada->getLongitud()) 
			{
				return;
			}
			else {
				cout << endl << "\t\t++++++++++++++++++ Usuario N: " << objetoListaDoblementeEnlazada->getNodoEnPosicion(indice)->valor->getIdentificador()+1 << " +++++++++++++++++++" << endl << endl;
				objetoListaDoblementeEnlazada->getNodoEnPosicion(indice)->valor->mostrarUsuarios(indice);
				mostrarUsuarioConjunto(n, indice + 1);
				break;
			}
		default:
			break;
		}
	}
	void modificarUnUsuario(int n) {
		switch (n)
		{
		case 1:
			cout << "\n\n\n\n\t\t\tIngrese el usuario menor que desea modificar:"; cin >> rpta;
			Console::Clear();
			cout << "\n\n\n\n\t\t\tUSUARIO N"<<rpta<<" POR MODIFICAR: " << endl << endl;
			if (objetoListaSimpleEnlazadaMenores->getLongitud()>rpta-1)
			{
				objetoListaSimpleEnlazadaMenores->getNodoEnPosicion(rpta - 1)->elemento->modificarUsuario(rpta - 1);
			}
			else
			{
				cout << "No existe el usuario deseado" << endl;
			}

			//modificar lista doble
			break;
		case 2:
			cout << "\n\n\n\n\t\t\tIngrese el usuario mayor que desea modificar: ";	cin >> rpta;
			Console::Clear(); 
			cout << "\n\n\n\n\t\t\tUSUARIO N" << rpta << " POR MODIFICAR: " << endl << endl; 
			if (objetoListaSimpleEnlazadaMayores->getLongitud() > rpta - 1) 
			{
				objetoListaSimpleEnlazadaMayores->getNodoEnPosicion(rpta - 1)->elemento->modificarUsuario(rpta - 1);
			}
			else
			{
				cout << "No existe el usuario deseado" << endl;
			}

			break;
		case 3:
			cout << "Regresando...";
			break;
		}
	} 
	void agregarUnUsuario(int n) {
		switch (n)
		{
		case 1:
			cout << "\n\n\n\n\t\t\tNUEVO USUARIO POR AGREGAR:" << endl << endl;
			objmenores = new MenoresEdad(); // Crear una nueva instancia 
			objmenores->agregarUsuario(objetoListaSimpleEnlazadaMenores->getLongitud()); 
			objmenores->setDatos(objetoListaSimpleEnlazadaMenores->getLongitud()); 
			objetoListaSimpleEnlazadaMenores->push_front(objmenores); 
			objetoListaDoblementeEnlazada->insertarFinal(objmenores); 
			objetoListaDoblementeEnlazada->getNodoEnPosicion(objetoListaDoblementeEnlazada->getLongitud() - 1)->valor->setIdentificador(objetoListaDoblementeEnlazada->getLongitud() - 1); 
			break;
		case 2:
			cout << "\n\n\n\n\t\t\tNUEVO USUARIO POR AGREGAR:" << endl << endl;
			objmayores = new MayoresEdad(); // Crear una nueva instancia
			objmayores->agregarUsuario(objetoListaSimpleEnlazadaMayores->getLongitud());
			objmayores->setDatos(objetoListaSimpleEnlazadaMayores->getLongitud());
			objetoListaSimpleEnlazadaMayores->push_front(objmayores);
			objetoListaDoblementeEnlazada->insertarFinal(objmayores);
			objetoListaDoblementeEnlazada->getNodoEnPosicion(objetoListaDoblementeEnlazada->getLongitud() - 1)->valor->setIdentificador(objetoListaDoblementeEnlazada->getLongitud() - 1);
			break;
		case 3:
			cout << "Regresando...";
			break;
		}
	}
	void ordenarDescendenteRecursivo(int i, int n) {
		// Caso base: si hemos llegado al final de la lista
		if (i >= n - 1) {
			mostrarUsuarioConjunto(3, 0); // Mostrar la lista ordenada
			return;
		}

		// Lógica recursiva: realizar un paso del ordenamiento burbuja
		for (int j = 0; j < n - i - 1; j++) {
			if (objetoListaDoblementeEnlazada->getNodoEnPosicion(j)->valor->getIdentificador() <
				objetoListaDoblementeEnlazada->getNodoEnPosicion(j + 1)->valor->getIdentificador()) {

				objetoListaDoblementeEnlazada->ordenamientoBurbuja(j); // Intercambio para orden descendente
			}
		}
		ordenarDescendenteRecursivo(i + 1, n);
	}
	void ordenarDescendente() {
		int n = objetoListaDoblementeEnlazada->getLongitud();
		ordenarDescendenteRecursivo(0, n);
	}


	void insertarCertificadoEnPila(const string& tipo) {
		Certificados* certificado = new Certificados();
		certificado->setTipos(tipo);
		pila->insertar(certificado);
	}
	void piladeCertificados(int n, int indice) {
		switch (n) {
		case 1:
			if (indice == 0) {
				cout << "\t\t\t++++++++++++++++++ Los certificados disponibles son: ++++++++++++++++++" << endl << endl;
				insertarCertificadoEnPila("1.Certificado de nacimiento");
				insertarCertificadoEnPila("2.Certificado de bautizo");
				insertarCertificadoEnPila("3.Certificado de estudios inicial");
				insertarCertificadoEnPila("4.Certificado de estudios primaria");
				insertarCertificadoEnPila("5.Certificado de estudios secundaria");
				insertarCertificadoEnPila("6.Certificado de estudios superiores");
				insertarCertificadoEnPila("7.Certificado de estudios posgrado");
			}
			break;
		case 2:
			cout << "Regresando...";
			break;
		}
	}

};


#pragma once
#include <iostream>
#include <conio.h>
#include "Controladora.h"

using namespace std;
using namespace System;

void titulo() {
    cout << endl;
    cout << endl;
    cout << "  _  _  _           _  _  _  _           _  _  _  _  _        _           _        _  _  _  _  _ \n";
    cout << " (_)(_)(_)         (_)(_)(_)(_)         (_)(_)(_)(_)(_)      (_) _       (_)      (_)(_)(_)(_)(_)         (_)(_)(_)              _(_)_     \n";
    cout << "    (_)             (_)      (_)_       (_)                  (_)(_)_     (_)            (_)                  (_)               _(_) (_)_   \n";
    cout << "    (_)             (_)        (_)      (_) _  _             (_)  (_)_   (_)            (_)                  (_)             _(_)     (_)_ \n";
    cout << "    (_)             (_)        (_)      (_)(_)(_)            (_)    (_)_ (_)            (_)                  (_)            (_) _  _  _ (_)\n";
    cout << "    (_)             (_)       _(_)      (_)                  (_)      (_)(_)            (_)                  (_)            (_)(_)(_)(_)(_)\n";
    cout << "  _ (_) _           (_)_  _  (_)        (_) _  _  _  _       (_)         (_)            (_)                _ (_) _          (_)         (_)\n";
    cout << " (_)(_)(_)         (_)(_)(_)(_)         (_)(_)(_)(_)(_)      (_)         (_)            (_)               (_)(_)(_)         (_)         (_)\n";
    cout << endl; 
    cout << endl; 
}
void salir() {
    cout << "Saliendo del software IDENTIA...";
}
short menuPrincipal() {
        Console::Clear();
        short opc = 0;
        titulo();
        cout << "\t\t\t\t\t\t\t\tBIENVENIDO\n";
        Console::BackgroundColor = ConsoleColor::White;
        Console::ForegroundColor = ConsoleColor::Black;
        cout << "\t\t\t\t\t\t1.Mostrar base de usuarios                \n";
        cout << "\t\t\t\t\t\t2.Ingresar un Nuevo Usuario               \n";
        cout << "\t\t\t\t\t\t3.Modificar Informacion de un Usuario     \n";
        cout << "\t\t\t\t\t\t4.Ver pila de certificados disponibles    \n";
        cout << "\t\t\t\t\t\t5.Ordenar de forma Ascendente la lista    \n";
        cout << "\t\t\t\t\t\t6.Salir                                   \n";
        Console::BackgroundColor = ConsoleColor::Black;
        Console::ForegroundColor = ConsoleColor::White;
        cout << "\t\t\t\t\t\tIngrese una opcion: "; cin >> opc;
        return opc;
}

short menuSecundario(Controladora* objControladora) {
    short opcion, n, indice=0; 
    do
    {
        opcion = menuPrincipal();
    } while (opcion<1 || opcion>7);
    system("cls");
    switch (opcion){
    case 1:
        do
        {
            cout << "\n\n\n\t\t1.Usuarios menores de edad registrados" << endl;
            cout << "\n\n\n\t\t2.Usuarios mayores de edad registrados" << endl;
            cout << "\n\n\n\t\t3.Toda la base de usuarios registrados" << endl;
            cout << "\n\n\n\t\tIngrese una opcion: "; cin >> n;
            Console::Clear();
        } while (n<1 || n>3);
        cout << "\n\n\n\n\t\t\tLISTA DE USUARIOS REGISTRADOS:" << endl << endl;
        objControladora->mostrarUsuarioConjunto(n, indice);
        break;
    case 2:
        do
        {
            cout << "\n\n\n\t\t1.Agregar un menor de edad" << endl;
            cout << "\n\n\n\t\t2.Agregar un mayor de edad" << endl;
            cout << "\n\n\n\t\t3.Retroceder" << endl;
            cout << "\n\n\n\t\tIngrese una opcion: "; cin >> n;
            Console::Clear();
        } while (n < 1 || n>3);
        objControladora->agregarUnUsuario(n);
        break;
    case 3:
        do
        {
            cout << "\n\n\n\t\t1.Modificar un menor de edad" << endl;
            cout << "\n\n\n\t\t2.Modificar un mayor de edad" << endl;
            cout << "\n\n\n\t\t3.Retroceder" << endl;
            cout << "\n\n\n\t\tIngrese una opcion: "; cin >> n;
            Console::Clear();
        } while (n < 1 || n>3);
        objControladora->modificarUnUsuario(n);
        break;
    case 4:  
        cout << endl << "\t\t++++++++++++++++++ Certificados +++++++++++++++++++" << endl << endl;
        do
        {
            cout << "\n\n\n\t\t1.Mostrar pila de certificados disponibles" << endl;
            cout << "\n\n\n\t\t2.Retroceder" << endl;
            cout << "\n\n\n\t\tIngrese una opcion: "; cin >> n;
            Console::Clear();
        } while (n < 1 || n>2);
        objControladora->piladeCertificados(n,0);
        break;
    case 5:
        cout << endl << "\t\t++++++++++++++++ Lista Descendente +++++++++++++++++" << endl << endl;
        objControladora->ordenarDescendente();
        break;
    case 6:
        salir();
        return 1;
        break;
    }
    return 0;
}

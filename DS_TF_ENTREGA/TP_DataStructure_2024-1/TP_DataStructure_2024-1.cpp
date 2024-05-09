#include "pch.h"
#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 

#include "Menu.h"
#include "Controladora.h"

using namespace System;
using namespace std;

int main()
{
	srand(time(NULL)); 
	short num;
	Controladora* objControladora = new Controladora;
	objControladora->insertarUsuariosPreestablecidos();
	do
	{
		num=menuSecundario(objControladora);
		getch();
	} while (num==0);
	system("pause>0");
	delete objControladora;
    return 0;
}

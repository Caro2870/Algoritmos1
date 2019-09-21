// u201711783-lista circular ptr al inicio.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <iostream>
#include "listacircular.h"

using namespace std;


int main()
{
	Lista* nodo = new Lista();
	int R = 0;
	nodo->inicializar();
	do
	{
		int r;
		system("cls");
		cout << "                    Lista Circular Simplemente Enlazada uwu                    " << endl;
		cout << "¿Que accion desea realizar?\nSeleccione el numero\n1: Ingresar dato\n2: Eliminar dato\n3: Mostrar todos los datos\n4: Eliminar todos los datos\n5: Salir" << endl;
		cin >> r;
		system("cls");
		switch (r)
		{
		case 1: //insertar()
			cout << "                    Lista Circular Simplemente Enlazada uwu                  " << endl;
			cout << "Ingresa el numero a la lista" << endl;
			int x;
			cin >> x;
			nodo->insertar(x);
			system("cls");
			break;
		case 2: //eliminar()
			cout << "                    Lista Circular Simplemente Enlazada uwu                    " << endl;
			cout << "Ingresa el numero que desea eliminar de la lista" << endl;
			int y;
			cin >> y;
			nodo->eliminar(y);
			system("cls");
			break;
		case 3: //imprime()
			cout << "                    Lista Circular Simplemente Enlazada uwu                    " << endl;
			nodo->imprime();
			system("cls");
			break;
		case 4: //limpia()
			cout << "                    Lista Circualar Simplemente Enlazada uwu                    " << endl;
			nodo->limpia();
			system("cls");
			break;
		case 5: //Salir
			R = 1;
			break;
		}
	} while (R != 1);
	return 0;
}
// lista.cpp.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <iostream>
#include "lista.h"

using namespace System;
using namespace std;

class Persona
{
private:
	int x;
	int y;

public:
	Persona(int x, int y){
		this->x = x;
		this->y = y;
	}

	int getx() { return this->x; }
	int gety() { return  this->y; }


};





int main()
{

	Lista <Persona*>* lst = new Lista<Persona*>();

	for (int i = 0;i < 8; i++) {
		lst->agregaInicial(new Persona(i,2+i));


	}
	for (int i = lst->longitud()-1;i >=0 ; i--) {
		cout << lst->obtenerPos(i)->getx() << endl;


	}

	cout << endl;
	for (Persona* s : *lst) {
		cout << s->getx() << endl;
	}
	

	system("pause");
}

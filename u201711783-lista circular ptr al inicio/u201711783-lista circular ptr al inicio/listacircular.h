#pragma once
#include <iostream>
using namespace std;

class Lista
{

private:


	struct Nodo
	{
		int dato;
		Nodo *sig;
		Nodo(int _dato) {
			dato = _dato;
			sig = nullptr;
		}

	};
	class Iterator {
		unsigned int pos;
		Nodo* aux;
	public:
		Iterator(unsigned int pos, Nodo* AUX) {
			this->aux = AUX;
			this->pos = pos;
		}
		void operator ++() { pos++; aux = aux->sig; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		int operator *() { return aux->dato; }

	};
	Nodo*inicio, *aux, *aux2, *nodo;

public:
	Lista(Nodo* inicio = nullptr) {

	}

	void inicializar()
	{
		inicio = NULL;
	}

	bool vacia()
	{
		if (inicio == NULL)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}

	void insertar(int dato)
	{
		nodo = new Nodo(dato);
		nodo->dato = dato;
		nodo->sig = NULL;
		if (vacia())
		{
			inicio = nodo;
			inicio->sig = inicio;
		}
		else
		{
			if (buscar(dato))
			{
				cout << "El dato ya existe en la lista\nNo se pueden repetir los datos" << endl;
			}
			else
			{
				if (dato < inicio->dato)
				{
					bool exit = true;
					aux = inicio;
					while (exit == true)
					{
						if (aux->sig == inicio)
						{
							aux->sig = nodo;
							exit = false;
						}
						else
						{
							aux = aux->sig;
						}
					}
					nodo->sig = inicio;
					inicio = nodo;
				}
				else
				{
					bool exit = true;
					aux = inicio;
					while (exit == true)
					{
						if (nodo->dato < aux->sig->dato || aux->sig == inicio)
						{
							nodo->sig = aux->sig;
							aux->sig = nodo;
							exit = false;
						}
						else
						{
							aux = aux->sig;
						}
					}
				}
			}
		}
		system("Pause");
	}

	void eliminar(int dato)
	{
		if (vacia())
		{
			cout << "La lista ya esta vacia" << endl;
		}
		else
		{
			if (!buscar(dato))
			{
				cout << "El elemento que decea eliminar no esta en la fila" << endl;
			}
			else
			{
				if (dato == inicio->dato)
				{
					if (inicio->sig == inicio)
					{
						inicializar();
					}
					else
					{
						aux = inicio;
						bool exit = true;
						while (exit == true)
						{
							if (aux->sig == inicio)
							{
								aux->sig = inicio->sig;
								delete inicio;
								inicio = aux->sig;
								exit = false;
							}
							else
							{
								aux = aux->sig;
							}
						}
					}
				}
				else
				{
					bool exit = true;
					aux = inicio;
					while (exit == true)
					{
						if (aux->sig->dato == dato)
						{
							aux2 = aux->sig;
							aux->sig = aux2->sig;
							delete aux2;
							exit = false;
						}
						else
						{
							aux = aux->sig;
						}
					}
				}
			}
		}
		system("Pause");
	}

	void imprime()
	{
		if (vacia())
		{
			cout << "La lista esta vacia" << endl;
		}
		else
		{
			aux = inicio;
			do
			{
				cout << aux->dato << " - ";
				aux = aux->sig;
			} while (aux != inicio);
			cout << endl;
		}
		system("Pause");
	}

	void limpia()
	{
		if (vacia())
		{
			cout << "La lista ya se encuentra vacia" << endl;
		}
		else
		{
			bool exit = true;
			aux = inicio;
			while (exit)
			{
				if (aux->sig == inicio)
				{
					aux->sig = NULL;
					exit = false;
				}
				else
				{
					aux = aux->sig;
				}
			}
			aux = inicio;
			while (inicio != NULL)
			{
				if (inicio->sig == inicio)
				{
					inicializar();
				}
				else
				{
					inicio = inicio->sig;
					delete aux;
					aux = inicio;
				}

			}
		}
	}

	bool buscar(int dato)
	{
		if (vacia())
		{
			return(false);
		}
		else
		{
			aux = inicio;
			do
			{
				if (aux->dato == dato)
				{
					return(true);
				}
				else
				{
					aux = aux->sig;
				}
			} while (aux != inicio);
			if (aux == inicio)
			{
				return(false);
			}
		}
	}


};


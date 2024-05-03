// Lab3P3_CarlosBonilla.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
using namespace std;
#include <iostream>
#include <array>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
void imprimir(vector<int>& arreglo) {
	cout << "[ ";
	for (int i = 0; i < arreglo.size(); i++)
	{
		cout << arreglo[i]<<" ";
	}
	cout << "]"<<endl;
}
void imprimirdouble(double[] arreglo) {
	cout << "[ ";
	for (int i = 0; i < arreglo.size(); i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << "]" << endl;
}





void Eliminacion(vector<int>& alumnos, bool adelante=true) {
	if (alumnos.size()>1)
	{
		if (adelante)
		{
			vector<int>temp;
			if (alumnos.size() % 2 == 0)
			{
				for (int i = 0; i < alumnos.size(); i++)
				{
					if (i % 2 == 0)
					{
						temp.push_back(alumnos[i]);
					}

					adelante = false;

				}

			}
			else {
				for (int i = 0; i < alumnos.size(); i++)
				{
					if (i % 2 == 1)
					{
						temp.push_back(alumnos[i]);
					}

					adelante = false;

				}
			}
			imprimir(temp);
			Eliminacion(temp, adelante);
		}
		else {
			vector<int>temp;
			if (alumnos.size()% 2 == 0) {
				for (int i = alumnos.size() - 1; i < 0; i--)
				{
					if (i % 2 == 1)
					{
						temp.push_back(alumnos[i]);
					}
				}
			}
			else {
				for (int i = alumnos.size() - 1; i < 0; i--)
				{
					if (i % 2 == 1)
					{
						temp.push_back(alumnos[i]);
					}
				}
			}
			adelante = true;
			imprimir(temp);
			Eliminacion(temp, adelante);
		}
	}
	else {
		cout << "el alumno elegido es ";
		imprimir(alumnos);
	}
	
	}

void ejer1() {
	cout << "Ingrese el tamaño del arreglo de alumnos: ";
	int tamano = 0;
	cin >> tamano;
	cout << endl;
	vector<int> alumnos;
	do
	{
		if (tamano > 15 || tamano <= 0)
		{
			cout << "ingrese un valor valido para el arreglo";
		}
		else {
			for (int i = 0; i < tamano; i++)
			{
				alumnos.push_back(rand() % 10 + 1);
			}
			imprimir(alumnos);
		}
		
	} while (tamano > 15 || tamano <= 0);
	Eliminacion(alumnos);
	

}
vector<double> llenarArreglos(vector<double>& arreglo) {
	for (int i = 0; i < 20; i++)
	{
		arreglo.push_back(rand() % 20 + 1);
	}
	return arreglo;
}
void ejer2() {
	int tamano=0;
	do
	{
		cout << "ingrese el tamano de la longitud del arreglo (entre 2 y 10): ";
		cin >> tamano;
		cout<<endl;
		if ((tamano > 10) || tamano < 2)
		{
			cout << "ingrese un valor valido" << endl;
		}
	} while ((tamano>10)||tamano<2);
	
	double* X = new double[tamano];
	double* Y = new double[tamano];
	
	for (int i = 0; i < tamano; i++)
	{
		X[i] = rand() % 20 + 1;
		Y[i] = rand() % 20 + 1;
	}
	cout << "Elija 2 valores para usar en el ejercicio, dentro del rango del tamaño de los arreglos"<<endl;
	int valor1=0;
	do
	{
		cout << "valor 1: ";
		cin >> valor1;
		if (valor1 > tamano + 1 || valor1 < 0)
		{
			
			cout << "elija un valor entre 0 y " << tamano;
			cout<<endl;
		}
	} while (valor1>tamano+1||valor1<0);

	int valor2 = 0;
	do
	{
		cout << "valor 2: ";
		cin >> valor2;
		if (valor2 > tamano + 1 || valor2 < 0)
		{
			
			cout << "elija un valor entre 0 y " << tamano;
		}
	} while (valor2 > tamano + 1 || valor2 < 0);
	
	int menu = 0;
	do
	{
		cout << "1. Calculo de la Distancia Euclidiana"<<endl;
		cout << "2. Verificación de Colinealidad."<<endl;
		cout << "3. Cálculo de Punto Medio" << endl;
		cin >> menu;

		if (menu == 1) {
			double answer=(X[valor2] - X[valor1])* (X[valor2] - X[valor1]) + (Y[valor2] + Y[valor1]) * (Y[valor2] + Y[valor1]);
			cout <<"la distancia euclidiana entre los puntos "<<valor1<<" y "<<valor2 <<" es "<< sqrt(answer)<<endl;
		}
		else if (menu == 2) {
			cout << "me quede sin tiempo para este pipipi";
			double absoluto = abs(X[valor1] * (Y[valor2] - 0) - Y[valor1] * (X[valor2] - 0));
			cout<<"el area de los puntos " << valor1 << " y " << valor2 << " es " <<absoluto/2  << endl;
		}
		else if (menu == 3) {
			double puntoX;
			double puntoY;
			
			puntoX = (X[valor1] + X[valor2]) / 2;
			puntoY = (Y[valor1] + Y[valor2]) / 2;
			cout << "el punto medio entre los puntos " << valor1 << " y " << valor2 << " es X= " << puntoX << " y Y= " << puntoY<<endl;
		}
	} while (menu);

}

void menu()
{
	srand(time(NULL));
	int menu = 0;
	do{
		cout << "Laboratorio 3" << endl << "1. Ejercicio 1" << endl << "2. Ejercicio 2" << endl;
		cin >> menu;
		if (menu == 1) {
			ejer1();
		}
		else if (menu == 2) {
			ejer2();
		}
		else if(menu) {
			cout << "Ingrese una opcion valida" << endl;
		}
	} while(menu);
}
int main()
{
	menu();
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

// Simulaci�n AutoClick.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"
//Para las funciones GET
#include <windows.h>
//Para las funciones cout, cin
#include <iostream>
//Para getch
#include <conio.h> 


int _tmain(int argc, _TCHAR* argv[])
{
	//Declarar un valor l�gico para que podamos salir del programa cuando
	bool exit = false;
	//Importamos las funciones de la librer�a est�ndar
	using std::cout; //Salida de datos
	using std::cin; //Entrada de datos
	//Declaramos variables de tipo entero
	int xPos, yPos, numeroClic, retraso;
	//Variable de tipo char
	char input;
	POINT coordenada;//POINT es una estructura que sostiene x, y; Esto es necesario para GetCursorPos
	//Instrucci�n do while
	do{
		cin.clear(); //Borrar el b�fer
		//Imprimimos un mensaje
		cout << "Coloque el cursor en posici�n";
		cout << "\n Pulsa la tecla F8 para capturar las coordenadas";
		//Instrucci�n while
		while (true)
		{
			//La funci�n GetCursorPos recupera la posici�n del cursor del rat�n,
			//en coordenadas de pantalla.
			GetCursorPos(&coordenada);
			//Capturo la tecla F8 presionada
			/*La funci�n GetAsyncKeyState determina si una clave es hacia arriba o hacia abajo 
			a la vez que la funci�n se llama,y si la tecla fue presionada despu�s de una llamada
			previa a GetAsyncKeyState .*/
			if (GetAsyncKeyState(VK_F8))
			{
				xPos = coordenada.x;//Obtener las coordenadas correctas 
				yPos = coordenada.y;
				break;
			}
		}
		cout << "\n� Cu�ntas veces te gustar�a  hacer clic en la posici�n ";
		cout << xPos << ", ";
		cout << yPos << "?\n";
		cout << "Cuantos clic: ";
		//Obtenemos la cantidad de clic que har� en la posici�n
		cin >> numeroClic;
		cout << "Retardo (segundos) ";
		//Obtenemos el retraso que tendr� cada clic
		cin >> retraso;
		//Ciclo for que se recorre de pendiendo el n�mero de clic
		//haga clic en el n�mero de veces que nos propusimos
		for (int i = 1; i <= numeroClic; i++)
		{
			//La funci�n SetCursorPos mueve el cursor a las coordenadas de pantalla especificadas.
			SetCursorPos(xPos, yPos);
			//Eventos del mouse para generar los clics
			mouse_event(MOUSEEVENTF_LEFTDOWN, xPos, yPos, 0, 0); //Hacer los clic
			mouse_event(MOUSEEVENTF_LEFTUP, xPos, yPos, 0, 0);
			//La funci�n Sleep es usado para suspender la ejecuci�n de un programa
			Sleep(retraso * 1000);

		}
		cout << "�Desea reiniciar  y/n:";
		//Obtenemos el dato ingresado
		cin >> input;
		//Evaluamos la variable
		if (input == 'n')
		{
			exit = true; /*Valor de salida llega a ser verdad caus�ndonos
						 Para llegar al final del programa*/

		}
	} while (exit == false);
	return 0;
}


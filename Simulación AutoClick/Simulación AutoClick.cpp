// Simulación AutoClick.cpp: define el punto de entrada de la aplicación de consola.
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
	//Declarar un valor lógico para que podamos salir del programa cuando
	bool exit = false;
	//Importamos las funciones de la librería estándar
	using std::cout; //Salida de datos
	using std::cin; //Entrada de datos
	//Declaramos variables de tipo entero
	int xPos, yPos, numeroClic, retraso;
	//Variable de tipo char
	char input;
	POINT coordenada;//POINT es una estructura que sostiene x, y; Esto es necesario para GetCursorPos
	//Instrucción do while
	do{
		cin.clear(); //Borrar el búfer
		//Imprimimos un mensaje
		cout << "Coloque el cursor en posición";
		cout << "\n Pulsa la tecla F8 para capturar las coordenadas";
		//Instrucción while
		while (true)
		{
			//La función GetCursorPos recupera la posición del cursor del ratón,
			//en coordenadas de pantalla.
			GetCursorPos(&coordenada);
			//Capturo la tecla F8 presionada
			/*La función GetAsyncKeyState determina si una clave es hacia arriba o hacia abajo 
			a la vez que la función se llama,y si la tecla fue presionada después de una llamada
			previa a GetAsyncKeyState .*/
			if (GetAsyncKeyState(VK_F8))
			{
				xPos = coordenada.x;//Obtener las coordenadas correctas 
				yPos = coordenada.y;
				break;
			}
		}
		cout << "\n¿ Cuántas veces te gustaría  hacer clic en la posición ";
		cout << xPos << ", ";
		cout << yPos << "?\n";
		cout << "Cuantos clic: ";
		//Obtenemos la cantidad de clic que hará en la posición
		cin >> numeroClic;
		cout << "Retardo (segundos) ";
		//Obtenemos el retraso que tendrá cada clic
		cin >> retraso;
		//Ciclo for que se recorre de pendiendo el número de clic
		//haga clic en el número de veces que nos propusimos
		for (int i = 1; i <= numeroClic; i++)
		{
			//La función SetCursorPos mueve el cursor a las coordenadas de pantalla especificadas.
			SetCursorPos(xPos, yPos);
			//Eventos del mouse para generar los clics
			mouse_event(MOUSEEVENTF_LEFTDOWN, xPos, yPos, 0, 0); //Hacer los clic
			mouse_event(MOUSEEVENTF_LEFTUP, xPos, yPos, 0, 0);
			//La función Sleep es usado para suspender la ejecución de un programa
			Sleep(retraso * 1000);

		}
		cout << "¿Desea reiniciar  y/n:";
		//Obtenemos el dato ingresado
		cin >> input;
		//Evaluamos la variable
		if (input == 'n')
		{
			exit = true; /*Valor de salida llega a ser verdad causándonos
						 Para llegar al final del programa*/

		}
	} while (exit == false);
	return 0;
}


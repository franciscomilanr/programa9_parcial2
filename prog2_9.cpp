/* 
Autor: Franciscomilan
Realizado: 04/04/22 - 07/04/22
Escuela: Universidad UVM
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa 9 del parcial 2 en C que utiliza la libreria string para usar cadenas de caracteres y 
sus funciones mas comunes, el programa guarda los datos de un solo alumno por medio de una estructura
y usa funciones para la materia programacion estructurada
*/

//#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Variables globales
//Estructura alumno
struct alumno {
	char nombre[30];
	float promedio;
	int faltas;
};  
//Prototipos de funcion
void leers(char *mensaje, char s[], int n);
float leerf(char *mensaje, float inferior, float superior);
int leerd(char * mensaje, int inferior, int superior);
//Principal
int main() {
	//Variables
	struct alumno a1, a2; 
	//Entrada de datos
	leers(" Introduce el nombre: ", a1.nombre,30);
	//Proceso
	a1.promedio=leerf("Introduce el promedio: ",0,10); 	
	a1.faltas=leerd("Introduce las faltas: ",0,32);
	a2=a1; 
	//Salida
	printf("\n Datos del alumno: \n");
	printf(" Nombre: %s \n",a2.nombre);
	printf(" Promedio: %.1f \n", a2.promedio);
	printf(" Faltas: %d \n", a2.faltas);
	//Retorno
	return 0;
}

// Funcion leer cadena - nombre
void leers( char *mensaje, char s[], int n) {
	printf(mensaje);
	fgets(s,n,stdin);
	fflush(stdin); 		
	if (s[strlen(s)-1] == '\n') {
	    s[strlen(s)-1]=0;
	} 
}

//Funcion leer flotante - promedio
float leerf (char *mensaje, float inferior, float superior) {
	float valor;
	do {
		printf(mensaje);
		scanf("%f",&valor);
		if (valor<inferior || valor>superior ) {
			printf(" Dato inavalido !!! Debe estar entre (%.2f - %.2f). Vuelva a introducirlo: \n", inferior, superior);
		}
	}while (valor<inferior || valor>superior);
	//Retorno
	return valor;
}

//Funcion leer entero - faltas
float leerd (char *mensaje, int inferior, int superior) {
	int valor;
	do {
		printf(mensaje);
		scanf("%d",&valor);
		if (valor<inferior || valor>inferior) {
			printf(" Dato invalido !!! Debe estar entre (%d - %d). Vuelva a introducirlo: \n", inferior, superior);
		}
	}while (valor<inferior || valor>superior);
	//Retorno
	return valor;
}

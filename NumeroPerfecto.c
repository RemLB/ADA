/*INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

An�lisis y Dise�o de Algoritmos
Grupo: 3CM3

Alumnos:
GARC�S RODR�GUEZ VALERIA
GARC�A RAM�REZ SOEMMY GUADALUPE

Profesor:
LUNA BENOSO BEJAM�N

Fecha: 05-Octubre-2024

PRACTICA 2. COMPLEJIDADES TEMPORALES POLINOMIALES Y NO POLINOMIALES: N�mero Perfecto*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funci�n que verifica si un n�mero es perfecto
int Perfecto(int n, int *ct) 
{
	(*ct)++;
	int sum=0;
	// Se suman todos sus divisores (menores que n)
	(*ct)++;
	for (int i = 1; i < n; i++) 
	{
		(*ct)++;
		if (n % i == 0) //Se verifica si i es divisor de n (en caso de ser igual a 0) 
		{
			sum+= i; (*ct)++;
		}
	(*ct)++;
	}
	(*ct)++;
	// Si la suma sus divisores es igual a n entonces, es perfecto
	(*ct)++;
	return (sum==n);
}

// Funci�n que muestra los primeros n n�meros perfectos solicitados por el usuario
void MostrarPerfectos(int n) 
{
	int encontrados = 0;
	int num = 1;
	FILE *pf=fopen("NumeroPerfecto.csv", "at"); //creaci�n del archivo excel
	// Se realizan n busquedas de n�meros perfectos 
	while (encontrados < n) 
	{
		int ct=0;
		if (Perfecto(num, &ct)) 
		{

			printf("%d es un n�mero perfecto\n", num); 
			encontrados++;
			fprintf(pf,"%d,%d\n",num, ct);
		}
		num++;
	}
	fclose(pf);
}

void Inicio()
{
	int n;
	srand(time(NULL));
	printf("Ingrese la cantidad de n�meros perfectos a mostrar: ");
	scanf("%d", &n);
	MostrarPerfectos(n);
}

int main() 
{
	Inicio();
	return 0;
}


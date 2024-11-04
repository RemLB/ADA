/*INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

Análisis y Diseño de Algoritmos
Grupo: 3CM3

Alumnos:
GARCÉS RODRÍGUEZ VALERIA
GARCÍA RAMÍREZ SOEMMY GUADALUPE

Profesor:
LUNA BENOSO BEJAMÍN

Fecha: 05-Octubre-2024

PRACTICA 2. COMPLEJIDADES TEMPORALES POLINOMIALES Y NO POLINOMIALES: Número Perfecto*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que verifica si un número es perfecto
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

// Función que muestra los primeros n números perfectos solicitados por el usuario
void MostrarPerfectos(int n) 
{
	int encontrados = 0;
	int num = 1;
	FILE *pf=fopen("NumeroPerfecto.csv", "at"); //creación del archivo excel
	// Se realizan n busquedas de números perfectos 
	while (encontrados < n) 
	{
		int ct=0;
		if (Perfecto(num, &ct)) 
		{

			printf("%d es un número perfecto\n", num); 
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
	printf("Ingrese la cantidad de números perfectos a mostrar: ");
	scanf("%d", &n);
	MostrarPerfectos(n);
}

int main() 
{
	Inicio();
	return 0;
}


/*INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

Análisis y Diseño de Algoritmos
Grupo: 3CM3

Alumnos:
GARCÉS RODRÍGUEZ VALERIA
GARCÍA RAMÍREZ SOEMMY GUADALUPE

Profesor:
LUNA BENOSO BEJAMÍN

Fecha: 16-Octubre-2024

PRACTICA 3. FUNCIONES RECURSIVAS VS FUNCIONES ITERATIVAS: 
1.a Cuadrado de un número
2. Funcion Binary*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char A[15];
//Función iterativa que calcula el cuadrado de un número.
/*int Cuadrado_I(int n, int *ct)
{
	(*ct)++;
	int cuadrado = 0;
	(*ct)++;
	for (int i=0; i < n; i++)
	{
		(*ct)++;
		cuadrado+=n; 
		(*ct)++;
	}
	
	(*ct)++;
	return cuadrado;
}

//Función recursiva que calcula el cuadrado de un número.
int Cuadrado_R(int n, int p, int *ct)
{
	(*ct)++;
	if(p==0)
	{
		return 0;
	}
	else 
	{
		(*ct)++;
		return n + Cuadrado_R(n, p-1, ct);
	}
}*/

//La función genera todas las combinaciones binarias de longitud n, se imprime cuándo n es menor a 1
void Binary(int n, int *ct)
{
	(*ct)++;
	if(n<1)
	{
		printf("%s\n", A); (*ct)++;
	}
	else	   
	{
		(*ct)++;
		A[n-1]='0';
		Binary(n-1, ct);
		A[n-1]='1';
		Binary(n-1, ct);
	}
}

void Inicio()
{
	FILE *pf=fopen("CuadradosBinario.csv", "at");
	int n, rep, ct;
	srand(time(NULL));
	printf("Ingrese un número de ejecuciones que desea obtener: ");
	scanf("%d", &rep);
	for(int i=0; i<rep; i++)
	{
		/*ct=0;
		printf("Introduzca un número:\n");
		scanf("%d", &n);
		printf("Cuadrado de %d es: %d\n", n, Cuadrado_I(n,&ct));
		//fprintf(pf, "%d,%d\n", n,ct);
		
		//ct=0;
		printf("Cuadrado de %d es: %d\n", n, Cuadrado_R(n,n,&ct));
		fprintf(pf, "%d,%d\n", n, ct);*/
		
		printf("Introduzca el tamaño de la cadena binaria:");
		scanf("%d", &n);
		ct=0; //se reinicia el contador antes de llamar a Binary 
		Binary(n, &ct);
		fprintf(pf, "Binary, %d,%d\n", n, ct);
	}
	fclose(pf);
}

int main() 
{
	Inicio();
	return 0;
}


/*INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO

Análisis y Diseño de Algoritmos
Grupo: 3CM3

Alumnos:
	GARCÉS RODRÍGUEZ VALERIA
	GARCÍA RAMÍREZ SOEMMY GUADALUPE

Profesor:
	LUNA BENOSO BEJAMÍN

Fecha: 19-Septiembre-2024

PRACTICA 1. DETERMINACION EXPERIMENTAL DE LA COMPLEJIDAD TEMPORAL DE UN ALGORITMO: Punto Silla*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerarAleatorio(int **M, int fil, int col)
{
	srand(time(NULL));
	int i, j;
	for (i=0; i<fil; i++)
	{	
		for (j=0; j<col; j++)
		{	
			M[i][j]= rand()%100;
		}
		printf("\n");
	}
}

void MejorCasoA(int **M, int a, int b, int fil, int col)
{
	srand(time(NULL));
	//FORZAR MEJOR CASO
	a=0,b=0;
	for (int i=0; i<fil; i++)
		for (int j=0; j<col; j++)
		{
		    if(i==a)
                M[i][j]=rand()%25+25;
            else if(j==b)
                M[i][j]=rand()%25;
            else
                M[i][j]=rand()%50;
		}
		M[a][b]=25;
}
void PeorCasoA(int **M, int a, int b, int fil, int col)
{
	srand(time(NULL));
	//FORZAR PEOR CASO
	int i, j;
	for (i=0; i<fil; i++)
		for (j=0; j<col; j++)
		{
			if(i==a)
			M[i][j]=rand()%25+25;
			else if(j==b)
				M[i][j]=rand()%25;
			else
			M[i][j]=rand()%50;
		}
	M[a][b]=25;
}

void imprimir(int **M, int fil, int col)
{
    int i,j;
	for (i=0; i<fil; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%d\t", M[i][j]);
		}
		printf("\n");
	}
}
int minFila(int **M, int i, int col, int *ct)
{
	(*ct)++; (*ct)++;
	int aux=M[i][0];
	(*ct)++;(*ct)++;
	for(int k=0; k<col;k++)
	{
		(*ct)++;
		aux=aux<M[i][k]?aux:M[i][k];(*ct)++;
		(*ct)++;
	}
	(*ct)++;
	
	(*ct)++;
	return aux;
}

int maxColumna(int **M, int fil, int j, int *ct)
{
	(*ct)++; (*ct)++;
	int aux=M[0][j];
	(*ct)++; 
	(*ct)++;
	for(int k=0;k<fil;k++)
	{
		(*ct)++;
		aux=aux>M[k][j]?aux:M[k][j];(*ct)++;
		(*ct)++;
	}
	(*ct)++;
	(*ct)++;
	return aux;
}

//Funcion para el caso a.
void PuntoSillaA(int **M, int fil, int col, int *ct)
{
	int p=0; (*ct)++;
	int a, b;
	
	(*ct)++;
	(*ct)++;
	for(int i=0; i<fil && p==0; i++)
	{
		(*ct)++;
		
		(*ct)++;
		(*ct)++;
		for (int j=0; j<col && p==0; j++)
		{
			(*ct)++;
		    if(M[i][j] == minFila(M,i,col, ct) && M[i][j] == maxColumna(M,fil,j, ct))
            {
				(*ct)++;
                p=1; (*ct)++;
                a=i;
                b=j;
            }
			(*ct)++;
		(*ct)++;	
		}
		(*ct)++;
	(*ct)++;
	}
	(*ct)++;
	if(p==1)
        printf("\n[%d][%d]=%d\n", a,b,M[a][b]);(*ct)++;
}

// Función para encontrar todos los puntos silla
void PuntoSillaB(int **M, int fil, int col, int *ct)
{
	int puntosSilla = 0; (*ct)++; // Contador para verificar si se encontraron puntos silla
	
	// Recorre cada elemento de la matriz
	(*ct)++;
	(*ct)++;
	for (int i = 0; i < fil; i++)
	{
		(*ct)++;
		
		(*ct)++;
		(*ct)++;
		for (int j = 0; j < col; j++)
		{
			// Verifica si M[i][j] es un punto silla
			(*ct)++;
			if (M[i][j] == minFila(M, i, col, ct) && M[i][j] == maxColumna(M, fil, j, ct))
			{
				(*ct)++;
				// Imprime el punto silla encontrado y su posición
				printf("Punto silla encontrado en [%d][%d] = %d\n", i, j, M[i][j]); (*ct)++;
				puntosSilla++; (*ct)++;
			}
			(*ct)++;
		(*ct)++;
		}
		(*ct)++;
	(*ct)++;
	}
	
	// Si no se encontraron puntos silla
	(*ct)++;
	if (puntosSilla == 0)
	{
		printf("No se encontraron puntos silla en la matriz.\n");(*ct)++;
	}
}

void principal()
{
	FILE *pf=fopen("puntoSilla.csv", "at"); //creación del archivo excel
	int i,ct;
	srand(time(NULL));
	int fil=3, col=4;
	fil=col=3;
	
	printf("\nInciso 'A' Mejor Caso:\n");
	for(i=0; i<20; i++)
	{
		ct=0;
		int **M=(int **)malloc(fil*sizeof(int*));
		for(i=0;i<fil;i++)
		
			M[i]=(int*)malloc(col*sizeof(int));
			//Se plantea el mejor caso para el inciso A: El Punto silla se encuentra en la primera posición
			MejorCasoA(M,fil-1, col-1, fil, col);
			printf("Matriz:\n");
			imprimir(M,fil,col);
			PuntoSillaA(M,fil,col, &ct);
			fprintf(pf,"%d,%d\n", fil*col,ct);
			
			//Se plantea el peor caso para el inciso A: El Punto silla se encuentra en la ultima posición
			/*PeorCasoA(M,fil-1, col-1, fil, col);
			printf("Matriz:\n");
			imprimir(M,fil,col);
			PuntoSillaA(M,fil,col, &ct);
			fprintf(pf,"%d,%d\n", fil*col,ct);*/
			
			/*Se plantea mejor o peor caso para el inciso B: Al ser más de un punto silla, se recorre la matriz 
			ya sea buscando todos los puntos o para no encontrar ninguno*/
			/*GenerarAleatorio(M, fil, col);
			printf("Matriz:\n");
			imprimir(M,fil,col);
			PuntoSillaB(M,fil,col, &ct);
			fprintf(pf,"%d,%d\n", fil*col,ct);*/
		
			fil+=1;
			col+=1;

	}
	fclose(pf);
}


int main()
{
	principal();
	return 0;
}


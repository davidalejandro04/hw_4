#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void cargarDatos(double **matriz);
void obtenerCoordenadas(double **Matriz, double *x,double *y);
double **Matriz(void);
double aleatorio(void);
double calcularRadio(double x0, double y0);
void freeMatriz(double **matriz);

int nx=744;
int ny=500;
int N=120877;

double delta = 2;
double *x;
double *y;
double rmax,xmax,ymax;


void cargarDatos(double **matriz)
{

	char *delimiter=" ";

	FILE* f = fopen("map_data.txt", "r");

	char data[10000];
	char * pch;
	int i;
	int j=0;
	while(fscanf(f, "%s",data)==1)
	{
		

			pch = strtok(data," ");
			matriz[j/744][j%744]=atof(pch);

			j++;
	}
	pch=strtok(NULL, " ");


	fclose(f);

}


double **Matriz(void)
{
    int i;
    double **matriz;
    matriz = malloc(ny*sizeof(double *));

    for(i = 0; i < ny; i++)
    {
        matriz[i] = malloc(nx*sizeof(double *));
    }

    return matriz;
}	  


void freeMatriz(double **matriz)
{
    int i;
    for(i = 0; i<ny; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}


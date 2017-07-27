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
void hallarPuntin(void);

int nx=744;
int ny=500;
int N=120877;

double delta = 2.5;
double *x;
double *y;
double rmax,xmax,ymax;
double **matriz;
int i,j;


int main(void)
{   
	
	x= malloc(N*sizeof(double));
	y= malloc(N*sizeof(double)); 
	matriz=Matriz();
	cargarDatos(matriz);
	obtenerCoordenadas(matriz,x,y);
	hallarPuntin();

return 0;


}

void hallarPuntin()
{

	double xActual, xAnterior, yActual, yAnterior, rActual, rAnterior, alfa;

	xAnterior = (2*aleatorio()*N/744);
	yAnterior = (2*aleatorio()*N/500 );
	rAnterior = calcularRadio(xAnterior, yActual);
	

	FILE *file = fopen("radios.dat", "w");

	for(i=0; i<500; i++)
	{

		xActual = xAnterior + (2*aleatorio() - 1)*delta;
		yActual = yAnterior + (2*aleatorio() - 1)*delta;

		if(xActual<0 )
		{	
			xActual=744-xActual;
		}
		if(yAnterior<0 )
		{	
			yAnterior=500-yAnterior;
		}
		if(xActual>744 )
		{	
			xActual=744-xActual;
		}
		if(yAnterior>500 )
		{	
			yAnterior=500-yAnterior;
		}
		
		rActual = calcularRadio(xActual, yActual);
		alfa = exp((rActual - rAnterior));

		if(rActual>rmax)
		{
			rmax =rActual;
			ymax =yActual;
			xmax=xActual;
		}
			if(alfa > 1)
			{
				alfa = 1;
			}
			if(alfa > aleatorio())
			{
				xAnterior = xActual;
				yAnterior = yActual;
				rAnterior = rActual;
			}
			fprintf(file, "%f %f %f\n", xAnterior, yAnterior, rAnterior);
	}
	fprintf(file, "%f %f %f\n", xAnterior, yAnterior, rAnterior);
	fclose(file);


	//Regla de tres para las coordenadas
	xmax=-xmax*2*180/nx;
	ymax=ymax*2*90/ny-90;
	rmax=rmax*20000/744;


	//Imprimir punto
	printf("El radio mas grande es :%lfKm\nEn las coordenadas: latitud: %lf longitud: %lf\n",rmax,ymax,xmax);

}


double aleatorio(void)
{
    return (double) rand()/RAND_MAX;
}


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



void obtenerCoordenadas(double **matriz, double *x,double *y)
{	
	int k=0;
	int i;
	int j;
	for( i=0; i<ny; i++)
	{
		for( j=0; j<nx; j++)
		{
			if(matriz[i][j]==1)
			{
				x[k]=(double)i;
				y[k]=(double)j;
				k=k+1;			
			}
		}
	}
	
}

double calcularRadio(double x0, double y0)
{
    int i;
    double min, actual;
    min = pow(pow(x[0] - x0, 2.0) + pow(y[0] - y0, 2.0), 0.5);
    for(i = 1; i<N; i++)
    {
	
		actual = pow(pow(x[i] - x0, 2.0) + pow(y[i] - y0, 2.0), 0.5);
		if(actual < min)
		{
		    min = actual;
		}
	
    }
    return min;
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


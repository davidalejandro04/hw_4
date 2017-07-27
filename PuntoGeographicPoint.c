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


/*
 * nomPrograma:
 * descripcion:
 *
 * *//**Todavia falta completar o modificar*
      *Agregar Ordenar vector**//*
 * autor: ROMAN CESPEDES, Samuel Aaron
 *        TORRE ARTEAGA, Alexander
 *        CARMEN CRUZATTI, Angel Gerardo
 *        GIL JAUREGUI, Jesus Orlando
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int const MAX=100;
using namespace std;

struct CALCULO{
   int codAlu;
   float promFinal;
};

struct PRACTICA{
 	int codAlu=0;
	int codCur=0;
   int prac[10];
   int promedio;
};

struct EXPARCIAL{
	int codAlu=0;
	int codCur=0;
	float expar=0;
};

struct EXFINAL{
	int  codAlu=0;
	int codCur=0;
	float exfin=0;
};

void RecuperarNotas(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int *dx, int *dy, int *dz);
void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int dx, int dy, int dz);

int main()
{
   PRACTICA p[MAX];
   EXPARCIAL par[MAX];
   EXFINAL fin[MAX];
   int np,npar,nfin;
   RecuperarNotas(p,par,fin,&np,&npar,&nfin);
   CalculoPromedio(p,par,fin,np,npar,nfin);

   system("pause");
   return(0);
}

void RecuperarNotas(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int *dx, int *dy, int *dz){
   FILE *A,*B,*C,*D;
   int i;
   A= fopen("Practica.dat","r");
   B= fopen("Parcial.dat","r");
   C= fopen("Final.dat","r");
   D= fopen("PromedioFinal.dat","w");

   PRACTICA p;
   EXPARCIAL par;
   EXFINAL fin;

   if(A==NULL||B==NULL||C==NULL){
      printf("Error en la apertura de archivos...!\n");
      system("pause");
      exit(0);
   }
   i=0;
   fread(&p,sizeof(PRACTICA),1,A);
   while(!feof(A)){
         x[i]=p;
        fread(&p,sizeof(PRACTICA),1,A);
        i++;
   }
   *dx=i;
   fclose(A);
   i=0;
   fread(&par,sizeof(EXPARCIAL),1,B);
   while(!feof(B)){
         y[i]=par;
        fread(&par,sizeof(EXPARCIAL),1,B);
        i++;
   }
   *dy=i;
   fclose(B);
   i=0;
   fread(&fin,sizeof(EXFINAL),1,C);
   while(!feof(C)){
         z[i]=fin;
        fread(&fin,sizeof(EXFINAL),1,C);
        i++;
   }
   *dz=i;
   fclose(C);
}

void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int dx, int dy, int dz){
   CALCULO prom[MAX];
   int i=0;
   float suma=0;
   if(dx==dy&&dx==dz){
      for(i=0;i<dx;i++){
         suma=x[i].promedio+y[i].expar + z[i].exfin;// registros previamente ordenados
         suma=suma/4;
         prom[i].codAlu=x[i].codAlu;
         prom[i].promFinal=suma;
         suma=0;
      }
   }
}

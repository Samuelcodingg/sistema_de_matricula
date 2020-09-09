/*
 * nomPrograma:
 * descripcion:
 *
 * *//**Todavia falta completar o modificar*//*
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
   char nomAlu[40];
   char escuela[4];
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

void crearVector(int *dp);
void RecuperarNotas(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int *dx, int *dy, int *dz);
void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[],CALCULO prom[], int dx, int dy, int dz,int *dp);

void encabezado();
void raya1();
void raya2();

int main()
{
   PRACTICA p[MAX];
   EXPARCIAL par[MAX];
   EXFINAL fin[MAX];
   CALCULO prom[MAX];
   int np,npar,nfin,nprom;
   RecuperarNotas(p,par,fin,&np,&npar,&nfin);
   CalculoPromedio(p,par,fin,prom,np,npar,nfin,&nprom);
   system("pause");
   return(0);
}
void crearVector(int *dp){
   *dp=-1;
}
void RecuperarNotas(PRACTICA x[], EXPARCIAL y[], EXFINAL z[], int *dx, int *dy, int *dz){
   FILE *A,*B,*C,*D;
   int i;
   A= fopen("Practica.dat","r");
   B= fopen("Parcial.dat","r");
   C= fopen("Final.dat","r");
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

void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[],CALCULO prom[], int dx, int dy, int dz,int *dp){//falta modificar
   int i=0;
   float suma=0;
   int codigo;

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

void mostrarPromedios(CALCULO prom[], int dp){
   int i;
   if(dp>0){
      for(i=0;i<dp;i++){
         encabezado();
         printf("%3d\t%-12d%-30s%-10s%-10.1f\n",i+1,prom[i].codAlu,prom[i].nomAlu,prom[i].escuela,prom[i].promFinal);

      }
   }else{
      printf("\nVector vacioooo...!\n");
   }
   system("pause");
}

void encabezado(){
   system("cls");
   char title[]="REGISTRO DE PROMEDIOS FINALES";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="APELLIDOS, Nombres";
   char escuela[]="ESCUELA";
   char nota[]="NOTA";
   printf("\n\t\t%s\n\n",title);
   raya1();
   printf("%-6s\t%-12s%-30s%-14s%-5s\n",num,cod,nom,escuela,nota);
   raya2();
}

void raya2()
{
   printf("-------------------------------------------------------------------------------------------------------------\n");
}

void raya1()
{
   printf("=============================================================================================================\n");
}

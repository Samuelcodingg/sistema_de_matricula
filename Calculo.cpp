/*
 * nomPrograma:
 * descripcion:
 *
 * 
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
#include <string.h>
int const MAX=100;
using namespace std;

struct CALCULO{
   int codAlu;
   char nomAlu[40];
   char escuela[4];
   float promFinal;
};

struct FECHA{
	int dia;
   int mes;
	int anio;
};

struct ALUMNO{
   int  codAlu;
	char nomAlu[40];
	char escuela[4];
	FECHA fnac;
	float peso;
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
void RecuperarNombreyEscuela(CALCULO prom[]);
void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[],CALCULO prom[], int dx, int dy, int dz,int *dp);
void mostrarPromedios(CALCULO [],int);
int menu();

void encabezado();
void raya1();
void raya2();

int main()
{
   PRACTICA p[MAX];
   EXPARCIAL par[MAX];
   EXFINAL fin[MAX];
   CALCULO prom[MAX];
   ALUMNO a[MAX];
   int np,npar,nfin,nprom=0, opc=0;
   while(true){
      opc = menu();
      system("cls");
      switch (opc)
      {
      case 0:
         printf("\n\n\t\tGRACIAS POR USAR EL SISTEMA..!\n");
         system("pause");
         exit(0);
      case 1:
         RecuperarNotas(p,par,fin,&np,&npar,&nfin);
         break;
      case 2:
         RecuperarNombreyEscuela(prom);
         break;
      case 3:
         CalculoPromedio(p,par,fin,prom,np,npar,nfin,&nprom);
         break;
      case 4:;
         mostrarPromedios(prom,nprom);   
      default:
         break;
      }
      system("pause");
   }
   system("pause");
   return(0);
}
void crearVector(int *dp){
   *dp=-1;
}

int menu(){
   system("cls");
   int opc;

   printf("\n\n\t\tPROMEDIOS FINALES\n\n");
   printf("\t0.TERMINAR\n\n");
   printf("\t1.RECUPERAR NOTAS\n");
   printf("\t2.RECUPERAR NOMBRE Y ESCUELA\n");
   printf("\t3.CALCULAR PROMEDIO\n");
   printf("\t4.MOSTRAR\n");
   printf("  Digite su opcion--->");
   scanf("%d",&opc);

   return opc;
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
   printf("NOTAS RECUPERADAS...!\n");
}

void CalculoPromedio(PRACTICA x[], EXPARCIAL y[], EXFINAL z[],CALCULO prom[], int dx, int dy, int dz,int *dp){
   int i,j,k;
   float suma=0;
   int codigo;
   /*
   printf("N de Practicas %d\n",dx);
   printf("N de ExParcial %d\n",dy);
   printf("N de ExFinal %d\n",dz);
   */
   if(dx==dy&&dx==dz){
      printf("Ingreso");
      for(i=0;i<dx;i++){
         //Consistencia    Verificamos que todos tengan el mismo codigo de alumno
         codigo = prom[i].codAlu;
         for(j=0;j<dx;j++){
            
         }
         
         suma=x[i].promedio+y[i].expar + z[i].exfin;// registros previamente ordenados
         suma=suma/3;
         prom[i].codAlu=x[i].codAlu;
         prom[i].promFinal=suma;
         suma=0;
      }
      *dp = dx;
      printf("CALCULO HECHO...!\n");
   }
   else{
      printf("NO ES POSIBLE REALIZAR EL CALCULO...!\n");
   }
}

void mostrarPromedios(CALCULO prom[], int dp){
   int i;
   if(dp>0){
      encabezado();
      for(i=0;i<dp;i++){
         printf("%3d\t%-12d%-30s%-10s%-10.1f\n",i+1,prom[i].codAlu,prom[i].nomAlu,prom[i].escuela,prom[i].promFinal);
      }
   }else{
      printf("\nVector vacioooo...!\n");
   }
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

void RecuperarNombreyEscuela(CALCULO prom[]){
   int i;
   FILE *F;
   ALUMNO a;
   F = fopen("Alumnos.dat","r");

   if(F == NULL){
      printf("No se pudo abrir el archivo...!\n");
      system("pause");
      exit(0);
   }

   i=0;
   fread(&a,sizeof(ALUMNO),1,F);
   while(!feof(F)){
         //Capturamos los nombres y la escuela
         prom[i].codAlu = a.codAlu;
         strcpy(prom[i].nomAlu,a.nomAlu);
         fflush(stdin); 
         strcpy(prom[i].escuela,a.escuela);
        fread(&a,sizeof(ALUMNO),1,F);
        i++;
   }
   printf("DATOS DE ALUMNOS RECUPERADOS...!\n");
}

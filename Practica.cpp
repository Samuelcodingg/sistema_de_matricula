/*
 * nomPrograma
 * descripcion:
 *
 *
 * autor:  ROMAN CESPEDES, Samuel Aaron
 *         TORRE ARTEAGA, Alexander
 *         CARMEN CRUZATTI, Angelo Gerardo
 *         GIL JAUREGUI, Jesus Orlando
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

const int MAX=100;
using namespace std;

struct PRACTICA{
 	int codAlu=0;
	int codCur=0;
   int prac[10];
   int promedio;
};
void crearVector(int *dx);
void leerVectorPc(PRACTICA p[MAX],int *dx);
void mostrarVectorPc(PRACTICA p[MAX],int dx);
int buscarPcxCodAlu(PRACTICA p[MAX],int dx,int cod);
int buscarPcxCodCurso(PRACTICA p[MAX],int dx,int cod);
void editarporCodigoPc(PRACTICA p[MAX], int dx);
void editarPc(PRACTICA p[MAX],int dx);
void insertarporPosPc(PRACTICA p[MAX],int dx,int aux,int pos);
void fileSalvarPractica(FILE *F,PRACTICA p[MAX],int dx);
void fileRecuperarPractica(FILE *F);
void menu(PRACTICA p[MAX],FILE *FPC,int *dx,int &opc);
void encabezado2(char title[]);
void raya3();
void raya4();

int main (){
    FILE *FPC;
    int np=2,opc;
    PRACTICA p[]={
      100, 113, {13,14,15,12,14,12,14,13,14,11},13,
      101,113, {8,9,11,12,13,16,11,12,14,7},11,
      103,113, {15,20,11,16,15,14,13,15,15,11},15,
      106,113, {8,8,8,9,6,14,9,10,11,11},9,
   };
   np = sizeof(p)/(sizeof(int)*4 );
    do{
      menu(p,FPC,&np,opc);

   }while(opc!=0);

    system("pause");
    return 0;

}
void menu(PRACTICA p[MAX],FILE *FPC,int *dx,int &opc){


   system("cls");
   printf(" \n\nSISTEMA DE NOTAS DE EXAMEN FINAL\n\n");
   printf("0. TERMINAR \n\n");
   printf("1. CREAR\n");
   printf("2. LEER\n");
   printf("3. MOSTRAR\n");
   printf("4. BUSCARxCodCur\n");
   printf("5. BUSCARxCodCur\n");
   printf("6. EDITAR\n");
   printf("7. INSERTAR\n");
   printf("8. SALVAR\n");
   printf("9. RECUPERAR\n");
   do{
      printf("\nDigite su opcion ---> ");
      scanf("%d",&opc);
   }while(opc<0 || opc>9);
        system("cls");
        switch(opc){
            case 0:
                system("cls");
                printf("SALIO DEL PROGRAMA\n");
                system("pause");
                exit(0);
            case 1:
                crearVector(dx);
                break;
            case 2:
                leerVectorPc(p,dx);
                break;
            case 3:
                mostrarVectorPc(p,*dx);
                break;
            case 4:
            {
                int cod;
                printf("Digita el codigo a buscar: ");
                scanf("%d",&cod);
                buscarPcxCodCurso(p,*dx,cod);
            }
            break;
            case 5:
            {
                int cod;
                printf("Digita el codigo a buscar: ");
                scanf("%d",&cod);
                buscarPcxCodAlu(p,*dx,cod);
            }
            break;
            case 6:
                editarPc(p,*dx);
                break;
            case 7:
            {

               int aux=0,pos=0;
               insertarporPosPc(p,*dx,aux,pos);
            }
            break;
            case 8:
                fileSalvarPractica(FPC,p,*dx);
                break;
            case 9:
                fileRecuperarPractica(FPC);
                break;
            default:
                printf("Opcion invalida....!\n");
        }
        system("pause");
    }


void crearVector(int *dx){
    *dx=-1;
}
void leerVectorPc (PRACTICA p[MAX],int *dx)
{
   int i=0,k=0, n,suma;
   printf("\n\tINGRESO DE LA LISTA DE PRACTICAS:\n\n");
   printf("\n\nNumero de Alumnos---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tCurso:  %d\n", i+1);
         cout <<" Codigo de Alumno---> ";
         cin >>p[i].codAlu;
         cout <<" Codigo de Curso ---> ";
         cin>>p[i].codCur;
         printf("\n\n\tIngrese las notas de las practicas calificadas: \n");
            for(k=0;k<10;k++){
               printf("\n\t\tPractica %d: ",k+1);
               cin>>p[i].prac[k];
               cout<<endl;
               suma=suma+p[i].prac[k];
            }
            p[i].promedio=suma/10;
            suma=0;
            printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,p[i].promedio);
         }
          *dx = i;
   }else{
      printf("\nRegistro de alumnos vaciooo...\n\n");
   }
   system("pause");
}
void mostrarVectorPc(PRACTICA p[MAX],int dx){
   int i=0,j=0,contblanco=0;
   PRACTICA vacio;
   vacio.codAlu=0;
   char titulo[]="\n\nREPORTE DE PROMEDIO DE PRACTICAS";
   if(dx>0){
      for(i=0;i<dx;i++){
         if(p[i].codAlu==vacio.codAlu){
            contblanco=contblanco+1;//no mostrar elementos en blanco
         }
      }
      encabezado2(titulo);
      for(i=0;i<dx-contblanco;i++){
         printf("%3d\t%-12d%-10d\n",i+1,p[i].codAlu,p[i].promedio);
      }
      printf("\n");
      system("pause");
   }else{
      printf("\nRegistro de alumnos vaciooo.\n\n");
      system("pause");
   }
}
void encabezado2(char title[]){
   system("cls");
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char promedio[]="PROMEDIO";
   printf("\t\t%s\n\n",title);
   raya3();
   printf("%-6s\t%-12s%-5s\n",num,cod,promedio);
   raya4();
}
void raya3(){
   printf("===============================\n");
}
void raya4(){
   printf("-------------------------------\n");
}
int buscarPcxCodCurso(PRACTICA p[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(p[i].codCur==cod){
         pos = i;
      }
   }

   return pos;
}
int buscarPcxCodAlu(PRACTICA p[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(p[i].codAlu==cod){
         pos = i;
      }
   }

   return pos+1;
}
void insertarporPosPc(PRACTICA p[MAX],int dx,int aux,int pos){
   int i,j,n,suma=0,comp=0;//comp es un valor bandera
   mostrarVectorPc(p,dx);
   if(aux==0){
   printf("Ingrese la posicion cuyas notas desea insertar: ");
   scanf("%i",&pos);
   }
   n = dx;
   n = n + 1;//
   i = dx;
   if(n<MAX){
      if(pos-1>-1 && pos-1<dx+1){
         dx=n;
         while(i>pos-1){
            p[i] = p[i-1];
            i = i-1;
         }
         printf("\n\n**Registro de PRACTICAS:\n");
         for(j=0;j<10;j++){
            printf("\n\tPractica %d: ",j+1);
            cin>>p[i].prac[j];
            cout<<endl;
            suma=suma+p[i].prac[j];
         }
         p[i].promedio=suma/10;
         suma=0;
         printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,p[i].promedio);

      printf("\nDatos INSERTADOS en posicion %d \n\n ",pos);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", pos);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
   system("pause");
}

void editarporCodigoPc(PRACTICA p[MAX], int dx){
   int cod,i,j,comp=0,suma=0;//comp es un valor bandera
   mostrarVectorPc(p,dx);
   printf("\n\nIngrese el codigo del alumno cuya nota desea editar: ");
   scanf("%i",&cod);
   for(i=0;i<dx;i++){
      if(p[i].codAlu==cod){
         comp=1;
         cout <<"\n\tCodigo "<<i+1<<". ";
         for(j=0;j<10;j++){
            printf("\n\t\tPractica %d: ",j+1);
            cin>>p[i].prac[j];
            cout<<endl;
            suma=suma+p[i].prac[j];
         }
         p[i].promedio=suma/10;
         suma=0;
         printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,p[i].promedio);
      }
   }
   if(comp==0){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cod);
   }
}

void editarPc(PRACTICA p[MAX],int dx){
   int cod,edit,i,suma=0;
   printf("Digite el codigo del curso:");
   scanf("%d",&cod);

   edit = buscarPcxCodCurso(p,dx,cod);

   if(edit == 0){
      printf("Practica no encontrada");
   }
   else{
      for(i=0;i<10;i++){
         printf("\n\n\tIngrese las notas de las practicas calificadas: \n");
         printf("\n\t\tPractica %d: ",i+1);
         cin>>p[edit].prac[i];
         cout<<endl;
         suma=suma+p[edit].prac[i];
      }
      p[edit].promedio=suma/10;
      suma=0;
      printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",edit+1,p[edit].promedio);
      printf("\n**Promedio de practicas guardada con exito...\n");
   }

}
void fileSalvarPractica(FILE *F,PRACTICA p[MAX],int dx){
    F = fopen("Practica.dat","a+");
    if(F == NULL){
        printf("Ha ocurrido un error...!\n");
        system("pause");
        exit(0);
    }

    for(int i=0;i<dx;i++){
        fwrite(&p[i],sizeof(PRACTICA),1,F);
    }

    printf("Datos guardados...!\n");
    fclose(F);
    system("pause");
}
void fileRecuperarPractica(FILE *F){
    int i=0;
    PRACTICA pp;
    F = fopen("Practica.dat","r+");
    char titulo[]="\n\nREPORTE DE Practicas";

    if(F==NULL){
        printf("Ha ocurrido un error...!\n");
        system("pause");
        exit(0);
    }

    encabezado2(titulo);
    fread(&pp,sizeof(PRACTICA),1,F);
    while(!feof(F)){
        printf("%3d\t%-12d%-10d\n",i+1,pp.codAlu,pp.promedio);
        fread(&pp,sizeof(PRACTICA),1,F);
        i++;
    }

    fclose(F);
    system("pause");
}
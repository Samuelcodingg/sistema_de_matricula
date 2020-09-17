/*
 * NombreProg :Exparcial.cpp
 * Descripcion:
 *Registro y archivo de examenes parciales de los alumnos, 
 *con operaciones basicas
 *
 * Autor:  ROMAN CESPEDES, Samuel Aaron
 *         TORRE ARTEAGA, Alexander
 *         CARMEN CRUZATTI, Angel Gerardo
 *         GIL JAUREGUI, Jesús Orlando
 * Fecha:
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

const int MAX=100;
using namespace std;

struct EXPARCIAL{
	int codAlu;
	int codCur;
	float expar;
};
//OPERACIONES BASICAS
void crearVectorParcial(int *dx);
void leerVectorParcial(EXPARCIAL par[MAX],int *dx);
void mostrarVectorParcial(EXPARCIAL par[MAX],int dx);
int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod);
void buscarParcialporCodigoCurso(EXPARCIAL par[MAX], int dx);
int buscarParcialxCodAlu(EXPARCIAL par[MAX],int dx,int cod);
void buscarParcialporCodigoAlumno(EXPARCIAL par[MAX], int dx);
void editarParcial(EXPARCIAL par[MAX],int dx);
void insertarPosParcial(EXPARCIAL par[MAX],int *dx,int pos,int expar);
//ARCHIVOS
void fileSalvarParcial(FILE *F,EXPARCIAL par[MAX],int dx);
void fileRecuperarParcial(FILE *F);
//MENU
void menu();
void encabezado(char title[]);
void raya1();
void raya2();

int main (){
    menu();
    system("pause");
    return 0;


}
void menu(){
   FILE *FP;
   int np,opc,pos;
   EXPARCIAL par[]={
        108,202,15,
        109,188,12,
        110,190,13,
        111,200,15,
    };
   np = sizeof(par)/(sizeof(int)*2 + sizeof(float));

   do{
   system("cls");
   printf(" \n\n\t\tSISTEMA DE NOTAS DE EXAMEN PARCIAL\n\n");
   printf("\t0. TERMINAR \n\n");
   printf("\t1. CREAR\n");
   printf("\t2. LEER\n");
   printf("\t3. MOSTRAR\n");
   printf("\t4. BUSCARxCodCur\n");
   printf("\t5. BUSCARxCodAlu\n");
   printf("\t6. EDITAR\n");
   printf("\t7. INSERTAR\n");
   printf("\t8. SALVAR\n");
   printf("\t9. RECUPERAR\n");
   do{
      printf("\nDigite su opcion ---> ");
      scanf("%d",&opc);
   }while(opc<0 || opc>9);
   switch(opc){
      case 0:

         system("cls");
         printf("Salio del programa\n");
         break;

      case 1:

         system("cls");
         crearVectorParcial(&np);
         break;

      case 2:

         system("cls");
         leerVectorParcial(par,&np);
         break;

      case 3:

         system("cls");
         mostrarVectorParcial(par,np);
         break;

      case 4:

         system("cls");
         buscarParcialporCodigoCurso(par, np);
         break;

      case 5:

         system("cls");
         buscarParcialporCodigoAlumno(par, np);
         break;

      case 6:

         system("cls");
         editarParcial(par,np);
         break;

      case 7:

         {
         system("cls");
         int pos,nota;
         printf("NUEVA NOTA: ");
         scanf("%d",&nota);
         printf("POSICION: ");
         scanf("%d",&pos);
         insertarPosParcial(par,&np,pos,nota);

         }
         break;

      case 8:

         system("cls");
         fileSalvarParcial(FP,par,np);
         break;

      case 9:

         system("cls");
         fileRecuperarParcial(FP);
         break;
         default:
         printf("Opcion invalida....!\n");

        }

    }while(opc!=0);
}


void crearVectorParcial(int *dx){
    *dx=-1;
}

void leerVectorParcial(EXPARCIAL par[MAX],int *dx)
{
   int i=0, n, cant = *dx;
   printf("\n\tINGRESO DE LA LISTA DE PARCIALES:\n\n");
   printf("\n\nNumero de PARCIALES---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tCurso:  %d\n", i+1);
         cout <<" Codigo de Alumno---> ";
          cin >>par[i].codAlu;
          cout <<" Codigo de Curso ---> ";
          cin>>par[i].codCur;
          cout <<" Nota ---> ";
          cin >>par[i].expar;
          cout<<endl;
      }
      *dx = i + cant;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      exit(1);
   }
   system("pause");
}

void mostrarVectorParcial(EXPARCIAL par[MAX],int dx){
   int i=0,contblanco=0;
   EXPARCIAL vacio;
   vacio.codAlu=0;
   char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";
   if(dx>0){
      for(i=0;i<dx;i++){
         if(par[i].codAlu==vacio.codAlu){
            contblanco=contblanco+1;
         }
      }
      encabezado(titulo);
      for(i=0;i<dx-contblanco;i++){
         printf("%3d\t%-12d%-10.1f\n",i+1,par[i].codAlu,par[i].expar);
      }
      printf("\n");
      system("pause");
   }else{
      printf("\nRegistro de alumnos vaciooo...\n\n");
      system("pause");
   }
}

void encabezado(char title[]){
   system("cls");
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nota[]="NOTA";
   printf("\t\t%s\n\n",title);
   raya1();
   printf("%-6s\t%-12s%-5s\n",num,cod,nota);
   raya2();
}
void raya1(){
   printf("===============================\n");
}
void raya2(){
   printf("-------------------------------\n");
}

int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(par[i].codCur==cod){
         pos = i;
      }
   }

   return pos+1;
}
void buscarParcialporCodigoCurso(EXPARCIAL par[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(par[i].codCur==cd){
         encabezado(titulo);
         printf("%3d\t%-12d%-10.1f\n",i+1,par[i].codCur,par[i].expar);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}

int buscarParcialxCodAlu(EXPARCIAL par[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(par[i].codAlu==cod){
         pos = i;
      }
   }

   return pos+1;
}
void buscarParcialporCodigoAlumno(EXPARCIAL par[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(par[i].codAlu==cd){
         encabezado(titulo);
         printf("%3d\t%-12d%-10.1f\n",i+1,par[i].codAlu,par[i].expar);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}

void insertarPosParcial(EXPARCIAL par[MAX],int *dx,int pos,int expar){
   int i, n=*dx+1;
   if(*dx+1>MAX){
      for(i=*dx+1;i>pos+1;i--){
         par[i-1].expar=par[i].expar;
      }
      par[pos-1].expar = expar;
      *dx=n;
   }
   else{
      printf("Excede Dimension");
   }
}

void editarParcial(EXPARCIAL par[MAX],int dx){
   int cod,edit,i;
   printf("CODIGO:");
   scanf("%d",&cod);

   edit = buscarParcialxCodCurso(par,dx,cod);

   if(edit == 0){
      printf("Parcial no encontrado");
   }
   else{
      printf("\n\n\tIngrese la nota del examen parcial: ");
      cin>>par[edit].expar;
      cout<<endl;
      printf("\n**Nota del examen parcial guardada con exito...\n");
   }
}

void fileSalvarParcial(FILE *F,EXPARCIAL par[MAX],int dx){
    F = fopen("Parcial.dat","a+");
    if(F == NULL){
        printf("Ha ocurrido un error...!\n");
        system("pause");
        exit(0);
    }

    for(int i=0;i<dx;i++){
        fwrite(&par[i],sizeof(EXPARCIAL),1,F);
    }

    printf("Datos guardados...!\n");
    fclose(F);
    system("pause");
}
void fileRecuperarParcial(FILE *F){
    int i=0;
    EXPARCIAL p;
    F = fopen("Parcial.dat","r+");
    char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";

    if(F==NULL){
        printf("Ha ocurrido un error...!\n");
        system("pause");
        exit(0);
    }

    encabezado(titulo);
    fread(&p,sizeof(EXPARCIAL),1,F);
    while(!feof(F)){
        printf("%3d\t%-12d%-10.1f\n",i+1,p.codAlu,p.expar);
        fread(&p,sizeof(EXPARCIAL),1,F);
        i++;
    }

    fclose(F);
    system("pause");
}

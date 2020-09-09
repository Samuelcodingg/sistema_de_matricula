/*
 * NombreProg : 
 * Descripcion: 
 *             
 *   
 *    
 *    
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

void crearVectorParcial(int *dx);
void leerVectorParcial(EXPARCIAL par[MAX],int *dx);
void mostrarVectorParcial(EXPARCIAL par[MAX],int dx);
int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod);
int buscarParcialxCodAlu(EXPARCIAL par[MAX],int dx,int cod);
void editarParcial(EXPARCIAL par[MAX],int dx);
void insertarPosParcial(EXPARCIAL par[MAX],int *dx,int pos,int expar);
void fileSalvarParcial(FILE *F,EXPARCIAL par[MAX],int dx);
void fileRecuperarParcial(FILE *F);


void encabezado2(char title[]);
void raya3();
void raya4();

int main(){
    FILE *FP;
    int np, menu=0,opc;
    EXPARCIAL par[]={
        108,112,15,
        109,154,12,
        110,142,13,
        111,122,15,   
    };
    np = sizeof(par)/(sizeof(int)*2 + sizeof(float));
    
    while(menu==0){
        system("cls");
        printf("\n\n\t\tSISTEMA DE NOTAS EXPARCIAL\n\n");
        printf("\t0.SALIR\n\t1.CREAR\n\t2.LEER\n\t3.MOSTRAR\n\t4.BUSCAR XCodCur\n\t5.BUSCAR xCodAlu.\n\t6.EDITAR\n\t7.INSERTAR\n\t8.SALVAR\n\t9.RECUPERAR\n");
        printf("\n\nDigite su opcion---> ");
        scanf("%d",&opc);

        system("cls");
        switch(opc){
            case 0:
                system("cls");
                printf("GRACIAS POR USAR EL SISTEMA!\n");
                system("pause");
                exit(0);
            case 1:
                crearVectorParcial(&np);
                break;
            case 2:
                leerVectorParcial(par,&np);
                break;
            case 3:
                mostrarVectorParcial(par,np);
                break;
            case 4:
            {
                int cod;
                printf("CODIGO: ");
                scanf("%d",&cod);
                buscarParcialxCodCurso(par,np,cod);
            }
            break;
            case 5:
            {
                int cod;
                printf("CODIGO: ");
                scanf("%d",&cod);
                buscarParcialxCodAlu(par,np,cod);
            }
            break;
            case 6:
                editarParcial(par,np);
                break;
            case 7:
            {
                int pos, nota;
                printf("Indica la nueva nota a insertar: ");
                scanf("%d",&nota);
                printf("Indica la posicion: ");
                scanf("%d",&pos);
                insertarPosParcial(par,&np,pos,nota);
            }
            break;
            case 8:
                fileSalvarParcial(FP,par,np);
                break;
            case 9:
                fileRecuperarParcial(FP);
                break;
            default:
                printf("Opcion invalida....!\n");
        }
        system("pause");
    }

    system("pause");
    return 0;

    system("pause");
    return 0;
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
      encabezado2(titulo);
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

void encabezado2(char title[]){
   system("cls");
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nota[]="NOTA";
   printf("\t\t%s\n\n",title);
   raya3();
   printf("%-6s\t%-12s%-5s\n",num,cod,nota);
   raya4();
}
void raya3(){
   printf("===============================\n");
}
void raya4(){
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

int buscarParcialxCodAlu(EXPARCIAL par[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(par[i].codAlu==cod){
         pos = i;
      }
   }
   
   return pos+1; 
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

    encabezado2(titulo);
    fread(&p,sizeof(EXPARCIAL),1,F);
    while(!feof(F)){    
        printf("%3d\t%-12d%-10.1f\n",i+1,p.codAlu,p.expar);
        fread(&p,sizeof(EXPARCIAL),1,F);
        i++;
    }

    fclose(F);
    system("pause");
}

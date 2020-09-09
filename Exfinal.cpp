/*
 * nomPrograma
 * descripcion:
 *
 *
 * autor: ROMAN CESPEDES, Samuel Aaron
 *        TORRE ARTEAGA, Alexander
 *        CARMEN CRUZATTI, Angel Gerardo
 *        GIL JAUREGUI, Jesús Orlando
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int MAX=100;
using namespace std;

struct EXFINAL{
	int  codAlu=0;
	int codCur=0;
	float exfin=0;
};

void crearVectorFinal(int *dx);
void leerVectorFinal(EXFINAL fin[MAX],int *dx);
void mostrarVectorFinal(EXFINAL fin[MAX],int dx);
int buscarFinalxCodCurso(EXFINAL fin[MAX],int dx,int cod);
int buscarFinalxCodAlu(EXFINAL fin[MAX],int dx,int cod);
void editarporCodigoFinal(EXFINAL fin[MAX], int dx);
void editarFinal(EXFINAL fin[MAX],int dx);
void insertarPosFinal(EXFINAL fin[MAX],int *dx,int pos,int exfin);

void fileSalvarFinal(FILE *F,EXFINAL fin[MAX],int dx);
void fileRecuperarFinal(FILE *F);

void menu(EXFINAL fin[MAX],FILE *FFIN,int *dx,int &opc);
void encabezado2(char title[]);
void raya3();
void raya4();


int main (){
   FILE *FFIN;
   int nfin=2,opc;
   EXFINAL fin[]={
        108,130,18,
        109,152,14,
        110,134,12,
        111,118,15,
    };
   nfin = sizeof(fin)/(sizeof(int)*2 + sizeof(float));

   do{
      menu(fin,FFIN,&nfin,opc);

   }while(opc!=0);

    system("pause");
    return 0;


}
void menu(EXFINAL fin[MAX],FILE *FFIN,int *dx,int &opc){


   system("cls");
   printf(" \n\n\t\tSISTEMA DE NOTAS DE EXAMEN FINAL\n\n");
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
         crearVectorFinal(dx);
         break;

      case 2:
         system("cls");
         leerVectorFinal(fin,dx);
         system("pause");
         break;
      case 3:
         system("cls");
         mostrarVectorFinal(fin,*dx);
         system("pause");
         break;
      case 4:
         {
         system("cls");
         int cod;
         printf("CODIGO: ");
         scanf("%d",&cod);
         buscarFinalxCodCurso(fin,*dx,cod);
         system("pause");
         }
         break;
      case 5:
         {
         system("cls");
         int cod;
         printf("CODIGO: ");
         scanf("%d",&cod);
         buscarFinalxCodAlu(fin,*dx,cod);
         system("pause");
         }
         break;
      case 6:
         system("cls");
         editarFinal(fin,*dx);
         system("pause");
         break;
      case 7:
         {
         system("cls");
         int pos, nota;
         printf("NUEVA NOTA: ");
         scanf("%d",&nota);
         printf("POSICION: ");
         scanf("%d",&pos);
         insertarPosFinal(fin,dx,pos,nota);
         system("pause");
         }
         break;
      case 8:
         system("cls");
         fileSalvarFinal(FFIN,fin,*dx);
         break;
      case 9:
         system("cls");
         fileRecuperarFinal(FFIN);
         break;
      default:
         printf("Opcion invalida....!\n");

        }
        system("pause");
    }


void crearVectorFinal(int *dx){
    *dx=-1;
}

void leerVectorFinal(EXFINAL fin[MAX],int *dx)
{
   int i=0, n;
   printf("\n\tINGRESO EN LA LISTA DE FINALES:\n\n");
   printf("\n\nNumero de FINALES---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tCurso:  %d\n", i+1);
         cout <<" Codigo de Alumno---> ";
         cin >>fin[i].codAlu;
         cout <<" Codigo de Curso ---> ";
         cin>>fin[i].codCur;
         cout <<" Nota ---> ";
         cin >>fin[i].exfin;
         cout<<endl;
      }
      *dx = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      exit(1);
   }

}
void mostrarVectorFinal(EXFINAL fin[MAX],int dx){
   int i=0,contblanco=0;
   EXFINAL vacio;
   vacio.codAlu=0;
   char titulo[]="\n\nREPORTE DE EXAMENES FINALES";
   if(dx>0){
      for(i=0;i<dx;i++){
         if(fin[i].codAlu==vacio.codAlu){
            contblanco=contblanco+1;
         }
      }
      encabezado2(titulo);
      for(i=0;i<dx-contblanco;i++){
         printf("%3d\t%-12d%-10.1f\n",i+1,fin[i].codAlu,fin[i].exfin);

      }
      printf("\n");

   }else{
      printf("\nRegistro de alumnos vaciooo...\n\n");
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
int buscarFinalxCodCurso(EXFINAL fin[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(fin[i].codCur==cod){
         pos = i;
      }
   }

   return pos+1;
}

int buscarFinalxCodAlu(EXFINAL fin[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(fin[i].codAlu==cod){
         pos = i;
      }
   }

   return pos;
}
void editarporCodigoFinal(EXFINAL fin[MAX], int dx){
   int cod,i,comp=0;//comp es un valor bandera
   mostrarVectorFinal(fin,dx);
   printf("\n\nIngrese el codigo del alumno cuya nota desea editar: ");
   scanf("%i",&cod);
   for(i=0;i<dx;i++){
      if(fin[i].codAlu==cod){
         comp=1;
         cout <<"\n\tCodigo "<<i+1<<". ";
         printf("\n\n\tIngrese la nota del examen Final: ");
         cin>>fin[i].exfin;
         cout<<endl;
      }
   }
   if(comp==0){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cod);
   }
}
void editarFinal(EXFINAL fin[MAX],int dx){
   int cod,edit,i;
   printf("Digite el codigo del curso:");
   scanf("%d",&cod);

   edit = buscarFinalxCodCurso(fin,dx,cod);

   if(edit == 0){
      printf("Examen Final no encontrado");
   }
   else{
      printf("\n\n\tIngrese la nota del examen Final: ");
      cin>>fin[edit].exfin;
      cout<<endl;
      printf("\n**Nota del examen Final guardada con exito...\n");
   }
}
void insertarPosFinal(EXFINAL fin[MAX],int *dx,int pos,int exfin){
   int i;
   if(*dx+1<MAX){
      for(i=*dx+1;i>pos+1;i--){
         fin[i-1].exfin=fin[i].exfin;
      }
      fin[pos-1].exfin = exfin;
      dx +=1;
   }
   else{
      printf("Excede Dimension");
   }
}
void fileSalvarFinal(FILE *F,EXFINAL fin[MAX],int dx){
    F = fopen("Final.dat","a+");
    if(F == NULL){
        printf("Ha ocurrido un error...!\n");
        system("pause");
        exit(0);
    }

    for(int i=0;i<dx;i++){
        fwrite(&fin[i],sizeof(EXFINAL),1,F);
    }

    printf("Datos guardados...!\n");
    fclose(F);
}
void fileRecuperarFinal(FILE *F){
    int i=0;
    EXFINAL f ;
    F = fopen("Final.dat","r+");
    char titulo[]="\n\nREPORTE DE EXAMENES FINALES";

    if(F==NULL){
        printf("Ha ocurrido un error...!\n");

        exit(0);
    }

    encabezado2(titulo);
    fread(&f,sizeof(EXFINAL),1,F);
    while(!feof(F)){
        printf("%3d\t%-12d%-10.1f\n",i+1,f.codAlu,f.exfin);
        fread(&f,sizeof(EXFINAL),1,F);
        i++;
    }

    fclose(F);
    system("pause");
}

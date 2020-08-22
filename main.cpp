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
 *         CARMEN CRUZATTI, Angelo Gerardo
 *         GIL JAUREGUI, Jesús Orlando
 * Fecha:
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
const int MAX=100;
using namespace std;

struct FECHA{
   int dia=0;
   int mes=0;
   int anio=0;
};

struct ALUMNO{
	int  codAlu=0;
	char nomAlu[40];
	char escuela[15];
	FECHA fnac;
	float peso=0;
};

struct PRACTICA{
 	int codAlu=0;
   int prac[10];
   int promedio;
};

struct EXPARCIAL{
	int  codAlu=0;
	float expar=0;
};

struct EXFINAL{
	int  codAlu=0;
	float exfin=0;
};

void crearVector(int *dx);
void leerVectorAlu(ALUMNO x[MAX], int *dx);
void mostrarVectorAlu(ALUMNO x[MAX], int dx);
void leerVectorPc(ALUMNO x[MAX],PRACTICA p[MAX],int dx);
void mostrarVectorPc(PRACTICA p[MAX],int dx);
void leerVectorParcial(ALUMNO x[MAX],EXPARCIAL par[MAX], int dx);
void mostrarVectorParcial(EXPARCIAL par[MAX],int dx);
void leerVectorFinal(ALUMNO x[MAX],EXFINAL fin[MAX], int dx);
void mostrarVectorFinal(EXFINAL fin[MAX],int dx);
void buscarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int dx);
void editarporCodigoAlu(ALUMNO x[MAX], int dx);
void editarporCodigoPc(PRACTICA p[MAX], int dx);
void editarporCodigoParcial(EXPARCIAL par[MAX], int dx);
void editarporCodigoFinal(EXFINAL fin[MAX], int dx);
void insertarporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx,int aux, int posi, int cod);
void eliminaporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx);
void ordenarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int dx);
void insertarporValor(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx, int aux);

void encabezado1();
void encabezado2(char title[]);
void raya1();
void raya2();
void raya3();
void raya4();

int Menu(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int *dx);
void Menu2(int op,ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int dx);

int main()
{

   ALUMNO a[MAX];
   int na,op;
   PRACTICA p[MAX];
   EXPARCIAL par[MAX];
   EXFINAL fin[MAX];
   crearVector(&na);
   printf("\n\n**Llenado del registro ALUMNOS:\n\n");
   leerVectorAlu(a,&na);
   mostrarVectorAlu(a,na);
   do{
      op=Menu(a,p,par,fin,&na);
      if(op!=0&&op==5||op==2||op==1){
         if(na>0){
            Menu2(op,a,p,par,fin,na);
         }else{
            printf("\nRegistro ALUMNOS vacio...");
         }
      }
   }while(op>=1&&op<=8);
   printf("\n\nPrograma finalizado...\n\n");
   system("pause");
   return(0);
}

void crearVector(int *dx)
{
   *dx=-1;
}

void leerVectorAlu(ALUMNO x[MAX], int *dx)
{
   int i=0, n, val;
   printf("\n\nNumero de ALUMNOS ---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tAlumno:  %d\n", i+1);
         cout <<" Codigo ---> ";
         cin >>x[i].codAlu;
         cout <<" Nombre ---> ";
         cin>>x[i].nomAlu;
         cout <<" Escuela ---> ";
         cin >>x[i].escuela;
         cout <<" Fecha de nacimiento(dd/mm/aaaa):"<<endl;
         cout<<"\tdd--->";
         cin >>x[i].fnac.dia;
         cout<<"\tmm--->";
         cin >>x[i].fnac.mes;
         cout<<"\taaaa--->";
         cin >>x[i].fnac.anio;
         cout <<" Peso(kg.)---> ";
         cin >>x[i].peso;
         cout<<endl;
      }
      *dx = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      system("pause");
      exit(1);
   }
}
void mostrarVectorAlu(ALUMNO x[MAX], int dx)
{
   int i;
   if(dx>0){
      encabezado1();
      for(i=0;i<dx;i++){
         printf("%3d\t%-12d%-32s%-18s%-d/%-d/%-18d%-.1fkg\n",i+1,x[i].codAlu,x[i].nomAlu,
                x[i].escuela,x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio,x[i].peso);
      }
      raya1();
      cout <<"\n\n";
      system("pause");
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}

void leerVectorPc(ALUMNO x[MAX],PRACTICA p[MAX], int dx){
   int i=0,j=0,k=0,comp,suma;
   if(dx>0){
     for(i=0;i<dx;i++){
         mostrarVectorAlu(x,dx);
         printf("\n\tINGRESO DE LAS PRACTICAS CALIFICADAS:\n\n");
         printf("\nIngrese los codigos de los alumnos: \n\n");
         comp=0;//cambia de valor si el codigo se encuentra en el registro AlUMNOS
         do{
            cout <<"\n\tCodigo "<<i+1<<" ---> ";
            cin >>p[i].codAlu;
            for(j=0;j<dx;j++){//compara si el codigo digitado se encuentra en el registro ALUMMNOS
               if(x[j].codAlu==p[i].codAlu){
                  comp=1;
               }
            }
            if(comp==0){
               printf("\nEl codigo digitado no se encuentra en el registro ALUMNOS.");
               printf("\nVuelva a digitar el codigo: \n");
            }
         }while(comp!=1);
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
         printf("\n**Promedio de practicas guardada con exito...\n");
         if(i<dx-1){
            printf("\n**Continue con el siguiente alumno...\n\n");
         }
         system("pause");
      }
   }else{
      system("pause");
      exit(1);
   }
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
      printf("\nReporte de practicas vacio.\n");
      system("pause");
      exit(1);
   }
}

void leerVectorParcial(ALUMNO x[MAX],EXPARCIAL par[MAX], int dx){
   int i=0,j=0,comp;
   if(dx>0){
      for(i=0;i<dx;i++){
         mostrarVectorAlu(x,dx);
         printf("\n\tINGRESO DE LOS EXAMENES PARCIALES:\n\n");
         printf("\nIngrese los codigos de los alumnos: \n\n");
         comp=0;//cambia de valor si el codigo se encuentra en el registro AlUMNOS
         do{
            cout <<"\n\tCodigo "<<i+1<<" ---> ";
            cin >>par[i].codAlu;
            for(j=0;j<dx;j++){//compara si el codigo digitado se encuentra en el registro ALUMMNOS
               if(x[j].codAlu==par[i].codAlu){
                  comp=1;
               }
            }
            if(comp==0){
               printf("\nEl codigo digitado no se encuentra en el registro ALUMNOS.");
               printf("\nVuelva a digitar el codigo: \n");
            }
         }while(comp!=1);
         printf("\n\n\tIngrese la nota del examen parcial: ");
         cin>>par[i].expar;
         cout<<endl;
         printf("\n**Nota del examen parcial guardada con exito...\n");
         if(i<dx-1){
            printf("\n**Continue con el siguiente alumno...\n\n");
         }
         system("pause");
      }
   }else{
      system("pause");
      exit(1);
   }
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
      system("pause");
      exit(1);
   }
}

void leerVectorFinal(ALUMNO x[MAX],EXFINAL fin[MAX], int dx){
   int i=0,j=0,comp;
   if(dx>0){
      for(i=0;i<dx;i++){
         mostrarVectorAlu(x,dx);
         printf("\n\tINGRESO DE LOS EXAMENES FINALES:\n\n");
         printf("\nIngrese los codigos de los alumnos: \n\n");
         comp=0;//cambia de valor si el codigo se encuentra en el registro AlUMNOS
         do{
            cout <<"\n\tCodigo "<<i+1<<" ---> ";
            cin >>fin[i].codAlu;
            for(j=0;j<dx;j++){//compara si el codigo digitado se encuentra en el registro ALUMMNOS
               if(x[j].codAlu==fin[i].codAlu){
                  comp=1;
               }
            }
            if(comp==0){
               printf("\nEl codigo digitado no se encuentra en el registro ALUMNOS.");
               printf("\nVuelva a digitar el codigo: \n");
            }
         }while(comp!=1);
         printf("\n\n\tIngrese la nota del examen final: ");
         cin>>fin[i].exfin;
         cout<<endl;
         printf("\n**Nota del examen final guardada con exito...\n");
         if(i<dx-1){
            printf("\n**Continue con el siguiente alumno...\n\n");
         }
         system("pause");
      }
   }else{
      system("pause");
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
      system("pause");
   }else{
      system("pause");
      exit(1);
   }
}
void buscarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int dx){
   int cd,i,comp=0;//comp es un valor bandera
   mostrarVectorAlu(x,dx);
   printf("\n\nIngrese el codigo del alumno a buscar: ");
   scanf("%i",&cd);
   for(i=0;i<dx;i++){
      if(x[i].codAlu==cd){
         comp=1;
         printf("\nAlumno %d\n",i+1);
         printf("Nombre: %s\n",x[i].nomAlu);
         printf("Escuela: %s\n",x[i].escuela);
         printf("Peso: %.1f\n",x[i].peso);
         printf("Fecha de nacimiento: %d/%d/%d \n",x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio);
      }
      if(p[i].codAlu==cd){
         comp=1;
         printf("Promedio de practicas: %d\n",p[i].promedio);
      }
      if(par[i].codAlu==cd){
         comp=1;
         printf("Nota de parcial: %.1f\n",par[i].expar);
      }
      if(fin[i].codAlu==cd){
         comp=1;
         printf("Nota de final %.1f\n",fin[i].exfin);
      }
   }
   if(comp==0){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cd);
   }
}
void editarporCodigoAlu(ALUMNO x[MAX], int dx){
   int cod,i,comp=0;//comp es un valor bandera
   mostrarVectorAlu(x,dx);
   printf("\n\nIngrese el codigo del alumno cuyos datos desea editar: ");
   scanf("%i",&cod);
   for(i=0;i<dx;i++){
      if(x[i].codAlu==cod){
         comp=1;
         printf("\n\tAlumno:  %d\n", i+1);
         cout <<" Nombre ---> ";
         cin>>x[i].nomAlu;
         cout <<" Escuela ---> ";
         cin >>x[i].escuela;
         cout <<" Fecha de nacimiento(dd/mm/aaaa):"<<endl;
         cout<<"\tdd--->";
         cin >>x[i].fnac.dia;
         cout<<"\tmm--->";
         cin >>x[i].fnac.mes;
         cout<<"\taaaa--->";
         cin >>x[i].fnac.anio;
         cout <<" Peso(kg.)---> ";
         cin >>x[i].peso;
         cout<<endl;
      }
   }
   if(comp==0){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cod);
   }
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
void editarporCodigoParcial(EXPARCIAL par[MAX], int dx){
   int cod,i,comp=0;//comp es un valor bandera
   mostrarVectorParcial(par,dx);
   printf("\n\nIngrese el codigo del alumno cuya nota desea editar: ");
   scanf("%i",&cod);
   for(i=0;i<dx;i++){
      if(par[i].codAlu==cod){
         comp=1;
         cout <<"\n\tCodigo "<<i+1<<". ";
         printf("\n\n\tIngrese la nota del examen parcial: ");
         cin>>par[i].expar;
         cout<<endl;
      }
   }
   if(comp==0){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cod);
   }
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

void insertarporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx,int aux,int posi,int cod){
   int i,j,n,suma=0,comp=0;//comp es un valor bandera
   mostrarVectorAlu(x,*dx);
   if(aux==0){// el aux verifica si se encuentra en la funcion insertar por posicion o insertar por valor
   printf("\n\nIngrese la posicion del alumno en el registro ALUMNOS,cuyos datos desea insertar en todos los registros: ");
   scanf("%i",&posi);
   }
   n = *dx;
   n = n + 1;//
   i = *dx;
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx+1){
         *dx=n;
         while(i>posi-1){
            x[i] = x[i-1];
            p[i] = p[i-1];
            par[i] = par[i-1];
            fin[i] = fin[i-1];
            i = i-1;
         }
         printf("\n**Registro de ALUMNOS: \n");
         printf("\n\tAlumno:  %d\n", posi);
         if(aux==0){
            cout <<" Codigo ---> ";
            cin >>cod;
         }
         x[i].codAlu=cod;
         p[i].codAlu=cod;
         par[i].codAlu=cod;
         fin[i].codAlu=cod;
         cout <<" Nombre ---> ";
         cin>>x[i].nomAlu;
         cout <<" Escuela ---> ";
         cin >>x[i].escuela;
         cout <<" Fecha de nacimiento(dd/mm/aaaa):"<<endl;
         cout<<"\tdd--->";
         cin >>x[i].fnac.dia;
         cout<<"\tmm--->";
         cin >>x[i].fnac.mes;
         cout<<"\taaaa--->";
         cin >>x[i].fnac.anio;
         cout <<" Peso(kg.)---> ";
         cin >>x[i].peso;
         cout<<endl;
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
         printf("\n\n**Registro de PARCIALES:\n");
         printf("\n\n\tIngrese la nota del examen parcial: ");
         cin>>par[i].expar;
         cout<<endl;
         printf("\n\n**Registro de FINALES: \n");
         printf("\n\n\tIngrese la nota del examen final: ");
         cin>>fin[i].exfin;
         cout<<endl;
      printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
   system("pause");
}

void eliminaporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx){
   int i,n,posi;
   mostrarVectorAlu(x,*dx);
   printf("\n\nIngrese la posicion del alumno en el registro ALUMNOS,cuyos datos desea eliminar de todos los registros: ");
   scanf("%i",&posi);
   n=*dx;
   n=n-1;
   i=posi-1;
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx){
         *dx=n;
         while(i<n){
            x[i] = x[i+1];
            p[i] = p[i+1];
            par[i] = par[i+1];
            fin[i] = fin[i+1];
            i = i+1;
         }
      printf("\nDatos del alumno de la posicion %d ELIMINADOS\n\n ",posi);
   }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
   system("pause");
}

void ordenarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int dx)
{
   int aux, i, j;
   if(dx>-1){
      for(i=0; i<dx-1;){
         for(j=i+1; j<dx;){
            if(x[i].codAlu>x[j].codAlu){
               aux=x[j].codAlu;
               x[j].codAlu=x[i].codAlu;
               x[i].codAlu=aux;
            }
            if(p[i].codAlu>p[j].codAlu){
               aux=p[j].codAlu;
               p[j].codAlu=p[i].codAlu;
               p[i].codAlu=aux;
            }
            if(par[i].codAlu>par[j].codAlu){
               aux=par[j].codAlu;
               par[j].codAlu=par[i].codAlu;
               par[i].codAlu=aux;
            }
            if(fin[i].codAlu>fin[j].codAlu){
               aux=fin[j].codAlu;
               fin[j].codAlu=fin[i].codAlu;
               fin[i].codAlu=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void insertarporValor(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx, int aux){
   int posi,i,j,n,suma=0;
   int codigo;
   mostrarVectorAlu(x,*dx);
   printf("\n\nLos codigos de los registros han sido ordenados de forma ascendente...\n");
   printf("\n\nIngrese el codigo del alumno cuyos datos desea insertar en todos los registros: ");
   scanf("%i",&codigo);
   printf("\n\nCodigo Leido...");
   printf("\n\nA continuacion ingrese los datos del alumno...\n");
   system("pause");
   aux=1;
   if(n<MAX){
         for(i=0;i<*dx;i++){
            if(codigo>x[i].codAlu){
            posi=i+1;
            }else{
               if(codigo<x[0].codAlu){
                  posi=0;
               }
            }
         }
         insertarporPosicion(x,p,par,fin,&*dx,aux,posi+1,codigo);
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
}

void encabezado1()
{
   system("cls");
   char title[]="\n\nREPORTE DE ALUMNOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="APELLIDOS, Nombres";
   char escuela[]="ESCUELA";
   char fecha[]="FECHA DE NACIMIENTO";
   char peso[]= "PESO";

   printf("\t\t%s\n\n",title);
   raya2();
   printf("%-7s\t%-12s%-32s%-15s%-25s%-8s\n",num,cod,nom,escuela,fecha,peso);
   raya1();
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
void raya2()
{
   printf("====================================================================");
   printf("=========================================\n");
}
void raya1()
{
   printf("--------------------------------------------------------------------");
   printf("-----------------------------------------\n");
}
void raya3(){
   printf("===============================\n");
}
void raya4(){
   printf("-------------------------------\n");
}
int Menu(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int *dx){
   int op,aux=0,posi=0,cod=0;
   system("cls");
   printf(" \n\nOPERACIONES CON VECTORES \n\n");
   printf("0. TERMINAR \n\n");
   printf("1. Ingreso de datos \n");
   printf("2. Mostrar \n");
   printf("3. Buscar datos por codigo \n");
   printf("4. Ordenar registros por codigo \n");
   printf("5. Editar por codigo \n");
   printf("6. Insertar por posicion \n");
   printf("7. Insertar por Valor \n");
   printf("8. Eliminar por posicion \n");
   do{
   printf("\nDigite su opcion ---> ");
   scanf("%d",&op);
   }while(op<0 || op>8);
   switch(op){
      case 3://buscar por codigo
         buscarporCodigo(x,p,par,fin,*dx);
         cout<<endl;
         system("pause");
         break;
      case 4://ordenar
         ordenarporCodigo(x,p,par,fin,*dx);
         printf("\nLos codigos de los registros han sido ordenados de forma ascendente...\n\n.");
         cout<<endl;
         system("pause");
         break;
      case 6://insertar por posicion
         insertarporPosicion(x,p,par,fin,&*dx,aux,posi,cod);
         cout<<endl;
         break;
      case 7://insertar por valor
         ordenarporCodigo(x,p,par,fin,*dx);
         insertarporValor(x,p,par,fin,&*dx,aux);
         break;
      case 8://eliminar por posicion
         eliminaporPosicion(x,p,par,fin,&*dx);
         break;
   }
   return(op);
}
void Menu2(int op,ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int dx){
   int op2;
   system("cls");
   printf(" \n\nSOBRE QUE VECTOR DESEA REALIZAR LA OPERACION?: \n\n");
   printf("0. ATRAS \n\n");
   printf("1. REGISTRO DE ALUMNOS \n");
   printf("2. REGISTRO DE PRACTICAS \n");
   printf("3. REGISTRO DE EXAMENES PARCIALES \n");
   printf("4. REGISTRO DE EXAMENES FINALES \n");
   do{
   printf("\nDigite su opcion ---> ");
   scanf("%d",&op2);
   }while(op2<0 || op2>4);
   if(op2!=0){
      switch(op){
         case 1://ingreso de datos
            switch(op2){
               case 1:
                  printf("\n\nEl registro ALUMNOS ya ha sido llenado\n\n");
                  system("pause");
                  break;
               case 2:
                  leerVectorPc(x,p,dx);
                  break;
               case 3:
                  leerVectorParcial(x,par,dx);
                  break;
               case 4:
                  leerVectorFinal(x,fin,dx);
                  break;
            }
            break;
         case 2://mostrar
            switch(op2){
               case 1:
                  mostrarVectorAlu(x,dx);
                  break;
               case 2:
                  mostrarVectorPc(p,dx);
                  break;
               case 3:
                  mostrarVectorParcial(par,dx);
                  break;
               case 4:
                  mostrarVectorFinal(fin,dx);
                  break;
            }
            break;
         case 5://editar
            switch(op2){
               case 1:
                  editarporCodigoAlu(x,dx);
                  system("pause");
                  break;
               case 2:
                  editarporCodigoPc(p,dx);
                  system("pause");
                  break;
               case 3:
                  editarporCodigoParcial(par,dx);
                  system("pause");
                  break;
               case 4:
                  editarporCodigoFinal(fin,dx);
                  system("pause");
                  break;
            }
            break;
      }
   }
}

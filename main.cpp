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
#include <string.h>

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
	int codCurso=0;
   	int prac[10];
   	int promedio;
};

struct EXPARCIAL{
	int codAlu=0;
	int codCurso=0;
	float expar=0;
};

struct EXFINAL{
	int  codAlu=0;
	int codCur=0;
	float exfin=0;
};

struct CURSO{
	int codCur;
	char nomCur[40];
	int creditosCur;
	char scal;
};

struct Docente{
	int codDoc;
	char nomDoc[40];
	CURSO c[10];
	char escuela[4];
	float peso=0;
};

void crearVector(int *dx,int *dcursos, int *ddoc);
void leerVectorAlu(ALUMNO x[MAX], int *dx);
void mostrarVectorAlu(ALUMNO x[MAX], int dx);
void leerVectorPc(ALUMNO x[MAX],PRACTICA p[MAX],int dx);
void mostrarVectorPc(PRACTICA p[MAX],int dx);
void leerVectorParcial(ALUMNO x[MAX],EXPARCIAL par[MAX], int dx);
void mostrarVectorParcial(EXPARCIAL par[MAX],int dx);
void leerVectorFinal(ALUMNO x[MAX],EXFINAL fin[MAX], int dx);
void mostrarVectorFinal(EXFINAL fin[MAX],int dx);
void leerVectorCursos(CURSO curs[MAX], int *dcursos);
void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX], int dcursos,int *ddoc);
void buscarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],int dx);
void editarporCodigoAlu(ALUMNO x[MAX], int dx);
void editarporCodigoPc(PRACTICA p[MAX], int dx);
void editarporCodigoParcial(EXPARCIAL par[MAX], int dx);
void editarporCodigoFinal(EXFINAL fin[MAX], int dx);
void insertarporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx,int aux, int posi, int cod);
void eliminaporPosicion(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx);
void ordenarporCodigo(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int dx);
void insertarporValor(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin [MAX],int *dx, int aux);
void mostrarVectorCurso(CURSO x[MAX],int dx);
void mostrarVectorDoc(Docente x[MAX],int dx);
void mostrarCursosxDoc(Docente x,int dx);
void ordenarxCodigoDoc(Docente x[MAX],int dx);
void ordenarxCodigoCur(CURSO x[MAX],int dx);
void ordenarxCodigoCurDoc(Docente x,int dx);
void insertarPosPc(PRACTICA p[MAX],int pos,int dx,int pc[10]);
int buscarPcxCodCurso(PRACTICA p[MAX],int dx,int cod);
void editarPc(PRACTICA p[MAX],int dx);
void editarParcial(EXPARCIAL par[MAX],int dx);
int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod);
void insertarPosParcial(EXPARCIAL par[MAX],int *dx,int pos,int expar);
void editarFinal(EXPARCIAL fin[MAX],int dx);
int buscarxCodigoFinal(EXPARCIAL fin[MAX],int dx,int cod);
void insertarPosFinal(EXPARCIAL fin[MAX],int *dx,int pos,int exfin);
void editarCurso(CURSO x[MAX],int dx);
int buscarxCodCur(CURSO x[MAX],int dx,int cod);
void insertarPosCurso(CURSO x[MAX],int *dx,int pos,CURSO y);
void editarDocente(Docente x[MAX],int dx);
int buscarxCodigoDoc(Docente x[MAX],int dx,int cod);
void insertarPosDocente(Docente x[MAX],int pos,Docente y);
void ordenarporNombreAlu(ALUMNO x[MAX],int dx);
void ordenarPorNombreDoc(Docente x [MAX], int dx);
void ordenarPorNombreCur(CURSO x [MAX], int dx);
void eliminarxValorAlu(ALUMNO x[MAX],int *dx,ALUMNO dato,PRACTICA p[MAX], EXPARCIAL par[MAX],EXFINAL fin[MAX]);
void eliminarxValorDoc(Docente x[MAX],int *dx,Docente dato);
void eliminarxValorCur(CURSO x[MAX],int *dx,CURSO dato);

//Menu
void encabezado1();
void encabezado2(char title[]);
void encabezado3();
void encabezado4(Docente doc);
void encabezado5();
void raya1();
void raya2();
void raya3();
void raya4();
void raya1Doc();
void raya2Doc();
void raya1Cur();
void raya2Cur();

int Menu(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],CURSO curs[],Docente doc[],int *dx,int *dcursos,int *ddoc);
void Menu2(int op,ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],CURSO curs[],Docente doc[],int *dx,int *dcursos,int *ddoc);

int main()
{

   ALUMNO a[MAX];
   int na,nc,nd,op;
   PRACTICA p[MAX];
   EXPARCIAL par[MAX];
   EXFINAL fin[MAX];
   CURSO curs[MAX];
   Docente doc[MAX];
   crearVector(&na,&nc,&nd);

   do{
      op=Menu(a,p,par,fin,curs,doc,&na,&nc,&nd);
      if(op!=0&&op==5||op==2||op==1){
           Menu2(op,a,p,par,fin,curs,doc,&na,&nc,&nd);
       }
   }while(op>=1&&op<=8);
   printf("\n\nPrograma finalizado...\n\n");
   system("pause");
   return(0);
}

void crearVector(int *dx,int *dcursos, int *ddoc)
{
   *dx=-1;
   *dcursos=-1;
   *ddoc=-1;
}

void leerVectorAlu(ALUMNO x[MAX], int *dx)
{
   int i=0, n, val;
   printf("\n\n**Llenado del registro ALUMNOS:\n\n");
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
   system("pause");
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
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
   system("pause");
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
void leerVectorCursos(CURSO curs[MAX], int *dcursos){
   int i=-1, n, val;
   printf("\n\tINGRESO DE LA LISTA DE CURSOS:\n\n");
   if(n < MAX){
      do{
         i++;
         printf("\n\tCurso:  %d\n", i+1);
         cout <<" Codigo "<<i+1<<"('0' para terminar) ---> ";
         cin >>curs[i].codCur;
         if(curs[i].codCur!=0){
            cout <<" Nombre ---> ";
            cin>>curs[i].nomCur;
            cout <<" Creditos ---> ";
            cin >>curs[i].creditosCur;
            cout <<" Sistema de calificacion ---> ";
            cin >>curs[i].scal;
         }
         cout<<endl;
      }
      while(curs[i].codCur!=0);
      *dcursos= i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      system("pause");
      exit(1);
   }
}

void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX],int dcursos, int *ddoc){
   int i=-1, n, val,comp;
   printf("\n\tLLENADO DEl REGISTRO DE DOCENTES:\n\n");
   if(n < MAX){
      do{
         i++;
         printf("\n\tDocente:  %d\n", i+1);
         cout <<" Codigo "<<i+1<<"('0' para terminar)---> ";
         cin >>doc[i].codDoc;
         if(doc[i].codDoc!=0){
            cout <<" Nombre ---> ";
            cin>>doc[i].nomDoc;
            cout <<" Escuela ---> ";
            cin >>doc[i].escuela;
            cout <<" Peso(kg.)---> ";
            cin >>doc[i].peso;
         }
         cout<<endl;
      }
      while(doc[i].codDoc!=0);
      *ddoc= i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
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
int Menu(ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],CURSO curs[],Docente doc[],int *dx,int *dcursos,int *ddoc){
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
void Menu2(int op,ALUMNO x[MAX],PRACTICA p[MAX],EXPARCIAL par[MAX],EXFINAL fin[MAX],CURSO curs[],Docente doc[],int *dx,int *dcursos,int *ddoc){
   int op2;
   system("cls");
   printf(" \n\nSOBRE QUE VECTOR DESEA REALIZAR LA OPERACION?: \n\n");
   printf("0. ATRAS \n\n");
   printf("1. REGISTRO DE ALUMNOS \n");
   printf("2. REGISTRO DE CURSOS \n");
   printf("3. REGISTRO DE PRACTICAS  \n");
   printf("4. REGISTRO DE EXAMENES PARCIALES \n");
   printf("5. REGISTRO DE EXAMENES FINALES \n");
   printf("6. REGISTRO DE DOCENTES \n");
   do{
   printf("\nDigite su opcion ---> ");
   scanf("%d",&op2);
   }while(op2<0 || op2>6);
   if(op2!=0){
      switch(op){
         case 1://ingreso de datos
            switch(op2){
               case 1:
                  if(*dx<0){
                     leerVectorAlu(x,&*dx);
                  }else{
                     printf("\n\nEl registro ALUMNOS ya ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
               case 2:
                  if(*dcursos<0){
                     leerVectorCursos(curs,&*dcursos);
                  }else{
                     printf("\n\nEl registro de CURSOS ya ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
               case 3:
                  if(*dcursos>0){
                     leerVectorPc(x,p,*dx);
                  }else{
                     printf("\n\nEl registro de CURSOS aun no ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
               case 4:
                  if(*dcursos>0){
                     leerVectorParcial(x,par,*dx);
                  }else{
                     printf("\n\nEl registro de CURSOS aun no ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
               case 5:
                  if(*dcursos>0){
                     leerVectorFinal(x,fin,*dx);
                  }else{
                     printf("\n\nEl registro de CURSOS aun no ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
               case 6:
                  if(*dcursos>0){
                     leerVectorDocente(curs,doc,*dcursos,&*ddoc);
                  }else{
                     printf("\n\nEl registro de CURSOS aun no ha sido llenado.\n\n");
                     system("pause");
                  }
                  break;
            }
            break;
         case 2://mostrar
            switch(op2){
               case 1:
                  mostrarVectorAlu(x,*dx);
                  break;
               case 2:
                  mostrarVectorPc(p,*dx);
                  break;
               case 3:
                  mostrarVectorParcial(par,*dx);
                  break;
               case 4:
                  mostrarVectorFinal(fin,*dx);
                  break;
            }
            break;
         case 5://editar
            switch(op2){
               case 1:
                  editarporCodigoAlu(x,*dx);
                  system("pause");
                  break;
               case 2:
                  editarporCodigoPc(p,*dx);
                  system("pause");
                  break;
               case 3:
                  editarporCodigoParcial(par,*dx);
                  system("pause");
                  break;
               case 4:
                  editarporCodigoFinal(fin,*dx);
                  system("pause");
                  break;
            }
            break;
      }
   }
}

void raya2Doc()
{
   printf("==================================================\n");
}
void raya1Doc()
{
   printf("--------------------------------------------------\n");
}

void encabezado3()
{
   system("cls");
   char title[]="\n\n\tREPORTE GENERAL DE DOCENTES";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="APELLIDOS, Nombres";
   char scal[]="ESCUELA";
   char peso[]="PESO";

   printf("\t\t%s\n\n",title);
   raya2();
   printf("%-7s\t%-12s%-32s%-18s%-18s\n",num,cod,nom,scal,peso);
   raya1();
}

void mostrarVectorDoc(Docente x[MAX], int dx)
{
   int i;
   if(dx>0){
      encabezado3();
      for(i=0;i<dx;i++){
         printf("%3d\t%-12d%-32s%-18s%-18.2f\n",i+1,x[i].codDoc,x[i].nomDoc,x[i].escuela,x[i].peso);
      }
      raya1();
      cout <<"\n\n";
      system("pause");
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}

void encabezado4(Docente doc)
{
   system("cls");
   char nombre[]=" ";
   strcpy(nombre,doc.nomDoc);
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char scal[]="SISTEMA CALIF";

   printf("\t\t\n\n\tREPORTE CURSOS %s\n\n",nombre);
   raya2Doc();
   printf("%-7s\t%-12s%-32s\n",num,cod,nom,scal);
   raya1Doc();
}

void mostrarCursosxDoc(Docente x,int dx){
   int i;
   if(dx>0){
      encabezado4(x);
      for(i=0;i<dx;i++){
         printf("%3d\t%-12d%-32s\n",i+1,x.c[i].codCur,x.c[i].nomCur,x.c[i].scal);
      }
      raya1Doc();
      cout <<"\n\n";
      system("pause");
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}

void encabezado5()
{
   system("cls");
   char title[]="\n\n\tREPORTE GENERAL DE CURSOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char creditos[]="CREDITOS";
   char sistema[]="Sistema Calific";

   printf("\t\t%s\n\n",title);
   raya2();
   printf("%-7s\t%-12s%-32s%-18s%-18s\n",num,cod,nom,creditos,sistema);
   raya1();
}

void mostrarVectorCurso(CURSO x[MAX],int dx){
   int i;
   if(dx>0){
      encabezado5();
      for(i=0;i<dx;i++){
         printf("%3d\t%-12d%-32s%-18d%-18c\n",i+1,x[i].codCur,x[i].nomCur,x[i].creditosCur,x[i].scal);
      }
      raya1();
      cout <<"\n\n";
      system("pause");
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}

void ordenarxCodigoDoc(Docente x[MAX],int dx){
   int i, j;
   Docente aux;
   if(dx>0){
      for(i=0; i<dx-1;){
         for(j=i+1; j<dx;){
            if(x[i].codDoc>x[j].codDoc){
               aux=x[j];
               x[j]=x[i];
               x[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
      mostrarVectorDoc(x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}

void ordenarxCodigoCur(CURSO x[MAX],int dx){
   int i, j;
   CURSO aux;
   if(dx>0){
      for(i=0; i<dx-1;){
         for(j=i+1; j<dx;){
            if(x[i].codCur>x[j].codCur){
               aux=x[j];
               x[j]=x[i];
               x[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
      mostrarVectorCurso(x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}

void ordenarxCodigoCurDoc(Docente x,int dx){
   int i, j;
   CURSO aux;
   if(dx>0){
      for(i=0; i<dx-1;){
         for(j=i+1; j<dx;){
            if(x.c[i].codCur>x.c[j].codCur){
               aux=x.c[j];
               x.c[j]=x.c[i];
               x.c[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
      mostrarCursosxDoc(x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarporNombreAlu(ALUMNO x[MAX],int dx)
{
   int i, j;
   ALUMNO aux;
   if(dx>-1){
      for(i=0; i<dx-1;){
         for(j=i+1; j<dx;){
            if(strcmp(x[i].nomAlu,x[j].nomAlu)>0){
               aux = x[j];
               x[j]=x[i];
               x[i]=aux;
            }

            j=j+1;
         }
         i=i+1;
      }
      mostrarVectorAlu (x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarPorNombreDoc(Docente x [MAX], int dx)
{
   int  i, j;
   Docente aux;
   if(dx>-1){
      for(i=0; i<dx-1;i++){
         for(j=i+1; j<dx;j++){
            if(strcmp(x[i].nomDoc,x[j].nomDoc)>0){
               aux = x[j];
               x[j]=x[i];
               x[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
      mostrarVectorDoc (x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarPorNombreCur(CURSO x [MAX], int dx)
{
   int  i, j;
   CURSO aux;
   if(dx>-1){
      for(i=0; i<dx-1;i++){
         for(j=i+1; j<dx;j++){
            if(strcmp(x[i].nomCur,x[j].nomCur)>0){
               aux=x[j];
               x[j]=x[i];
               x[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
      mostrarVectorCurso(x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}			
void insertarPosPc(PRACTICA p[MAX],int pos,int dx,int pc[10]){
   int i,n;
   int suma=0;
   
   if(dx>0){
      for(i=0;i<10;i++){
         p[pos-1].prac[i] = pc[i];
         suma +=pc[i];
      }
      p[pos-1].promedio=suma/10;
      printf("%d",p[pos-1].promedio);
      
   }
   else{
      printf("Vector Vacio...");
   }
   mostrarVectorPc(p,dx);
}
int buscarPcxCodCurso(PRACTICA p[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(p[i].codCurso==cod){
         pos = i;
      }
   }
   
   return pos;
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



int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(par[i].codCurso==cod){
         pos = i;
      }
   }
   
   return pos; 
}
void editarParcial(EXPARCIAL par[MAX],int dx){
   int cod,edit,i;
   printf("Digite el codigo del curso:");
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
void insertarPosParcial(EXPARCIAL par[MAX],int *dx,int pos,int expar){
   int i;
   if(*dx+1>MAX){
      for(i=*dx+1;i>pos+1;i--){
         par[i-1].expar=par[i].expar;
      }
      par[pos-1].expar = expar;
      dx +=1;
   }
   else{
      printf("Excede Dimension");
   }
}




int buscarxCodigoFinal(EXFINAL fin[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(fin[i].codCur==cod){
         pos = i;
      }
   }
   
   return pos;    
}
void editarFinal(EXFINAL fin[MAX],int dx){
   int cod,edit,i;
   printf("Digite el codigo del curso:");
   scanf("%d",&cod);

   edit = buscarxCodigoFinal(fin,dx,cod);

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
   if(*dx+1>MAX){
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


int buscarxCodCur(CURSO x[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(x[i].codCur==cod){
         pos = i;
      }
   }
   
   return pos;
}
void editarCurso(CURSO x[MAX],int dx){
   int cod,edit,i;
   printf("Digite el codigo del curso:");
   scanf("%d",&cod);

   edit = buscarxCodCur(x,dx,cod);

   if(edit == 0){
      printf("Curso no encontrado");
   }
   else{  
      printf("\n\n\tIngrese datos del Curso: ");
      printf("Codigo: ");
      cin>>x[edit].codCur;
      printf("Nombre: ");
      cin>>x[edit].nomCur;
      printf("Sistema de Calificaciones: ");
      cin>>x[edit].scal;
      printf("Creditos: ");
      cin>>x[edit].creditosCur;
      cout<<endl;
      printf("\n**Datos del Curso guardados con exito...\n");
   }
}
void insertarPosCurso(CURSO x[MAX],int *dx,int pos,CURSO y){
   int i;
   if(*dx+1>MAX){
      for(i=*dx+1;i>pos+1;i--){
         x[i-1].codCur=x[i].codCur;
         strcpy(x[i-1].nomCur,x[i].nomCur);
         x[i-1].scal=x[i].scal;
         x[i-1].creditosCur=x[i].creditosCur;
      }
      x[pos-1].codCur = y.codCur;
      strcpy(x[pos-1].nomCur,y.nomCur);
      x[pos-1].scal = y.scal;
      x[pos-1].creditosCur = y.creditosCur;
      dx +=1;
   }
   else{
      printf("Excede Dimension");
   }
}


void insertarPosDocente(Docente x[MAX],int *dx,int pos,Docente y){
   int i,j;
   if(*dx+1>MAX){
      for(i=*dx+1;i>pos+1;i--){
         x[i-1].codDoc=x[i].codDoc;
         strcpy(x[i-1].nomDoc,x[i].nomDoc);
         
         for(j=0;j<10;j++){
            x[i-1].c[j].codCur=x[i].c[j].codCur;
            strcpy(x[i-1].c[j].nomCur,x[i].c[j].nomCur);
            x[i-1].c[j].scal=x[i].c[j].scal;
            x[i-1].c[j].creditosCur=x[i].c[j].creditosCur;
         }
         strcpy(x[i-1].escuela,x[i].escuela);
         x[i-1].peso=x[i].peso;
      }
      x[pos-1].codDoc = y.codDoc;
      strcpy(x[pos-1].nomDoc,y.nomDoc);
      
      for(j=0;j<10;j++){
         x[pos-1].c[j].codCur=y.c[j].codCur;
         strcpy(x[pos-1].c[j].nomCur,y.c[j].nomCur);
         x[pos-1].c[j].scal=y.c[j].scal;
         x[pos-1].c[j].creditosCur=y.c[j].creditosCur;
      }

      strcpy(x[pos-1].escuela,y.escuela);
      x[pos-1].peso = y.peso;
      dx +=1;
   }
   else{
      printf("Excede Dimension");
   }
}
int buscarxCodigoDoc(Docente x[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(x[i].codDoc==cod){
         pos = i;
      }
   }
   
   return pos;
}
void editarDocente(Docente x[MAX],int dx){
   int cod,edit,i;
   printf("Digite el codigo del Docente:");
   scanf("%d",&cod);

   edit = buscarxCodigoDoc(x,dx,cod);

   if(edit == 0){
      printf("Docente no encontrado");
   }
   else{  
      printf("\n\n\tIngrese datos del Doncente: ");
      printf("Codigo: ");
      cin>>x[edit].codDoc;
      printf("Nombre: ");
      cin>>x[edit].codDoc;
      editarCurso(x[edit].c,10);
      printf("Peso: ");
      cin>>x[edit].peso;
      cout<<endl;
      printf("\n**Datos del Docente guardados con exito...\n");
   }
}

void eliminarxValorAlu(ALUMNO x[MAX],int *dx,ALUMNO dato,PRACTICA p[MAX], EXPARCIAL par[MAX],EXFINAL fin[MAX]){
   int band=0, n=*dx,bandN=0;
   if(*dx>0){
      for(int i=0;i<n;i++){
         for(int j=0;j<strlen(x[i].nomAlu);j++){
            if(x[i].nomAlu[j]!=dato.nomAlu[j]){
               j=strlen(x[i].nomAlu)+1;
            }
            else if(j==strlen(x[i].nomAlu)-1){
               bandN=1;
            }
         }
         if(x[i].codAlu==dato.codAlu && x[i].peso==dato.peso && x[i].fnac.anio==dato.fnac.anio && x[i].fnac.mes==x[i].fnac.mes && x[i].fnac.dia==x[i].fnac.dia && bandN==1){
            for(int j=i;j<n;j++){
               x[j]=x[j+1];
               p[j]=p[j+1];
               par[j]=par[j+1];
               fin[j]=fin[j+1];
            }
            band=1;
            i=*dx+1;
         }
      }
      if(band==1){
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorAlu(x,*dx);
         mostrarVectorFinal(fin,*dx);
         mostrarVectorParcial(par,*dx);
         mostrarVectorPc(p,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}

void eliminarxValorDoc(Docente x[MAX],int *dx,Docente dato){
   int band=0, n=*dx,bandN=0;
   if(*dx>0){
      for(int i=0;i<n;i++){
         //verifica nombre
         for(int j=0;j<strlen(x[i].nomDoc);j++){
            if(x[i].nomDoc[j]!=dato.nomDoc[j]){
               j=strlen(x[i].nomDoc)+1;
            }
            else if(j==strlen(x[i].nomDoc)-1){
               bandN=1;
            }
         }
         //verifica escuela
         if(bandN==1){
            for(int j=0;j<strlen(x[i].escuela);j++){
               if(x[i].escuela[j]!=dato.escuela[j]){
                  bandN=0;
                  j=strlen(x[i].escuela)+1;
               }
               else if(j==strlen(x[i].escuela)-1){
                  bandN=1;
               }
            }
         }
         if(x[i].codDoc==dato.codDoc && x[i].peso==dato.peso && bandN==1){
            for(int j=i;j<n;j++){
               fflush(stdin);
               x[j]=x[j+1];
            }
            band=1;
            i=*dx+1;
         }
      }
      if(band==1){
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorDoc(x,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}

void eliminarxValorCur(CURSO x[MAX],int *dx,CURSO dato){
   int band=0, n=*dx,bandN=0;
   if(*dx>0){
      for(int i=0;i<n;i++){
         //verifica nombre
         for(int j=0;j<strlen(x[i].nomCur);j++){
            if(x[i].nomCur[j]!=dato.nomCur[j]){
               j=strlen(x[i].nomCur)+1;
            }
            else if(j==strlen(x[i].nomCur)-1){
               bandN=1;
            }
         }
         
         if(x[i].codCur==dato.codCur && x[i].creditosCur==dato.creditosCur && bandN==1 && x[i].scal==dato.scal){
            for(int j=i;j<n;j++){
               fflush(stdin);
               x[j]=x[j+1];
            }
            band=1;
            i=*dx+1;
         }
      }
      if(band==1){
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorCurso(x,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}

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
	float peso;
	int cantCur;
};

//CREAR
void crearVector(int *dcursos, int *ddoc);
//LEER
void leerVectorCursos(CURSO curs[MAX], int *dcursos);
void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX], int dcursos,int *ddoc); //Observar(modificado)
//MOSTRAR
void mostrarVectorCurso(CURSO x[MAX],int dx);
void mostrarVectorDoc(Docente x[MAX],int dx);
void mostrarCursosxDoc(Docente x,int dx); //Modificar por la relación curso-docente
//BUSCAR
void buscarCursoporCodigo(CURSO curs[MAX], int dcurso);
void buscarDocenteporCodigo(Docente doc[MAX],int ddoc);
//BUSCAR(AUXILIARES)
int buscarxCodCur(CURSO x[MAX],int dx,int cod);
int buscarxCodigoDoc(Docente x[MAX],int dx,int cod);
//EDITAR
void editarCurso(CURSO x[MAX],int dx);
void editarDocente(Docente x[MAX],int dx);     //Modificar por lo de los cursos
//INSERTAR
void insertarPosCurso(CURSO x[MAX],int *dx,int pos,CURSO y); 
void insertarPosDocente(Docente x[MAX],int *dx,int pos,Docente y); //Mal planteado, tener en cuenta lo de los cursos
//ELIMINAR
void eliminarxValorDoc(Docente x[MAX],int *dx,Docente dato);
void eliminarxValorCur(CURSO x[MAX],int *dx,CURSO dato); // Modificar por la relación
void eliminaCursoporPosicion(CURSO curs[MAX],int *dcurso,Docente doc[MAX], int ddoc); //Modificar por la relación(modificado)
void eliminarDocenteporPosicion(Docente doc[MAX], int *ddoc); //Modificar por lo de los cursos(modificado)
//ORDENAR
void ordenarxCodigoDoc(Docente x[MAX],int dx);
void ordenarxCodigoCur(CURSO x[MAX],int dx);
void ordenarxCodigoCurDoc(Docente x,int dx); //Modificar por la relación
void ordenarPorNombreDoc(Docente x [MAX], int dx);
void ordenarPorNombreCur(CURSO x [MAX], int dx);
//MENU
void menu();
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

//ARCHIVOS

//Escribir
void fileSalvarDocentes(FILE *F,Docente x[],int dx);
void fileSalvarCursos(FILE *F,CURSO x[],int dx);
//Leer
void fileRecuperarDocentes(FILE *F,Docente x[],int *dx);
void fileRecuperarCursos(FILE *F,CURSO x[],int *dx);

int main(){
    menu();
    system("pause");
    return 0;
}

void crearVector(int *dcursos, int *ddoc)
{
   *dcursos=-1;
   *ddoc=-1;
}

void leerVectorCursos(CURSO curs[MAX], int *dcursos){
   int i=0, n;
   printf("\n\tINGRESO DE LA LISTA DE CURSOS:\n\n");
   printf("\n\nNumero de CURSOS---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tCurso:  %d\n", i+1);
         cout <<" Codigo ---> ";
          cin >>curs[i].codCur;
          cout <<" Nombre ---> ";
          cin>>curs[i].nomCur;
          cout <<" Creditos ---> ";
          cin >>curs[i].creditosCur;
          cout <<" Sistema de calificacion ---> ";
          cin >>curs[i].scal;
          cout<<endl;
      }
      *dcursos = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      exit(1);
   }
   system("pause");
}

void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX],int dcursos, int *ddoc){
   int i=0, n,k=0,j,comp=0,nc=0;
   printf("\n\tLLENADO DEl REGISTRO DE DOCENTES:\n\n");
   printf("\n\nNumero de DOCENTES ---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         printf("\n\tDocente:  %d\n", i+1);
         cout <<" Codigo ---> ";
         cin >>doc[i].codDoc;
         cout <<" Nombre ---> ";
         cin>>doc[i].nomDoc;
         cout <<" Escuela ---> ";
         cin >>doc[i].escuela;
         cout <<" Peso(kg.)---> ";
         cin >>doc[i].peso;
         printf("\nCursos llevados por el profesor: ");
         scanf("%d",&nc);
         cout<<" Escriba los codigo de los cursos dictados por el profesor: ";
         for(k=0;k<nc;k++){
            do{
               cout <<"\n\tCodigo de Curso "<<k+1<<" ---> ";
               cin >>doc[i].c[k].codCur;
               for(j=0;j<dcursos;j++){//compara si el curso ingresado se encuentra en el registro CURSOS
                  if(curs[j].codCur==doc[i].c[k].codCur){
                     doc[i].c[k]=curs[j];
                     comp=1;
                  }
               }
               if(comp==0){
                  printf("\nEl curso ingresado no se encuentra en el registro de CURSOS.");
                  printf("\nVuelva a ingresar el curso: \n");
               }
            }while(comp!=1);
         }
         cout<<endl;
         doc[i].cantCur=k;
      }
      *ddoc = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      exit(1);
   }
   system("pause");
}

void buscarCursoporCodigo(CURSO curs[MAX], int dcurso){
   int cd,i,comp=0;//comp es un valor bandera
   printf("\n\nIngrese el codigo del curso a buscar: ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dcurso;i++){
      if(curs[i].codCur==cd){
         encabezado5();
         printf("%3d\t%-12d%-32s%-18d%-18c\n",i+1,curs[i].codCur,curs[i].nomCur,curs[i].creditosCur,curs[i].scal);
         raya1();
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}

void buscarDocenteporCodigo(Docente doc[MAX],int ddoc){
   int cd,i,j,comp=0;//comp es un valor bandera
   printf("\n\nIngrese el codigo del docente a buscar: ");
   scanf("%i",&cd);
   cout <<"\n\n";
   system("pause");
   for(i=0;i<ddoc;i++){
      if(doc[i].codDoc==cd){
         comp=1;
         encabezado3();
         printf("%3d\t%-12d%-32s%-18s%-18.2f\n",i+1,doc[i].codDoc,doc[i].nomDoc,doc[i].escuela,doc[i].peso);
         raya1();
         cout <<"\n\n";
         if(doc[i].cantCur!=0){
            printf("Cursos dictados por el profesor: \n");
            for(j=0;j<doc[i].cantCur;j++){
               printf("\tCurso %d: %s\n",j+1, doc[i].c[j].nomCur);
            }
         }else{
            printf("El docente no dicta cursos actualmente.\n");
         }
      }
   }
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
}

void eliminaCursoporPosicion(CURSO curs[MAX],int *dcurso,Docente doc[MAX], int ddoc){
   int i,n,posi,j,k,posiDoc,comp=0;// comp es un valor bandera que ayuda a cerrar el bucle do-while
   mostrarVectorCurso(curs,*dcurso);
   printf("\n\nIngrese la posicion del curso que desea eliminar del registro: ");
   scanf("%i",&posi);
   n=*dcurso;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dcurso){
      *dcurso=n;
      for(j=0;j<ddoc;j++){
         k=-1;
         do{
            k++;
            if(curs[i].codCur==doc[j].c[k].codCur){
               doc[j].cantCur=doc[j].cantCur-1;
               while(k<doc[j].cantCur){//elimina cursos dentro del registros de docentes
                  doc[j].c[k]=doc[j].c[k+1];
                  k++;
               }
               comp=1;
            }
         }while(k<doc[j].cantCur||comp!=1);
      }
      while(i<n){
         curs[i] = curs[i+1];
         i = i+1;
      }
   printf("\nDatos del curso de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
   system("pause");
}
void eliminarDocenteporPosicion(Docente doc[MAX], int *ddoc){
   int i,n,posi;
   mostrarVectorDoc(doc,*ddoc);
   printf("\n\nIngrese la posicion del docente que desea eliminar del registro: ");
   scanf("%i",&posi);
   n=*ddoc;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*ddoc){
      *ddoc=n;
      while(i<n){
         doc[i] = doc[i+1];
         i = i+1;
      }
   printf("\nDatos del curso de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
   system("pause");
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

   if(dx>0){
      encabezado4(x);
      for(int i=0;i<dx;i++){
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
         }
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
         }
      }
      mostrarVectorCurso(x,dx); //muestra el resultado
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
int buscarxCodCur(CURSO x[MAX],int dx,int cod){
   int pos = -1,i;

   for(i=0;i<dx;i++){
      if(x[i].codCur==cod){
         pos = i;
      }
   }
   
   return pos+1;
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
      printf("\n\n\tIngrese datos del Curso: \n");
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
   int i,n=*dx+1;
   pos--;
   i=n;
   if(i<MAX){
      while(i>pos){
         x[i]=x[i-1];
         i=i-1;
      }
      x[pos]=y;
      printf("\n INSERTADO en posicion %d\n",pos+1);
      fflush(stdin);
      *dx=n;
      mostrarVectorCurso(x,*dx); //Muestra el resultado
   }
   else{
      printf("Dimension fuera de Rango\n");
   }
}


void insertarPosDocente(Docente x[MAX],int *dx,int pos,Docente y){
   int i,j, 
   n=*dx+1;
   
   if(*dx+1<MAX){
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
      *dx=n;
    //   mostrarVectorDoc(x,*dx);
      system("pause");
   }
   else{
      printf("Excede Dimension");
   }
}
int buscarxCodigoDoc(Docente x[MAX],int dx,int cod){
   int pos = -1,i;

   for(i=0;i<dx;i++){
      if(x[i].codDoc==cod){
         pos = i;
      }
   }
   
   return pos+1;
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
      printf("\n\n\tIngrese datos del Docente: \n");
      printf("Codigo: ");
      cin>>x[edit].codDoc;
      fflush(stdin);
      printf("Nombre: ");
      gets(x[edit].nomDoc);
    //   editarCurso(x[edit].c,10);
      fflush(stdin);  
      printf("Peso: ");
      cin>>x[edit].peso;
      cout<<endl;
      printf("\n**Datos del Docente guardados con exito...\n");
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

void fileSalvarDocentes(FILE *F,Docente x[],int dx){
   int i=0;
   F = fopen("Docentes.dat","w");
   if(F == NULL){
      printf("Error en la apertura de archivos...!\n");
      system("pause");
      exit(0);
   for(i=0;i<dx;i++){
      fwrite(&x[i],sizeof(Docente),1,F);
   }
   fclose(F);
   }
}
void fileSalvarCursos(FILE *F,CURSO x[],int dx){
   int i=0;
   F = fopen("Cursos.dat","w");
      if(F == NULL){
        printf("Error en la apertura de archivos...!\n");
        system("pause");
        exit(0);
      }
   for(i=0;i<dx;i++){
      fwrite(&x[i],sizeof(CURSO),1,F);
    }
   fclose(F);
}

void fileRecuperarDocentes(FILE *F,Docente x[],int *dx){
   int i=0;
   Docente d;
   F = fopen("Docentes.dat","r");
   if(F == NULL){
      printf("Error en la apertura de archivos...!\n");
      system("pause");
      exit(0);
   }
   fread(&d,sizeof(Docente),1,F);
   while(!feof(F)){
      x[i]=d;
      fread(&d,sizeof(Docente),1,F);
      i++;
   }
   *dx=i;
   fclose(F);
}

void fileRecuperarCursos(FILE *F,CURSO x[],int *dx){
   int i=0;
   CURSO c;
   F = fopen("Cursos.dat","r");
   if(F == NULL){
      printf("Error en la apertura de archivos...!\n");
      system("pause");
      exit(0);
   }
   fread(&c,sizeof(CURSO),1,F);
   while(!feof(F)){
      x[i]=c;
      fread(&c,sizeof(CURSO),1,F);
      i++;
   }
   *dx=i;
   fclose(F);
}

void menu(){
   FILE *FD, *FC;
    int nd, nc,pos;
    CURSO c[]={
        202,"ALGORITMICA I",4,'F',
        188,"INTR. DESARR. SOFTWARE",3,'F',
        184,"MATEMATICA BASICA",4,'F',
        190,"FISICA ELECTRONICA",3,'F',
        192,"ESTADISTICA",3,'F',
        189,"ORG. Y ADMINIST.",3,'G',
        200,"ING. ECONOMICA",3,'G',
    };
   Docente d[]={
        1001,"PEREZ LOPEZ, Juan",{c[0],c[3],c[6]},"I2",60.2,3,
        1005,"ROMAN HUAMAN, Eugenio",{c[1],c[2],c[5]},"I1",70.6,3,
        1002,"RUIZ MARTINEZ, Maria",{c[4],c[1],c[2]},"I2",52.6,3,
        1004,"GAVILAN CESPEDES, Julio",{c[2],c[5],c[6]},"I1",63.8,3,
        1003,"MORILLO HUAYANAI, Paula",{c[2],c[0],c[1]},"I1",54.2,3,
        1006,"SANSONI HURTADO, Jose",{c[2],c[0],c[6]},"I2",80.1,3,
    };
    nc=sizeof(c)/(sizeof(int)*2+sizeof(char)*41);
    nd=sizeof(d)/(sizeof(int)+sizeof(char)*44+sizeof(CURSO)*10+sizeof(float));

    int op,op2;
   char var;
   do{
      system("cls");
      printf(" \n\nSISTEMA DE CURSOS-DOCENTES \n\n");
      printf("0. TERMINAR \n\n");
      printf("1. Ingreso de datos \n");
      printf("2. Mostrar \n");
      printf("3. Buscar por Codigo \n");
      printf("4. Editar por codigo \n");
      printf("5. Insertar por posicion \n");
      printf("6. Eliminar por posicion \n");
      printf("7. Eliminar por valor \n");
      printf("8. Ordenar por codigo \n");
      printf("9. Ordenar por nombre \n");
      printf("10. Salvar \n");
      printf("11. Recuperar \n\n");
      do{
         printf("Digite su opcion ---> ");
         scanf("%d",&op);
      }while(op<0 || op>11);
      if(op!=0){
         printf("\n\n");
         system("cls");
         printf(" \n\nSobre que Registro desea realizar la operacion? \n\n");
         printf("0. ATRAS \n\n");
         printf("1. CURSOS \n");
         printf("2. DOCENTES \n\n");
         do{
            printf("Digite su opcion ---> ");
            scanf("%d",&op2);
         }while(op2<0 || op2>2);
      }
      switch(op){
         case 1://leer
            switch(op2){
            case 1:
               leerVectorCursos(c,&nc);
               break;
            case 2:
               leerVectorDocente(c,d,nc,&nd);
               break;
            }
         break;
         case 2://mostrar
             switch(op2){
            case 1:
               mostrarVectorCurso(c,nc);
               break;
            case 2:
               mostrarVectorDoc(d,nd);
               break;
            }
         break;
         case 3://buscar
             switch(op2){
            case 1:
               buscarCursoporCodigo(c,nc);
               break;
            case 2:
               buscarDocenteporCodigo(d,nd);
               break;
            }
         break;
         case 4://editar
             switch(op2){
            case 1:
               editarCurso(c,nc);
               break;
            case 2:
               editarDocente(d,nd);
               break;
            }
         break;
         case 5://insertarxpos
             switch(op2){
            case 1:
               break;
            case 2:
               break;
            }
         break;
         case 6://eliminarxpos
             switch(op2){
            case 1:
               eliminaCursoporPosicion(c,&nc,d,nd);
               break;
            case 2:
               eliminarDocenteporPosicion(d,&nd);
               break;
            }
         break;
         case 7://eliminarxvalor
             switch(op2){
            case 1:
               break;
            case 2:
               break;
            }
         break;
         case 8: //ordenarxcodigo
             switch(op2){
            case 1:
               ordenarxCodigoCur(c,nc);
               break;
            case 2:
               ordenarxCodigoDoc(d,nd);
               break;
            }
         break;
         case 9://ordenarxnombre
             switch(op2){
            case 1:
               ordenarPorNombreCur(c,nc);
               break;
            case 2:
               ordenarPorNombreDoc(d,nd);
               break;
            }
         break;
         case 10://salvar
             switch(op2){
            case 1:
               printf("\n\nDesea sobreescribir los datos de Cursos en el archivo si(s)/no(n): ");
               cin>>var;
               if(var=='s'||var=='S'){
                  fileSalvarCursos(FC,c,nc);
                  printf("\n\nRegistro de Cursos archivado...\n\n");
               }
               system("pause");
               break;
            case 2:
               printf("\n\nDesea sobreescribir los datos de Docentes en el archivo(si(s)/no(n): ");
               cin>>var;
               if(var=='s'||var=='S'){
                  fileSalvarDocentes(FD,d,nd);
                  printf("\n\nRegistro de Docentes archivado...\n\n");
               }
               system("pause");
               break;
            }
         break;
         case 11://recuperar
             switch(op2){
            case 1:
               fileRecuperarCursos(FC,c,&nc);
               printf("\n\nRegistro de Cursos recuperado");
               system("pause");
               break;
            case 2:
               fileRecuperarDocentes(FD,d,&nd);
               printf("\n\nRegistro de Docentes recuperado...\n\n");
               system("pause");
               break;
            }
         break;
      }
   }while(op!=0);
}

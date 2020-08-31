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
};

//CREAR
void crearVector(int *dcursos, int *ddoc);
//LEER
void leerVectorCursos(CURSO curs[MAX], int *dcursos);
void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX], int dcursos,int *ddoc,int dcursosxdocente[MAX]); //Observar
//MOSTRAR
void mostrarVectorCurso(CURSO x[MAX],int dx);
void mostrarVectorDoc(Docente x[MAX],int dx);
void mostrarCursosxDoc(Docente x,int dx); //Modificar por la relación curso-docente
//BUSCAR
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
void eliminarxValorCur(CURSO x[MAX],int *dx,CURSO dato);
void eliminaCursoporPosicion(CURSO curs[MAX],int *dcurso);
void eliminarDocenteporPosicion(Docente doc[MAX], int *ddoc,int dcursosxdocente[MAX]); //Modificar por lo de los cursos
//ORDENAR
void ordenarxCodigoDoc(Docente x[MAX],int dx);
void ordenarxCodigoCur(CURSO x[MAX],int dx);
void ordenarxCodigoCurDoc(Docente x,int dx); //Modificar por la relación
void ordenarPorNombreDoc(Docente x [MAX], int dx);
void ordenarPorNombreCur(CURSO x [MAX], int dx);
//MENU
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
void fileEscribirDocentes(FILE *F,Docente x);
void fileEscribirCursos(FILE *F,CURSO x);
//Leer
void fileLeerDocentes(FILE *F);
void fileLeerCursos(FILE *F);
//Buscar
void fileBuscarDocente(FILE *F);
void fileBuscarCurso(FILE *F);
//Filtrar
void fileFiltrarDocentes(FILE *F);
void fileFiltrarCursos(FILE *F);
//Eliminar
void fileEliminarDocente(FILE *F);
void fileEliminarCurso(FILE *FF);
//Editar
void fileEditarDocente(FILE *FF);
void fileEditarCurso(FILE *FF);
//Copiar
void fileCopiarDocentes(FILE *F);
void fileCopiarCursos(FILE *F);
//Ordenar
void fileOrdenarDocentes(FILE *F);
void fileOrdenarCursos(FILE *F);

int main(){
    FILE *FD, *FC;
    FD = fopen("Docentes.dat","a+");
    FC = fopen("Cursos.dat","a+");
    if(FC == NULL && FD == NULL){
        printf("Error en la apertura de archivos...!\n");
        system("pause");
        exit(0);
    }
    int nd, nc;
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
        1001,"PEREZ LOPEZ, Juan",{c[0],c[3],c[6]},"I2",60.2,
        1005,"ROMAN HUAMAN, Eugenio",{c[1],c[2],c[5]},"I1",70.6,
        1002,"RUIZ MARTINEZ, Maria",{c[4],c[1],c[2]},"I2",52.6,
        1004,"GAVILAN CESPEDES, Julio",{c[2],c[5],c[6]},"I1",63.8,
        1003,"MORILLO HUAYANAI, Paula",{c[2],c[0],c[1]},"I1",54.2,
        1006,"SANSONI HURTADO, Jose",{c[2],c[0],c[6]},"I2",80.1,
    };
    nc=sizeof(c)/(sizeof(int)*2+sizeof(char)*41);
    nd=sizeof(d)/(sizeof(int)+sizeof(char)*44+sizeof(CURSO)*10+sizeof(float));

    // mostrarVectorCurso(c,nc);
    // mostrarVectorDoc(d,nd);
    // int i = buscarxCodCur(c,nc,189);
    // printf("%d",i);
    // int j = buscarxCodigoDoc(d,nd,1002);
    // printf("%d",j);
    // editarCurso(c,nc);
    // editarDocente(d,nd);
    // printf("%d",nc);
    // insertarPosCurso(c,&nc,3,c[0]);
    // insertarPosDocente(d,&nd,2,d[5]);
    // fflush(stdin);
    // mostrarVectorDoc(d,nd);
    // eliminarxValorCur(c,&nc,c[1]);
    // eliminarxValorDoc(d,&nd,d[2]);
    // eliminaCursoporPosicion(c,&nc);
    // mostrarVectorCurso(c,nc);
    // eliminarDocenteporPosicion(d,&nd);
    // mostrarVectorDoc(d,nd);
    // ordenarxCodigoCur(c,nc);
    // ordenarxCodigoDoc(d,nd);
    // ordenarPorNombreCur(c,nc);
    // ordenarPorNombreDoc(d,nd);
    //  for(int i=0;i<nd;i++){
   //     FD = fopen("Docentes.dat","a+");
   //    fileEscribirDocentes(FD,d[i]);
   //  }
   // fileLeerDocentes(FD);
   // for(int i=0;i<nc;i++){
   //     FC = fopen("Cursos.dat","a+");
   //    fileEscribirCursos(FC,c[i]);
   //  }
   // FC = fopen("Cursos.dat","a+");
   // fileLeerCursos(FC);
   // fileBuscarDocente(FD);
   // fileBuscarCurso(FC);
   // fileFiltrarDocentes(FD);
   // fileFiltrarCursos(FC);
   // fileEliminarDocente(FD);
   // fileEditarDocente(FD);
   // FD = fopen("Docentes.dat","a+");
   // fileLeerDocentes(FD);
   // fileEditarCurso(FC);
   // FC = fopen("Cursos.dat","a+");
   // fileLeerCursos(FC);
   // fileCopiarCursos(FC);
   // fileCopiarDocentes(FD);
   // fileEliminarCurso(FC);
   // FC = fopen("Cursos.dat","a+");
   // fileLeerCursos(FC);
   // FC = fopen("Cursos.dat","a+");
   // fileLeerCursos(FC);
   // fileOrdenarDocentes(FD);
   // FD = fopen("Docentes.dat","a+");
   // fileLeerDocentes(FD);
   // fileOrdenarCursos(FC);
   // FC = fopen("Cursos.dat","a+");
   // fileLeerCursos(FC);

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

void leerVectorDocente(CURSO curs[MAX],Docente doc[MAX],int dcursos, int *ddoc,int dcursosxdocente[MAX]){
   int i=0, n,k,j,comp;
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
         cout<<" Escriba el(los) curso(s) dictado(s) por el profesor: ";
         do{
            k++;
            cout <<"\n\tCurso "<<k+1<<"('.' para terminar)  ---> ";
            cin >>doc[i].c[k].nomCur;
            if(strcmp(doc[i].c[k].nomCur,".")!=0){
               do{
                  for(j=0;j<dcursos;j++){//compara si el curso ingresado se encuentra en el registro CURSOS
                     if(strcmp(curs[j].nomCur,doc[i].c[k].nomCur)==0){
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
         }while(strcmp(doc[i].c[k].nomCur,".")!=0);
         cout<<endl;
         dcursosxdocente[i]=k;
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
   for(i=0;i<dcurso;i++){
      if(curs[i].codCur==cd){
         comp=1;
         printf("\nCurso %d\n",i+1);
         printf("Nombre: %s\n",curs[i].nomCur);
         printf("Creditos: %d\n",curs[i].creditosCur);
         printf("Sistema de calificacion: %c\n",curs[i].scal);
      }
   }
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
}

void buscarDocenteporCodigo(CURSO curs[MAX],Docente doc[MAX],int dcursos,int ddoc,int dcursosxdocente[MAX]){
   int cd,i,j,comp=0;//comp es un valor bandera
   printf("\n\nIngrese el codigo del docente a buscar: ");
   scanf("%i",&cd);
   for(i=0;i<dcursos;i++){
      if(doc[i].codDoc==cd){
         comp=1;
         printf("\nDocente %d\n",i+1);
         printf("Nombre: %s\n",doc[i].nomDoc);
         printf("Escuela: %s\n",doc[i].escuela);
         printf("Peso: %.1f\n",doc[i].peso);
         printf("Cursos dictados por el profesor: \n");
         for(j=0;j<dcursosxdocente[i];j++){
            printf("\tCurso %d: %s",j+1, doc[i].c[j].nomCur);
         }
      }
   }
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
}

void eliminaCursoporPosicion(CURSO curs[MAX],int *dcurso){
   int i,n,posi;
   mostrarVectorCurso(curs,*dcurso);
   printf("\n\nIngrese la posicion del curso que desea eliminar del registro: ");
   scanf("%i",&posi);
   n=*dcurso;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dcurso){
      *dcurso=n;
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
void eliminarDocenteporPosicion(Docente doc[MAX], int *ddoc,int dcursosxdocente[MAX]){
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
         dcursosxdocente[i]=dcursosxdocente[i+1];
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

void fileEscribirDocentes(FILE *F,Docente x){
    fwrite(&x,sizeof(x),1,F);
    fclose(F);
}
void fileEscribirCursos(FILE *F,CURSO x){
   fwrite(&x,sizeof(x),1,F);
   fclose(F);
}

void fileLeerDocentes(FILE *F){
   int i=0;
   Docente x;
   encabezado3();
   fread(&x,sizeof(x),1,F);
   while(!feof(F)){
      printf("%3d\t%-12d%-32s%-18s%-18.2f\n",i+1,x.codDoc,x.nomDoc,x.escuela,x.peso);
      fread(&x,sizeof(x),1,F);
      i++;
   }
   raya1();
   fclose(F);
}

void fileLeerCursos(FILE *F){
   int i=0;
   CURSO x;
   encabezado5();
   fread(&x,sizeof(x),1,F);
   while(!feof(F)){
      printf("%3d\t%-12d%-32s%-18d%-18c\n",i+1,x.codCur,x.nomCur,x.creditosCur,x.scal);
      fread(&x,sizeof(x),1,F);
      i++;
   }
   raya1();
   cout <<"\n\n";
   system("pause");
   fclose(F);
}

void fileBuscarDocente(FILE *H){
   Docente A;
   int Codigo, i=0;
   // cargando clave a buscar
   printf("Codigo a buscar ---> ");
   scanf("%d",&Codigo);
   // aqui siempre debe empezar el ciclo de lectura
   // y fread() regresa siempre cuantas estructuras leyo

   encabezado3();
   fread(&A,sizeof(A),1,H);
   while(!feof(H))
   { // desplegando Registro Buscado
      if(A.codDoc == Codigo)
      {
         printf("%3d\t%-12d%-32s%-18s%-18.2f\n",i+1,A.codDoc,A.nomDoc,A.escuela,A.peso);
      }
      fread(&A, sizeof(A), 1, H);
   }; // aqui termina while
   // no olvidar cerrar archivo y siempre fuera de while
   raya1();
   fclose(H);
}
void fileBuscarCurso(FILE *H){
   CURSO A;
   int Codigo, i=0;
   // cargando clave a buscar
   printf("Codigo a buscar ---> ");
   scanf("%d",&Codigo);
   // aqui siempre debe empezar el ciclo de lectura
   // y fread() regresa siempre cuantas estructuras leyo

   encabezado5();
   fread(&A,sizeof(A),1,H);
   while(!feof(H))
   { // desplegando Registro Buscado
      if(A.codCur == Codigo)
      {
         printf("%3d\t%-12d%-32s%-18d%-18c\n",i+1,A.codCur,A.nomCur,A.creditosCur,A.scal);
      }
      fread(&A, sizeof(A), 1, H);
   }; // aqui termina while
   // no olvidar cerrar archivo y siempre fuera de while
   raya1();
   fclose(H);
}

void fileFiltrarDocentes(FILE *H){
   Docente A;
    int Hallado=0, Codigo, i=0;
    // cargando clave a buscar
    printf("Codigo >= que ---> ");
    scanf("%d",&Codigo);
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    encabezado3();
    fread(&A,sizeof(A),1,H);
    while(!feof(H))
    { // desplegando Registro Buscado
        if(A.codDoc >= Codigo)
        {
            printf("%3d\t%-12d%-32s%-18s%-18.2f\n",i+1,A.codDoc,A.nomDoc,A.escuela,A.peso);
            Hallado = 1;
            i++;
        }
        fread(&A, sizeof(A), 1, H);
    }; // aqui termina while
    raya1();
    if(Hallado == 0)
    {
    printf("Ninguno cumple con esa Condicion\n\n");
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(H);
}

void fileFiltrarCursos(FILE *H){
   CURSO A;
    int Hallado=0, Codigo, i=0;
    // cargando clave a buscar
    printf("Codigo >= que ---> ");
    scanf("%d",&Codigo);
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    encabezado5();
    fread(&A,sizeof(A),1,H);
    while(!feof(H))
    { // desplegando Registro Buscado
        if(A.codCur >= Codigo)
        {
         printf("%3d\t%-12d%-32s%-18d%-18c\n",i+1,A.codCur,A.nomCur,A.creditosCur,A.scal);
            Hallado = 1;
            i++;
        }
        fread(&A, sizeof(A), 1, H);
    }; // aqui termina while
    raya1();
    if(Hallado == 0)
    {
    printf("Ninguno cumple con esa Condicion\n\n");
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(H);
}

void fileEliminarDocente(FILE *FF){
    FILE *GG;
    Docente A;
    int Hallado=0, Codigo, remo, rena;
    printf("Codigo a Eliminar ---> ");
    //scanf("%d",&Codigo);getchar();
    cin>>Codigo;
    //abriendo, leyendo,cargando estructura
    GG = fopen("Temporal.dat","a+");
    if (GG == NULL){
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    fread(&A, sizeof(A), 1, FF);
    while(!feof(FF)){ // Registro Buscado
        if(Codigo != A.codDoc){
            fwrite(&A, sizeof(A), 1, GG);
        }
        if(Codigo == A.codDoc){
            Hallado = 1;
        }
        fread(&A, sizeof(A), 1, FF);
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(GG);
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3 caracteres
    remo=remove("Docentes.dat"); // Elimina
    printf("remove = %d\n", remo);
    rena=rename("Temporal.dat", "Docentes.dat"); //renombre
    printf("rename = %d\n", rena);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO ...\n\n");
    }
    else{
        printf("Registro eliminado\n\n");
    }
}

void fileEliminarCurso(FILE *FF){
    FILE *GG;
    CURSO A;
    int Hallado=0, Codigo, remo, rena;
    printf("Codigo a Eliminar ---> ");
    //scanf("%d",&Codigo);getchar();
    cin>>Codigo;
    //abriendo, leyendo,cargando estructura
    GG = fopen("Temporal.dat","a+");
    if (GG == NULL){
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    fread(&A, sizeof(A), 1, FF);
    while(!feof(FF)){ // Registro Buscado
        if(Codigo != A.codCur){
            fwrite(&A, sizeof(A), 1, GG);
        }
        if(Codigo == A.codCur){
            Hallado = 1;
        }
        fread(&A, sizeof(A), 1, FF);
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(GG);
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3 caracteres
    remo=remove("Cursos.dat"); // Elimina
    printf("remove = %d\n", remo);
    rena=rename("Temporal.dat", "Cursos.dat"); //renombre
    printf("rename = %d\n", rena);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO ...\n\n");
    }
    else{
        printf("Registro eliminado\n\n");
    }
}

void fileEditarDocente(FILE *FF)
{
    FILE *GG;
    Docente A;
    int Hallado=0, Codigo, Rem, Ren;
    // cargando clave a buscar
    printf("Codigo a Editar ---> ");
    scanf("%d",&Codigo);

    GG = fopen("Temporal.dat","a+");
    if (GG == NULL)
    {
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo

    fread(&A, sizeof(A), 1, FF);
    while(!feof(FF))
    { // Registro Buscado
        if(A.codDoc == Codigo)
        {
            int aux=0;
            char desea='n';
            Docente B;
            Hallado=1;
            B=A;
            while(aux==0){
                int opc1;
                fflush(stdin);
                system("cls");
                printf("RUTINA DE EDICION\n0SALIR\n1.Codigo\n2.Nombre\n3.Peso\nDigite su opcion--->");
                scanf("%d",&opc1);
                fflush(stdin);
                switch(opc1){
                    case 0:
                        printf("Desea guardar los cambios? S/N--->");
                        scanf("%c",&desea);
                        aux=1;
                        break;
                    case 1:
                        printf("Nuevo codigo --->");
                        scanf("%d",&B.codDoc);
                        break;
                    case 2:
                        fflush(stdin);
                        printf("Nuevo Nombre ---> ");
                        gets(B.nomDoc);
                        break;
                    case 3:
                        printf("Nuevo Peso -----> ");
                        scanf("%d",&B.peso);
                        break;
                    default:
                        printf("Opcion incorrecta!\n");
                }
                
            }
            if(desea=='S' || desea=='s'){
                fwrite(&B,sizeof(B),1,GG);
            }
            else{
                fwrite(&A, sizeof(A), 1, GG);
            }
            
        }
        else
        {
            fwrite(&A, sizeof(A), 1, GG);
        }
        fread(&A, sizeof(A), 1, FF);
    }; // aqui termina while
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(GG);
    //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3 caracteres
    Rem=remove("Docentes.dat");
    printf("remove %d", Rem);
    Ren=rename("Temporal.dat","Docentes.dat ");
    printf("rename %d", Ren);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO...\n\n");
    }
    else{
        printf("Registro Actualizado");
    }
}

void fileEditarCurso(FILE *FF)
{
    FILE *GG;
    CURSO A;
    int Hallado=0, Codigo, Rem, Ren;
    // cargando clave a buscar
    printf("Codigo a Editar ---> ");
    scanf("%d",&Codigo);

    GG = fopen("Temporal.dat","a+");
    if (GG == NULL)
    {
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo

    fread(&A, sizeof(A), 1, FF);
    while(!feof(FF))
    { // Registro Buscado
        if(A.codCur == Codigo)
        {
            int aux=0;
            char desea='n';
            CURSO B;
            Hallado=1;
            B=A;
            while(aux==0){
                int opc1;
                fflush(stdin);
                system("cls");
                printf("RUTINA DE EDICION\n0SALIR\n1.Codigo\n2.Nombre\n3.Sistema Calif\n4.Creditos\nDigite su opcion--->");
                scanf("%d",&opc1);
                fflush(stdin);
                switch(opc1){
                    case 0:
                        printf("Desea guardar los cambios? S/N--->");
                        scanf("%c",&desea);
                        aux=1;
                        break;
                    case 1:
                        printf("Nuevo codigo --->");
                        scanf("%d",&B.codCur);
                        break;
                    case 2:
                        fflush(stdin);
                        printf("Nuevo Nombre ---> ");
                        gets(B.nomCur);
                        break;
                    case 3:
                        printf("Nuevo Sistema Calif -----> ");
                        scanf("%c",&B.scal);
                        break;
                     case 4:
                        printf("Nuevo Numero Creditos--->");
                        scanf("%d",&B.creditosCur);
                    default:
                        printf("Opcion incorrecta!\n");
                }
                
            }
            if(desea=='S' || desea=='s'){
                fwrite(&B,sizeof(B),1,GG);
            }
            else{
                fwrite(&A, sizeof(A), 1, GG);
            }
            
        }
        else
        {
            fwrite(&A, sizeof(A), 1, GG);
        }
        fread(&A, sizeof(A), 1, FF);
    }; // aqui termina while
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(GG);
    //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3 caracteres
    Rem=remove("Cursos.dat");
    printf("remove %d", Rem);
    Ren=rename("Temporal.dat","Cursos.dat ");
    printf("rename %d", Ren);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO...\n\n");
    }
    else{
        printf("Registro Actualizado");
    }
}

void fileCopiarDocentes(FILE *F){
    FILE *G;
    Docente A;
    G = fopen("CopiaDocentes.dat","a+");

    fread(&A,sizeof(A),1,F);

    while(!feof(F)){
        fwrite(&A,sizeof(A),1,G);
        fread(&A,sizeof(A),1,F);
    }
    fclose(G);
    fclose(F);
}

void fileCopiarCursos(FILE *F){
    FILE *G;
    CURSO A;
    G = fopen("CopiaCursos.dat","a+");

    fread(&A,sizeof(A),1,F);

    while(!feof(F)){
        fwrite(&A,sizeof(A),1,G);
        fread(&A,sizeof(A),1,F);
    }
    fclose(G);
    fclose(F);
}

void fileOrdenarDocentes(FILE *F){
   Docente A[MAX];
    Docente t;
    FILE *G;
    G=fopen("Temporal.dat","a+");
    int i=0,aux=0,j=0,n;

    fread(&A[i],sizeof(Docente),1,F);
    i++;
    while(!feof(F)){
        fread(&A[i],sizeof(Docente),1,F);
        i++;
    }
    n=i-1;
    fclose(F);

    for(i=0;i<n-1;i++){
         aux=i;
         for(j=i+1;j<n;j++){
            if(A[aux].codDoc>A[j].codDoc){
               aux=j;
            }
         }
         //Intercambiando
         t=A[i];
         A[i]=A[aux];
         A[aux]=t;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
        fwrite(&A[i],sizeof(Docente),1,G);
    }
    fclose(G);

    int rem=remove("Docentes.dat");
    printf("rem=%d\n",rem);
    int ren=rename("Temporal.dat","Docentes.dat");
    printf("ren=%d\n",ren);

}
void fileOrdenarCursos(FILE *F){
   CURSO A[MAX];
    CURSO t;
    FILE *G;
    G=fopen("Temporal.dat","a+");
    int i=0,aux=0,j=0,n;

    fread(&A[i],sizeof(CURSO),1,F);
    i++;
    while(!feof(F)){
        fread(&A[i],sizeof(CURSO),1,F);
        i++;
    }
    n=i-1;
    fclose(F);

    for(i=0;i<n-1;i++){
         aux=i;
         for(j=i+1;j<n;j++){
            if(A[aux].codCur>A[j].codCur){
               aux=j;
            }
         }
         //Intercambiando
         t=A[i];
         A[i]=A[aux];
         A[aux]=t;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
        fwrite(&A[i],sizeof(CURSO),1,G);
    }
    fclose(G);

    int rem=remove("Cursos.dat");
    printf("rem=%d\n",rem);
    int ren=rename("Temporal.dat","Cursos.dat");
    printf("ren=%d\n",ren);
}

/*
 * NombreProg : Alumnos.cpp
 * Descripcion:  Registro de vector Alumnos
 *                con operaciones basicas
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

//OPERACIONES BASICAS
void crearVectorAlu(ALUMNO x[MAX],int *dx);

void leerVectorAlu(ALUMNO x[MAX], int *dx);

void mostrarVectorAlu(ALUMNO x[MAX], int dx);

int buscarAluporCodigo(ALUMNO x[MAX],int dx);
void buscaAluporNom(ALUMNO x[MAX],int dx);

void ordenarAluporCodigo(ALUMNO x[MAX],int dx);
void ordenarAluporNombre(ALUMNO x[MAX],int dx);

void editarAluporCodigo(ALUMNO x[MAX], int dx);

void insertarAluporPosicion(ALUMNO x[MAX],int *dx);
void insertarAluporValor(ALUMNO x[MAX],int *dx);

void eliminaAluporPosicion(ALUMNO x[MAX],int *dx);
void eliminarAluporValor(ALUMNO x[MAX],int *dx);

//ARCHIVOS
//Escribir
void FileWriteAlu(ALUMNO x[MAX],FILE *y,int dx);
//Leer
void FileReadAlu(FILE *y);
//Buscar
void FileFindAlu(FILE *y);
//Filtrar
void FileFilAlu(FILE *y);
//Eliminar
void FileDelAlu(FILE *y);
//Editar
void FileEditAlu(FILE *y);
//Copiar
void FileCopyAlu(FILE *y);
//Ordenar
void FileOrderAlu(FILE *y);

//MENU
void menu(ALUMNO x[MAX],FILE *y,int *dx,int &opc);
void menu2(ALUMNO x[MAX],int *dx,int mod);
void encabezado1();
void raya1();
void raya2();

int main(){
   int nA,opc;
   ALUMNO A[]={ //Vector de Prueba
      108,"Jorge","edu",{1,1,1},12,
      109,"Eva","fis",{1,1,1},18,
      110,"Luis","med",{1,1,1},5,
      111,"Alina","let",{1,1,1},16,
   };

   FILE *F;
   crearVectorAlu(A,&nA);
   nA = sizeof(A)/(sizeof(int)*4+sizeof(char)*44+sizeof(float));
   do{
      menu(A,F,&nA,opc);
   }while(opc!=0);
   system("pause");
   return 0;
   
}

void menu(ALUMNO x[MAX],FILE *y,int *dx,int &opc){
   system("cls");
   printf(" \n\n\t\tREGISTRO DE ALUMNOS\n\n");
   printf("\t0. TERMINAR \n\n");
   printf("\t1. Ingreso de datos\n");
   printf("\t2. Mostrar Alumnos\n");
   printf("\t3. Buscar Alumno\n");
   printf("\t4. Ordenar Registro de Alumnos\n");
   printf("\t5. Editar Alumno por codigo\n");
   printf("\t6. Insertar Alumno\n");
   printf("\t7. Eliminar Alumno\n");
   printf("\t8. Guardar datos\n");
   printf("\t9. Leer datos guardados\n");

   do{
      printf("\nDigite su opcion ---> ");
      scanf("%d",&opc);
   }while(opc<0 || opc>9);

   switch(opc){
      case 1://LEER
         leerVectorAlu(x,dx);
         system("pause");
         break;
      case 2://MOSTRAR
         mostrarVectorAlu(x,*dx);
         system("pause");
         break;
      case 3://BUSCAR
         menu2(x,dx,opc);
         system("pause");
         break;
      case 4://ORDENAR
         menu2(x,dx,opc);
         system("pause");
         break;
      case 5://EDITAR
         editarAluporCodigo(x,*dx);
         system("pause");
         break;
      case 6://INSERTAR
         menu2(x,dx,opc);
         system("pause");
         break;
      case 7://ELIMINAR
         menu2(x,dx,opc);
         system("pause");
         break;
      case 8:
         FileWriteAlu(x,y,*dx);
         system("pause");
         break;
      case 9:
         FileReadAlu(y);
         system("pause");
         break;
   }
}

void menu2(ALUMNO x[MAX],int *dx,int mod){
   int opc;
   system("cls");
   if(mod==3){
      printf("\tBUSCAR ALUMNO\n");
   }else if(mod==4){
      printf("\tORDENAR REGISTRO ALUMNO\n");
   }else if(mod==6){
      printf("\tINSERTAR ALUMNO\n");
   }else{
      printf("\tELIMINAR ALUMNO");
   }

   printf("0. TERMINAR\n\n");

   if(mod==3 || mod==4){
      printf("\t1.CODIGO\n");
      printf("\t2.NOMBRE\n");
   }else{
      printf("\t1.POSICION\n");
      printf("\t2.VALOR\n");
   }

   do{
      printf("\nDigite su opcion ---> ");
      scanf("%d",&opc);
   }while(opc<0 || opc>2);
   switch (opc)
   {
   case 1:
      if(mod==3){
         buscarAluporCodigo(x,*dx);
      }else if(mod==4){
         ordenarAluporCodigo(x,*dx);
         printf("\nLos codigos de los registros han sido ordenados de forma ascendente...\n\n");
         cout<<endl;
      }else if(mod==6){
         insertarAluporPosicion(x,dx);
      }else{
         eliminaAluporPosicion(x,dx);
      }
      break;

   case 2:
      if(mod==3){
         buscaAluporNom(x,*dx);
      }else if(mod==4){
         ordenarAluporNombre(x,*dx);
         printf("\nLos nombres de los registros han sido ordenados de forma ascendente...\n\n");
         cout<<endl;
      }else if(mod==6){
         insertarAluporValor(x,dx);
      }else{
         eliminarAluporValor(x,dx);
      }
      break;
   }
}

void FileWriteAlu(ALUMNO x[MAX],FILE *y,int dx){
   int i;
   system("cls");
   //Abre el archivo ,a+ -> abrir para lectura y escritura
   y = fopen("Alumnos.dat","a+");

   //Consistencia
   if(y != NULL){
      //Grabado en disco
      for(i=0;i<dx;i++){
         fwrite(&x[i],sizeof(ALUMNO),1,y);
      }
      //Confirmacion para el usuario
      printf("Registro Guardado\n\n");
      //Cerrando archivo
      fclose(y);
   }
    else{
      printf("\nNo se puede abrir el archivo...\n\n");
   }
}

void FileReadAlu(FILE *y){
   int i;
   ALUMNO a;
   system("cls");
   i = 0;

   //Abre el archivo -> r = abre un archivo para leer
   y = fopen("Alumnos.dat","a+");
   
   //Consistencia
   if(y!=NULL){
      encabezado1();
      fread(&a,sizeof(ALUMNO),1,y);
      i++;
      while(!feof(y)){//desplegando estructuras
         printf("%3d\t%-12d%-32s%-18s%-2d/%-2d/%-16d%-.1fkg\n",i,a.codAlu,a.nomAlu,a.escuela,a.fnac.dia,a.fnac.mes,a.fnac.anio,a.peso);
         fread(&a,sizeof(ALUMNO),1,y);
         i++;
      }
      //Cerrando archivo
      fclose(y);
      raya1();
      cout <<"\n\n";
   }
   else{
      printf("\nNo se puede abrir el archivo...\n\n");
   }
}

void crearVectorAlu(ALUMNO x[MAX],int *dx){
   *dx=-1;
}

void leerVectorAlu(ALUMNO x[MAX], int *dx){
   int n, i=0;
   system("cls");
   printf("*Llenando Registro de Alumnos*\n");
   printf("\n\nNumero de ALUMNOS ---> ");
   scanf("%d", &n);
   if(n < MAX){
   for(i=0;i<n;i++){
      printf("\n\tAlumno:  %d\n", i+1);
      cout <<" Codigo ---> ";
      cin >>x[i].codAlu;
      cout <<" Nombre ---> ";
      fflush(stdin);
      cin.getline(x[i].nomAlu,40,'\n');
      cout <<" Escuela ---> ";
      cin >>x[i].escuela;
      
      //Consistencia fecha de nacimiento
      do{
      cout <<" Fecha de nacimiento(dd/mm/aaaa):"<<endl;
      cout<<"\tdd--->";
      cin >>x[i].fnac.dia;
      cout<<"\tmm--->";
      cin >>x[i].fnac.mes;
      cout<<"\taaaa--->";
      cin >>x[i].fnac.anio;
      }while(x[i].fnac.dia>31 || x[i].fnac.mes>12 || x[i].fnac.anio<1900);
      
      cout <<" Peso(kg.)---> ";
      cin >>x[i].peso;
      cout<<endl;
   }
    *dx = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
   }
}

void mostrarVectorAlu(ALUMNO x[MAX], int dx){
   int i;
   //Consistencia
   if(dx>0){
      encabezado1();
         for(i=0;i<dx;i++){
            printf("%3d\t%-12d%-32s%-18s%-2d/%-2d/%-16d%-.1fkg\n",i+1,x[i].codAlu,x[i].nomAlu,x[i].escuela,x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio,x[i].peso);
         }
      raya1();
      cout <<"\n\n";
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}

int buscarAluporCodigo(ALUMNO x[MAX],int dx){
   int cd,i,pos=-1;
   bool comp=false;//comp es un valor bandera
   
   printf("\n\nCODIGO: ");
   scanf("%d",&cd);
   //Busca el alumno y muestra sus datos
   for(i=0;i<dx;i++){
      if(x[i].codAlu==cd){
         printf("\nAlumno %d\n",i+1);
         printf("Nombre: %s\n",x[i].nomAlu);
         printf("Escuela: %s\n",x[i].escuela);
         printf("Peso: %.1f\n",x[i].peso);
         printf("Fecha de nacimiento: %d/%d/%d \n",x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio);
         comp=true;
         pos = i;
      }
   }
   //Muestra en caso no se encuentre el alumno
   if(!comp){
      printf("No se encontro alumnos con el codigo ingresado %d\n",cd);
   }

   return pos;
}

void buscaAluporNom(ALUMNO x[MAX],int dx){
   int i=0;
   char band = false;
   char buscar[40];
   
   printf("\n\nNOMBRE: ");
   fflush(stdin);
   cin.getline(buscar,40,'\n');
   while(!band && i<dx){
      if(strcmp(x[i].nomAlu,buscar)==0){
         system("cls");
         printf("\nAlumno encontrado mostrando datos...");
         printf("\nAlumno %d\n",i+1);
         printf("Nombre: %s\n",x[i].nomAlu);
         printf("Escuela: %s\n",x[i].escuela);
         printf("Peso: %.1f\n",x[i].peso);
         printf("Fecha de nacimiento: %d/%d/%d \n\n",x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio);
         band = true ;
      }
      i++;
   }
}

void editarAluporCodigo(ALUMNO x[MAX], int dx){
   int cod,i,pos, men=0;
    ALUMNO B;
   mostrarVectorAlu(x,dx);
   fflush(stdin);
   pos = buscarAluporCodigo(x,dx);
   if(pos!=-1){
       B = x[pos];
       while(men==0){
           int opc;
           char desea='n';
           system("cls");
           printf("\t\tAlumno %d, EDICION",pos+1);
           printf("\n\t0.TERMINAR: \n");
           printf("\t1.NOMBRE: \n");
           printf("\t2.ESCUELA: \n");
           printf("\t3.PESO: \n");
           printf("Digite su opcion ---> ");
           scanf("%d",&opc);
           switch (opc)
           {
           case 0:
               fflush(stdin);
               printf("Desea guardar? (s/n): ");
               scanf("%c",&desea);
               if(desea == 'S' || desea=='s'){
                   x[pos] = B;
               }
               men=1;
               break;
            case 1:
                system("cls");
		fflush(stdin);
                printf("NUEVO NOMBRE: ");
                gets(B.nomAlu);
                break;
            case 2:
                system("cls");
		fflush(stdin);
                printf("NUEVA ESCUELA: ");
                gets(B.escuela);
            case 3:
                system("cls");
                printf("NUEVO PESO: ");
                scanf("%f",&B.peso);
                break;
           default:
                system("Opcion invalida...!\n");
               break;
           }
       }
   }
}

void insertarAluporPosicion(ALUMNO x[MAX],int *dx){
   int i,n;
   int posi,cod;
   mostrarVectorAlu(x,*dx);

   n = *dx;
   n = n + 1;
   i = *dx;
   printf("\n\nPOSICION: ");    scanf("%i",&posi);

   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx+1){
         *dx=n;
         while(i>posi-1){
               x[i] = x[i-1];
               i--;
            }
         printf("\n**Registro de ALUMNOS: \n");
         printf("\n\tAlumno:  %d\n", posi);

         cout <<" Codigo ---> ";
         cin >>cod;

         x[i].codAlu=cod;
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
         printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
    else{
      printf("Dimension fuera de rango ...\n");
   }
}

void insertarAluporValor(ALUMNO x[MAX],int *dx){
   int posi,i,j,n;
   int codigo;
   n=*dx;
   posi = 1;
   mostrarVectorAlu(x,*dx);
   if(n<MAX){
      printf("\n\nCODIGO: ");
      scanf("%i",&codigo);
      printf("\n\nCodigo Leido...");

      for(i=0;i<*dx;i++){
         if(codigo>x[i].codAlu){
               posi+=1;
         }
      }

      printf("\n\nA continuacion ingrese los datos del alumno...\n");

      printf("\n**Registro de ALUMNOS: \n");
      printf("\n\tAlumno:  %d\n", posi);

      x[posi-1].codAlu=codigo;
      cout <<" Nombre ---> ";
      cin>>x[posi-1].nomAlu;
      cout <<" Escuela ---> ";
      cin >>x[posi-1].escuela;
      cout <<" Fecha de nacimiento(dd/mm/aaaa):"<<endl;
      cout<<"\tdd--->";
      cin >>x[posi-1].fnac.dia;
      cout<<"\tmm--->";
      cin >>x[posi-1].fnac.mes;
      cout<<"\taaaa--->";
      cin >>x[posi-1].fnac.anio;
      cout <<" Peso(kg.)---> ";
      cin >>x[posi-1].peso;
      cout<<endl;
      printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      *dx+=1;
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
}

void eliminaAluporPosicion(ALUMNO x[MAX],int *dx){
   int i,n,posi;
   mostrarVectorAlu(x,*dx);
   printf("\n\nPOSICION: ");
   scanf("%i",&posi);
   n=*dx;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dx){
      *dx=n;
      while(i<n){
         x[i] = x[i+1];
         i = i+1;
      }
      printf("\nDatos del alumno de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
}

void eliminarAluporValor(ALUMNO x[MAX],int *dx){
   int n,i,j,pos;
   bool band;
   ALUMNO dato;
   n = *dx;
   band=false;

   system("cls");
   printf("\n\tDigite el Codigo del Alumno a elimnar:\n");
   cout <<" Codigo ---> ";
   cin>>dato.codAlu;
   cout<<endl;

   if(*dx>0){
      for(i=0;i<n;i++){
         if(dato.codAlu==x[i].codAlu){
            pos = i;
            band = true;
         }
      }
      if(band){
         for(j=pos;j<n;j++){
            x[j]=x[j+1];
         }
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorAlu(x,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}

void ordenarAluporCodigo(ALUMNO x[MAX],int dx){
   int i,j,min;
   ALUMNO aux;
   if(dx>-1){
      for(i=0;i<dx;i++){
         min = i;
         for(j=i+1;j<dx;j++){
            if(x[j].codAlu < x[min].codAlu){
               min = j;
            }
         }
         aux = x[i];
         x[i] = x[min];
         x[min] = aux;
      }

      mostrarVectorAlu(x,dx);
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}

void ordenarAluporNombre(ALUMNO x[MAX],int dx){
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

void raya1()
{
   printf("-------------------------------------------------------------------------------------------------------------\n");
}

void raya2()
{
   printf("=============================================================================================================\n");
}

void FileFindAlu(FILE *y){
   y = fopen("Alumnos.dat","r");
   ALUMNO x;
   int codigo;
   bool band = false;
   //Digita el codigo del alumno que quiere buscar
   printf("Codigo a buscar --> ");
   printf("%d",&codigo);

   fread(&x,sizeof(x),1,y);
   while(!feof(y))
   {
      if(x.codAlu==codigo){//Desplega registro cuando encuentre al alumno
         encabezado1();
         printf("1\t%-12d%-32s%-18s%-2d/%-2d/%-16d%-.1fkg\n",x.codAlu,x.nomAlu,x.escuela,x.fnac.dia,x.fnac.mes,x.fnac.anio,x.peso);
         raya1();
         band = true;
      }
      fread(%x,sizeof(x),1,y);
   }
   if(!band){
      printf("No se encontro el codigo del alumno");
   }

   fclose(y);
}
void FileFilAlu(FILE *y){
   //Abre el archivo
   y = fopen("Alumnos.dat","r");
   ALUMNO x;
   int codigo,i=0;
   float peso;
   bool band = false;
   
   printf("Peso >= que --> ");
   printf("%f",&peso);

   fread(&x,sizeof(x),1,y);
   while(!feof(y)){
      if(x.peso>=peso){
         //Muestra Registro cuando se cumpla la condicion
         encabezado1();
         printf("%3d\t%-12d%-32s%-18s%-2d/%-2d/%-16d%-.1fkg\n",i+1,x.codAlu,x.nomAlu,x.escuela,x.fnac.dia,x.fnac.mes,x.fnac.anio,x.peso);
         band = true;
         i++;
      }
      fread(&x,sizeof(x),1,y);
   }
   raya1();
   if(!band){
      printf("Ningun Alumno cumple con la condicion\n\n")
   }
   //cierra el archivo
   fclose(y);
}

void FileDelAlu(FILE *y){
   //Abre el archivo
   y = fopen("Alumnos.dat","r");
   FILE *z;
   ALUMNO x;
   int codigo,i=0;
   bool band = false;

   printf("Codigo a Eliminar --->");
   cin>>codigo;

   z = fopen("Temp.dat","a+");
   if(z == NULL){
      printf("Nose puede abrir el archivo\n");
      exit(1);
   }
   fread(&x,sizeof(x),1,y);

   while(!feof(y)){
      if(codigo!=x.codAlu){
         fwrite(&x,sizeof(x),1,z);
      }
      if(codigo==x.codAlu){
         band=true;
      }
   }

}
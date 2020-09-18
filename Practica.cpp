/*
 * nomPrograma: Practica.cpp
 * descripcion:
 * Registro y archivo de practicas de los alumnos,
 * Con operaciones basicas
 * autor:  ROMAN CESPEDES, Samuel Aaron
 *         TORRE ARTEAGA, Alexander
 *         CARMEN CRUZATTI, Angel Gerardo
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
//OPERACIONES BASICAS CON VECTORES
void crearVectorPc(int *dx);
void leerVectorPc(PRACTICA p[MAX],int *dx);
void mostrarVectorPc(PRACTICA p[MAX],int dx);
int buscarPcxCodAlu(PRACTICA p[MAX],int dx,int cod);
void buscarPracticasporCodigoAlumno(PRACTICA p[MAX], int dx);
int buscarPcxCodCurso(PRACTICA p[MAX],int dx,int cod);
void buscarPracticasporCodigoCurso(PRACTICA p[MAX], int dx);
void editarporCodigoPc(PRACTICA p[MAX], int dx);
void editarPc(PRACTICA p[MAX],int dx);
void insertarPracticasporPosicion(PRACTICA p[MAX],int *dx);
void insertarPracticasporValor(PRACTICA p[MAX],int *dx);
void eliminarPracticasporPosicion(PRACTICA p[MAX],int *dx);
void eliminarPracticasporValor(PRACTICA p[MAX],int *dx);

//MENU
void menu();
void menu2(PRACTICA fin[MAX],int *dx,int mod);
void encabezado2(char title[]);
void raya3();
void raya4();

//ARCHIVOS

//Escribir
void fileSalvarPractica(FILE *F,PRACTICA p[MAX],int dx);
//Leer
void fileRecuperarPractica(FILE *F);
//Buscar
void fileBuscarPractica(FILE *F);
//Filtrar
void fileFiltrarPractica(FILE *F);
//Eliminar
void fileEliminarPractica(FILE *F);
//Editar
void fileEditarPractica(FILE *FF);
//Copiar
void fileCopiarPractica(FILE *F);
//Ordenar
void fileOrdenarPractica(FILE *F);

int main (){
   menu();
   system("pause");
   return 0;

}
void menu(){
   FILE *FPC;
   int np=0,opc;
   PRACTICA p[]={
      108,202, {13,14,15,12,14,12,14,13,14,11},13,
      109,188, {8,9,11,12,13,16,11,12,14,7},11,
      110,192, {15,20,11,16,15,14,13,15,15,11},15,
      111,202, {8,8,8,9,6,14,9,10,11,11},9,
   };
   np = sizeof(p)/(sizeof(int)*13);
   do{
   system("cls");
   printf(" \n\n\t\tSISTEMA DE NOTAS DE PRACTICA\n\n");
   printf("\t0. TERMINAR \n\n");
   printf("\t1. INGRESO DE DATOS\n");
   printf("\t2. MOSTRAR\n");
   printf("\t3. BUSCAR\n");
   printf("\t4. EDITAR\n");
   printf("\t5. INSERTAR\n");
   printf("\t6. ORDENAR POR CODIGO\n");
   printf("\t7. ORDENAR POR NOTA\n");
   printf("\t8. ELIMINAR\n");
   printf("\t\tOPERACIONES CON ARCHIVOS\n");
   printf("\t9.  SALVAR\n");
   printf("\t10. RECUPERAR\n");
   printf("\t11. Buscar\n");
   printf("\t12. Filtrar\n");
   printf("\t13. Eliminar\n");
   printf("\t14. Editar\n");
   printf("\t15. Copiar\n");
   printf("\t16. Ordenar\n");
   do{
      printf("\nDigite su opcion ---> ");
      scanf("%d",&opc);
   }while(opc<0 || opc>16);
        system("cls");
        switch(opc){
            case 0:
                system("cls");
                printf("SALIO DEL PROGRAMA\n");
                system("pause");
                exit(0);
            case 1://LEER
                leerVectorPc(p,&np);
                break;
            case 2://MOSTRAR
                mostrarVectorPc(p,np);
                break;
            case 3://BUSCAR
                menu2(p,&np,opc);
                break;
            case 4://EDITAR
               editarPc(p,np);
               break;
            case 5://INSERTAR
               menu2(p,&np,opc);
               break;
            case 6:
               break;
            case 7:
               break;
            case 8:
               menu2(p,&np,opc);
               break;
            case 9:
                fileSalvarPractica(FPC,p,np);
                break;
            case 10:
                fileRecuperarPractica(FPC);
                break;
            case 11:
               fileBuscarPractica(FPC);
               break;
            case 12:
               fileFiltrarPractica(FPC);
               break;
            case 13:
               fileEliminarPractica(FPC);
               break;
            case 14:
               fileEditarPractica(FPC);
               break;
            case 15:
               fileCopiarPractica(FPC);
               break;
            case 16:
               fileOrdenarPractica(FPC);
               break;
            default:
                printf("Opcion invalida....!\n");
        }
   }while(opc!=0);
}

void menu2(PRACTICA p[MAX],int *dx,int mod){
  int opc;
   system("cls");
   if(mod==3){
      printf("\tBUSCAR NOTAS DE PRACTICAS\n");
   }else if(mod==5){
      printf("\tINSERTAR NOTAS DE PRACTICAS\n");
   }else{
      printf("\tELIMINAR NOTAS DE PRACTICAS");
   }

   printf("\n0. TERMINAR\n\n");

   if(mod==3){
      printf("\t1.CODIGO ALUMNO\n");
      printf("\t2.CODIGO CURSO\n");
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
         buscarPracticasporCodigoAlumno(p,*dx);
      }else if(mod==5){
         insertarPracticasporPosicion(p,dx);
      }else{
         eliminarPracticasporPosicion(p,dx);
      }
      break;

   case 2:
      if(mod==3){
         buscarPracticasporCodigoCurso(p,*dx);
      }else if(mod==5){
         insertarPracticasporValor(p,dx);
      }else{
         eliminarPracticasporValor(p,dx);
      }
      break;
   }
}

void crearVectorPc(int *dx){
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
   char promedio[]="NOTA";
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

void buscarPracticasporCodigoCurso(PRACTICA p[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE PROMEDIO DE PRACTICAS";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(p[i].codCur==cd){
         encabezado2(titulo);
         printf("%3d\t%-12d%-10d\n",i+1,p[i].codCur,p[i].promedio);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}

void buscarPracticasporCodigoAlumno(PRACTICA p[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE PROMEDIO DE PRACTICAS";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(p[i].codAlu==cd){
         encabezado2(titulo);
         printf("%3d\t%-12d%-10.1d\n",i+1,p[i].codAlu,p[i].promedio);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}
void insertarPracticasporPosicion(PRACTICA p[MAX],int *dx){
   int i,j,n,suma=0;
   int posi,cod;
   mostrarVectorPc(p,*dx);
   n = *dx;
   n = n + 1;
   i = *dx;
   printf("\n\nPOSICION: ");
   scanf("%i",&posi);
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx+1){
         while(i>posi-1){
               p[i] = p[i-1];
               i--;
            }
         *dx=n;
         printf("\n**Registro de PRACTICAS: \n");
         printf("\n\tAlumno:  %d\n", posi);

         cout <<" Codigo ---> ";
         cin >>cod;

         p[i].codAlu=cod;
         cout <<" Codigo de Curso ---> ";
         cin>>p[i].codCur;
         for(j=0;j<10;j++){
            printf("\n\tPractica %d: ",j+1);
            cin>>p[i].prac[j];
            cout<<endl;
            suma=suma+p[i].prac[j];
         }
         p[i].promedio=suma/10;
         suma=0;
         printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,p[i].promedio);
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
void insertarPracticasporValor(PRACTICA p[MAX],int *dx){
   int posi,i,j,n,suma;
   int codigo;
   n=*dx;
   posi = 1;
   mostrarVectorPc(p,*dx);
   if(n<MAX){
      printf("\n\nCODIGO DE ALUMNO: ");
      scanf("%i",&codigo);

      for(i=0;i<*dx;i++){
         if(codigo>p[i].codAlu){
               posi+=1;
         }
      }
      printf("\n\nA continuacion ingrese los datos de las practicas...\n");

      printf("\n**Registro de PRACTICAS: \n");
      printf("\n\tAlumno:  %d\n", posi);

      p[posi-1].codAlu=codigo;
      cout <<" Codigo de Curso ---> ";
      cin>>p[i].codCur;
      for(j=0;j<10;j++){
            printf("\n\t\tPractica %d: ",j+1);
            cin>>p[i].prac[j];
            cout<<endl;
            suma=suma+p[i].prac[j];
         }
         p[i].promedio=suma/10;
         suma=0;
         printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,p[i].promedio);

      printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      *dx+=1;
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
}

void eliminarPracticasporPosicion(PRACTICA p[MAX],int *dx){
   int i,n,posi;
   mostrarVectorPc(p,*dx);
   printf("\n\nPOSICION: ");
   scanf("%i",&posi);
   n=*dx;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dx){
      *dx=n;
      while(i<n){
         p[i] = p[i+1];
         i = i+1;
      }
      printf("\nDatos de las Practicas de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
}

void eliminarPracticasporValor(PRACTICA p[MAX],int *dx){
   int n,i,j,pos;
   bool band;
   int codigo;
   n = *dx;
   band=false;

   system("cls");
   printf("\n\nCODIGO DE ALUMNO:\n");
   cout <<" Codigo ---> ";
   cin>>codigo;
   cout<<endl;

   if(*dx>0){
      for(i=0;i<n;i++){
         if(codigo==p[i].codAlu){
            pos = i;
            band = true;
         }
      }
      if(band){
         for(j=pos;j<n;j++){
            p[j]=p[j+1];
         }
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
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

void editarPc(PRACTICA p[MAX],int dx){
   int cod,edit,i,suma=0;
   printf("CODIGO:");
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
	system("pause");

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
void fileBuscarPromPractica(FILE *F){
   F = fopen("Practica.dat","a+");
   char titulo[]="\n\nREPORTE DE PROMEDIO DE PRACTICAS";
   PRACTICA k ;
   int Codigo, i=0;
   // Digita el codigo del alumno
   printf("Ingrese codigo de alumno ---> ");
   scanf("%d",&Codigo);
   // aqui siempre debe empezar el ciclo de lectura
   // y fread() regresa siempre cuantas estructuras leyo
   encabezado2(titulo);
   fread(&k,sizeof(k),1,F);
   while(!feof(F))
   { // desplegando Registro Buscado
      if(k.codAlu == Codigo)
      {
         printf("%3d\t%-12d%-10.1f\n",i+1,k.codAlu,k.promedio);
      }
      fread(&k, sizeof(k), 1, F);
   }; // aqui termina while
   // no olvidar cerrar archivo y siempre fuera de while
   raya3();
   fclose(F);
}
void fileFiltrarPromPractica(FILE *F){
   F = fopen("Practica.dat","a+");
   char titulo[]="\n\nREPORTE DE PROMEDIO PRACTICAS";
   PRACTICA k;
    int Hallado=0, Codigo, i=0;
    // Digitando codigo
    printf("Codigo >= que ---> ");
    scanf("%d",&Codigo);
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    encabezado2(titulo);
    fread(&k,sizeof(k),1,F);
    while(!feof(F))
    {
        if(k.codAlu >= Codigo)
        {
           //Muestra Registro cuando se cumpla la condicion
            printf("%3d\t%-12d%-10.1f\n",i+1,k.codAlu,k.promedio);
            Hallado = 1;
            i++;
        }
        fread(&k, sizeof(k), 1, F);
    }; // aqui termina while
    raya3();
    if(Hallado == 0)
    {
    printf("Ninguno cumple con esa Condicion\n\n");
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(F);
}
void fileEliminarPromPractica(FILE *FF){
    FF = fopen("Practica.dat","a+");
    FILE *HH;
    PRACTICA k;
    int Hallado=0, Codigo, remo, rena;
    printf("Codigo de alumno para eliminar su promedio ---> ");
    //scanf("%d",&Codigo);getchar();
    cin>>Codigo;
    //abriendo, leyendo,cargando estructura
    HH = fopen("Temporal.dat","w");
    if (HH == NULL){
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    fread(&k, sizeof(k), 1, FF);
    while(!feof(FF)){ // Registro Buscado
        if(Codigo != k.codAlu){
            fwrite(&k, sizeof(k), 1, HH);
        }
        if(Codigo == k.codAlu){
            Hallado = 1;
        }
        fread(&k, sizeof(k), 1, FF);
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    remo=remove("Practica.dat"); // Elimina
    printf("remove = %d\n", remo);
    rena=rename("Temporal.dat", "Practica.dat"); //renombre
    printf("rename = %d\n", rena);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO ...\n\n");
    }
    else{
        printf("Registro eliminado\n\n");
    }
}

void fileEditarPractica(FILE *FF)
{
    FF = fopen("Practica.dat","a+");
    FILE *HH;
    PRACTICA k;
    int Hallado=0, Codigo, Rem, Ren,i,j,suma=0;
    // cargando codigo a buscar
    printf("Codigo de alumno a Editar ---> ");
    scanf("%d",&Codigo);
   HH = fopen("Temporal.dat","a+");
    if (HH == NULL)
    {
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    // aqui siempre debe empezar el ciclo de lectura
    fread(&k, sizeof(k), 1, FF);
    while(!feof(FF))
    { // Registro Buscado
        if(k.codAlu == Codigo)
        {
            int aux=0;
            char desea='n';
            PRACTICA m;
            Hallado=1;
            m=k;
            while(aux==0){
                int opc1;
                fflush(stdin);
                system("cls");
                printf("RUTINA DE EDICION\n0SALIR\n1.Codigo\n2.Nota\nDigite su opcion--->");
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
                        scanf("%d",&m.codAlu);
                        break;
                    case 2:
                        for(j=0;j<10;j++){
                        printf("\n\t\tPractica %d: ",j+1);
                        cin>>k[i].prac[j];
                        cout<<endl;
                        suma=suma+k[i].prac[j];
                        }
                        k[i].promedio=suma/10;
                        suma=0;
                        printf("\n\tEl promedio de practicas del alumno %d : es %d\n\n",i+1,k[i].promedio);
                        break;
                        default:
                        printf("Opcion incorrecta!\n");
                }
            }
            if(desea=='S' || desea=='s'){
                fwrite(&m,sizeof(m),1,HH);
            }
            else{
                fwrite(&k, sizeof(k), 1, HH);
            }
        }
        else
        {
            fwrite(&k, sizeof(k), 1, HH);
        }
        fread(&k, sizeof(k), 1, FF);
    };
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    //Removiendo y eliminando
    Rem=remove("Practica.dat");
    printf("remove %d", Rem);
    Ren=rename("Temporal.dat","Practica.dat ");
    printf("rename %d", Ren);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO...\n\n");
    }
    else{
        printf("Registro Actualizado");
    }
}
void fileCopiarPractica(FILE *F){
    F = fopen("Practica.dat","a+");
    FILE *H;
    PRACTICA k;
    H = fopen("CopiaPractica.dat","a+");
    fread(&k,sizeof(k),1,F);
    while(!feof(F)){
        fwrite(&k,sizeof(k),1,H);
        fread(&k,sizeof(k),1,F);
    }
    fclose(H);
    fclose(F);
}
void fileOrdenarPractica(FILE *F){
    F = fopen("Final.dat","a+");
    PRACTICA k[MAX];
    PRACTICA t;
    FILE *H;
    H=fopen("Temporal.dat","a+");
    int i=0,aux=0,j=0,n;
    fread(&k[i],sizeof(PRACTICA),1,F);
    i++;
    while(!feof(F)){
        fread(&k[i],sizeof(PRACTICA),1,F);
        i++;
    }
    n=i-1;
    fclose(F);
    for(i=0;i<n-1;i++){
         aux=i;
         for(j=i+1;j<n;j++){
            if(k[aux].codAlu>k[j].codAlu){
               aux=j;
            }
         }
         //Intercambiando
         t=k[i];
         k[i]=k[aux];
         k[aux]=t;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
        fwrite(&k[i],sizeof(PRACTICA),1,H);
    }
    //Cierra el archivo
    fclose(H);
    int rem=remove("Practica.dat");
    printf("rem=%d\n",rem);
    int ren=rename("Temporal.dat","Practica.dat");
    printf("ren=%d\n",ren);
}

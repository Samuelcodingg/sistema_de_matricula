/*
 * nomPrograma: Exfinal.cpp
 * descripcion:
 * Registro y archivo de los examenes finales de los alumnos,
 * Con operaciones basicas.
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

//OPERACIONES BASICAS

void crearVectorFinal(int *dx);
void leerVectorFinal(EXFINAL fin[MAX],int *dx);
void mostrarVectorFinal(EXFINAL fin[MAX],int dx);
int buscarFinalxCodCurso(EXFINAL fin[MAX],int dx,int cod);
void buscarFinalporCodigoCurso(EXFINAL fin[MAX], int dx);
int buscarFinalxCodAlu(EXFINAL fin[MAX],int dx,int cod);
void buscarFinalporCodigoAlumno(EXFINAL fin[MAX], int dx);
void editarFinal(EXFINAL fin[MAX], int dx);
void insertarFinalporPosicion(EXFINAL fin[MAX],int *dx);
void insertarFinalporValor(EXFINAL fin[MAX],int *dx);
void eliminaFinalporPosicion(EXFINAL fin[MAX],int *dx);
void eliminarFinalporValor(EXFINAL fin[MAX],int *dx);
void ordenarcodigoAluFinal(EXFINAL fin[MAX],int dx);
void ordenarnotaFinal(EXFINAL fin[MAX],int dx);

///MENU
void menu();
void menu2(EXFINAL fin[MAX],int *dx,int mod);
void encabezado(char title[]);
void raya1();
void raya2();


//ARCHIVOS

//Escribir
void fileSalvarFinal(FILE *F,EXFINAL fin[MAX],int dx);
//Leer
void fileRecuperarFinal(FILE *F);
//Buscar
void fileBuscarFinal(FILE *F);
//Filtrar
void fileFiltrarFinal(FILE *F);
//Eliminar
void fileEliminarFinal(FILE *F);
//Editar
void fileEditarFinal(FILE *FF);
//Copiar
void fileCopiarFinal(FILE *F);
//Ordenar
void fileOrdenarFinal(FILE *F);



int main (){
    menu();
    system("pause");
    return 0;


}
void menu(){
   FILE *FFIN;
   int nf,opc,pos;
   EXFINAL fin[]={
        108,202,18,
        109,188,14,
        110,184,12,
        111,190,15,
    };
   nf = sizeof(fin)/(sizeof(int)*2 + sizeof(float));
   do{
   system("cls");
   printf(" \n\n\t\tSISTEMA DE NOTAS DE EXAMEN FINAL\n\n");
   printf("\t0. TERMINAR \n\n");
   printf("\t1. INGRESO DE DATOS\n");
   printf("\t2. MOSTRAR\n");
   printf("\t3. BUSCAR\n");
   printf("\t4. EDITAR\n");
   printf("\t5. INSERTAR\n");
   printf("\t6. ORDENAR POR CODIGO \n");
   printf("\t7. ORDENAR POR NOTA\n");
   printf("\t8. ELIMINAR\n");
   printf("\t\tARCHIVOS\n");
   printf("\t9. SALVAR\n");
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
   switch(opc){
      case 0:

         system("cls");
         printf("Salio del programa\n");
         break;

      case 1://LEER
         leerVectorFinal(fin,&nf);
         break;
      case 2://MOSTRAR
         mostrarVectorFinal(fin,nf);
         break;
      case 3://BUSCAR
         menu2(fin,&nf,opc);
         break;
      case 4://EDITAR
         editarFinal(fin, nf);
         break;
      case 5://INSERTAR
         menu2(fin,&nf,opc);
         break;
      case 6://ORDENARXCOD
         ordenarcodigoAluFinal(fin,nf);
         break;
      case 7://ORDENARXNOTA
         ordenarnotaFinal(fin,nf);
         break;

      case 8://ELIMINAR
         menu2(fin,&nf,opc);
         break;
      case 9:
         system("cls");
         fileSalvarFinal(FFIN,fin,nf);
         break;
      case 10:
         system("cls");
         fileRecuperarFinal(FFIN);
         break;
         default:
         printf("Opcion invalida....!\n");
      case 11:
         fileBuscarFinal(FFIN);
         break;
      case 12:
         fileFiltrarFinal(FFIN);
         break;
      case 13:
         fileEliminarFinal(FFIN);
         break;
      case 14:
         fileEditarFinal(FFIN);
         break;
      case 15:
         fileCopiarFinal(FFIN);
         break;
      case 16:
         fileOrdenarFinal(FFIN);
         break;
    }
   system("pause");
    }while(opc!=0);

}
void menu2(EXFINAL fin[MAX],int *dx,int mod){
   int opc;
   system("cls");
   if(mod==3){
      printf("\tBUSCAR EXAMEN FINAL\n");
   }else if(mod==5){
      printf("\tINSERTAR EXAMEN FINAL\n");
   }else{
      printf("\tELIMINAR EXAMEN FINAL");
   }

   printf("0. TERMINAR\n\n");

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
         buscarFinalporCodigoAlumno(fin,*dx);
      }else if(mod==5){
         insertarFinalporPosicion(fin,dx);
      }else{
         eliminaFinalporPosicion(fin,dx);
      }
      break;

   case 2:
      if(mod==3){
         buscarFinalporCodigoCurso(fin,*dx);
      }else if(mod==5){
         insertarFinalporValor(fin,dx);
      }else{
         eliminarFinalporValor(fin,dx);
      }
      break;
   }
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
      encabezado(titulo);
      for(i=0;i<dx-contblanco;i++){
         printf("%3d\t%-12d%-10.1f\n",i+1,fin[i].codAlu,fin[i].exfin);

      }
      printf("\n");
      system("pause");

   }else{
      printf("\nRegistro de alumnos vaciooo...\n\n");
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
int buscarFinalxCodCurso(EXFINAL fin[MAX],int dx,int cod){
   int pos = 0,i;

   for(i=0;i<dx;i++){
      if(fin[i].codCur==cod){
         pos = i;
      }
   }

   return pos+1;
}

void buscarFinalporCodigoCurso(EXFINAL fin[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE EXAMENES FINALES";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(fin[i].codCur==cd){
         encabezado(titulo);
         printf("%3d\t%-12d%-10.1f\n",i+1,fin[i].codCur,fin[i].exfin);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}

int buscarFinalxCodAlu(EXFINAL fin[MAX],int dx,int cod){
   int pos = -1,i;

   for(i=0;i<dx;i++){
      if(fin[i].codAlu==cod){
         pos = i;
      }
   }

   return pos+1;
}
void buscarFinalporCodigoAlumno(EXFINAL fin[MAX], int dx){
   int cd,i,comp=0;//comp es un valor bandera
   char titulo[]="\n\nREPORTE DE EXAMENES FINALES";
   printf("\n\nCODIGO : ");
   scanf("%i",&cd);
   cout <<"\n\n";
   for(i=0;i<dx;i++){
      if(fin[i].codAlu==cd){
         encabezado(titulo);
         printf("%3d\t%-12d%-10.1f\n",i+1,fin[i].codAlu,fin[i].exfin);
         comp=1;
      }
   }
   cout <<"\n\n";
   if(comp==0){
      printf("No se encontraron cursos con el codigo ingresado %d\n",cd);
   }
   system("pause");
}
void editarFinal(EXFINAL fin[MAX], int dx){
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
void insertarFinalporPosicion(EXFINAL fin[MAX],int *dx){
   int i,n;
   int posi,cod;
   mostrarVectorFinal(fin,*dx);

   n = *dx;
   n = n + 1;
   i = *dx;
   printf("\n\nPOSICION: ");    scanf("%i",&posi);

   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx+1){
         *dx=n;
         while(i>posi-1){
               fin[i] = fin[i-1];
               i--;
            }
         printf("\n**Registro de EXAMENES FINALES: \n");
         printf("\n\tAlumno:  %d\n", posi);

         cout <<" Codigo ---> ";
         cin >>cod;

         fin[i].codAlu=cod;
         cout <<" Codigo de Curso ---> ";
         cin>>fin[i].codCur;
         cout <<" Nota ---> ";
         cin >>fin[i].exfin;
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

void insertarFinalporValor(EXFINAL fin[MAX],int *dx){
   int posi,i,j,n;
   int codigo;
   n=*dx;
   posi = 1;
   mostrarVectorFinal(fin,*dx);
   if(n<MAX){
      printf("\n\nCODIGO DE ALUMNO: ");
      scanf("%i",&codigo);

      for(i=0;i<*dx;i++){
         if(codigo>fin[i].codAlu){
               posi+=1;
         }
      }

      printf("\n\nA continuacion ingrese los datos del examen final...\n");

      printf("\n**Registro de EXAMEN FINAL: \n");
      printf("\n\tAlumno:  %d\n", posi);

      fin[posi-1].codAlu=codigo;
      cout <<" Codigo de Curso ---> ";
      cin>>fin[i].codCur;
      cout <<" Nota ---> ";
      cin >>fin[i].exfin;
      cout<<endl;

      printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      *dx+=1;
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
}

void eliminaFinalporPosicion(EXFINAL fin[MAX],int *dx){
   int i,n,posi;
   mostrarVectorFinal(fin,*dx);
   printf("\n\nPOSICION: ");
   scanf("%i",&posi);
   n=*dx;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dx){
      *dx=n;
      while(i<n){
         fin[i] = fin[i+1];
         i = i+1;
      }
      printf("\nDatos del Examen Final de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
}

void eliminarFinalporValor(EXFINAL fin[MAX],int *dx){
   int n,i,j,pos;
   bool band;
   EXFINAL a;
   n = *dx;
   band=false;

   system("cls");
   printf("\n\tDigite el Codigo del Alumno a elimnar para eliminar su examen final:\n");
   cout <<" Codigo ---> ";
   cin>>a.codAlu;
   cout<<endl;

   if(*dx>0){
      for(i=0;i<n;i++){
         if(a.codAlu==fin[i].codAlu){
            pos = i;
            band = true;
         }
      }
      if(band){
         for(j=pos;j<n;j++){
            fin[j]=fin[j+1];
         }
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorFinal(fin,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}
void ordenarcodigoAluFinal(EXFINAL fin[MAX],int dx){
   int i,j,min;
   EXFINAL aux;
   if(dx>-1){
      for(i=0;i<dx;i++){
         min = i;
         for(j=i+1;j<dx;j++){
            if(fin[j].codAlu < fin[min].codAlu){
               min = j;
            }
         }
         aux = fin[i];
         fin[i] = fin[min];
         fin[min] = aux;
      }

      mostrarVectorFinal(fin,dx);
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarnotaFinal(EXFINAL fin[MAX],int dx){
   int i,j,min;
   EXFINAL aux;
   if(dx>-1){
      for(i=0;i<dx;i++){
         min = i;
         for(j=i+1;j<dx;j++){
            if(fin[j].exfin < fin[min].exfin){
               min = j;
            }
         }
         aux = fin[i];
         fin[i] = fin[min];
         fin[min] = aux;
      }

      mostrarVectorFinal(fin,dx);
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}

void fileSalvarFinal(FILE *F,EXFINAL fin[MAX],int dx){
    int i=0;
    F = fopen("Final.dat","w");
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
    system("pause");
}
void fileRecuperarFinal(FILE *F){
    int i=0;
    EXFINAL f ;
    F = fopen("Final.dat","r");
    char titulo[]="\n\nREPORTE DE EXAMENES FINALES";

    if(F==NULL){
        printf("Ha ocurrido un error...!\n");

        exit(0);
    }

    encabezado(titulo);
    fread(&f,sizeof(EXFINAL),1,F);
    while(!feof(F)){
      printf("%3d\t%-12d%-10.1f\n",i+1,f.codAlu,f.exfin);
      fread(&f,sizeof(EXFINAL),1,F);
      i++;
    }

    fclose(F);
    system("pause");
}

void fileBuscarFinal(FILE *F){
   F = fopen("Final.dat","a+");
   char titulo[]="\n\nREPORTE DE EXAMENES FINALES";
   EXFINAL f ;
   int Codigo, i=0;
   // Digita el codigo del alumno
   printf("Ingrese codigo de alumno ---> ");
   scanf("%d",&Codigo);
   // aqui siempre debe empezar el ciclo de lectura
   // y fread() regresa siempre cuantas estructuras leyo

   encabezado(titulo);
   fread(&f,sizeof(f),1,F);
   while(!feof(F))
   { // desplegando Registro Buscado
      if(f.codAlu == Codigo)
      {
         printf("%3d\t%-12d%-10.1f\n",i+1,f.codAlu,f.exfin);
      }
      fread(&f, sizeof(f), 1, F);
   }; // aqui termina while
   // no olvidar cerrar archivo y siempre fuera de while
   raya1();
   fclose(F);
}
void fileFiltrarFinal(FILE *F){
   F = fopen("Final.dat","a+");
   char titulo[]="\n\nREPORTE DE EXAMENES FINALES";
   EXFINAL f;
    int Hallado=0, Codigo, i=0;
    // Digitando codigo
    printf("Codigo >= que ---> ");
    scanf("%d",&Codigo);
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    encabezado(titulo);
    fread(&f,sizeof(f),1,F);
    while(!feof(F))
    {
        if(f.codAlu >= Codigo)
        {
           //Muestra Registro cuando se cumpla la condicion
            printf("%3d\t%-12d%-10.1f\n",i+1,f.codAlu,f.exfin);
            Hallado = 1;
            i++;
        }
        fread(&f, sizeof(f), 1, F);
    }; // aqui termina while
    raya1();
    if(Hallado == 0)
    {
    printf("Ninguno cumple con esa Condicion\n\n");
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(F);
}
void fileEliminarFinal(FILE *FF){
    FF = fopen("Final.dat","a+");
    FILE *HH;
    EXFINAL f;
    int Hallado=0, Codigo, remo, rena;
    printf("Codigo de alumno a Eliminar ---> ");
    //scanf("%d",&Codigo);getchar();
    cin>>Codigo;
    //abriendo, leyendo,cargando estructura
    HH = fopen("Temporal.dat","a+");
    if (HH == NULL){
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    fread(&f, sizeof(f), 1, FF);
    while(!feof(FF)){ // Registro Buscado
        if(Codigo != f.codAlu){
            fwrite(&f, sizeof(f), 1, HH);
        }
        if(Codigo == f.codAlu){
            Hallado = 1;
        }
        fread(&f, sizeof(f), 1, FF);
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    remo=remove("Final.dat"); // Elimina
    printf("remove = %d\n", remo);
    rena=rename("Temporal.dat", "Final.dat"); //renombre
    printf("rename = %d\n", rena);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO ...\n\n");
    }
    else{
        printf("Registro eliminado\n\n");
    }
}
void fileEditarFinal(FILE *FF)
{
    FF = fopen("Final.dat","a+");
    FILE *HH;
    EXFINAL f;
    int Hallado=0, Codigo, Rem, Ren;
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
    fread(&f, sizeof(f), 1, FF);
    while(!feof(FF))
    { // Registro Buscado
        if(f.codAlu == Codigo)
        {
            int aux=0;
            char desea='n';
            EXFINAL g;
            Hallado=1;
            g=f;
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
                        scanf("%d",&g.codAlu);
                        break;
                    case 2:
                        fflush(stdin);
                        printf("Nueva Nota ---> ");
                        scanf("%d",&g.exfin);
                        break;
                    default:
                        printf("Opcion incorrecta!\n");
                }

            }
            if(desea=='S' || desea=='s'){
                fwrite(&g,sizeof(g),1,HH);
            }
            else{
                fwrite(&f, sizeof(f), 1, HH);
            }

        }
        else
        {
            fwrite(&f, sizeof(f), 1, HH);
        }
        fread(&f, sizeof(f), 1, FF);
    };
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    //Removiendo y eliminando
    Rem=remove("Final.dat");
    printf("remove %d", Rem);
    Ren=rename("Temporal.dat","Final.dat ");
    printf("rename %d", Ren);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO...\n\n");
    }
    else{
        printf("Registro Actualizado");
    }
}
void fileCopiarFinal(FILE *F){
    F = fopen("Final.dat","a+");
    FILE *H;
    EXFINAL f;
    H = fopen("CopiaFinal.dat","a+");

    fread(&f,sizeof(f),1,F);

    while(!feof(F)){
        fwrite(&f,sizeof(f),1,H);
        fread(&f,sizeof(f),1,F);
    }
    fclose(H);
    fclose(F);
}
void fileOrdenarFinal(FILE *F){
    F = fopen("Final.dat","a+");
    EXFINAL f[MAX];
    EXFINAL t;
    FILE *H;
    H=fopen("Temporal.dat","a+");
    int i=0,aux=0,j=0,n;

    fread(&f[i],sizeof(EXFINAL),1,F);
    i++;
    while(!feof(F)){
        fread(&f[i],sizeof(EXFINAL),1,F);
        i++;
    }
    n=i-1;
    fclose(F);

    for(i=0;i<n-1;i++){
         aux=i;
         for(j=i+1;j<n;j++){
            if(f[aux].codAlu>f[j].codAlu){
               aux=j;
            }
         }
         //Intercambiando
         t=f[i];
         f[i]=f[aux];
         f[aux]=t;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
        fwrite(&f[i],sizeof(EXFINAL),1,H);
    }
    //Cierra el archivo
    fclose(H);

    int rem=remove("Final.dat");
    printf("rem=%d\n",rem);
    int ren=rename("Temporal.dat","Final.dat");
    printf("ren=%d\n",ren);

}

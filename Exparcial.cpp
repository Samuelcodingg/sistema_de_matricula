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
//OPERACIONES BASICAS
void crearVectorParcial(int *dx);
void leerVectorParcial(EXPARCIAL par[MAX],int *dx);
void mostrarVectorParcial(EXPARCIAL par[MAX],int dx);
int buscarParcialxCodCurso(EXPARCIAL par[MAX],int dx,int cod);
void buscarParcialporCodigoCurso(EXPARCIAL par[MAX], int dx);
int buscarParcialxCodAlu(EXPARCIAL par[MAX],int dx,int cod);
void buscarParcialporCodigoAlumno(EXPARCIAL par[MAX], int dx);
void editarParcial(EXPARCIAL par[MAX],int dx);
void insertarParcialporPosicion(EXPARCIAL par[MAX],int *dx);
void insertarParcialporValor(EXPARCIAL par[MAX],int *dx);
void eliminaParcialporPosicion(EXPARCIAL par[MAX],int *dx);
void eliminarParcialporValor(EXPARCIAL par[MAX],int *dx);
void ordenarcodigoAluParcial(EXPARCIAL par[MAX],int dx);
void ordenarnotaParcial(EXPARCIAL par[MAX],int dx);

//ARCHIVOS
//Escribir
void fileSalvarParcial(FILE *F,EXPARCIAL par[MAX],int dx);
//Leer
void fileRecuperarParcial(FILE *F);
//Buscar
void fileBuscarParcial(FILE *F);
//Filtrar
void fileFiltrarParcial(FILE *F);
//Eliminar
void fileEliminarParcial(FILE *F);
//Editar
void fileEditarParcial(FILE *FF);
//Copiar
void fileCopiarParcial(FILE *F);
//Ordenar
void fileOrdenarParcial(FILE *F);

//MENU
void menu();
void menu2(EXPARCIAL par[MAX],int *dx,int mod);
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
        108,202,17,
        109,188,12,
        110,190,13,
        111,200,15,
    };
   np = sizeof(par)/(sizeof(int)*2 + sizeof(float));

   do{
   system("cls");
   printf(" \n\n\t\tSISTEMA DE NOTAS DE EXAMEN PARCIAL\n\n");
   printf("\t0. TERMINAR \n\n");
   printf("\t1. INGRESO DE DATOS\n");
   printf("\t2. MOSTRAR\n");
   printf("\t3. BUSCAR\n");
   printf("\t4. EDITAR\n");
   printf("\t5. INSERTAR\n");
   printf("\t6. ORDENAR POR CODIGO \n");
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
   switch(opc){
      case 0:
         system("cls");
         printf("Salio del programa\n");
         break;
      case 1://LEER
         system("cls");
         leerVectorParcial(par,&np);
         break;
      case 2://MOSTRAR
         mostrarVectorParcial(par,np);
         break;
      case 3://BUSCAR
         menu2(par,&np,opc);
         break;
      case 4://EDITAR
         editarParcial(par, np);
         break;
      case 5://INSERTAR
         menu2(par,&np,opc);
         break;
      case 6://ORDENARXCOD
         ordenarcodigoAluParcial(par,np);
         break;
      case 7://ORDENARXNOTA
         ordenarnotaParcial(par,np);
         break;
      case 8://ELIMINAR
         menu2(par,&np,opc);
         break;
      case 9:
         system("cls");
         fileSalvarParcial(FP,par,np);
         break;
      case 10:
         system("cls");
         fileRecuperarParcial(FP);
         break;
         default:
         printf("Opcion invalida....!\n");
      case 11:
         fileBuscarParcial(FP);
         break;
      case 12:
         fileFiltrarParcial(FP);
         break;
      case 13:
         fileEliminarParcial(FP);
         break;
      case 14:
         fileEditarParcial(FP);
         break;
      case 15:
         fileCopiarParcial(FP);
         break;
      case 16:
         fileOrdenarParcial(FP);
         break;

    }

    }while(opc!=0);
}
void menu2(EXPARCIAL par[MAX],int *dx,int mod){
   int opc;
   system("cls");
   if(mod==3){
      printf("\tBUSCAR EXAMEN PARCIAL\n");
   }else if(mod==5){
      printf("\tINSERTAR EXAMEN PARCIAL\n");
   }else{
      printf("\tELIMINAR EXAMEN PARCIAL");
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
         buscarParcialporCodigoAlumno(par,*dx);
      }else if(mod==5){
         insertarParcialporPosicion(par,dx);
      }else{
         eliminaParcialporPosicion(par,dx);
      }
      break;

   case 2:
      if(mod==3){
         buscarParcialporCodigoCurso(par,*dx);
      }else if(mod==5){
         insertarParcialporValor(par,dx);
      }else{
         eliminarParcialporValor(par,dx);
      }
      break;
   }
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
void insertarParcialporPosicion(EXPARCIAL par[MAX],int *dx){
   int i,n;
   int posi,cod;
   mostrarVectorParcial(par,*dx);

   n = *dx;
   n = n + 1;
   i = *dx;
   printf("\n\nPOSICION: ");    scanf("%i",&posi);

   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx+1){
         *dx=n;
         while(i>posi-1){
               par[i] = par[i-1];
               i--;
            }
         printf("\n**Registro de EXAMENES PARCIALES: \n");
         printf("\n\tAlumno:  %d\n", posi);

         cout <<" Codigo ---> ";
         cin >>cod;

         par[i].codAlu=cod;
         cout <<" Codigo de Curso ---> ";
         cin>>par[i].codCur;
         cout <<" Nota ---> ";
         cin >>par[i].expar;
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

void insertarParcialporValor(EXPARCIAL par[MAX],int *dx){
   int posi,i,j,n;
   int codigo;
   n=*dx;
   posi = 1;
   mostrarVectorParcial(par,*dx);
   if(n<MAX){
      printf("\n\nCODIGO DE ALUMNO: ");
      scanf("%i",&codigo);

      for(i=0;i<*dx;i++){
         if(codigo>par[i].codAlu){
               posi+=1;
         }
      }

      printf("\n\nA continuacion ingrese los datos del examen parcial...\n");

      printf("\n**Registro de EXAMEN PARCIAL: \n");
      printf("\n\tAlumno:  %d\n", posi);

      par[posi-1].codAlu=codigo;
      cout <<" Codigo de Curso ---> ";
      cin>>par[i].codCur;
      cout <<" Nota ---> ";
      cin >>par[i].expar;
      cout<<endl;

      printf("\nDatos INSERTADOS en posicion %d \n\n ",posi);
      *dx+=1;
   }
   else{
      printf("Dimension fuera de rango ...\n");
   }
}

void eliminaParcialporPosicion(EXPARCIAL par[MAX],int *dx){
   int i,n,posi;
   mostrarVectorParcial(par,*dx);
   printf("\n\nPOSICION: ");
   scanf("%i",&posi);
   n=*dx;
   n=n-1;
   i=posi-1;
   if(posi-1>-1 && posi-1<*dx){
      *dx=n;
      while(i<n){
         par[i] = par[i+1];
         i = i+1;
      }
      printf("\nDatos del Examen Final de la posicion %d ELIMINADOS\n\n ",posi);
   }
   else{
      printf("La posicion %d no existe en el vector...\n", posi);
   }
}

void eliminarParcialporValor(EXPARCIAL par[MAX],int *dx){
   int n,i,j,pos;
   bool band;
   EXPARCIAL a;
   n = *dx;
   band=false;

   system("cls");
   printf("\n\tDigite el Codigo del Alumno a elimnar para eliminar su examen final:\n");
   cout <<" Codigo ---> ";
   cin>>a.codAlu;
   cout<<endl;

   if(*dx>0){
      for(i=0;i<n;i++){
         if(a.codAlu==par[i].codAlu){
            pos = i;
            band = true;
         }
      }
      if(band){
         for(j=pos;j<n;j++){
            par[j]=par[j+1];
         }
         printf("Dato eliminado...!\n");
         *dx=n-1;
         //muestra resultados
         mostrarVectorParcial(par,*dx);
      }
      else{
         printf("No existe ese dato...!\n");
      }
   }
   else{
      printf("Vacio...!\n");
   }
}
void ordenarcodigoAluParcial(EXPARCIAL par[MAX],int dx){
   int i,j,min;
   EXPARCIAL aux;
   if(dx>-1){
      for(i=0;i<dx;i++){
         min = i;
         for(j=i+1;j<dx;j++){
            if(par[j].codAlu < par[min].codAlu){
               min = j;
            }
         }
         aux = par[i];
         par[i] = par[min];
         par[min] = aux;
      }

      mostrarVectorParcial(par,dx);
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarnotaParcial(EXPARCIAL par[MAX],int dx){
   int i,j,min;
   EXPARCIAL aux;
   if(dx>-1){
      for(i=0;i<dx;i++){
         min = i;
         for(j=i+1;j<dx;j++){
            if(par[j].expar < par[min].expar){
               min = j;
            }
         }
         aux = par[i];
         par[i] = par[min];
         par[min] = aux;
      }

      mostrarVectorParcial(par,dx);
   }
   else{
      printf("Vector vacioooo...!\n");
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
    F = fopen("Parcial.dat","r");
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
void fileBuscarParcial(FILE *F){
   F = fopen("Parcial.dat","a+");
   char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";
   EXPARCIAL p ;
   int Codigo, i=0;
   // Digita el codigo del alumno
   printf("Ingrese codigo de alumno ---> ");
   scanf("%d",&Codigo);
   // aqui siempre debe empezar el ciclo de lectura
   // y fread() regresa siempre cuantas estructuras leyo

   encabezado(titulo);
   fread(&p,sizeof(p),1,F);
   while(!feof(F))
   { // desplegando Registro Buscado
      if(p.codAlu == Codigo)
      {
         printf("%3d\t%-12d%-10.1f\n",i+1,p.codAlu,p.expar);
      }
      fread(&p, sizeof(p), 1, F);
   }; // aqui termina while
   // no olvidar cerrar archivo y siempre fuera de while
   raya1();
   fclose(F);
}
void fileFiltrarParcial(FILE *F){
   F = fopen("Parcial.dat","a+");
   char titulo[]="\n\nREPORTE DE EXAMENES PARCIALES";
   EXPARCIAL p;
    int Hallado=0, Codigo, i=0;
    // Digitando codigo
    printf("Codigo >= que ---> ");
    scanf("%d",&Codigo);
    // aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    encabezado(titulo);
    fread(&p,sizeof(p),1,F);
    while(!feof(F))
    {
        if(p.codAlu >= Codigo)
        {
           //Muestra Registro cuando se cumpla la condicion
            printf("%3d\t%-12d%-10.1f\n",i+1,p.codAlu,p.expar);
            Hallado = 1;
            i++;
        }
        fread(&p, sizeof(p), 1, F);
    }; // aqui termina while
    raya1();
    if(Hallado == 0)
    {
    printf("Ninguno cumple con esa Condicion\n\n");
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(F);
}
void fileEliminarParcial(FILE *FF){
    FF = fopen("Parcial.dat","a+");
    FILE *HH;
    EXPARCIAL p;
    int Hallado=0, Codigo, remo, rena;
    printf("Codigo de alumno a Eliminar ---> ");
    //scanf("%d",&Codigo);getchar();
    cin>>Codigo;
    //abriendo, leyendo,cargando estructura
    HH = fopen("Temporal.dat","w");
    if (HH == NULL){
        printf("No se puede abrir el archivo\n");
        exit(1);
    }
    fread(&p, sizeof(p), 1, FF);
    while(!feof(FF)){ // Registro Buscado
        if(Codigo != p.codAlu){
            fwrite(&p, sizeof(p), 1, HH);
        }
        if(Codigo == p.codAlu){
            Hallado = 1;
        }
        fread(&p, sizeof(p), 1, FF);
    }
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    remo=remove("Parcial.dat"); // Elimina
    printf("remove = %d\n", remo);
    rena=rename("Temporal.dat", "Parcial.dat"); //renombre
    printf("rename = %d\n", rena);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO ...\n\n");
    }
    else{
        printf("Registro eliminado\n\n");
    }
}
void fileEditarParcial(FILE *FF)
{
    FF = fopen("Parcial.dat","a+");
    FILE *HH;
    EXPARCIAL p;
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
    fread(&p, sizeof(p), 1, FF);
    while(!feof(FF))
    { // Registro Buscado
        if(p.codAlu == Codigo)
        {
            int aux=0;
            char desea='n';
            EXPARCIAL q;
            Hallado=1;
            q=p;
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
                        scanf("%d",&q.codAlu);
                        break;
                    case 2:
                        fflush(stdin);
                        printf("Nueva Nota ---> ");
                        scanf("%d",&q.expar);
                        break;
                    default:
                        printf("Opcion incorrecta!\n");
                }

            }
            if(desea=='S' || desea=='s'){
                fwrite(&q,sizeof(q),1,HH);
            }
            else{
                fwrite(&p, sizeof(p), 1, HH);
            }

        }
        else
        {
            fwrite(&p, sizeof(p), 1, HH);
        }
        fread(&p, sizeof(p), 1, FF);
    };
    // no olvidar cerrar archivo y siempre fuera de while
    fclose(FF);
    fclose(HH);
    //Removiendo y eliminando
    Rem=remove("Parcial.dat");
    printf("remove %d", Rem);
    Ren=rename("Temporal.dat","Parcial.dat ");
    printf("rename %d", Ren);
    //avisando
    if(Hallado == 0){
        printf("No existe ese CODIGO...\n\n");
    }
    else{
        printf("Registro Actualizado");
    }
}
void fileCopiarParcial(FILE *F){
    F = fopen("Parcial.dat","a+");
    FILE *H;
    EXPARCIAL p;
    H = fopen("CopiaParcial.dat","a+");

    fread(&p,sizeof(p),1,F);

    while(!feof(F)){
        fwrite(&p,sizeof(p),1,H);
        fread(&p,sizeof(p),1,F);
    }
    fclose(H);
    fclose(F);
}
void fileOrdenarParcial(FILE *F){
    F = fopen("Final.dat","a+");
    EXPARCIAL p[MAX];
    EXPARCIAL t;
    FILE *H;
    H=fopen("Temporal.dat","a+");
    int i=0,aux=0,j=0,n;

    fread(&p[i],sizeof(EXPARCIAL),1,F);
    i++;
    while(!feof(F)){
        fread(&p[i],sizeof(EXPARCIAL),1,F);
        i++;
    }
    n=i-1;
    fclose(F);

    for(i=0;i<n-1;i++){
         aux=i;
         for(j=i+1;j<n;j++){
            if(p[aux].codAlu>p[j].codAlu){
               aux=j;
            }
         }
         //Intercambiando
         t=p[i];
         p[i]=p[aux];
         p[aux]=t;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++){
        fwrite(&p[i],sizeof(EXPARCIAL),1,H);
    }
    //Cierra el archivo
    fclose(H);

    int rem=remove("Parcial.dat");
    printf("rem=%d\n",rem);
    int ren=rename("Temporal.dat","Parcial.dat");
    printf("ren=%d\n",ren);

}

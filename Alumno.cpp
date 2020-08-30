/*
 * NombreProg : Alumnos.cpp
 * Descripcion:  Registro de vector Alumnos 
*                con operaciones basicas             
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

void buscarAluporCodigo(ALUMNO x[MAX],int dx);
void buscaAluporNom(ALUMNO x[MAX],int dx);

void editarporCodigoAlu(ALUMNO x[MAX], int dx);

void insertarporPosicion(ALUMNO x[MAX],int *dx);
void insertarporValor(ALUMNO x[MAX],int *dx);

void eliminaAluporPosicion(ALUMNO x[MAX],int *dx);
void eliminarxValorAlu(ALUMNO x[MAX],int *dx);

void ordenarporCodigo(ALUMNO x[MAX],int dx);
void ordenarporNombre(ALUMNO x[MAX],int dx);

//MENU
void menu(ALUMNO x[MAX],int *dx,int &opc);
void menu2(ALUMNO x[MAX],int *dx,int mod,int aux);
void encabezado1();
void raya1();
void raya2();



int main(){
    ALUMNO A[MAX]={
        100,"Jorge","edu",{1,1,1},12,
        102,"Eva","fis",{1,1,1},18,
        104,"Luis","med",{1,1,1},5,
        108,"Alina","let",{1,1,1},16,
        109,"Karenina","ing",{1,1,1},17,
    };
    int nA,opc;
    crearVectorAlu(A,&nA);
    nA = 5;

    do{
        menu(A,&nA,opc);
    }while(opc!=0);
    system("pause");
    return 0;
}

void crearVectorAlu(ALUMNO x[MAX],int *dx){
    *dx=-1;
}

void leerVectorAlu(ALUMNO x[MAX], int *dx){
    int i=0, n, val;
    system("cls");
    printf("****Llenando Registro de Alumnos****\n");
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
   }
}

void mostrarVectorAlu(ALUMNO x[MAX], int dx){
    int i;
    if(dx>0){
    encabezado1();
        for(i=0;i<dx;i++){
            printf("%3d\t%-12d%-32s%-18s%-d/%-d/%-18d%-.1fkg\n",i+1,x[i].codAlu,x[i].nomAlu,x[i].escuela,x[i].fnac.dia,x[i].fnac.mes,x[i].fnac.anio,x[i].peso);
        }
    raya1();
    cout <<"\n\n";
    }
    else{
        printf("Vector vaciooo...\n\n");
    }
}

void buscarAluporCodigo(ALUMNO x[MAX],int dx){
    int cd,i,comp=0;//comp es un valor bandera
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
    }
    if(comp==0){
        printf("No se encontro alumnos con el codigo ingresado %d\n",cd);
    }
}

void buscaAluporNom(ALUMNO x[MAX],int dx){
    int i=0;
    char band = false;
    char buscar[40];
    printf("\n\nIngrese el nombre del alumno a buscar: ");  //Se corta y no imprime el resto
    fflush(stdin);
    cin.getline(buscar,40,'\n');
    while(!band && i<dx){
        if(strcmp(x[i].nomAlu,buscar)==0){ //Compara cadenas retorna 0 si son iguales
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

void insertarporPosicion(ALUMNO x[MAX],int *dx){
   int i,j,n,suma=0,comp=0;//comp es un valor bandera
   int posi,cod;

   mostrarVectorAlu(x,*dx);
   
   n = *dx;
   n = n + 1;
   i = *dx;
   
    printf("\n\nIngrese la posicion del alumno en el registro ALUMNOS,cuyos datos desea insertar en todos los registros: ");
    scanf("%i",&posi);
   
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

void insertarporValor(ALUMNO x[MAX],int *dx){
   int posi,i,j,n,suma=0;
   int codigo;
   n=*dx;
   posi = 1;
   mostrarVectorAlu(x,*dx);
    if(n<MAX){
        printf("\n\nIngrese el codigo del alumno cuyos datos desea insertar en todos los registros: ");
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
   printf("\n\nIngrese la posicion del alumno en el registro ALUMNOS,cuyos datos desea eliminar de todos los registros: ");
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

void eliminarxValorAlu(ALUMNO x[MAX],int *dx){
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

void ordenarporCodigo(ALUMNO x[MAX],int dx){
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

void ordenarporNombre(ALUMNO x[MAX],int dx){
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
   printf("--------------------------------------------------------------------");
   printf("-----------------------------------------\n");
}

void raya2()
{
   printf("====================================================================");
   printf("=========================================\n");
}

void menu(ALUMNO x[MAX],int *dx,int &opc){
    int aux=0;
    system("cls");
    printf(" \n\nREGISTRO DE ALUMNOS\n\n");
    printf("0. TERMINAR \n\n");
    printf("1. Ingreso de datos\n");
    printf("2. Mostrar Alumnos\n");
    printf("3. Buscar Alumno\n");
    printf("4. Ordenar Registro de Alumnos\n");
    printf("5. Editar Alumno por codigo\n");
    printf("6. Insertar Alumno\n");
    printf("7. Eliminar Alumno\n");
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
            menu2(x,dx,opc,aux);
            break;
        case 4://ORDENAR
            menu2(x,dx,opc,aux); 
            break;
        case 5://EDITAR
            editarporCodigoAlu(x,*dx);
            break;
        case 6://INSERTAR
            menu2(x,dx,opc,aux);
            break;
        case 7://ELIMINAR
            menu2(x,dx,opc,aux);
            break;
    }
}

void menu2(ALUMNO x[MAX],int *dx,int mod,int aux){
    ALUMNO dato;
    int opc,ndato,pos;
    
    system("cls");
    if(mod==3){
        printf("BUSCAR ALUMNO\n");
    }else if(mod==4){
        printf("ORDENAR REGISTRO ALUMNO\n");
    }else if(mod==6){
        printf("INSERTAR ALUMNO\n");
    }else{
        printf("ELIMINAR ALUMNO");
    }
    
    printf("0. TERMINAR\n\n");
    
    if(mod==3 || mod==4){
        printf("1. Por Codigo\n");
        printf("2. Por Nombre\n");
    }else{
        printf("1. Por Posicion\n");
        printf("2. Por Valor\n");
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
            ordenarporCodigo(x,*dx);
            printf("\nLos codigos de los registros han sido ordenados de forma ascendente...\n\n");
            cout<<endl;
        }else if(mod==6){
            insertarporPosicion(x,dx);
        }else{
            eliminaAluporPosicion(x,dx);
        }

        system("pause");
        break;
    
    case 2:
        if(mod==3){
            buscaAluporNom(x,*dx);
        }else if(mod==4){
            ordenarporNombre(x,*dx);
            printf("\nLos nombres de los registros han sido ordenados de forma ascendente...\n\n");
            cout<<endl;
        }else if(mod==6){
            insertarporValor(x,dx);
        }else{
            eliminarxValorAlu(x,dx);
        }
        system("pause");
        break;
    }   
}


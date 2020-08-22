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

using namespace std;

struct FECHA{
    int dia;
    int mes;
    int anio;
};
struct ALUMNO{
    int codAlu;
    char nomAlu[40];
    char escuela[40];
    FECHA fnac;
    float peso;
};
struct PRACTICA{
    int codAlu;
    int codCurso;
    int prac[10];
};
struct EXPARCIAL{
    int codAlu;
    int codCur;
    float expar;
};
struct EXFINAL{
    int codAlu;
    int codCur;
    float exFin;
};
struct CURSO{
   int codCur;
   char nomCur[40];
   char scal;
};
struct Docente{
   int codDoc;
   char nomDoc[40];
   CURSO c[10];
};

int main(){

  system("pause");
  return 0;
}

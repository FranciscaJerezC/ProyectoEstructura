#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "List.h"

struct Usuario{
    unsigned long long Presupuesto;
    char nombre;
    char nombreComunidad; //nombre[100]??
};

struct Comunidad{
    list* listaParamatros;
    int parametros;
};

struct Proyecto{
    char name;
    int puntos;
    int contSubpro;
    list* subProyectos;
};

struct subProyecto{
    char namesub;
    int aportePuntos;
    int costo;
    int aporteParametros;
};

struct tiempo{
    unsigned long long hora;
};


Usuario* crearUsuario(char *nombre,char *nombreComunidad){
    Usuario* usuario=(Usuario*)calloc(1,sizeof(Usuario));
    usuario->Presupuesto=500;
    strcpy(usuario->nombre,nombre);
    strcpy(usuario->nombreComunidad,nombreComunidad);
    return usuario;

}

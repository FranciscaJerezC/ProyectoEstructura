#ifndef Funciones_h
#define Funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "List.h"

typedef struct Usuario Usuario;
typedef struct Comunidad Comunidad;
typedef struct Proyecto Proyecto;
typedef struct subProyecto subProyecto;
typedef struct tiempo tiempo;

Usuario* crearUsuario(char *nombre,char *nombreComunidad);

#endif

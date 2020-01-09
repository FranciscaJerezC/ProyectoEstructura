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

int stringEqual(const void * key1, const void * key2);
long long stringHash(const void * key);

void numerosRandom(int minimo, int maximo);
void print_image(FILE *fptr);


void guardarUsuario(Usuario* usuario);
Usuario* UsuarioEntrada();


Usuario* crearUsuario(char *nombre,char *nombreComunidad, Map *mapaUsuarios);
void mostrarCancion(Map * mapaUsuarios);

#endif

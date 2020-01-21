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
const char *get_csv_field (char * tmp, int i);
char * _strdup (const char *s);

void numerosRandom();
int mostrarTiempoSegundos();
int mostrarTiempoMinutos();

void crearPartidaNueva();

void cargarDatosParametros(Map * mapaParametros,FILE * fp);
Comunidad * crearParametro(char * linea);

void cargarDatosProyectos(list *ListaProyectos,FILE *fb);
Proyecto * crearProyecto (char * linea);

void guardarUsuario(Usuario* usuario);
Usuario* UsuarioEntrada();

void buscarProyecto (char *proyecto, list *ListaProyectos, Map *mapaParametros);
void buscarParametro(char *parametroAfectado, char *puntos,Map *mapaParametros);

Usuario* crearUsuario(char *nombre,char *nombreComunidad, Map *mapaUsuarios);
void mostrarCancion(Map * mapaUsuarios);
void ImprimirPresupuesto (char *nombre, FILE *usuarios);


#endif

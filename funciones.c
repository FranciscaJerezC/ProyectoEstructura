#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Map.h"
#include "List.h"


struct Usuario{
    unsigned long long Presupuesto;
    char *nombre;
    char *nombreComunidad; //nombre[100]??
};

struct Comunidad{
    list* listaParamatros;
    unsigned long long parametros;
};

struct Proyecto{
    char name;
    unsigned long long costos;
    unsigned long long puntos;
    unsigned long long contSubpro;
    list* subProyectos;
};

struct subProyecto{
    char namesub;
    unsigned long long aportePuntos;
    unsigned long long costo;
    unsigned long long aporteParametros;
};

struct tiempo{
    unsigned long long hora;
};


Usuario* crearUsuario(char *nombre,char *nombreComunidad, Map *mapaUsuarios){
    Usuario* usuario=(Usuario*)calloc(1,sizeof(Usuario));
    usuario->nombre = (char*)calloc(100,sizeof(char));
    usuario->nombreComunidad = (char*)calloc(100,sizeof(char));
    usuario->Presupuesto = (char*)calloc(100,sizeof(char));

    usuario->Presupuesto=500;
    strcpy(usuario->nombre,nombre);
    strcpy(usuario->nombreComunidad,nombreComunidad);
    insertMap(mapaUsuarios,usuario->nombre,usuario);
    return usuario;

}

Usuario* UsuarioEntrada(){
    Usuario* usuario=(Usuario*)calloc(1,sizeof(Usuario));
    return usuario;
}

void guardarUsuario(Usuario* usuario){
    FILE* fp=fopen("Usuario.txt","w");
    fprintf(fp,"%s %s %llu",usuario->nombre,usuario->nombreComunidad,usuario->Presupuesto);
    fclose(fp);
}



void mostrarCancion(Map * mapaUsuarios){  //SOLO PARA VERIFICAR
        Usuario * user = (Usuario*)calloc(1,sizeof(Usuario));
        user = firstMap(mapaUsuarios);
        while (user != NULL)
        {
            printf("USUARIOS: %s %s %i\n",user->nombre,user->nombreComunidad,user->Presupuesto);
            getchar();
            user = nextMap(mapaUsuarios);
        }
        getchar();
        getchar();
}

void numerosRandom(int minimo, int maximo){
    int i;
    for (i = 0; i < 1; i++)
    {
        int num = (rand() % (maximo - minimo + 1)) + minimo;
        printf("%i ", num);
    }
}

long long stringHash(const void * key) {
    long long hash = 5381;

    const char * ptr;

    for (ptr = key; *ptr != '\0'; ptr++) {
        hash = ((hash << 5) + hash) + tolower(*ptr); /* hash * 33 + c */
    }

    return hash;
}

int stringEqual(const void * key1, const void * key2) {
    const char * A = key1;
    const char * B = key2;

    return strcmp(A, B) == 0;
}

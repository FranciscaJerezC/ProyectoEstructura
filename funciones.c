#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Map.h"
#include "List.h"


struct Usuario{
    int Presupuesto;
    char *nombre;
    char *nombreComunidad;
};

struct Comunidad{
    list* listaParametros;
    char *parametros;
    char* avance;
};

struct Proyecto{
    char * name;
    char *  puntos;
    char *parametroAfectado;
};


/*-----------------------------------------------------------------------------------------------------------*/

void ImprimirPresupuesto (char *nombre, FILE *usuarios){  //No utilizada
    char * linea = (char*)calloc(1024,sizeof(char));
    Usuario *user = (Usuario*)malloc(sizeof(Usuario));
    printf("\nLA LINEA: %s\n", linea);
    while (fgets(linea,1024,usuarios) != NULL)
    {
        linea = strtok(linea,"\r");
        linea = _strdup(linea);
        user->nombre =(char*)calloc(100,sizeof(char));

        strcpy(user->nombre,get_csv_field(linea,1));
        user->Presupuesto= get_csv_field(linea,3);
        printf("\nNOMBRE USER: %s y NOMBRE %s\n",user->nombre,nombre);
        if ( strcmp(user->nombre, nombre ) == 0)
        {
            printf("ENCONTRO PARAMETRO %s que es igual a %s",user->nombre,nombre);
            break;
        }
    }
    printf("\nPRESUPUESTO ACTUAL: %i\n", user->Presupuesto);
}

/*-----------------------------------------------------------------------------------------------------------*/

int mostrarTiempoSegundos(){ //No utilizada
    time_t s, val = 1;
    struct tm* current_time;
    int numeroRandom;
    s = time(NULL);

    current_time = localtime(&s);

    printf("HORA ACTUAL: %02d:%02d:%02d",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);

    return current_time->tm_sec;
}

/*-----------------------------------------------------------------------------------------------------------*/

int mostrarTiempoMinutos(){  //No utilizada
    time_t s, val = 1;
    struct tm* current_time;
    int numeroRandom;
    s = time(NULL);
    current_time = localtime(&s);

    return current_time->tm_min;
}

/*-----------------------------------------------------------------------------------------------------------*/

void buscarProyecto (char *proyecto, list *ListaProyectos, Map *mapaParametros){
    Proyecto *proyectoActual = (Proyecto*)malloc(sizeof(Proyecto));
    Comunidad * parametro = (Comunidad*)calloc(1,sizeof(Comunidad));
    parametro = firstMap(mapaParametros);

    proyectoActual = list_first(ListaProyectos);
    while (proyectoActual != NULL)
    {
        if ( strcmp(proyectoActual->name,proyecto ) == 0) //Si es que el nombre del proyecto actual y el nombre entregado son iguales entonces
        {
            break;
        }
        proyectoActual = list_next(ListaProyectos);
    }
    list_pop_current(ListaProyectos); //Se elimina de la lista ya que ya fue usado
    buscarParametro(proyectoActual->parametroAfectado,proyectoActual->puntos,mapaParametros); //Se llama a esta funcion para que el proyecto haga un cambio en el parametro
}

/*-----------------------------------------------------------------------------------------------------------*/

void buscarParametro(char *parametroAfectado, char *puntos,Map *mapaParametros){
    Comunidad * parametro = (Comunidad*)calloc(1,sizeof(Comunidad));
    parametro = firstMap(mapaParametros);
    while (parametro != NULL)
    {
        if ( strcmp(parametro->parametros, parametroAfectado ) == 0)
        {
            break;
        }
        parametro = nextMap(mapaParametros);
    }
    parametro->avance = puntos;
    return;

}

/*-----------------------------------------------------------------------------------------------------------*/

Usuario* crearUsuario(char *nombre,char *nombreComunidad, Map *mapaUsuarios){
    Usuario* usuario=(Usuario*)calloc(1,sizeof(Usuario));
    usuario->nombre = (char*)calloc(100,sizeof(char));
    usuario->nombreComunidad = (char*)calloc(100,sizeof(char));

    usuario->Presupuesto=500;
    strcpy(usuario->nombre,nombre);
    strcpy(usuario->nombreComunidad,nombreComunidad);
    insertMap(mapaUsuarios,usuario->nombre,usuario);

    guardarUsuario(usuario);
    return usuario;
}

/*-----------------------------------------------------------------------------------------------------------*/

void cargarDatosParametros(Map *mapaParametros,FILE * fp ){
    char * linea = (char*)calloc(1024,sizeof(char));
    while (fgets(linea,1024,fp) != NULL)
    {
        linea = strtok(linea,"\r");
        linea = _strdup(linea);

        Comunidad * nuevoParametro = crearParametro(linea);
        if (searchMap(mapaParametros,nuevoParametro->parametros) == NULL)
        {
             insertMap(mapaParametros, nuevoParametro->parametros, nuevoParametro); //Se inserta el parametro en el mapa parametros
        }
        linea = (char*)calloc(1024,sizeof(char));
    }
}

/*-----------------------------------------------------------------------------------------------------------*/

void cargarDatosProyectos(list *ListaProyectos,FILE *fb){
    char * linea = (char*)calloc(1024,sizeof(char));
    while (fgets(linea,1024,fb) != NULL)
    {
        linea = strtok(linea,"\r");
        linea = _strdup(linea);
        Proyecto * nuevoProyecto = crearProyecto(linea);

        list_push_back(ListaProyectos,nuevoProyecto); //Se inserta el proyecto en la lista
    }

}

/*-----------------------------------------------------------------------------------------------------------*/

void MostrarLista (list *ListaProyectos){
    Proyecto *PrimerProyecto = (Proyecto*)malloc(sizeof(Proyecto));
    PrimerProyecto = list_first(ListaProyectos);
    while (PrimerProyecto != NULL)
    {
        printf("%s |  Puntos que aporta: %s\n",PrimerProyecto->name, PrimerProyecto->puntos);
        PrimerProyecto = list_next(ListaProyectos);
    }

}

/*-----------------------------------------------------------------------------------------------------------*/

Proyecto * crearProyecto (char * linea){
    Proyecto * nuevoProyecto = (Proyecto*)calloc(1,sizeof(Proyecto));
    nuevoProyecto->name = (char*)calloc(100,sizeof(char));
    nuevoProyecto->puntos = (char*)calloc(100,sizeof(char));
    nuevoProyecto->parametroAfectado = (char*)calloc(100,sizeof(char));
    //Se obtienen los datos de la linea entregada (csv)
    strcpy(nuevoProyecto->name,get_csv_field(linea,1));
    strcpy(nuevoProyecto->puntos,get_csv_field(linea,2));
    strcpy(nuevoProyecto->parametroAfectado,get_csv_field(linea,3));

    return nuevoProyecto;

}

/*-----------------------------------------------------------------------------------------------------------*/

Comunidad * crearParametro(char * linea){
    Comunidad * nuevoParametro = (Comunidad*)calloc(1,sizeof(Comunidad));
    nuevoParametro->parametros = (char*)calloc(100,sizeof(char));
    nuevoParametro->avance = (char*)calloc(100,sizeof(char));

    strcpy(nuevoParametro->parametros, get_csv_field(linea,1));
    strcpy(nuevoParametro->avance, get_csv_field(linea,2));

    return nuevoParametro;
}

/*-----------------------------------------------------------------------------------------------------------*/

Usuario* UsuarioEntrada(){
    Usuario* usuario=(Usuario*)calloc(1,sizeof(Usuario));
    return usuario;
}

/*-----------------------------------------------------------------------------------------------------------*/

void guardarUsuario(Usuario* usuario){
    printf("\n NOMBRE: %s\n",usuario->nombre);
    printf("\n NOMBRE COMUNIDAD: %s\n",usuario->nombreComunidad);
    FILE* fp=fopen("Usuario.csv","w");
    fprintf(fp,"%s,%s,%i\n",usuario->nombre,usuario->nombreComunidad,usuario->Presupuesto);
    fclose(fp);
}

/*-----------------------------------------------------------------------------------------------------------*/

void mostrarInformacion(void){
    int op;
    char informacion;
    FILE *info;
    do
    {
        printf("Que es lo que deseas saber?\n");
        printf("1.Poderes del Estado.\n");
        printf("2.Conceptos Politicos.\n");
        printf("3.Datos freak de Chile.\n");
        printf("4.Arte y Musica.\n");
        printf("5.Volver al Menu Principal.\n");
        printf("Ingresar opcion: ");
        scanf("%i",&op);
        system("cls");
        switch (op)
        {
            case 1://Mostrar poderes del estado
                info = fopen("OrganosDelEstado.txt","r");
                while((informacion = fgetc(info)) != EOF)
                {
                    printf("%c",informacion);
                }
                fclose(info);
                printf("\n\n Presione ENTER para volver.");
                getchar();
                getchar();
                system("cls");
                break;

            case 2://Moestrar conceptos politicos
                info = fopen("ConceptosPoliticos.txt","r");
                while((informacion = fgetc(info)) != EOF)
                {
                    printf("%c",informacion);
                }
                fclose(info);
                printf("\n\n Presione ENTER para volver.");
                getchar();
                getchar();
                system("cls");
                break;

            case 3://Muestra datos de freak Chile
                info = fopen("DatosChilenos.txt","r");
                while((informacion = fgetc(info)) != EOF)
                {
                    printf("%c",informacion);
                }
                fclose(info);
                printf("\n\n Presione ENTER para volver.");
                getchar();
                getchar();
                system("cls");
                break;
            case 4://Muestra Datos de Arte y Musica
                info = fopen("ArteMusica.txt","r");
                while((informacion = fgetc(info)) != EOF)
                {
                    printf("%c",informacion);
                }
                fclose(info);
                printf("\n\n Presione ENTER para volver.");
                getchar();
                getchar();
                system("cls");
                break;
        }
    }while(op != 5);
};

/*-----------------------------------------------------------------------------------------------------------*/

void mostrarCancion(Map * mapaParametros){
        Comunidad * parametro = (Comunidad*)calloc(1,sizeof(Comunidad));
        parametro = firstMap(mapaParametros);
        while (parametro != NULL)
        {
            printf("%s %s\n",parametro->parametros,parametro->avance);
            parametro = nextMap(mapaParametros);
        }
}

/*-----------------------------------------------------------------------------------------------------------*/

void numerosRandom(){  //No utilizada
    srand(time(0));
    int minimo = 1;
    int maximo = 60;
    int segundos,minutos;
    int num;
    int i;
    for (i = 0; i < 1; i++)
    {
        num = (rand() % (maximo - minimo + 1)) + minimo;
        printf("NUMERO RANDOM: %i \n", num);
    }
    segundos = mostrarTiempoSegundos();
    minutos = mostrarTiempoMinutos();
    printf("\nSEGUNDOS: %i MINUTOS: %i", segundos,minutos);
    if ((segundos == num) || (minutos == num))
    {
        printf("\nSON IGUALES UNO DE LOS DOS");
    }
    return 0;
}

/*-----------------------------------------------------------------------------------------------------------*/

void crearPartidaNueva(){
    system("cls");
    char * nombre = (char*)calloc(20,sizeof(char));
    char nombreComunidad[200];
    char proyecto[200];
    char primerProyecto[200];
    char segundoProyecto[200];
    char tercerProyecto[200];


    Map* mapaUsuarios=createMap(stringHash,stringEqual);
    Map* mapaParametros=createMap(stringHash,stringEqual);
    list* ListaProyectos = list_create_empty();
    list* ListaSubproyectos = list_create_empty();
    FILE * fp = fopen("parametros.csv", "r");
    FILE * fb = fopen("proyectos.csv", "r");
    FILE * usuarios = fopen("Usuario.txt", "r");
    cargarDatosParametros(mapaParametros,fp);

    cargarDatosProyectos(ListaProyectos,fb);
                    printf("Ingrese Nombre de Usuario:\n");
                    getchar();
                    scanf("%[^\n]s",nombre);
                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("            %s, BIENVENIDA/O A 'NOVA TERRA' \n\n",nombre);
                    printf("            LUEGO DE QUE EL PLANETA FUERA AZOTADO POR UNA REVOLUCION LA CUAL\n");
                    printf("            CAMBIO LA MANERA DE VER LAS COSAS ALREDEDOR DE TODO EL MUNDO, INCLUIDO NUESTRO PAIS.\n\n");
                    printf("            TU, TIENES LA MISION DE RECONSTRUIR UNA DE LAS TANTAS NUEVAS COMUNIDADES QUE FORMAN PARTE DEL NUEVO CHILE.\n");
                    printf("            ESPERAMOS QUE PONGAS MUCHO ESFUERZO EN TODAS LAS DIFICULTADOS CON LAS QUE TE ENCUENTRES.\n\n");
                    printf("            CON EL PASAR DEL TIEMPO TE IREMOS CONTANDO MAS COSAS.");
                    getchar();
                    getchar();
                    system("cls");
                    printf("Ahora ingresa el nombre que deseas ponerle a tu comunidad:\n");
                    scanf("%[^\n]s",nombreComunidad);
                    system("cls");
                    printf("Perfecto, %s sera, muy buen nombre.\n",nombreComunidad);
                    getchar();
                    getchar();
                    system("cls");

                    crearUsuario(nombre,nombreComunidad,mapaUsuarios);
                    printf("\n\n\n\n\n");
                    printf("            A continuacion tendras que elegir entre tres proyectos iniciales\n");
                    printf("            que te ayudaran a dar un paso inicial, piensalo bien y elige los que creas\n");
                    printf("            que son mas importantes para partir \n");
                    getchar();
                    system("cls");
                    MostrarLista(ListaProyectos);
                    printf("\nA continuacion, escribe el primer proyecto a realizar:\n");
                    scanf("%[^\n]s",primerProyecto);
                    buscarProyecto (primerProyecto,ListaProyectos,mapaParametros);
                        getchar();
                    system("cls");
                    MostrarLista(ListaProyectos);
                    printf("\nA continuacion, escribe el segundo proyecto a realizar:\n");
                    scanf("%[^\n]s",segundoProyecto);
                        buscarProyecto (segundoProyecto,ListaProyectos,mapaParametros);
                        getchar();
                    system("cls");
                    MostrarLista(ListaProyectos);
                    printf("\nA continuacion, escribe el tercer proyecto a realizar:\n");
                    scanf("%[^\n]s",tercerProyecto);
                    buscarProyecto (tercerProyecto,ListaProyectos,mapaParametros);
                        getchar();
                    system("cls");
                    printf("\nOk, entonces %s, %s y %s son tus proyectos iniciales a eleccion",primerProyecto,segundoProyecto,tercerProyecto);
                    getchar();
                    mostrarCancion(mapaParametros);
                    getchar();
                    system("cls");
                    printf("Desde ahora en adelante, los proyectos que decidas llevar en adelante te costaran parte de tu presupuesto\n");
                    printf("Asi que tendras que administrarlo con mucho cuidado.\n");
                    getchar();
                    system("cls");
                    printf("Para empezar te daremos 500 pesos");
                    getchar();
                    system("cls");
                    printf("\n\nBueno, por ahora te dejaremos solo/a asi que tienes libertad de administrar tu comunidad como quieras");
                    getchar();
                    system("cls");
                    int opcion;
                    while (opcion != 2)
                    {
                        printf("1.- Crear Nuevo Proyecto\n");
                        printf("3.- Volver al Menu Principal\n");

                        printf("Escoja una opcion -> ");
                        scanf("%i",&opcion);

                        if ( opcion < 1 || opcion > 4)
                        {
                            system("cls");  //Limpia pantalla
                            printf("Ingrese un valor valido\n");
                            getchar();
                            getchar();
                            system("cls");
                        }
                        switch (opcion)
                        {
                            case 1:
                                system("cls");
                                printf("LISTA DE PROYECTOS DISPONIBLES: \n");
                                MostrarLista(ListaProyectos);
                                getchar();
                                printf("\nIngrese nombre de proyecto\n");
                                scanf("%[^\n]s",proyecto);
                                buscarProyecto(proyecto,ListaProyectos,mapaParametros);
                                getchar();
                                system("cls");
                                printf("Avance de tus Parametros:\n");
                                mostrarCancion(mapaParametros);
                                getchar();
                                system("cls");
                                break;
                            case 2:
                                break;


                        }
                    }
                    system("cls");
}

/*-----------------------------------------------------------------------------------------------------------*/

long long stringHash(const void * key) {
    long long hash = 5381;

    const char * ptr;

    for (ptr = key; *ptr != '\0'; ptr++) {
        hash = ((hash << 5) + hash) + tolower(*ptr); /* hash * 33 + c */
    }

    return hash;
}

/*-----------------------------------------------------------------------------------------------------------*/

int stringEqual(const void * key1, const void * key2) {
    const char * A = key1;
    const char * B = key2;

    return strcmp(A, B) == 0;
}

/*-----------------------------------------------------------------------------------------------------------*/

char * _strdup (const char *s){
	size_t len = strlen (s) + 1;
    void *new = malloc (len);

	if (new == NULL)
	    return NULL;

	return (char *) memcpy (new, s, len);
}

/*-----------------------------------------------------------------------------------------------------------*/

const char *get_csv_field (char * tmp, int i) {
    //se crea una copia del string tmp
    char * line = _strdup (tmp);
    const char * tok;
    for (tok = strtok (line, ","); tok && *tok; tok = strtok (NULL, ",\n")) {
        if (!--i) {
            return tok;
        }
    }
    return NULL;
}




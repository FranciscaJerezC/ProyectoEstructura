#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Map.h"
#include "List.h"

#include "funciones.h"

int main()
{
    printf("\n\n\n\n\n\n\n");
    printf(R"EOF(
    .__   __.   ______   ____    ____  ___         .___________. _______ .______      .______          ___
    |  \ |  |  /  __  \  \   \  /   / /   \        |           ||   ____||   _  \     |   _  \        /   \
    |   \|  | |  |  |  |  \   \/   / /  ^  \       `---|  |----`|  |__   |  |_)  |    |  |_)  |      /  ^  \
    |  . `  | |  |  |  |   \      / /  /_\  \          |  |     |   __|  |      /     |      /      /  /_\  \
    |  |\   | |  `--'  |    \    / /  _____  \         |  |     |  |____ |  |\  \----.|  |\  \----./  _____  \
    |__| \__|  \______/      \__/ /__/     \__\        |__|     |_______|| _| `._____|| _| `._____/__/     \__\)EOF");

    int op;
    Usuario* usuario=UsuarioEntrada();
    char * nombre = (char*)calloc(20,sizeof(char));
    char nombreComunidad[200];
    //cargarUsuarios
    Map* mapaUsuarios=createMap(stringHash,stringEqual);
    list *listaParametros = list_create_empty();
    list* ListaProyectos = list_create_empty();
    list* ListaSubproyectos = list_create_empty();

    while(op) //Menu principal
        {
            getchar();
            getchar();
            system("cls");
            printf("1.-Iniciar Partida Nueva\n");
            printf("2.-Cargar Partida\n");
            printf("3.-Informacion/Insumos\n");
            printf("4.-Salir y Guardar\n");
            printf("Escoja una opcion -> ");
            scanf("%i",&op);

            if( op < 1 || op > 4)
            {
                system("cls");  //Limpia pantalla
                printf("Ingrese un valor valido\n");
                getchar();
                getchar();
                system("cls");
            }

            switch (op)
            {
                case 1: //Iniciar Partida Nueva
                    printf("Ingrese Nombre de Usuario\n");
                    getchar();
                    scanf("%[^\n]s",nombre);
                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("            %s BIENVENIDE A 'NOVA TERRA' \n\n",nombre);
                    printf("            LUEGO DE QUE EL PLANETA FUERA AZOTADO POR UNA REVOLUCION LA CUAL\n");
                    printf("            CAMBIO LA MANERA DE VER LAS COSAS ALREDEDOR DE TODO EL MUNDO, INCLUIDO NUESTRO PAIS\n\n");
                    printf("            TU, TIENES LA MISION DE RECONSTRUIR UNA DE LAS TANTAS NUEVAS COMUNIDADES QUE FORMAN PARTE DEL NUEVO CHILE\n");
                    printf("            ESPERAMOS QUE PONGAS MUCHO ESFUERZO EN TODAS LAS DIFICULTADOS CON LAS QUE TE ENCUENTRES.\n\n");
                    printf("            CON EL PASAR DEL TIEMPO TE IREMOS CONTANDO MAS COSAS");
                    getchar();
                    getchar();
                    system("cls");
                    printf("Ahora ingresa el nombre que deseas ponerle a tu comunidad\n");
                    scanf("%[^\n]s",nombreComunidad);
                    system("cls");
                    printf("\n\nPerfecto, %s sera, muy buen nombre\n",nombreComunidad);
                    getchar();
                    getchar();

                    crearUsuario(nombre,nombreComunidad,mapaUsuarios);
                    system("cls");
                    break; //vuelve a la pantalla principal


              case 2: //Cargar Partida
                    system("cls");

                    //printf("Ingrese su Nombre de Usuario");
                    //getchar();
                    //scanf("%[^\n]s",nombre);
                    //buscarPartida(nombre,mapaUsuarios);
                    break;

              case 3: //Informacion

                    system("cls");
                    //mostrarCancion(mapaUsuarios);
                    break;
              case 4:  //genera numeros random, solo para probar
                    system("cls");
                    /*int minimo = 1;
                    int maximo = 30;
                    srand(time(0));
                    numerosRandom(minimo, maximo);
                    getchar();
                    getchar();*/
                    //y
                    guardarUsuario(usuario);
                    exit(1);
            }

        }

    return 0;
}

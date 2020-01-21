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
     __   __    ______   ____    ____  ___          __________   _______  ______    ______        ___
    |  \ |  |  /  __  \  \   \  /   / /   \        |          | |   ____||   _  \  |   _  \      /   \
    |   \|  | |  |  |  |  \   \/   / /  ^  \       '---|  |---' |  |__   |  |_)  | |  |_)  |    /  ^  \
    |       | |  |  |  |   \      / /  /_\  \          |  |     |   __|  |      /  |      /    /  /_\  \
    |  |\   | |  '--'  |    \    / /  _____  \         |  |     |  |____ |  |\  \  |  |\  \   /  _____  \
    |__| \__|  \______/      \__/ /__/     \__\        |__|     |_______|| _| `._| | _| `._| /__/     \__\)EOF");

    int op;
    printf("\n\n\n");
    printf("                                               Press ENTER to continue.");
    getchar();

    while(op) //Menu principal
        {

            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf(R"EOF(
     __   __    ______   ____    ____  ___          __________   _______  ______    ______        ___
    |  \ |  |  /  __  \  \   \  /   / /   \        |          | |   ____||   _  \  |   _  \      /   \
    |   \|  | |  |  |  |  \   \/   / /  ^  \       '---|  |---' |  |__   |  |_)  | |  |_)  |    /  ^  \
    |       | |  |  |  |   \      / /  /_\  \          |  |     |   __|  |      /  |      /    /  /_\  \
    |  |\   | |  '--'  |    \    / /  _____  \         |  |     |  |____ |  |\  \  |  |\  \   /  _____  \
    |__| \__|  \______/      \__/ /__/     \__\        |__|     |_______|| _| `._| | _| `._| /__/     \__\)EOF");

    printf("\n\n\n");

            printf("                                        1.-Iniciar Partida Nueva\n");
            printf("                                        2.-Informacion/Insumos\n");
            printf("                                        3.-Salir y Guardar\n");
            printf("                                        Escoja una opcion -> ");
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
                    crearPartidaNueva();
                    break; //vuelve a la pantalla principal


              case 2:
                    system("cls");
                    mostrarInformacion();
                    getchar();
                    getchar();

                    break;
              case 3: //Informacion

                    system("cls");
                    exit(1);
                    break;

            }

        }

    return 0;
}

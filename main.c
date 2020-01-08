#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "List.h"
#include "funciones.h"
int main()
{
    int op;
    char * nombre = (char*)calloc(20,sizeof(char));
    char nombreComunidad[200];

    while(op) //Menu principal
        {
            system("cls");
            printf("1.-Iniciar Partida Nueva\n");
            printf("2.-Cargar Partida\n");
            printf("3.-Informacion/Insumos\n");
            printf("Escoja una opcion -> ");
            scanf("%i",&op);

            if( op < 1 || op > 3)
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

                    crearUsuario(nombre,nombreComunidad);
                    system("cls");
                    break; //vuelve a la pantalla principal


              case 2: //Cargar Partida
                    system("cls");

                    break;

              case 3: //Informacion

                    system("cls");
                    break;
            }

        }

    return 0;
}

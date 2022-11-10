#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include "panelFonction.h"

pthread_mutex_t dmutex = PTHREAD_MUTEX_INITIALIZER;


static char** plateau[LIGNES][COLONNES] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#',' ',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#'},
	{' ',' ','#','#',' ','#',' ','#','#',' ','#','#','#',' ','#','#',' ','#',' ','#',' ','#',' ',' '},
	{'#',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ','#','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

int main(void)
{
    srand(time(NULL));


    //Initialisation

    terrain(**plateau);  //Placement des bombes sur le terrain

    joueur joueur1, joueur2;

    printf("nom du joueur1 : ");
    fgets(joueur1.pseudo, 20, stdin); //demande le nom du joueur1

    printf("\n");
    printf("nom du joueur2 : ");
    fgets(joueur2.pseudo, 20, stdin);   //demande le nom du joueur2

    positionAlea(**plateau); //Placement des joueurs sur le terrain

    afficher_plateau(**plateau);

    pthread_t deplaJ1, deplaJ2, poseBombeJ1, poseBombeJ2;

    pthread_create(&deplaJ1,NULL,deplacementJoueur1,&joueur1);
    pthread_create(&deplaJ2,NULL,deplacementJoueur2,&joueur2);
    pthread_create(&poseBombeJ1,NULL,installeBombe1, &joueur1);
    pthread_create(&poseBombeJ2,NULL,installeBombe2, &joueur2);

    pthread_join(deplaJ1,NULL);
    pthread_join(deplaJ2,NULL);
    pthread_join(poseBombeJ1,NULL);
    pthread_join(poseBombeJ2,NULL);

    return 0;
}

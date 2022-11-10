#include "panelFonction.h"

joueur joueur1, joueur2;

void afficher_plateau(char **plateau[LIGNES][COLONNES]){
    void clearScreen();

	for (size_t i = 0; i < LIGNES; i++)
	{
		for(size_t j = 0; j < COLONNES; j++)
		{
			printf("%c", **plateau[i][j]);
			if (!COLONNES - 1)
				printf(" ");
		}
		printf("\n");
	}
}

void positionAlea(char **plateau[LIGNES][COLONNES]){
    //initialisation joueur1

	do{
		joueur1.posLigne = rand()%LIGNES;
		joueur1.posColonne = rand()%COLONNES;
	} while (!placeLibre(plateau, joueur1.posLigne, joueur1.posColonne));

	**plateau[joueur1.posLigne][joueur1.posColonne]='B';


    //initialisation joueur2

    do{
		joueur2.posLigne = rand()%LIGNES;
		joueur2.posColonne = rand()%COLONNES;
	} while (!placeLibre(**plateau, joueur2.posLigne, joueur2.posColonne) || (joueur1.posLigne == joueur2.posLigne && joueur1.posColonne == joueur2.posColonne));

	**plateau[joueur2.posLigne][joueur2.posColonne]='b';
}

void *deplacementJoueur1(void *arg){

    char **plateau[LIGNES][COLONNES];
    int dir, dir1;
    while(1){
        dir = getch();
        if (dir == 224) {
            dir1 = getch();
        }
        //deplacementJoueur1
        **plateau[joueur1.posLigne][joueur1.posColonne] = ' ';
            if (dir1 == 72){ //HAUT
                if (placeLibre(**plateau, joueur1.posLigne - 1, joueur1.posColonne)){
                    joueur1.posLigne = joueur1.posLigne - 1;
                }
            }
            else if (dir1 == 80){ //BAS
                if (placeLibre(**plateau, joueur1.posLigne + 1, joueur1.posColonne)){
                    joueur1.posLigne = joueur1.posLigne + 1;
                }
            }
            else if (dir1 == 77){ //DROITE
                if (placeLibre(**plateau, joueur1.posLigne, joueur1.posColonne + 1)){
                    if (joueur1.posLigne == 4 && joueur1.posColonne + 1 == 23){
                        joueur1.posColonne = 1;
                        printf("ligne : %d et colonne : %d ",joueur1.posLigne, joueur1.posColonne);
                        printf("\n");
                    }
                    else{
                        joueur1.posColonne = joueur1.posColonne + 1;
                    }
                }
            }
            else if (dir1 == 75){ //GAUCHE
                if (placeLibre(**plateau, joueur1.posLigne, joueur1.posColonne - 1)){
                    if (joueur1.posLigne == 4 && joueur1.posColonne - 1 == 0){
                        joueur1.posColonne = 22;
                    }
                    else{
                        joueur1.posColonne = joueur1.posColonne - 1;
                    }
                }
            }
            **plateau[joueur1.posLigne][joueur1.posColonne] = 'B';
            sleep(1000);
            }

            //Fin déplacementJoueur1
}

void *deplacementJoueur2(void *arg){
    int dir;
    char **plateau[LIGNES][COLONNES];

    //deplacementJoueur2

    while(1){
        dir = getch();

        **plateau[joueur2.posLigne][joueur2.posColonne] = ' ';
        if (dir == HAUT2){
            if (placeLibre(**plateau, joueur2.posLigne - 1, joueur2.posColonne)){
                joueur2.posLigne = joueur2.posLigne - 1;
            }
        }
        else if (dir == BAS2){
            if (placeLibre(**plateau, joueur2.posLigne + 1, joueur2.posColonne)){
                joueur2.posLigne = joueur2.posLigne + 1;
            }
        }
        else if (dir == DROITE2){
            if (placeLibre(**plateau, joueur2.posLigne, joueur2.posColonne + 1)){
                if (joueur2.posLigne == 4 && joueur2.posColonne + 1 == 23){
                    joueur2.posColonne = 1;
                }
                else {
                joueur2.posColonne = joueur2.posColonne + 1;
                }
            }
        }
        else if (dir == GAUCHE2){
            if (placeLibre(**plateau, joueur2.posLigne, joueur2.posColonne - 1)){
                if (joueur2.posLigne == 4 && joueur2.posColonne - 1 == 0){
                    joueur2.posColonne = 22;
                }
                else {
                    joueur2.posColonne = joueur2.posColonne - 1;
                }
            }
        }
        **plateau[joueur2.posLigne][joueur2.posColonne] = 'b';
        sleep(1000);
        }

        //Fin déplacementJoueur2

}

int placeLibre(char **plateau[LIGNES][COLONNES], int ligne, int colonne){
        return **plateau[ligne][colonne] == ' ';
}

void clearScreen(void){   //pour un affichage lisible
    int z;
    for (z = 0; z < 10; z++){
        printf( "\n\n\n\n\n\n\n\n" );
    }
}

void terrain(char **plateau[LIGNES][COLONNES]){
    int nombre = 10;
    int obstableLigne, obstacleColonne;
    printf("\n");
    for (int i = 0; i < nombre; i++){
        do{
            obstableLigne = rand()%LIGNES;
            obstacleColonne = rand()%COLONNES;
        }while (!placeLibre(**plateau, obstableLigne, obstacleColonne));
        **plateau[obstableLigne][obstacleColonne] = 'x';
    }
}

void *installeBombe1(void *arg){
        char **plateau[LIGNES][COLONNES];
        int *nbObExplose;

        while(1){

            int clavier = getch();
            if (clavier == BOMBE){

                plateau[joueur1.posLigne][joueur1.posColonne] = 'o';
                joueur1.nbBombeUtilise = joueur1.nbBombeUtilise + 1;

                int secondes;

                time_t begin = time( NULL );
                do {
                    time_t now = time( NULL );
                    secondes = now - begin;
                }while (n != secondes);

                exploBombe(**plateau, joueur1.posLigne, joueur1.posColonne);
                int a = score (joueur1.nbBombeUtilise, *nbObExplose);
                printf("Le nouveau score de %c est %d", joueur1.pseudo, a);
            }
        }
}

void *installeBombe2(void *arg){
        char **plateau[LIGNES][COLONNES];

        int *nbObExplose;

        while(1){

            int clavier = getch();

            if (clavier == BOMBE2){
                plateau[joueur2.posLigne][joueur2.posColonne] = 'o';
                joueur2.nbBombeUtilise = joueur2.nbBombeUtilise + 1;

                int secondes;

                time_t begin = time( NULL );
                do {
                    time_t now = time( NULL );
                    secondes = now - begin;
                }while (n != secondes);

                exploBombe(**plateau, joueur2.posLigne, joueur2.posColonne);
                int b = score (joueur2.nbBombeUtilise, *nbObExplose);
                printf("Le nouveau score de %c est %d", joueur2.pseudo, b);
            }
        }
}

int exploBombe(char **plateau[LIGNES][COLONNES], int ligne, int colonne){
        int* nbObExplose = 0; //calculer le nombre de piege explosés en 1 une bombe
        int nbcasesL = 0;
        int nbcasesC = 0;
        while (**plateau[ligne][colonne] != '#' || 2 * n != nbcasesL){ //explosion sur la ligne
            if (**plateau[ligne][colonne] == 'x'){
                *nbObExplose = *nbObExplose + 1;
            }
            **plateau[ligne][colonne] = ' ';
            ligne = ligne + 1;
            nbcasesL = nbcasesL + 1;
            }

        while (**plateau[ligne][colonne] != '#' || 2 * n != nbcasesC){ //explosion sur la colonne
            if (**plateau[ligne][colonne] == 'x'){
                *nbObExplose = *nbObExplose + 1;
            }
            **plateau[ligne][colonne] = ' ';
            colonne = colonne + 1;
            nbcasesC = nbcasesC + 1;
        }
    return *nbObExplose;
}

int toujoursLa (char **plateau[LIGNES][COLONNES], char b){
    for(int i = 0; i <= LIGNES; i++){
        for (int j = 0; j <= COLONNES; j++){
            return **plateau[i][j] == b;
        }
    }
}

int score (int nbBombeUtilise, int *nbObExplose){
    char **plateau[LIGNES][COLONNES];

    int scoreFinal = *nbObExplose / (nbBombeUtilise * n);

    if (!toujoursLa(**plateau, 'b')){
        printf("Felicitation, le %c est le vainqueur", joueur1.pseudo);
        highscore(scoreFinal, joueur1.pseudo);
    }
    if (!toujoursLa(**plateau, 'B')){
        printf("Felicitation, le %c est le vainqueur", joueur2.pseudo);
        int scoreFinal = *nbObExplose / (nbBombeUtilise * n);
    }
    printf("\n");

    return scoreFinal;
}

//ouvrir le fichier de score final
void highscore(int scoreFinal, char personnage){

        //obtenir la date du jour
        time_t intps;
        struct tm * tm;
        intps = time(NULL);
        tm = localtime(&intps);

        int tousLesScores[3]; //liste réunissant les 3 meilleurs scores

        FILE *fichier=NULL;
        fichier= fopen("C:\\Users\\Valentine\\Documents\\Cours\\ensem\\2A\\C\\bomberman\\highscore.txt", "r+");
        if (fichier = NULL){
            fichier= fopen("C:\\Users\\Valentine\\Documents\\Cours\\ensem\\2A\\C\\bomberman\\highscore.txt", "a+");
            fprintf("Le nouveau meilleur score est %d réalisé par %c le %d/%d/%d à %d:%d:%d\n", scoreFinal, personnage, tm->tm_mday,tm->tm_mon,tm->tm_year,tm->tm_hour,tm->tm_min);
            tousLesScores[0] = scoreFinal;
        }

        else {
            if (scoreFinal >= tousLesScores[0])
            {
                fseek(fichier, 0, SEEK_SET);
                fprintf("Le nouveau meilleur score est %d réalisé par %c le %d/%d/%d à %d:%d:%d\n", scoreFinal, personnage, tm->tm_mday,tm->tm_mon,tm->tm_year,tm->tm_hour,tm->tm_min);
                tousLesScores[2] = tousLesScores[1];
                tousLesScores[1] = tousLesScores[0];
                tousLesScores[0] = scoreFinal;
            }
            else if (scoreFinal >= tousLesScores[1] && scoreFinal < tousLesScores[0])
            {
                fseek(fichier, 1, SEEK_SET);
                fprintf("Le second meilleur score est %d réalisé par %c le %d/%d/%d à %d:%d:%d\n", scoreFinal, personnage, tm->tm_mday,tm->tm_mon,tm->tm_year,tm->tm_hour,tm->tm_min);
                tousLesScores[2] = tousLesScores[1];
                tousLesScores[1] = scoreFinal;
            }
            else if (scoreFinal >= tousLesScores[2] && scoreFinal < tousLesScores[1])
            {
                fseek(fichier, 2, SEEK_SET);
                fprintf("Le troisième meilleur score est %d réalisé par %c le %d/%d/%d à %d:%d:%d\n", scoreFinal, personnage, tm->tm_mday,tm->tm_mon,tm->tm_year,tm->tm_hour,tm->tm_min);
                tousLesScores[2] = scoreFinal;
            }
            else
            {
                printf("Pas de meilleurs scores\n\n");
            }
            fclose(fichier);
        }
}

// Projet MIPS 2022-2023
// Auteurs : Cocagne_Strainovic

#include <stdio.h>
#include "utils.h"
#include "fonctionModes.h"

// TODO: verifier que les erreurs soient bien checkées pour le nouveau code
// TODO: bug programme si un caractere n'est ni une lettre, ni un nombre, ni un $ ou une ,

int main(int argc, char **argv) {
    char test[50] = "HelloWorld!";
    addChar(test, 5, ' ');
    printf("%s\n", test);



    switch (argc) {
        case 1:
            printf("* * * * * * * * * * * * Mode Interactif * * * * * * * * * * * *\n\n");
            modeInteractif();
            break;
        case 3:
            printf("* * * * * * * * * * * *  Mode Pas a pas * * * * * * * * * * *\n");
            printf("Appuyez sur [ENTRER] pour passer à l'instruction suivante\n");
            printf("Appuyez sur n'importe quelle touche pour quitter l'émulateur\n\n");
            modeAutoPasAPas(argv[1]);
            break;
        case 4:
            printf("* * * * * * * * * * * * Mode Automatique * * * * * * * * * * * *\n\n");
            modeAuto(argv[1], argv[2], argv[3]);
            break;
        default:
            break;
    }

    printf("Bye émulateur MIPS!\n");

    return 0;
}

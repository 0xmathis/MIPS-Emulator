#include <stdio.h>
#include <string.h>

#include "../include/Instruction.h"
#include "../include/utils.h"
#include "constantes.c"

void printInfos(Instruction *instruction) {
    printf("operateur     : %s\n", instruction->operateur);
    printf("format        : %d\n", instruction->format);
    printf("OPcodeOrFunc  : %d\n", instruction->OPcodeOrFunc);
    printf("nbParametres  : %d\n", instruction->nbParametres);
    printf("Ordre         : %d %d %d %d\n", instruction->parametresOrder[0], instruction->parametresOrder[1], instruction->parametresOrder[2], instruction->parametresOrder[3]);
    printf("x1            : %d\n", instruction->parametres[0]);
    printf("x2            : %d\n", instruction->parametres[1]);
    printf("x3            : %d\n", instruction->parametres[2]);
    printf("x4            : %d\n", instruction->parametres[3]);
}

void setOperateur(Instruction *instruction, char *operateur) {
    instruction->operateur = operateur;
}

void setFormat(Instruction *instruction, int format) {
    instruction->format = format;
}

void setOPcodeOrFunc(Instruction *instruction, int OPcodeOrFunc) {
    instruction->OPcodeOrFunc = OPcodeOrFunc;
}

void setNbParametres(Instruction *instruction, int nbParametres) {
    instruction->nbParametres = nbParametres;
}

void setParametres(Instruction *instruction, int *parametres) {
    for (int i = 0; i < 4; i++) {
        if (i < instruction->nbParametres) {
            instruction->parametres[i] = parametres[i];
        } else {
            instruction->parametres[i] = 0;
        }
    }
}

void setParametresOrder(Instruction *instruction, int *parametresOrder){


    for (int i = 0; i < 4; i++) {
        instruction->parametresOrder[i] = parametresOrder[i];
    }
}

void setOutputR(Instruction *instruction, char *output) {
    int parametres[4];

    for (int i = 0; i < 4; i++) {
        int index = instruction->parametresOrder[i];
        if (index == 0) {
            parametres[i] = 0;
        } else {
            parametres[i] = instruction->parametres[index - 1];
        }
    }

    // printf("x1     : %d\n", parametres[0]);
    // printf("x2     : %d\n", parametres[1]);
    // printf("x3     : %d\n", parametres[2]);
    // printf("x4     : %d\n", parametres[3]);

    char OPcode[7], func[7], x1[6], x2[6], x3[6], x4[6];

    // copyStrings(instruction->OPcodeOrFunc, func);
    // strcpy(func, instruction->OPcodeOrFunc);
    decToBin(0, 6, OPcode);
    decToBin(instruction->OPcodeOrFunc, 6, func);
    decToBin(parametres[0], 5, x1);
    decToBin(parametres[1], 5, x2);
    decToBin(parametres[2], 5, x3);
    decToBin(parametres[3], 5, x4);

    // printf("OPcode : %sf\n", OPcode);
    // printf("func   : %sf\n", func);
    // printf("x1     : %sf\n", x1);
    // printf("x2     : %sf\n", x2);
    // printf("x3     : %sf\n", x3);
    // printf("x4     : %sf\n", x4);

    sprintf(output, "%s%s%s%s%s%s", OPcode, x1, x2, x3, x4, func);
}

void setOutputI(Instruction *instruction, char *output) {
    int parametres[3];

    for (int i = 0; i < 3; i++) {
        // printf("%d ", i);
        int index = instruction->parametresOrder[i];
        if (index == 0) {
            parametres[i] = 0;
        } else if (index == -1) {
            parametres[i] = 1;
        } else {
            parametres[i] = instruction->parametres[index - 1];
        }
    }

    char OPcode[7], x1[6], x2[6], x3[17];
    decToBin(instruction->OPcodeOrFunc, 6, OPcode);
    decToBin(parametres[0], 5, x1);
    decToBin(parametres[1], 5, x2);
    decToBin(parametres[2], 16, x3);

    sprintf(output, "%s%s%s%s", OPcode, x1, x2, x3);
}

void setOutputJ(Instruction *instruction, char *output) {
    char OPcode[7], x[27];
    decToBin(instruction->parametres[0], 26, x);
    decToBin(instruction->OPcodeOrFunc, 6, OPcode);

    sprintf(output, "%s%s", OPcode, x);
}

void setOutputFull(Instruction *instruction, char *output) {
    switch (instruction->format) {
        case FORMAT_1:
            setOutputJ(instruction, output);
            break;
        case FORMAT_2:
        case FORMAT_3:
        case FORMAT_4:
            setOutputI(instruction, output);
            break;
        default:
            setOutputR(instruction, output);
            break;
    }
}
// Projet MIPS 2022-2023
// Auteurs : Cocagne_Strainovic

#include "registers.h"
#include "constantes.h"
#include "utils.h"

int registers[35] = {0};

void setValueToRegister(const int registerNumber, const int source) {
    if (registerNumber != 0) {  // on ne peut pas modifier le registre $0
        registers[registerNumber] = source;
    }
}

void getValueFromRegister(const int registerNumber, int *destination) {
    *destination = registers[registerNumber];
}

int getPCupper(const int PCvalue) {
    unsigned int PCupper = getUpperBits(4, 32);  // pour recuperer les 4 bits de poids fort de PC
    return PCvalue & ((int) PCupper);
}

void incrementPC(const int offset) {
    int pcValue;
    getValueFromRegister(PC, &pcValue);
    setValueToRegister(PC, pcValue + offset * 4);
}

void showRegistersStates() {
    for (int i = 0; i < 32; i++) {
        if (registers[i] != 0) {
            printf("$%02d : %d\n", i, registers[i]);
        }
    }

    if (registers[HI] || registers[LO]) {
        printf("HI:%d\n", registers[HI]);
        printf("LO:%d\n", registers[LO]);
    }
}

void writeFinalStateRegisters(FILE *fichierFinal) {
    for (int i = 0; i < 32; i++) {
        fprintf(fichierFinal, "$%.2d:%d\n", i, registers[i]);
    }

    fprintf(fichierFinal, "HI:%d\n", registers[HI]);
    fprintf(fichierFinal, "LO:%d\n", registers[LO]);
}

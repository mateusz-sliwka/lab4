
#include "simd.h"

clock_t start, stop;
double finaltime, steptime;

static double add(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++) {
        start = clock();
        for (int j = 0; j < numberOfNumbers; j++) {
            vector result;
            asm(
            "movups %1, %%xmm0\n"
            "movups %2, %%xmm1\n"
            "addps %%xmm1, %%xmm0\n"
            "movups %%xmm0, %0\n"
            : "=m"(result)
            : "m"(number1[j]), "m"(number2[j])
            );
        }
        stop = clock();
        steptime = (double) (stop - start) / CLOCKS_PER_SEC;
        finaltime += steptime;
    }
    return (double) (finaltime / repetitions);
}

static double sub(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++) {
        start = clock();
        for (int j = 0; j < numberOfNumbers; j++) {
            vector result;
            asm(
            "movups %1, %%xmm0\n"
            "movups %2, %%xmm1\n"
            "subps %%xmm1, %%xmm0\n"
            "movups %%xmm0, %0\n"
            : "=m"(result)
            : "m"(number1[j]), "m"(number2[j])
            );

        }
        stop = clock();
        steptime = (double) (stop - start) / CLOCKS_PER_SEC;
        finaltime += steptime;
    }
    return (double) (finaltime / repetitions);
}

static double mult(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++) {
        start = clock();
        for (int j = 0; j < numberOfNumbers; j++) {
            vector result;
            asm(
            "movups %1, %%xmm0\n"
            "movups %2, %%xmm1\n"
            "mulps %%xmm1, %%xmm0\n"
            "movups %%xmm0, %0\n"
            : "=m"(result)
            : "m"(number1[j]), "m"(number2[j])
            );
        }
        stop = clock();
        steptime = (double) (stop - start) / CLOCKS_PER_SEC;
        finaltime += steptime;
    }
    return (double) (finaltime / repetitions);
}

static double divv(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++) {
        start = clock();
        for (int j = 0; j < numberOfNumbers; j++) {
            vector result;
            asm(
            "movups %1, %%xmm0\n"
            "movups %2, %%xmm1\n"
            "divps %%xmm1, %%xmm0\n"
            "movups %%xmm0, %0\n"
            : "=m"(result)
            : "m"(number1[j]), "m"(number2[j])
            );
        }
        stop = clock();
        steptime = (double) (stop - start) / CLOCKS_PER_SEC;
        finaltime += steptime;
    }
    return (double) (finaltime / repetitions);

}

void testSIMD(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {

    FILE *file = fopen("wyniki.txt", "a");
    fprintf(file, "\nWyniki obliczen: SIMD\n");
    fprintf(file, "Liczba liczb: %d\n", numberOfNumbers);
    fprintf(file, "Sredni czas [s]:\n");
    fprintf(file, "+ %.6f\n", add(number1, number2, numberOfNumbers, repetitions));
    fprintf(file, "- %.6f\n", sub(number1, number2, numberOfNumbers, repetitions));
    fprintf(file, "* %.6f\n", mult(number1, number2, numberOfNumbers, repetitions));
    fprintf(file, "/ %.6f\n", divv(number1, number2, numberOfNumbers, repetitions));
    fclose(file);
}

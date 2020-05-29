#include "sisd.h"

clock_t start, stop;
double steptime, finaltime;

static double add(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++)
        for (int j = 0; j < numberOfNumbers; j++) {
            vector x = number1[j];
            vector y = number2[j];
            vector result;
            start = clock();
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(x.a), "m"(y.a)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(x.b), "m"(y.b)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(x.c), "m"(y.c)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(x.d), "m"(y.d)
            );
            stop = clock();
            steptime = (double) (stop - start) / CLOCKS_PER_SEC;
            finaltime += steptime;
        }
      return(double) (finaltime / repetitions);
}

static double sub(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++)
        for (int j = 0; j < numberOfNumbers; j++) {
            vector x = number1[j];
            vector y = number2[j];
            vector result;
            start = clock();
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(x.a), "m"(y.a)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(x.b), "m"(y.b)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(x.c), "m"(y.c)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(x.d), "m"(y.d)
            );
            stop = clock();
            steptime = (double) (stop - start) / CLOCKS_PER_SEC;
            finaltime += steptime;
        }
      return (double)(finaltime / repetitions);
}

static double mult(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++)
        for (int j = 0; j < numberOfNumbers; j++) {
            vector x = number1[j];
            vector y = number2[j];
            vector result;
            start = clock();
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(x.a), "m"(y.a)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(x.b), "m"(y.b)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(x.c), "m"(y.c)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(x.d), "m"(y.d)
            );
            stop = clock();
            steptime = (double) (stop - start) / CLOCKS_PER_SEC;
            finaltime += steptime;
        }
      return (double)(finaltime / repetitions);
}

static double divv(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++)
        for (int j = 0; j < numberOfNumbers; j++) {
            vector x = number1[j];
            vector y = number2[j];
            vector result;
            //cialo dodawania simd
            start = clock();
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(x.a), "m"(y.a)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(x.b), "m"(y.b)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(x.c), "m"(y.c)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(x.d), "m"(y.d)
            );
            stop = clock();
            steptime = (double) (stop - start) / CLOCKS_PER_SEC;
            finaltime += steptime;
        }
   return (double)(finaltime / repetitions);
}

void testSISD(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
	FILE *file = fopen("wyniki.txt","a");
	fprintf(file,"\nTyp obliczen: SISD\n");
    fprintf(file,"Liczba liczb: %d\n", numberOfNumbers);
    fprintf(file,"Sredni czas [s]:\n");
    fprintf(file,"+ %.6f\n", add(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"- %.6f\n", sub(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"* %.6f\n", mult(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"/ %.6f\n", divv(number1, number2, numberOfNumbers, repetitions));    
    fclose(file);
}

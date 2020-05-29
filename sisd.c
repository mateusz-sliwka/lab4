#include "sisd.h"

clock_t start, stop;
double steptime, finaltime;

static double add(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
    finaltime = 0;
    for (int i = 0; i < repetitions; i++)
        for (int j = 0; j < numberOfNumbers; j++) {
             
            vector result;
     start = clock();
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(number1[j].a), "m"(number2[j].a)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(number1[j].b), "m"(number2[j].b)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(number1[j].c), "m"(number2[j].c)
            );
            asm(
                "fld %1\n"
                "fadd %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(number1[j].d), "m"(number2[j].d)
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
            
            
            vector result;
             start = clock();
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(number1[j].a), "m"(number2[j].a)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(number1[j].b), "m"(number2[j].b)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(number1[j].c), "m"(number2[j].c)
            );
            asm(
                "fld %1\n"
                "fsub %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(number1[j].d), "m"(number2[j].d)
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
            
              start = clock();
            vector result;
          
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(number1[j].a), "m"(number2[j].a)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(number1[j].b), "m"(number2[j].b)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(number1[j].c), "m"(number2[j].c)
            );
            asm(
                "fld %1\n"
                "fmull %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(number1[j].d), "m"(number2[j].d)
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
            
            
              
            
            vector result;
          start = clock();
         
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.a)
                : "m"(number1[j].a), "m"(number2[j].a)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.b)
                : "m"(number1[j].b), "m"(number2[j].b)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.c)
                : "m"(number1[j].c), "m"(number2[j].c)
            );
            asm(
                "fld %1\n"
                "fdiv %2\n"
                "fstp %0\n"
                : "=m"(result.d)
                : "m"(number1[j].d), "m"(number2[j].d)
            );
            stop = clock();
            steptime = (double) (stop - start) / CLOCKS_PER_SEC;
            finaltime += steptime;
        }
   return (double)(finaltime / repetitions);
}

void testSISD(vector number1[], vector number2[], int numberOfNumbers, int repetitions) {
	FILE *file = fopen("wyniki.txt","a");
	fprintf(file,"\nWyniki obliczen: SISD\n");
    fprintf(file,"Liczba liczb: %d\n", numberOfNumbers);
    fprintf(file,"Sredni czas [s]:\n");
    fprintf(file,"+ %.6f\n", add(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"- %.6f\n", sub(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"* %.6f\n", mult(number1, number2, numberOfNumbers, repetitions));
    fprintf(file,"/ %.6f\n", divv(number1, number2, numberOfNumbers, repetitions));    
    fclose(file);
}

#include "simd.h"
#include "sisd.h"
#include <stdlib.h>
#include <stdio.h>


void randVector(vector ourVector[],int numberOfNumbers){
	for(int i=0;i<numberOfNumbers;i++){
		ourVector[i].a = (rand()%1000);
		ourVector[i].b = (rand()%1000);
		ourVector[i].c = (rand()%1000);
		ourVector[i].d = (rand()%1000);
	}
}

int main(){
	int maximumNumbers=8192;
	int repetitions = 10;

	FILE *file = fopen("wyniki.txt","w");
	fclose(file);
	vector firstVector[maximumNumbers],secondVector[maximumNumbers];
	randVector(firstVector,maximumNumbers);
	randVector(secondVector,maximumNumbers);
	testSIMD(firstVector,secondVector,2048, repetitions);
	testSIMD(firstVector,secondVector,4096, repetitions);
	testSIMD(firstVector,secondVector,8192, repetitions);
	testSISD(firstVector,secondVector,2048, repetitions);
	testSISD(firstVector,secondVector,4096, repetitions);
	testSISD(firstVector,secondVector,8192, repetitions);
}

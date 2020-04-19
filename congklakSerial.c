#include <stdio.h>
#include <stdlib.h>
#include "body.c"

int main(){
		double start, end;
        int* Hole=(int*)malloc(16*sizeof(int*));

		int LokasiAmbil,StopLumbung;
		for(LokasiAmbil=1;LokasiAmbil<=7;LokasiAmbil++){
        	IsiDataDefaultCongklak(Hole);
        	Mulai(Hole,LokasiAmbil,&StopLumbung);
       		printf("Pengambilan di Hole %i Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",LokasiAmbil,Hole[8],StopLumbung);
    	}

}


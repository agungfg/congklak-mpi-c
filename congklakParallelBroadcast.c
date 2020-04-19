#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "body.c"

int main(int argc, char** argv) {
    double start, end;
    MPI_Init(&argc, &argv);
    int rank,numProc,StopLumbung;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProc);
    MPI_Barrier(MPI_COMM_WORLD);
    start = MPI_Wtime();
    CekBanyakProcessor(numProc);
  
    int* Hole=(int*)malloc(128*sizeof(int*));
    
    if(rank == 0 ){
        IsiDataDefaultCongklak(Hole);
    } 

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Bcast(&Hole[0],128,MPI_INT,0,MPI_COMM_WORLD);    
    MPI_Barrier(MPI_COMM_WORLD);

    if(rank!=0){
        Mulai(Hole,rank,&StopLumbung);
        printf("Pengambilan di Hole %i Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",rank,Hole[8],StopLumbung);   
    }

    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();
    if (rank == 0) { 
        printf("Runtime = %f\n", end-start);
    }
    MPI_Finalize();

    
   

}


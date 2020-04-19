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
  
  int* Default=(int*)malloc(16*sizeof(int*));
  int* Hole=(int*)malloc(16*sizeof(int*));
  IsiDataDefaultCongklak(Default);
  
  if (rank == 0) {
    MPI_Send(&Default[0], 16, MPI_INT, 1, 1, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 2, 2, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 3, 3, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 4, 4, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 5, 5, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 6, 6, MPI_COMM_WORLD);
    MPI_Send(&Default[0], 16, MPI_INT, 7, 7, MPI_COMM_WORLD);
  
  }else if (rank == 1){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 1  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 11 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 111, MPI_COMM_WORLD);
  
  }else if (rank == 2){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 2  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 22 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 222, MPI_COMM_WORLD);
  
  }else if (rank == 3){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 3  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 33 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 333, MPI_COMM_WORLD);
  
  }else if (rank == 4){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 4  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 44 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 444, MPI_COMM_WORLD);
  
  }else if (rank == 5){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 5  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 55 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 555, MPI_COMM_WORLD);
  
  }else if (rank == 6){
  
    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 6  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 66 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 666, MPI_COMM_WORLD);
  
  }else if (rank == 7){

    MPI_Recv(&*Hole      ,16, MPI_INT, 0, 7  , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    Mulai(Hole,rank,&StopLumbung);
    MPI_Send(&Hole[8]    , 1, MPI_INT, 0, 77 , MPI_COMM_WORLD);
    MPI_Send(&StopLumbung, 1, MPI_INT, 0, 777, MPI_COMM_WORLD);
  
  }
  
  if(rank==0){

    int StopLumbung1,StopLumbung2,StopLumbung3,StopLumbung4,StopLumbung5,StopLumbung6,StopLumbung7;
    int Keuntungan1 ,Keuntungan2 ,Keuntungan3 ,Keuntungan4 ,Keuntungan5 ,Keuntungan6 ,Keuntungan7 ;

    MPI_Recv(&Keuntungan1 , 1, MPI_INT, 1, 11 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung1, 1, MPI_INT, 1, 111, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan2 , 1, MPI_INT, 2, 22 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung2, 1, MPI_INT, 2, 222, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan3 , 1, MPI_INT, 3, 33 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung3, 1, MPI_INT, 3, 333, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan4 , 1, MPI_INT, 4, 44 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung4, 1, MPI_INT, 4, 444, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan5 , 1, MPI_INT, 5, 55 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung5, 1, MPI_INT, 5, 555, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan6 , 1, MPI_INT, 6, 66 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung6, 1, MPI_INT, 6, 666, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&Keuntungan7 , 1, MPI_INT, 7, 77 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&StopLumbung7, 1, MPI_INT, 7, 777, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
    printf("Pengambilan di Hole 1 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan1,StopLumbung1);
    printf("Pengambilan di Hole 2 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan2,StopLumbung2);
    printf("Pengambilan di Hole 3 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan3,StopLumbung3);
    printf("Pengambilan di Hole 4 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan4,StopLumbung4);
    printf("Pengambilan di Hole 5 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan5,StopLumbung5);
    printf("Pengambilan di Hole 6 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan6,StopLumbung6);
    printf("Pengambilan di Hole 7 Memberikan Keuntungan %2.1i Berhenti di Lumbung [%i]\n",Keuntungan7,StopLumbung7);

  }

  MPI_Barrier(MPI_COMM_WORLD);
  end = MPI_Wtime();
  if (rank == 0) { 
    printf("Runtime = %f\n", end-start);
  }
  MPI_Finalize();
}
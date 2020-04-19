void CekBanyakProcessor(int numProc){
  if (numProc != 8) {
    printf("Banyak Proses Harus 8\n");
    exit(1);
  }
}

void IsiDataDefaultCongklak(int* Default){
  Default[1]=0;
  Default[2]=14;
  Default[3]=0;
  Default[4]=4;
  Default[5]=2;
  Default[6]=4;
  Default[7]=13;
  Default[8]=0;
  Default[9]=13; 
  Default[10]=3;
  Default[11]=5;
  Default[12]=14;
  Default[13]=0;
  Default[14]=14;
  Default[15]=4;
}

void Nembak(int* Hole, int LokasiMain, int BanyakBijiDitangan){
  if(LokasiMain==9 && BanyakBijiDitangan==1 && Hole[7]>0 && Hole[LokasiMain]==1 ){
    Hole[8]=Hole[8]+Hole[7]+1;
    Hole[9]=0;
    Hole[7]=0;
  }else if(LokasiMain==10 && BanyakBijiDitangan==1 && Hole[6]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[6]+1;
    Hole[10]=0;
    Hole[6]=0;
  }else if(LokasiMain==11 && BanyakBijiDitangan==1 && Hole[5]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[5]+1;
    Hole[11]=0;
    Hole[5]=0;
  }else if(LokasiMain==12 && BanyakBijiDitangan==1 && Hole[4]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[4]+1;
    Hole[12]=0;
    Hole[4]=0;
  }else if(LokasiMain==13 && BanyakBijiDitangan==1 && Hole[3]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[3]+1;
    Hole[13]=0;
    Hole[3]=0;
  }else if(LokasiMain==14 && BanyakBijiDitangan==1 && Hole[2]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[2]+1;
    Hole[14]=0;
    Hole[2]=0;
  }else if(LokasiMain==15 && BanyakBijiDitangan==1 && Hole[1]>0 && Hole[LokasiMain]==1){
    Hole[8]=Hole[8]+Hole[1]+1;
    Hole[15]=0;
    Hole[1]=0;
  }

}   
    
int BerhentiDiLumbung(int LokasiMain, int LokasiAmbil, int BanyakBijiDitangan){     
  if((LokasiMain==8) && (BanyakBijiDitangan==1)){ 
    return 1;
  }else{
    return 0;
  }
}

void TerusLagi(int* Hole, int LokasiMain, int* BanyakBijiDitangan){
  if((*BanyakBijiDitangan==1) && (Hole[LokasiMain]>=2) && (LokasiMain!=8)){
    *BanyakBijiDitangan=Hole[LokasiMain]+1;
    Hole[LokasiMain]=0;
  }
}

void StartLooping(int* Hole, int BanyakBijiDitangan, int LokasiMain, int LokasiAmbil, int* StopLumbung){
        for(BanyakBijiDitangan=BanyakBijiDitangan;BanyakBijiDitangan>=1;BanyakBijiDitangan--){     
                //printf("Hole [%i] = %i\n",LokasiMain,Hole[LokasiMain]);
                if(LokasiMain<=15){            
                        LokasiMain++;
                        Hole[LokasiMain]++;           
                }else{
                        LokasiMain=1;
                        Hole[LokasiMain]++; 
                        BanyakBijiDitangan++;
                }
                BerhentiDiLumbung(LokasiMain,LokasiAmbil,BanyakBijiDitangan);
                TerusLagi(Hole,LokasiMain,&BanyakBijiDitangan);
                Nembak(Hole,LokasiMain,BanyakBijiDitangan);
        }
        *StopLumbung=BerhentiDiLumbung(LokasiMain,LokasiAmbil,BanyakBijiDitangan+1);
}

void Mulai(int* Hole, int rank, int* StopLumbung){
        int LokasiAmbil=rank;
        int BanyakBijiDitangan=Hole[LokasiAmbil];                
        int LokasiMain=LokasiAmbil;  
        Hole[LokasiMain]=0;
        StartLooping(Hole,BanyakBijiDitangan,LokasiMain,LokasiAmbil,&*StopLumbung);
}

   
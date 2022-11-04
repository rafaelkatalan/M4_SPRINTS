//função que escreve um numero de 0-15 em um vetor em forma de binario

int bin16bit(int n, int* bin){

    if (n == 15){
      bin[0] = 1;
      bin[1] = 1;
      bin[2] = 1;
      bin[3] = 1;
      
    }
    if (n == 14){
      bin[0] = 1;
      bin[1] = 1;
      bin[2] = 1;
      bin[3] = 0;


    }
    if (n == 13){
      bin[0] = 1;
      bin[1] = 1;
      bin[2] = 0;
      bin[3] = 1;


    }
    if (n == 12){
      bin[0] = 1;
      bin[1] = 1;
      bin[2] = 0;
      bin[3] = 0;


    }
    if (n == 11){
      bin[0] = 1;
      bin[1] = 0;
      bin[2] = 1;
      bin[3] = 1;


    }
    if (n == 10){
      bin[0] = 1;
      bin[1] = 0;
      bin[2] = 1;
      bin[3] = 0;


    }
    if (n == 9){
      bin[0] = 1;
      bin[1] = 0;
      bin[2] = 0;
      bin[3] = 1;

      

    }
    if (n == 8){
      bin[0] = 1;
      bin[1] = 0;
      bin[2] = 0;
      bin[3] = 0;



    }
    if (n == 7){
      bin[0] = 0;
      bin[1] = 1;
      bin[2] = 1;
      bin[3] = 1;


    }
    if (n == 6){
      bin[0] = 0;
      bin[1] = 1;
      bin[2] = 1;
      bin[3] = 0;


    }
    if (n == 5){
      bin[0] = 0;
      bin[1] = 1;
      bin[2] = 0;
      bin[3] = 1;
    }
    if (n == 4){
      bin[0] = 0;
      bin[1] = 1;
      bin[2] = 0;
      bin[3] = 0;



    }
    if (n == 3){
      bin[0] = 0;
      bin[1] = 0;
      bin[2] = 1;
      bin[3] = 1;

      
    }
    if (n == 2){
      bin[0] = 0;
      bin[1] = 0;
      bin[2] = 1;
      bin[3] = 0;
      

    }
    if (n == 1){
      bin[0] = 0;
      bin[1] = 0;
      bin[2] = 0;
      bin[3] = 1;


    }
    if (n == 0){
      bin[0] = 0;
      bin[1] = 0;
      bin[2] = 0;
      bin[3] = 0;
    }

  return 0;
}
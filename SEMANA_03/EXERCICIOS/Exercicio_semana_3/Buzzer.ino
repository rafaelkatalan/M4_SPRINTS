//Toca o buzzer em uma frequencia especifica para cada valor passado de 0-15

int buzzer(int n){

  int BUZZZER_PIN = 16;
  int seq[4];
    if (n == 11){
     tone(16, 4186, 1000);
     delay(1);
    }
    if (n == 10){
     tone(16, 7459, 1000);
     delay(1);

    }
    if (n == 9){
     tone(16, 4698, 1000);
     delay(1);
    }
    if (n == 8){
     tone(16, 4978, 1000);
     delay(1);



    }
    if (n == 7){
     tone(16, 5274, 1000);
     delay(1);


    }
    if (n == 6){
     tone(16, 5587, 1000);
     delay(1);



    }
    if (n == 5){
     tone(16, 5920, 1000);
     delay(1);

    }
    if (n == 4){

     tone(16, 6272, 1000);
     delay(1);




    }
    if (n == 3){

     tone(16, 6645);
     delay(1);


    }
    if (n == 2){
     tone(16, 7040);
     delay(1);

    }
    if (n == 1){
     tone(16, 7459);
     delay(1);



    }
    if (n == 0){
     tone(16, 7902);
     delay(1);

    }
    if (n == 12){
     tone(16, 3951);
     delay(1);


      
    }
    if (n == 13){
     tone(16, 3729);
     delay(1);


    }
    if (n == 14){
     tone(16, 3520);
     delay(1);

    }
    if (n == 15){
     tone(16, 3322);
     delay(1);

    }
  return 0;
}
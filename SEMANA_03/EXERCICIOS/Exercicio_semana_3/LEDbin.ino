///Ascende as LEDs conforme um vetor passado com o numero escrito em binario
int LEDbin(int* bin, int* LEDs){
 
    if(bin[0] == 1){
      digitalWrite(7, LOW);
    }
    else{
      digitalWrite(7, HIGH);
    }
    if(bin[1] == 1){
      digitalWrite(9, LOW);
    }
    else{
      digitalWrite(9, HIGH);
    }
    if(bin[2] == 1){
      digitalWrite(10, LOW);
    }
    else{
      digitalWrite(10, HIGH);
    }
    if(bin[3]==1){
      digitalWrite(11, LOW);
    }
    else{
      digitalWrite(11, HIGH);
    }
    return 0;
}
#include <cmath>

const int BUZZZER_PIN = 16;
using namespace std; 

//declaração de variaveis globais
int con = 0;
int con2 = 0;
int gravado[1000];
int i = 0;
int a = 0;

void setup() {
  //inicia comunicação serial
  Serial.begin(9600);

  //declaração das portas utilizadas e tipo
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
}

void loop() {

  
  int sensorValue = analogRead(1);  // Ler o pino Analógico 1 onde está o LDR
  float value = sensorValue;
  float result = ((4095-value)/4095)*15; //Coloca o valor lido pelo sensor numa escala de 0-15
  int n = round(result); //Arredonda valor para inteiro mais proximo
  int bin[4] = {}; //Cria um vetor para armazenar numero em forma de binario
  int LEDs[4]={11,10,9,7};//vetor com pinos usados pelas LEDs
  
  bin16bit(n, bin);//Preenche o vetor "bin" com zeros e uns correspondentes ao numero "n" em binario
  buzzer(n); // Toca o buzzer na frequencia correspondente ao numero "n"
  LEDbin(bin, LEDs);//Ascende as LEDs conforme o vetor "bin"
  Serial.println(sensorValue);

  //Condições que atribuem a variavel "con" e "con2" 0 e 1 correspondente ao estado de cada botão
  if(digitalRead(2) == LOW){
    con = 1;
  }
  if(digitalRead(2) == HIGH){
    con = 0;
  }

  if(digitalRead(17) == LOW){
    con2 = 1;
  }
  if(digitalRead(17) == HIGH){
    con2 = 0;
  }

  
  if(con == 1){
    //Se o botão da porta 2 for precionado as leds o buzer ascendem/toca conforme os valores que foram gravados no vetor "gravado"
    digitalWrite(40, HIGH);
    for(int j=0; j<i; j++){
      //MESMO PROCESSO DE ANTES SÓ QUE COM OS VALORES DO VETOR INVEZ DOS DO SENSOR
       int bin2[4]={}; 
       bin16bit(gravado[j], bin2);
       buzzer(gravado[j]);
       int LEDs[4]={11,10,9,7};
       LEDbin(bin2, LEDs);
       delay(1000);
    }

    digitalWrite(40, LOW);
    //zera o "i" que determina a posição do vetor que o proximo valor gravado será armazenado
    i = 0;

  }

  if(con == 0){
     digitalWrite(40, LOW);
     delay(1);
   }

  if(con2 == 1 && a==0){
    //grava valor do sensor (já colocado na escala de 0-15) no vetor "gravado"
     delay(1);
     digitalWrite(40, HIGH);
     gravado[i] = n;
     i++;
     a = 1;//garante que o botão não será apertado continuamente
  }

  if(con2 == 0){
     digitalWrite(40, LOW);
     a = 0;
     delay(1);
  }
}

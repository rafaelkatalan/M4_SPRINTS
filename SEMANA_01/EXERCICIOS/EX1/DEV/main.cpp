#include <iostream>
#include <string>

using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

float percentual(float min, float max, float value){
  float intervalo = max - min;
  float valor = (value-min)/intervalo;
  float percentual = valor*100;
  return percentual;
}

float ex1(){
  cout << "ex1:" << endl;
  float min = 0;
  float max = 0;
  float value = 0;
  cout << "valor minimo" << endl;
  cin >> min;
  cout << "valor maximo" << endl;
  cin >> max;
  cout << "valor" << endl;
  cin >> value;
  float result = percentual(min, max, value);
  cout << result << "%" << endl;
  return result;
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

string ex2(){
  //cout << "ex2:" << endl;
  cout << "aperta alguma coisa no telado"<< endl;
  string value;
  getline (cin, value);
  cout << value;
  return(value);
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor

int insereVetor(int num, int *lastPos, int Numbers[]){
  (*lastPos)++;
  Numbers[*lastPos] = num;
  return 0;
}

int ex3(){
  
  int valorMax = 10;
  int lastPos = -1;
  int Numbers[valorMax];
  
  insereVetor(9, &lastPos, Numbers);

  insereVetor(8, &lastPos, Numbers);

  insereVetor(7, &lastPos, Numbers);

  insereVetor(6, &lastPos, Numbers);

  insereVetor(5, &lastPos, Numbers);

  insereVetor(4, &lastPos, Numbers);

  insereVetor(3, &lastPos, Numbers);
  
  insereVetor(2, &lastPos, Numbers);

  insereVetor(1, &lastPos, Numbers);

  insereVetor(0, &lastPos, Numbers);

  insereVetor(100, &lastPos, Numbers);
  
  // valor esperado: mensagem de erro "Erro: valorMax: 10, lastPos + 1 (indice): 10"
  
  cout << Numbers[0] << endl; // valor esperado: 9
  cout << Numbers[1] << endl; // valor esperado: 8
  cout << Numbers[2] << endl; // valor esperado: 7
  cout << Numbers[3] << endl; // valor esperado: 6
  cout << Numbers[4] << endl; // valor esperado: 5
  cout << Numbers[5] << endl; // valor esperado: 4
  cout << Numbers[6] << endl; // valor esperado: 3
  cout << Numbers[7] << endl; // valor esperado: 2
  cout << Numbers[8] << endl; // valor esperado: 1
  cout << Numbers[9] << endl; // valor esperado: 0
  return 0;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.

float maiorDir(float vetor[]){
  float n = 0;
  for (int i=0; i < 4; i++){
    if (vetor[i]>n){
        n=vetor[i];
      }
  }
  return n; 
}

string dirMaiorDir(float vetor[]){
  float n = 0;
  int dir;
  for (int i=0; i < 4; i++){
    if (vetor[i]>n){
        n=vetor[i];
        dir = i;
      }
  }
  if (dir == 0){
    return "Direita";
  }
   if (dir == 1){
    return "Esquerda";
  }
   if (dir == 2){
    return "Frente";
  }
   if (dir == 3){
    return "Tras";
  }
}

int ex4() {
  
  float vetor[4] = {0,3.98,890.51,221};
  // "Direita", "Esquerda", "Frente", "Tras"

  cout<< maiorDir(vetor)<<endl;
  cout<<dirMaiorDir(vetor)<<endl;
  return 0;
}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

bool continuar(){
  string ans;
  cout<<"deseja parar?(s/n?)";
  cin >> ans;

  if (ans == "s"){
    return(true);
  }
  else{
    return(false);
  }
}

int ex5(){
  int parar = false;
  
  while (!parar){
    parar = continuar();
  }
  cout<<"parado";
  return 0;
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 

//Não consegui entender direito a função incompleta, então escrevi uma do zero na qual são passadas as distancias das 4 direções e o robo se move para a 
//direção de maior distancia. A função simula que o robo está em uma sala sem nada com 4 paredes, desta
//forma, ele anda sozinho e quando se aproxima de uma parede, se afasta da outra.


int leComando(int *dirigindo){
  cout<< "continua?(s = 1; n = 0)";
  int resp;
  cin >>resp;
  (*dirigindo)= resp;
  return 0;
}

float dirige(float vetor[]){
  int dirigindo = 1;
  while (dirigindo == 1){
    float n = 0;
    int dir;
    for (int i=0; i < 4; i++){
      if (vetor[i]>n){
        n=vetor[i];
        dir = i;
      }
    }
    if(dir == 0){
      vetor[1]+=1;
      vetor[0]-=1;
    }
    if(dir == 1){
      vetor[0]+=1;
      vetor[1]-=1;
    }
    if(dir == 2){
      vetor[3]+=1;
      vetor[2]-=1;
    }
    if(dir == 3){
      vetor[2]+=1;
      vetor[3]-=1;
    }
    
    
    cout<<"posição atual: [";
    for (int i = 0; i<4; i++){
      cout<<vetor[i]<<",";
    }
    cout<<"]"<<endl;
    leComando(&dirigindo);
  }
  return 0;
}

int ex6() {
  
  float vetor[4] = {5,23,25,10};
  // "Direita", "Esquerda", "Frente", "Tras"
  dirige(vetor);
  cout<<"posição final:"<<endl<<"[";
  for (int i = 0; i<4; i++){
    cout<<vetor[i]<<",";
  }
  cout<<"]"<<endl;
  
  return 0;
}





//fuções main() para teste individuald de cada exercicio:

/*int main(){
  ex1();
}*/

/*int main(){
  ex2();
}*/

/*int main(){
  ex3();
}*/

/*int main(){
  ex4();
}*/

/*int main(){
  ex5();
}*/

/*int main(){
  ex6();
}*/

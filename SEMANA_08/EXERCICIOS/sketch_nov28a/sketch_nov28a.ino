#include <WiFi.h>
#define LR1 19
#define LR2 21
#define LR3 48
#define LR4 0
#define LR5 1
#define LR6 1
#define LR7 1
#define LR8 1
#define LR9 1
#define LA1 20
#define LA2 47
#define LA3 45
#define LA4 35
#define LA5 1
#define LA6 1
#define LA7 1
#define LA8 1
#define LA9 1

const char* ssid = "Inteli-COLLEGE";
const char* password = "QazWsx@123";
WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  pinMode(LA1,OUTPUT);
  pinMode(LA2,OUTPUT);
  pinMode(LA3,OUTPUT);
  pinMode(LA4,OUTPUT);
  pinMode(LA5,OUTPUT);
  pinMode(LA6,OUTPUT);
  pinMode(LA7,OUTPUT);
  pinMode(LA8,OUTPUT);
  pinMode(LA9,OUTPUT);
  pinMode(LR1,OUTPUT);
  pinMode(LR2,OUTPUT);
  pinMode(LR3,OUTPUT);
  pinMode(LR4,OUTPUT);
  pinMode(LR5,OUTPUT);
  pinMode(LR6,OUTPUT);
  pinMode(LR7,OUTPUT);
  pinMode(LR8,OUTPUT);
  pinMode(LR9,OUTPUT);

  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
  // put your setup code here, to run once:

}

int vermelho = 0;
int azul = 0;
int N1 = 0;
int N2 = 0;
int N3 = 0;
int N4 = 0;
int N5 = 0;
int N6 = 0;
int N7 = 0;
int N8 = 0;
int N9 = 0;

int vez = 0;
int pA = 0;
int pR = 0;

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("\
             <table>\
              <tr>\
                <td><a href=\"/A1\">A</a><a href=\"/R1\">R</a></td>\
                <td><a href=\"/A2\">A</a><a href=\"/R2\">R</a></td>\
                <td><a href=\"/A3\">A</a><a href=\"/R3\">R</a></td>\
              </tr>\
              <tr>\
                <td><a href=\"/A4\">A</a><a href=\"/R4\">R</a></td>\
                <td><a href=\"/A5\">A</a><a href=\"/R5\">R</a></td>\
                <td><a href=\"/A6\">A</a><a href=\"/R6\">R</a></td>\
              </tr>\
              <tr>\
                <td><a href=\"/A7\">A</a><a href=\"/R7\">R</a></td>\
                <td><a href=\"/A8\">A</a><a href=\"/R8\">R</a></td>\
                <td><a href=\"/A9\">A</a><a href=\"/R9\">R</a></td>\
              </tr>\
             </table>\
            ");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /R1") && N1 == 0  && vez == 0) {
          N1 = 1;
          vez = 1;
          digitalWrite(LR1,HIGH);
          pR += 1;
        }
        if (currentLine.endsWith("GET /R2") && N2 == 0  && vez == 0) {
          N2 = 1;
          vez = 1;
          digitalWrite(LR2,HIGH);
          pR += 2;
        }
        if (currentLine.endsWith("GET /R3") && N3 == 0  && vez == 0) {
          N3 = 1;
          vez = 1;
          digitalWrite(LR3,HIGH);
          pR += 4;
        }
        if (currentLine.endsWith("GET /R4") && N4 == 0  && vez == 0) {
          N4 = 1;
          vez = 1;
          digitalWrite(LR4,HIGH);
          pR += 8;
        }
        if (currentLine.endsWith("GET /R5") && N5 == 0  && vez == 0) {
          N5 = 1;
          vez = 1;
          digitalWrite(LR5,HIGH);
          pR += 16;
        }
        if (currentLine.endsWith("GET /R6") && N6 == 0  && vez == 0) {
          N6 = 1;
          vez = 1;
          digitalWrite(LR6,HIGH);
          pR += 32;
        }
        if (currentLine.endsWith("GET /R7") && N7 == 0  && vez == 0) {
          N7 = 1;
          vez = 1;
          digitalWrite(LR7,HIGH);
          pR += 64;
        }
        if (currentLine.endsWith("GET /R8") && N8 == 0  && vez == 0) {
          N8 = 1;
          vez = 1;
          digitalWrite(LR8,HIGH);
          pR += 128;
        }
        if (currentLine.endsWith("GET /R9") && N9 == 0  && vez == 0) {
          N9 = 1;
          vez = 1;
          digitalWrite(LR9,HIGH);
          pR += 256;
        }
//-----------------------------------------------------------------------//
        if (currentLine.endsWith("GET /A1") && N1 == 0  && vez == 1) {
          N1 = 1;
          vez = 0;
          digitalWrite(LA1,HIGH);
          pA += 1;
        }
        if (currentLine.endsWith("GET /A2") && N2 == 0  && vez == 1) {
          N2 = 1;
          vez = 0;
          digitalWrite(LA2,HIGH);
          pA += 2;
        }
        if (currentLine.endsWith("GET /A3") && N3 == 0  && vez == 1) {
          N3 = 1;
          vez = 0;
          digitalWrite(LA3,HIGH);
          pA += 4;
        }
        if (currentLine.endsWith("GET /A4") && N4 == 0  && vez == 1) {
          N4 = 1;
          vez = 0;
          digitalWrite(LA4,HIGH);
          pA += 8;
        }
        if (currentLine.endsWith("GET /A5") && N5 == 0  && vez == 1) {
          N5 = 1;
          vez = 0;
          digitalWrite(LA5,HIGH);
          pA+= 16;
        }
        if (currentLine.endsWith("GET /A6") && N6 == 0  && vez == 1) {
          N6 = 1;
          vez = 0;
          digitalWrite(LA6,HIGH);
          pA+=32;
        }
        if (currentLine.endsWith("GET /A7") && N7 == 0  && vez == 1) {
          N7 = 1;
          vez = 0;
          digitalWrite(LA7,HIGH);
          pA+=64;
        }
        if (currentLine.endsWith("GET /A8") && N8 == 0  && vez == 1) {
          N8 = 1;
          vez = 0;
          digitalWrite(LA8,HIGH);
          pA+=128;
        }
        if (currentLine.endsWith("GET /A9") && N9 == 0  && vez == 1) {
          N9 = 1;
          vez = 0;
          digitalWrite(LA9,HIGH);
          pA+=256;
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
    if (pA == 7||pA ==56||pA ==73||pA ==84||pA ==146||pA ==273||pA ==292||pA ==448 ){
//A wins
    }
    if (pR == 7||pR ==56||pR ==73||pR ==84||pR ==146||pR ==273||pR ==292||pR ==448){
//R wins
    }
  }

  // put your main code here, to run repeatedly:

}

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define led_red 12
#define led_green 10
#define led_yellow 3
#define led_blue 17
#define ldr 2
#define button1 13
#define button2 21
#define buzzer 38

const int tamanhoMaximo = 20;
string valorMedidas[tamanhoMaximo];
//variáveis responsáveis por salvar o o estado do botão(high e low)
int button1_read;
int button2_read;

int aux = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
// função que rotulariza em um intervalo de 1 a 15 os valores lidos pelo sensor ldr
int label(int read) {
  int numero = (read * 15) / 4095;
  return numero;
}
//função que transforma os valores já convertidos de 1 a 15 para números binários de 0001 a 1111
string bin(int n) {

  string r;
  while (n != 0) {
    r += (n % 2 == 0 ? "0" : "1");
    n /= 2;
  }
  return r;
}
//função que será acioanada toda vez que o botão de guardar valor(botão 1) for ligado
//ela guarda o valor em binario lido pelo ldr no vetor valorMedidas e aciona leds e buzzer conforme o número lido
void guardaValor(string leituraBin) {
  if (button1_read == LOW) {
    valorMedidas[aux] = leituraBin;
    aux += 1;
    if (leituraBin == "0001") {
      digitalWrite(led_blue, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 600, 1000);
      delay(1000);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);

    } 
    else if (leituraBin == "0010") {
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 700, 1000);
      delay(1000);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);

    } 
    else if (leituraBin == "0011") {
      digitalWrite(led_blue, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 800, 1000);
      delay(1000);
      digitalWrite(led_blue, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "0100") {
      digitalWrite(led_green, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 900, 1000);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(buzzer, LOW);

    } 
    else if (leituraBin == "0101") {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_blue, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1000, 1000);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "0110") {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1100, 1000);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);
    }
    else if (leituraBin == "0111") {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_blue, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1200, 1000);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1000") {
      digitalWrite(led_red, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1300, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1001") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_blue, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1400, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1010") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1500, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1011") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_blue, HIGH);
      tone(buzzer, 1600, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1100") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1700, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1101") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, HIGH);
      digitalWrite(led_blue, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1800, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if (leituraBin == "1110") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 1900, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(buzzer, LOW);
    } 
    else if(leituraBin == "1111") {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_blue, HIGH);
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 2000, 1000);
      delay(1000);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_blue, LOW);
      digitalWrite(buzzer, LOW);
    }
    else{
      tone(buzzer,500, 1000);
    }
  }
}
//função que será executada toda vez que o botão reproduzir(botão 2) for acionado
//pega cada elemento do vetor valorMedidas por meio do for e utiliza para acender o led e tocar o buzzer correspondente a esse elemento
void play() {
  if (button2_read == LOW) {
    for (int i = 0; i < aux ; i++) {
      if (valorMedidas[i] != "") {
        if (valorMedidas[i] == "0001") {
          digitalWrite(led_blue, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 600, 1000);
          delay(1000);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0010") {
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 700, 1000);
          delay(1000);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0011") {
          digitalWrite(led_blue, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 800, 1000);
          delay(1000);
          digitalWrite(led_blue, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0100") {
          digitalWrite(led_green, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 900, 1000);
          delay(1000);
          digitalWrite(led_green, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0101") {
          digitalWrite(led_green, HIGH);
          digitalWrite(led_blue, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1000, 1000);
          delay(1000);
          digitalWrite(led_green, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0110") {
          digitalWrite(led_green, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1100, 1000);
          delay(1000);
          digitalWrite(led_green, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "0111") {
          digitalWrite(led_green, HIGH);
          digitalWrite(led_blue, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1200, 1000);
          delay(1000);
          digitalWrite(led_green, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1000") {
          digitalWrite(led_red, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1300, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1001") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_blue, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1400, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1010") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1500, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1011") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(led_blue, HIGH);
          tone(buzzer, 1600, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1100") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_green, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1700, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_green, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1101") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_green, HIGH);
          digitalWrite(led_blue, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1800, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_green, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if (valorMedidas[i] == "1110") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_green, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 1900, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_green, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(buzzer, LOW);
        } 
        else if(valorMedidas[i] == "1111") {
          digitalWrite(led_red, HIGH);
          digitalWrite(led_green, HIGH);
          digitalWrite(led_yellow, HIGH);
          digitalWrite(led_blue, HIGH);
          digitalWrite(buzzer, HIGH);
          tone(buzzer, 2000, 1000);
          delay(1000);
          digitalWrite(led_red, LOW);
          digitalWrite(led_green, LOW);
          digitalWrite(led_yellow, LOW);
          digitalWrite(led_blue, LOW);
          digitalWrite(buzzer, LOW);
        }
        else{
          tone(buzzer,500, 1000);
        }
      }
      else{
        tone(buzzer,500, 1000);
      }
      //limpa os valore salvos no vetor valorMedidas para que novos valores sejam salvos
      delay(1000);
      valorMedidas[i] = "";
    }
  aux=0;
  }
}
// the loop function runs over and over again forever
void loop() {

  button1_read = digitalRead(button1);
  button2_read = digitalRead(button2);

  int ldr_value = label(analogRead(ldr));

  string binary = bin(ldr_value);
  guardaValor(binary);
  play();
  delay(500);
}
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#define LED_GREEN 5
#define LED_RED 2
#define buzzer 18


const char *ssid = "ESPJordan";
const char *password = "jordan123";

WebServer server(80);
void setup() {
pinMode(LED_GREEN, OUTPUT);
pinMode(LED_RED, OUTPUT);
Serial.begin(115200);

WiFi.softAP(ssid,password);
IPAddress myIP = WiFi.softAPIP();
Serial.print("SSID: ");
Serial.println(ssid);
Serial.print("AP IP address: ");
Serial.println(myIP);
server.begin();
Serial.println("Servidor Iniciado");

server.on("/",handleRoot);
server.on("/resultadoX/",handleRed);
server.on("/resultadoO/",handleGreen);
server.on("/velha/",handleVelha);
server.begin();
Serial.println("HTTP server strated");
}

void handleRoot(){
String html = "";
html+="<!DOCTYPE html> ";
html+="<html>";
html+="<head>";
html+=" <meta charset=\"UTF-8\"> ";
html+=" <title>Jogo da velha</title>";
html+="</head> ";
html+="<body>";
html+="<main>";
html+=" <h1>Jogo da velha</h1>";
html+=" <hr />";
html+=" <div class=\"game\"> ";
html+="   <button data-i=\"1\"></button>";
html+="   <button data-i=\"2\"></button>";
html+="   <button data-i=\"3\"></button>"; 
html+="   <button data-i=\"4\"></button>";
html+="   <button data-i=\"5\"></button>";
html+="   <button data-i=\"6\"></button>";
html+="   <button data-i=\"7\"></button>";
html+="   <button data-i=\"8\"></button>";
html+="   <button data-i=\"9\"></button>";
html+="   </div>";
html+="   <h2 class='currentPlayer'></h2>";
html+="   <a href=\'/velha/\'class='restart'>REINICIAR</a>";
html+="   </main>";
html+="   <script>";
html+="      const currentPlayer = document.querySelector('.currentPlayer');";
html+="      let selected;";
html+="      let player = 'X';";
html+="      let positions = [";
html+="           [1,2,3],";
html+="           [4,5,6],";
html+="           [7,8,9],";
html+="           [1,4,7],";
html+="           [2,5,8],";
html+="           [3,6,9],";
html+="           [1,5,9],";
html+="           [3,5,7],";
html+="     ];";
html+="       function init(){";
html+="            selected = [];";            
html+="            currentPlayer.innerHTML= `JOGADOR DA VEZ: ${player}`;";
html+="            document.querySelectorAll('.game button').forEach((item)=>{";
html+="                item.innerHTML = '';";
html+="                item.addEventListener('click',newMove);";
html+="            });";
html+="        }";
html+="        init();";
html+="       function newMove(e){";
html+="            const index = e.target.getAttribute('data-i');";
html+="            e.target.innerHTML = player;";
html+="            e.target.removeEventListener('click',newMove);";
html+="            selected[index] = player;";
html+="            setTimeout(() =>{";
html+="               check();";
html+="            },[100]);";
html+="            player = player === 'X' ? 'O' : 'X';";
html+="            currentPlayer.innerHTML = `JOGADOR DA VEZ: ${player}`;";
html+="        }";
html+="        function check(){";
html+="            let playerLastMove = player === 'X' ? 'O' : 'X';";
html+="            const items = selected";
html+="                .map((item,i)=>[item,i])";
html+="                .filter((item)=>item[0]=== playerLastMove)";
html+="                .map((item)=>item[1]);";
html+="            for(pos of positions){";
html+="                if (pos.every((item)=>items.includes(item))){";
html+="                    if(playerLastMove=='X'){";
html+="                        window.open('http://192.168.4.1/resultadoX/');";
html+="                    }   ";
html+="                    else if(playerLastMove=='O'){";
html+="                        window.open('http://192.168.4.1/resultadoO/');";
html+="                    }";
html+="                    else{";
html+="                        window.open('http://192.168.4.1/velha/');";
html+="                    }";
html+="                    alert('O JOGADOR '+playerLastMove+' GANHOU!');";
html+="                    init();";
html+="                    return;";
html+="                }";
html+="            }";
html+="        }";
html+="    </script>";
html+="    <style>";
html+="        *{";
html+="            margin:0;";
html+="            padding:0;";
html+="            box-sizing:border-box;";
html+="            font-family:cursive;";
html+="        }";
html+="        body{";
html+="            height:100vh;";
html+="            display:flex;";
html+="            align-items:center;";
html+="            justify-content:center;";
html+="            background-image:#f7f7f7;";
html+="        }";
html+="        main{";
html+="            display:flex;";
html+="            flex-direction:column;";
html+="            gap:5px;";
html+="        }";
html+="        h1{";
html+="            text-align:center;";
html+="        }";
html+="        hr{";
html+="            font-weight:bold;";
html+="            height:3px;";
html+="            background:black;";
html+="            margin-bottom:10px;";
html+="        }";
html+="        .game{";
html+="            display:grid;";
html+="            grid-template-columns:1fr 1fr 1fr;";
html+="        }";
html+="        .game button{";
html+="            width:100px;";
html+="            height:100px;";
html+="            margin:5px;";
html+="            cursor:pointer;";
html+="            font-size:50px;";
html+="            background:white;";
html+="        }";
html+="    </style>";
html+="</body>";
html+="</html>";

  server.send(200,"text/html", html);
}

void handleRed(){
  digitalWrite(LED_RED,HIGH);
  tone(buzzer,500,500);
  delay(2000);
  handleTurnOff();
  handleRoot();
}

void handleGreen(){
  digitalWrite(LED_GREEN,HIGH);
  tone(buzzer,500,500);
  delay(2000);
  handleTurnOff();
  handleRoot();
}

void handleVelha(){
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_RED,HIGH);
  tone(buzzer,600,500);
  delay(2000);
  handleTurnOff();  
  handleRoot();
}

void handleTurnOff(){
  digitalWrite(LED_GREEN,LOW);
  digitalWrite(LED_RED,LOW);
  handleRoot();
}

void loop() {
server.handleClient();
delay(2);
}
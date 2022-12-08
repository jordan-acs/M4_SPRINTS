#include <LiquidCrystal_I2C.h>

#define sda 4
#define scl 5

String senha;
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
// Function to scroll text
// The function acepts the following arguments:
// row: row number where the text will be displayed
// message: message to scroll
// delayTime: delay between each character shifting
// lcdColumns: number of columns of your LCD
void setup(){
  // initialize LCD
  Serial.begin(115200);
  Wire.begin(sda, scl);
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  
  Serial.println("Digite a senha que você gostaria de salvar: ");
  while (Serial.available() == 0) {}  
  senha = Serial.readString();
  Serial.print("A senha salva é: " + senha);

}


void loop(){
  #ifdef RGB_BUILTIN
  
  Serial.println("Digite a senha correta:");
  while (Serial.available() == 0) {}
  
  String senha_correta = Serial.readString();  //read until timeout
  Serial.println("A senha digitada foi: " + senha_correta);

  if (senha_correta == senha) {
    Serial.println("Senha correta");
    lcd.setCursor(0, 0);
    lcd.print("Senha Correta :D");

    neopixelWrite(RGB_BUILTIN,0,RGB_BRIGHTNESS,0); // Green
    delay(1000);
    
    delay(3000);
    lcd.clear();
  }
  else {
    Serial.println("Senha incorreta");
    lcd.setCursor(0, 0);
    lcd.print("Incorreta :( ");
    neopixelWrite(RGB_BUILTIN,RGB_BRIGHTNESS,0,0); // Red      delay(1000);
    delay(3000);
    lcd.clear();
  }
     
  #endif
  
}


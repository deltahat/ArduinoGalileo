#include <rgb_lcd.h>

rgb_lcd lcd;

char input = ' ';

void setup() {
  // put your setup code here, to run once:
  //inicializar puerto serie con velocidad 9600 baudios
  Serial.begin(9600);
  bienvenida();
    
}
void bienvenida(){
  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Bienvenido");
    delay(2500);
    lcd.clear();
    //no olvidar
    pinMode(6,OUTPUT);
   
    
    
  }
//en realidad usar el puerto serie no es recomendable
void menu(char c){
    int val;
    
    Serial.println(F("Ingrese una b: "));
    Serial.println(F("A - Estado 0: null"));
    Serial.println(F("B - Estado 1: Variar luminosidad. "));
    Serial.println(F("C - Estado 2: Barrido servo. "));
    
    switch(c){
    //sistema no realiza ninguna acción
    case 'A': 
    lcd.print("0");
    lcd.println("Temperatura: ");
    
    break;
    
    //utilizar potenciometro para ajustar luz led
    case 'B': 
      val=map(analogRead(A3),0,4095,0,255);
      analogWrite(6,val);
      lcd.print(val);
      
      
    break;
    
    //barrido servo
    case 'C':
    break;

    //mostrar mensaje de error en el led
    default:
    //se guarda la cadena de caracteres en la memoria flash
    lcd.print(Serial.println(F("ERROR")));
    break;
    }
    
  
  
  }
void loop() {
  // put your main code here, to run repeatedly:
 
 if(Serial.available()>0){
    input = Serial.read();
    menu(input);
    
    }
}

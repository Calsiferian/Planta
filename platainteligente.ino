float vref = 3.3;
float resolution = vref/1023;
 float temperatura;

 
const int ROJO = 16;
const int VERDE = 5;
const  int AZUL = 2;
const  int PARLANTE = 0;

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
   pinMode(PARLANTE, OUTPUT);
 Serial.begin(9600);  /* Define baud rate for serial communication */
}

void loop() {
sensartemperatura();
EncenderFrio();
EncenderTibio();
EncenderCaliente();
ApagarLed();
Hablar();
  /*
   * if(temperatura>= Yvalor){
   * EncenderCaliente();
   * Hablar();
   * }
   * if(temperatura> Xvalor && temperatura<Yvalor)
   * EncenderTibio();
   * if(temperatura<= Zvalor)
   * EncenderFrio();
   */
}



/*-------------------------------------------------------------------------
 * Lista de Funciones
 * sensartemperatura(); Siente cuanta tempratura existe.
 * EncenderFrio();      Enciende el led de color azul.
 * EncenderTibio();     Enciende el led de color Amarillo.
 * EncenderCaliente();  Enciende el led de color rojo.
 * ApagarLed();         Apaga el led.
 * Hablar();
 * ----------------------------------------------------------------------------
 */

void sensartemperatura(){
 temperatura = analogRead(A0);
 temperatura = (temperatura*resolution);
 temperatura = temperatura*100;
 Serial.println(temperatura);
 delay(1000);
  }
void EncenderFrio(){
  digitalWrite(AZUL,HIGH);
  digitalWrite(ROJO,LOW);
  digitalWrite(VERDE,LOW);
  }

void EncenderTibio(){
   digitalWrite(AZUL,LOW);
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE,HIGH);
  }
void EncenderCaliente(){
    digitalWrite(AZUL,LOW);
  digitalWrite(ROJO,HIGH);
  digitalWrite(VERDE,LOW);
  }
void ApagarLed(){
  digitalWrite(AZUL,LOW);
  digitalWrite(ROJO,LOW);
  digitalWrite(VERDE,LOW);
  
  }
void Hablar(){
  
  tone(PARLANTE,500);
  delay(200);
 noTone(PARLANTE);
  }



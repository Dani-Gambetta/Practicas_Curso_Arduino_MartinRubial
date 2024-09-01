/* TAREA 1 - CURSO ARDUINO - MARTIN RUBIAL-

En este codigo vamos a encender leds segun el valor mapeado de un pote.
Los leds van a parpadear y cuando lleguemos al final de la escala van a hacer un juego de rebote
Todo esto usando condicionales "if" "else" y "else if" */


int potPin = A1;  //asignamos entrada analog para pote
int PotVal; //asignamos nombre al valor que vamos a leer y mapear del pote
// asignamos los pines para los Leds
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int dt = 50;  //asignamos una variable de tiempo
int Bot= A0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  //inicializamos monitor
  //declaramos que los pines para los Led son salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(potPin, INPUT);  //declaramos entrada analogica
}

void loop() {
  // put your main code here, to run repeatedly:
  int Pote = analogRead(potPin);                         //leemos el valor del pote
  int PotVal = map(Pote, 0, 1023, 0, 255);  //le damos a la variable PotVal el esultadodel mapeodel pote

  // imprimimos en el monitor el valor PotVal
  Serial.print( "PotVal  ");
  Serial.println(PotVal);
  //Serial.print("Pote ");
  //Serial.println(Pote); //usamos el monitor serial para verificar funciones
  delay(dt);

  /*vamos a iniciar condicionales para los diferentes valores, vamos de a 50 para tener 5 estados */

  if (PotVal <= 50) {  //primer condicion para un valor menor o igual a 50
    digitalWrite(led1, 1); // En digitalWrite escrbir 1 equibale a HIGH y 0 a LOW
    delay(dt);
    digitalWrite(led1, 0);
    delay(dt);
  } else if (PotVal > 50){ 
    digitalWrite(led1, 1);  //nos aseguramos de que el led apague cuando el valor es mayor a 50
  }
  if (PotVal >= 51 && PotVal <= 100) {  //segunda condicion para valor entre 51 y 100
    digitalWrite(led2, 1);
    delay(dt);
    digitalWrite(led2, 0);
    delay(dt);
  } else if (PotVal > 100){
    digitalWrite(led2, 1);  //apagado por fuera de la condicion
  }
  if (PotVal >= 101 && PotVal <= 150) {  //tercera condicion para valor entre 101 y 150
    digitalWrite(led3, 1);
    delay(dt);
    digitalWrite(led3, 0);
    delay(dt);
  }else if (PotVal > 150) {
    digitalWrite(led3, 1);  //apagado por fuera de la condicion
  }
  if (PotVal >= 151 && PotVal <= 200) {  //cuarta condicion para valor entre 51 y 200
    digitalWrite(led4, 1);
    delay(dt);
    digitalWrite(led4, 0);
    delay(dt);
  } else if (PotVal > 200){
    digitalWrite(led4, 1);  //apagado por fuera de la condicion
  }
  if (PotVal >= 201 && PotVal <= 240) {  //quinta condicion para valor entre 201 y 240 (vamos hasta 240 asi podemos poner una sexta condicion para valores entr 240 y 255)
    digitalWrite(led5, 1);
    delay(dt);
    digitalWrite(led5, 0);
    delay(dt);
  } else if (PotVal > 240){
    digitalWrite(led5, 0);  //apagado de todos los led por fuera de la condicion
    digitalWrite(led4, 0);
    digitalWrite(led3, 0);
    digitalWrite(led2, 0);
    digitalWrite(led1, 0);
  }
   if (PotVal >= 241) {  ////Condicion de juego de leds para valores mayores a 241
    digitalWrite(led5, 1);
    delay(dt);
    digitalWrite(led5, 0);
    delay(dt);

    digitalWrite(led4, 1);
    delay(dt);
    digitalWrite(led4, 0);
    delay(dt);

    digitalWrite(led3, 1);
    delay(dt);
    digitalWrite(led3, 0);
    delay(dt);

    digitalWrite(led2, 1);
    delay(dt);
    digitalWrite(led2, 0);
    delay(dt);

    digitalWrite(led1, 1);
    delay(dt);
    digitalWrite(led1, 0);
    delay(dt);

    digitalWrite(led2, 1);
    delay(dt);
    digitalWrite(led2, 0);
    delay(dt);

    digitalWrite(led3, 1);
    delay(dt);
    digitalWrite(led3, 0);
    delay(dt);

    digitalWrite(led4, 1);
    delay(dt);
    digitalWrite(led4, 0);
    delay(dt);
  }
}

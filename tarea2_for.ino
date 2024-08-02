/* Tarea 2 - CURSO ARDUINO MARTIN RUBIAL

Con este codigo vamo a utilizar cilcos for para subir y bajar el brillo de los Leds analogicamente con pwm.
El codigo lee el valor de un POT y lo mapea. A ese map lo dividimos en 5 partes para repartirlas entre los Leds y con una etapa final de "emergencia" en la que prende todos.
Los Leds se conectan a las salidas pwm 5, 6, 9, 10, y 11, sienso este ultimo definido como "led1" y el pin 5 como "led5".
El Pote esta conectado al Pin analogico A1*/
/*--------------------------------------------------*/
int potPin = A1;  //asignamos entrada analog para pote
int PotVal;       //asignamos nombre al valor que vamos a leer y mapear del pote

// asignamos los pines para los Leds, son pines con salida PWM
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 6;
int led5 = 5;
int dt = 50;  //asignamos una variable de tiempo para cuando la nececitemos. Por si queremos modificarla, la cambiamos solo aca

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  //inicializamos monitor para futuras comprobaciones
  //declaramos que los pines para los Led son salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(potPin, INPUT);  //declaramos entrada analogica, aunque no es necesario pero me gusta para no dudar
}

void loop() {
  // put your main code here, to run repeatedly:
  int Pote = analogRead(potPin);            //leemos el valor del pote
  int PotVal = map(Pote, 0, 1023, 0, 255);  //le damos a la variable PotVal el resultado del mapeo del pote

  // imprimimos en el monitor el valor PotVal
  Serial.print("PotVal  ");
  Serial.println(PotVal);
  //Serial.print("Pote ");
  //Serial.println(Pote); //estas lineas son para verificaciones y prueba, pueden comentarce o descomentarce para uasrlas, no modifican el programa
  delay(dt); 

  /*vamos a iniciar condicionales para los diferentes valores, vamos de a 50 para tener 5 estados */

  if (PotVal <= 50) {  //primer condicion para un valor menor o igual a 50
     //aca usamos una variable "i" solo como un caracter al que le vamos a asignar un valor, puede usarce otra letra
    for (int i = 0; i <= 255; i++) { //aca dijimos "para i = 0 mientras sea <= a 255 vamos a sumarle 1 a i"
      analogWrite(led1, i); //aca le decimos que le de al pwm el valor de i (que es de 0 a 255)
      delay(1);   
    }
    for (int i = 255; i >= 0; i--) { //esto es lo mismo que el paso anterior pero inverso, cuando i vale 255 vamos a restarte de a uno hasta llegar a 0
      analogWrite(led1, i); //aca le decimos que le de al pwm el valor de i (que es de 255 a 0)
      delay(1);
    }  //nos aseguramos de que el led apague cuando el valor es mayor a 50
  }
  if (PotVal >= 51 && PotVal <= 100) {  //segunda condicion para valor entre 51 y 100
    for (int i = 0; i <= 255; i++) {
      analogWrite(led2, i);
      delay(1);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(led2, i);
      delay(1);  
    }
  }
    if (PotVal >= 101 && PotVal <= 150) {  //tercera condicion para valor entre 101 y 150
       for (int i = 0; i <= 255; i++) {
      analogWrite(led3, i);
      delay(1);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(led3, i);
      delay(1);  
    }
  }
    if (PotVal >= 151 && PotVal <= 200) {  //cuarta condicion para valor entre 51 y 200
       for (int i = 0; i <= 255; i++) {
      analogWrite(led4, i);
      delay(1);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(led4, i);
      delay(1);  
    }
  }
    if (PotVal >= 201 && PotVal <= 255) {  //quinta condicion para valor entre 201 y 240 (vamos hasta 240 asi podemos poner una sexta condicion para valores entr 240 y 255)
       for (int i = 0; i <= 255; i++) {
      analogWrite(led5, i);
      delay(1);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(led5, i);
      delay(1);  
    }
  }
  
  }

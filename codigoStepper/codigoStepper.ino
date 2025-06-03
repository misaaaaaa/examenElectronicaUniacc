//CONEXIONES arduino -> Driver
// ARD 2 - IN 1
// ARD 3 - IN 2
// ARD 4 - IN 3
// ARD 5 - IN 4
//SALIDAS DEL ARDUINO AL PASO A PASO
int out1 = 2;
int out2 = 3;
int out3 = 4;
int out4 = 5;

int tiempo = 5;    // TIEMPO ENTRE PASOS
int direccion = 1;  // 0 = detenido, -1 para un lado, 1 para el otro

void setup() {
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
}

void loop() {

  if (direccion == -1) {
    paso1();  //UTILIZO LA FUNCION ANTES CREADA
    delay(tiempo);
    paso2();
    delay(tiempo);
    paso3();
    delay(tiempo);
    paso4();
    delay(tiempo);
  }

  if (direccion == 1) {
    paso4();  //UTILIZO LA FUNCION ANTES CREADA
    delay(tiempo);
    paso3();
    delay(tiempo);
    paso2();
    delay(tiempo);
    paso1();
    delay(tiempo);
  }
  if (direccion == 0) {
    digitalWrite(out1, LOW);  // APAGA TODAS
    digitalWrite(out2, LOW);  
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
  }
}

//DECLARO LAS FUNCIONES ACA ABAJO

void paso1() {
  digitalWrite(out1, HIGH);  //PRENDE PRIMERA SALIDA
  digitalWrite(out2, LOW);   // APAGO EL RESTO
  digitalWrite(out3, LOW);
  digitalWrite(out4, LOW);
}

void paso2() {
  digitalWrite(out1, LOW);   //PRENDE SEGUNDA SALIDA
  digitalWrite(out2, HIGH);  // APAGO EL RESTO
  digitalWrite(out3, LOW);
  digitalWrite(out4, LOW);
}

void paso3() {
  digitalWrite(out1, LOW);  //PRENDE TERCERA SALIDA
  digitalWrite(out2, LOW);  // APAGO EL RESTO
  digitalWrite(out3, HIGH);
  digitalWrite(out4, LOW);
}

void paso4() {
  digitalWrite(out1, LOW);  //PRENDE CUARTA SALIDA
  digitalWrite(out2, LOW);  // APAGO EL RESTO
  digitalWrite(out3, LOW);
  digitalWrite(out4, HIGH);
}

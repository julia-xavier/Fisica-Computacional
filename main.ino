/*Programa destinado ao estudo de Cinemática. 
O programa detecta a velocidade de um objeto através de três sensores infravermelho*/

#define ledVerde 7 // O LED verde deverá ser ligado no pino digital 7
#define ledVermelho 6 // O LED vermelho deverá ser ligado no pino digital 6
#define sensorUM 2 // Configura o pino digital 2 para o PRIMEIRO SENSOR
#define sensorDOIS 3 // Configura o pino digital 3 para o SEGUNDO SENSOR
#define sensorTRES 4 // Configura o pino digital 4 para o TERCEIRO SENSOR

int estadoUM; // variável que guarda estado do primeiro sensor 
int estadoDOIS; // variável que guarda estado do segundo sensor 
int estadoTRES; // variável que guarda estado do terceiro sensor 
long interTempoUM ; // tempo decorrido no primeiro intervalo
long interTempoDOIS ; // tempo decorrido no segundo intervalo
long instanteUM = 0; // tempo total decorrido desde que o programa foi executado
long instanteDOIS = 0; // tempo total decorrido desde que o programa foi executado
long instanteTRES= 0; // tempo total decorrido desde que o programa foi executado
long velocidadeUM = 0;
long velocidadeDOIS = 0;
long deslocamentoUM = 500; // distancia sugerida em milimetro entre sensor 1 e 2. Mude a medida se for conveniente 
long deslocamentoDOIS = 500; // distancia sugerida em milimetro entre sensor 2 e 3. Mude a medida se for conveniente
long tempoTotal;

void setup(){ 
  Serial.begin(9600); 
  Serial.println("Introdução a Computação em Física");
  delay(2000); //Pausa de 2 segundos
  Serial.println("INICIE O EXPERIMENTO:");
  delay(1000); //Pausa de 1 segundos 
  pinMode(ledVermelho, OUTPUT); // Configura o pino 6 como saída
  pinMode(ledVerde, OUTPUT); // Configura o pino 7 como saída
  pinMode(sensorUM, INPUT); // Configura o pino 2 como entrada
  pinMode(sensorDOIS, INPUT); // Configura o pino 3 como entrada
  pinMode(sensorTRES, INPUT); // Configura o pino 4 como entrada
  digitalWrite(ledVermelho, LOW); // desliga LED vermelho
  digitalWrite(ledVerde, LOW); // desliga LED verde
} 

void loop(){ 
  estadoUM = digitalRead(sensorUM); // Ler o sensor UM e armazena em estadoUM 

  if(estadoUM == LOW){ 
    digitalWrite(ledVerde, HIGH); // Liga o LED VERDE 
    digitalWrite(ledVermelho, LOW); // desliga o LED VERMELHO 
    instanteUM = millis(); // armazena o tempo Total decorrido para Sensor UM 
  }
  else{
    digitalWrite(ledVerde, LOW); // desliga o lED VERDE e VERMELHO
    digitalWrite(ledVermelho, LOW); 
  }

  estadoDOIS = digitalRead(sensorDOIS); // Ler o sensor DOIS e armazena em estadoDOIS

  if(estadoDOIS == LOW){
    digitalWrite(ledVerde, LOW); // desliga LED verde
    digitalWrite(ledVermelho, HIGH); // liga LED vermelho
    instanteDOIS = millis(); // armazena o tempo Total decorrido para Sensor DOIS
    interTempoUM = (instanteDOIS - instanteUM); // cálculo do primeiro intervalo de tempo
    velocidadeUM = deslocamentoUM/interTempoUM; // calculo da velocidade média entre 1 e 2 sensor 
  }
  else{
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledVermelho, LOW); //desliga os LED verde e Vermelho 
  }

  estadoTRES = digitalRead(sensorTRES); // Ler o sensor TRÊS e armazena em estadoTRES

  if(estadoTRES == LOW) {
    digitalWrite(ledVerde, HIGH); // liga LED Verde
    digitalWrite(ledVermelho, HIGH); // liga LED Vermelho 
    instanteTRES = millis(); // armazena o tempo Total decorrido para Sensor TRÊS
    interTempoDOIS = (instanteTRES - instanteDOIS);
    velocidadeDOIS = deslocamentoDOIS/interTempoDOIS; // calculo da velocidade média entre 1 e 2 sensor
    tempoTotal = interTempoDOIS;
    Serial.print("Primeiro intervalo (ms) = ");
    Serial.println(interTempoUM);
    Serial.print("Segundo intervalo (ms) = ");
    Serial.println(interTempoDOIS);
    Serial.print("Velocidade Aproximada (em m/s) no sensor 2 V0 = ");
    Serial.println(velocidadeUM); // imprime no monitor serial o a velocidade entre sensor 1 e 2
    Serial.print("Velocidade Aproximada (em m/s) no sensor 3 V = ");
    Serial.println(velocidadeDOIS); // imprime no monitor serial o a velocidade entre sensor 2 e 3
    Serial.println("___________________");

    delay(tempoTotal); //tempo de espera para efetuar nova leitura
  }
  else{
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledVermelho, LOW); // desliga LED verde e Vermelho
  } 
}

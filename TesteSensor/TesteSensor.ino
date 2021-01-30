// Universidade Federal Rural de Pernambuco
// Trabalho de Conclusão de Curso
// 8º Semestre
// Discente: João Luiz da Silva Ramos
// Orientador: Obionor de Oliveira Nóbrega

#include <Ultrasonic.h>
#define pino_emi 2 // Pinagem conectada ao Arduíno do Trigger - HC-SR04 (emissor da onda sonora).
#define pino_rec 3 // Pinagem conectada ao Arduíno do Echo - HC-SR04 (receptor da onda sonora + tempo de retorno).
Ultrasonic Sensor (pino_emi, pino_rec); // Parâmetro da biblioteca Ultrasonic, que irá reconhecer os pinos Trigger e Echo
int led_vermelho = 11;
int led_amarelo = 12;
int led_verde = 13;

void setup() {
  pinMode (led_vermelho, OUTPUT);
  pinMode (led_amarelo, OUTPUT);
  pinMode (led_verde, OUTPUT);
  Serial.begin (9600); // Velocidade de bits por segundos. Tal transmissão de bits será exibida no monitor serial nessa velocidade.
  delay (500); // Tempo de espera para iniciar as funcionalidades do código.
  Serial.println ("Iniciando medições...");
}

void AcendeLEDVerde(){
  digitalWrite (led_verde, HIGH);
  digitalWrite (led_vermelho, LOW);
  digitalWrite (led_amarelo, LOW);
}

void AcendeLEDAmarelo(){
    digitalWrite (led_amarelo, HIGH);
  digitalWrite (led_verde, LOW);
  digitalWrite (led_vermelho, LOW);
}

void AcendeLEDVermelho(){
  digitalWrite (led_vermelho, HIGH);
  digitalWrite (led_verde, LOW);
  digitalWrite (led_amarelo, LOW);
}

// void EnviarOndaSonora(){
//   digitalWrite (pino_emi, HIGH);
//   delayMicroseconds (1000);
//   digitalWrite (pino_emi, LOW);
//}

void Distancia() {
  float dist, dist_m;
  long ms = Sensor.timing();
  dist = Sensor.convert(ms, Ultrasonic::CM); 
  dist_m = dist / 100; 

  if (dist >= 2000 && dist <= 3000){ // Condicional - regular precisão da medida de distância
    dist = dist - 0.03;
    dist_m = dist / 100;
  }

  if (dist > 3000 && dist <= 4000){ // Condicional - regular precisão da medida de distância
    dist = dist - 0.05;
    dist_m = dist / 100;
  }

  if (dist > 0 && dist <= 10) {
    AcendeLEDVermelho();
  } 
  if (dist > 10 && dist <= 20) {
    AcendeLEDAmarelo();
  }
  if (dist > 20 && dist <= 30) {
    AcendeLEDVerde();
  }
  
  Serial.println("-------------------------------");
  Serial.print("Distância em cm: ");
  Serial.println(dist);
  Serial.print("Distância em m: ");
  Serial.println(dist_m);
  Serial.println("-------------------------------");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Mede o tempo de duração do sinal no pino de leitura(us)
  Distancia();
}

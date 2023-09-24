/* definição das portas e do tamanho do focinho */
#define TRIGGER 6
#define ECHO 5
#define MOTOR 3
#define FOCINHO 10

/* declaração da variavel utilizada no codigo*/

float dist;

/* seção para configurar inicialmente o arduino*/

void setup()
{ 
  /* comando para o uso do monitor serial */
  Serial.begin(9600);
  /* portas que estao os sensores e motores e se sao de saida ou entrada*/
  
  pinMode(MOTOR, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

/* seção para dar as instruções que ficarão em loop infinito*/ 

void loop()
{
/* emissão da onda sonora e recepção*/
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  dist = pulseIn(ECHO, HIGH);
  
 /*transformando o valor recebido em cm*/
  dist = dist / 58;
  
/* comando para acompanhar os valores no monitor serial */
  Serial.print("distancia: ");
  Serial.print(dist);
  Serial.println("cm");

 /* se a distancia corresponder ao intervalo desejado, o motor eh ligado */
  
  if(dist > 8 && dist < FOCINHO + 20){
    digitalWrite(MOTOR, HIGH);
  	}else{
    digitalWrite(MOTOR, LOW);
	}
}

#include <Servo.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA

const int pinoServo = 3; //PINO DIGITAL UTILIZADO PELO SERVO 
Servo s; //OBJETO DO TIPO SERVO
int pos; //POSIÇÃO DO SERVO

//VARIAVEL QUE RECEBE DADOS BLUETOOTH
char comando;

void setup()
{
  //DEFININDO ENTRADAS E SAIDAS
 s.attach(pinoServo); //ASSOCIAÇÃO DO PINO DIGITAL AO OBJETO DO TIPO SERVO
 s.write(0); //INICIA O MOTOR NA POSIÇÃO 0º

  //INICIANDO A SERIAL
 Serial.begin(9600);
}

void loop()
{
  //CONTROLE
  while(Serial.available() > 0)
  {
    comando = Serial.read();
    
    switch (comando) 
    {
    case 'A':
    //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
       for(pos = 0; pos < 180; pos++)
       { 
          s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
          delay(15); //INTERVALO DE 15 MILISSEGUNDOS
       } 
      break;
    case 'B':
    //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
      for(pos = 180; pos >= 0; pos--)
      { 
         s.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
         delay(15); //INTERVALO DE 15 MILISSEGUNDOS
      }
      break;
    case 'C':
      
      break;
    case 'D':
      
      break;
    case 'E':
     
      break;
    case 'F':
 
      break;
    default: 
    
      break;
  }
  }
}

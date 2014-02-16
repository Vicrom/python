#define ADELANTE -1
#define IZQUIERDA -2
#define DERECHA -3
#define echoPin 0 
#define trigPin 1 
#define echoPinD 2 
#define trigPinD 4
#define echoPinI 5 
#define trigPinI 6
int pwm_a = 3;  
int pwm_b = 11;  
int dir_a = 12;  
int dir_b = 13;
long duration, distance;
long durationD, distanceD;
long durationI, distanceI;

void Velocidad(int sentido,int nPot)
{
  switch(sentido)
  {
  case ADELANTE:
    digitalWrite(dir_a, HIGH);  
    digitalWrite(dir_b, HIGH);  
    break;
  case IZQUIERDA:
    digitalWrite(dir_a, HIGH);  
    digitalWrite(dir_b, LOW);  
    break;
   case DERECHA:
    digitalWrite(dir_a, LOW);  
    digitalWrite(dir_b, HIGH);  
    break;
  }
  
  analogWrite(pwm_a, nPot);        
  analogWrite(pwm_b, nPot);
  
}
void setup()
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);
  pinMode(trigPinI, OUTPUT);
  pinMode(echoPinI, INPUT);
  analogWrite(pwm_a, 0);        
  analogWrite(pwm_b, 0);
}
void loop()
{
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;
 digitalWrite(trigPinD, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPinD, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPinD, LOW);
 durationD = pulseIn(echoPinD, HIGH);
 distanceD = durationD/58.2;
 digitalWrite(trigPinI, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPinI, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPinI, LOW);
 durationI = pulseIn(echoPinI, HIGH);
 distanceI = duration/58.2;
 
if(distance<=10){
 Velocidad(ADELANTE,100);
}
else if(distanceD<=10){
 Velocidad(DERECHA,80);
}
else if(distanceI<=10){
 Velocidad(IZQUIERDA,80);
}
else{
  Velocidad(ADELANTE,0);
}
}

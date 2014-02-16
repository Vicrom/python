#define ADELANTE -1
#define IZQUIERDA -2
#define DERECHA -3

int info[5]={A0,A1,A2,A3,A4};
int vectordig[5];
int pwm_a = 3;  
int pwm_b = 11;  
int dir_a = 12;  
int dir_b = 13;
int i;
int last;

void Velocidad(int sentido,int nPoti ,int nPotd)
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
  
  analogWrite(pwm_a, nPotd);        
  analogWrite(pwm_b, nPoti);
  
}

void cny(){
  
  for (i=0;i<5;i++){
   if(analogRead(info[i])<=700){ 
    vectordig[i]=1;
  }
   else {
     vectordig[i]=0;
   }
  } 
 
}
int compara( int masc[5]){
  for(i=0;i<5;i++){
    if(masc[i]!=vectordig[i]){
      return 0;
    }
  }
    return 1;
  }

void setup(){
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
   for (i=0;i<5;i++){
    pinMode(info[i],INPUT); 
   }
   Serial.begin(9600);
   
}

void loop(){
  int recto[5]={0,0,1,0,0};
  int izquierda[5]={0,1,1,0,0};
  int derecha[5]={0,0,1,1,0};
  int izquierda_uno[5]={0,1,0,0,0};
  int derecha_uno[5]={0,0,0,1,0};
  int extremo_izquierda[5]={1,1,0,0,0};
  int extremo_derecha[5]={0,0,0,1,1};
   int alerta_derecha[5]={0,0,0,0,1};
  int alerta_izquierda[5]={1,0,0,0,0};
  cny();
 if(compara(recto)){
   Velocidad(ADELANTE,25,25);
   delay(2);
 }
 else if(compara(izquierda)){
   Velocidad(ADELANTE,15,30);
   delay(2);
   last=1;
 }
 else if(compara(derecha)){
   Velocidad(ADELANTE,30,15);
   delay(2);
   last=0;
 }
 else if(compara(izquierda_uno)){
   Velocidad(ADELANTE,10,40);
   delay(2);
   last=1;
 }
 else if(compara(derecha_uno)){
   Velocidad(ADELANTE,40,10);
   delay(2);
   last=0;
 }
 else if(compara(extremo_izquierda)){
   Velocidad(ADELANTE,10,40);
   delay(2);
   last=1;
 }
 else if(compara(extremo_derecha)){
   Velocidad(ADELANTE,40,10);
   delay(2);
   last=0;
 }
   else if(compara(alerta_izquierda)){
   Velocidad(ADELANTE,10,40);
   delay(2);
   last=1;
 }
  else if(compara(alerta_derecha)){
   Velocidad(ADELANTE,40,10);
   delay(2);
   last=0;
 }
else{
  if(last==1){
    Velocidad(ADELANTE,10,30);}
    if(last==1){
    Velocidad(ADELANTE,30,10);}
  
}}

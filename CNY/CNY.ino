int info[5]={A0,A1,A2,A3,A4};
int vectordig[5];
int i;
void setup(){

   for (i=0;i<5;i++){
    pinMode(info[i],INPUT); 
   }
   Serial.begin(9600);
}

void loop(){
  for (i=0;i<5;i++){
   if(analogRead(info[i])<=700){ 
    vectordig[i]=1;
  }
   else {
     vectordig[i]=0;
   }
  }
  for (i=0;i<5;i++){
   Serial.print(vectordig[i]);
   Serial.print(" ");
  }
  Serial.println();
  delay(500);
 }



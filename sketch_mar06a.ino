const byte totalLeds=12;
int incomingAudio[30]={};
int averageAudio=0;
int ticker=1;
byte peak=1;
 
void setup(){
  for(byte i=2;i<=totalLeds+1;i++)
    pinMode(i, OUTPUT); // Ledler

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
 
void loop(){
  incomingAudio[ticker%30]=analogRead(A0); // Sensör Bağlantısı
  digitalWrite(5+peak,LOW); 
  if(ticker%30==0){ 
    for(byte i=0;i<30;i++)averageAudio+=incomingAudio[i];
    averageAudio/=30; 
    
    for(byte i=3;i<=totalLeds;i++){
      digitalWrite(2+i,LOW); 
    }
    
    for(float i=3;i<=totalLeds;i++){ 
      if(i>averageAudio/90-2)break;
      if(peak<i)peak=i; digitalWrite(2+i,HIGH); 
    } 
    
    averageAudio=0; 
    if(ticker>90*5){
      ticker=1;
      if(peak>0)
        peak--;
    }
   
        digitalWrite(2+peak,HIGH);
  }
  
  ticker++;
}

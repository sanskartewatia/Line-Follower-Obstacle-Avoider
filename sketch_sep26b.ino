int left1=2, left2=4, right1=7, right2=8, enableR=5, enableL=6; 
int irL=12;
int irR=13;
int irstateL=0;
int irstateR=0;
const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;

void setup ()  
{      
  
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(left1,OUTPUT);      
  pinMode(left2,OUTPUT);  
     
  pinMode(right1,OUTPUT);       
  pinMode(right2,OUTPUT);      
  
  pinMode(enableR,OUTPUT);     
  pinMode(enableL,OUTPUT);    

  Serial.begin(9600);
  pinMode(irL, INPUT);
  pinMode(irR, INPUT);
  
} 

void loop() 
{  
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);                 // Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);           // Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);    // Calculating the distance
distance= duration*0.034/2;           // Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

    if(distance>25)

 {
      irstateL = digitalRead(irL);
      if(!irstateL)
      {
        
   digitalWrite(left1,HIGH);      
   digitalWrite(left2,LOW);    
   
   digitalWrite(right1,LOW);      
   digitalWrite(right2,HIGH); 
   
      }

      irstateR = digitalRead(irR);
      if(!irstateR)
      {
             
   digitalWrite(left1,LOW);      
   digitalWrite(left2,HIGH);   
   
   digitalWrite(right1,HIGH);      
   digitalWrite(right2,LOW);  
   
      }

      else
      {
      
   digitalWrite(left1,HIGH);      
   digitalWrite(left2,LOW);    
   
   digitalWrite(right1,HIGH);      
   digitalWrite(right2,LOW); 
   
   analogWrite(enableR,250);      
   analogWrite(enableL,255); 

      }
 }
 else
 {
         // stop the bot
      digitalWrite(left1,HIGH);      
   digitalWrite(left2,LOW);  // Left Motor Forward  
   
    digitalWrite(right1,HIGH);      
    digitalWrite(right2,LOW);// Right Motor Forward 
   
   analogWrite(enableR,1);      
   analogWrite(enableL,1);  // Left Motor Forward 
}
}

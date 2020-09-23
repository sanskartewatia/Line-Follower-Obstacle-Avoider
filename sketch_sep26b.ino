int left1=2, left2=4, right1=7, right2=8, enable1=5, enable2=6, ls=10, rs=12, fs=9 ;


void setup()  
{  
  pinMode(ls, INPUT);
  pinMode(rs, INPUT);
  pinMode(fs, INPUT); // front sensor
 
  pinMode(left1,OUTPUT);      
  pinMode(left2,OUTPUT);  
     
  pinMode(right1,OUTPUT);      
  pinMode(right2,OUTPUT);  

  analogWrite(enable1,130);      
  analogWrite(enable2,135);  // Left Motor Forward
}

void loop()
{      

if(digitalRead(ls)==HIGH && digitalRead(rs)==HIGH && digitalRead(fs)==HIGH) // Move Forward on line
forward();
else if(digitalRead(ls)==LOW && (digitalRead(rs)==HIGH && digitalRead(fs)==HIGH)) // turn left by rotationg left motors in forward and right ones in backward direction
right();
else if(digitalRead(ls)==HIGH && digitalRead(rs)==LOW && digitalRead(fs)==HIGH) // Turn right by rotating right motors in forward and left ones in backward direction
left();
else if(digitalRead(ls)==LOW && digitalRead(rs)==LOW && digitalRead(fs)==HIGH) // Finish line, stop both the motors
stoprob();

else if ( digitalRead(fs)==LOW )  //front sensor
 {
  Serial.println(fs);
    right();
  delay(700);
    forward();
  delay(1250);
    left();
  delay(800);
    forward();
  delay(600);
    left();
  delay(550);
    forward();  
  delay(400);
   
   do {
       forward();
       
   }  while(digitalRead(ls)==HIGH && digitalRead(rs)==HIGH);
 
 
  delay(200);
  stoprob();
  delay(1000);

  while(digitalRead(ls)==HIGH)
  {
    right();
//    forward();
 }
}
}


void stoprob()
{  
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
 
  }


  void right()
  {
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
      }


  void left()
  {
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
      }


void forward()  
  {
   digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
    }

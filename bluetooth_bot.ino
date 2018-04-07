#include <Servo.h>
char bluein;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int ba1 = 10;
int ba2 = 11;
int pos=0;
Servo s;
void goforward();
void goleft();
void goright();
void goback();
void stopcommand();
void barelldir1();
void barelldir2();
void barelloff();
void motoroff();
void servoDir1();
void servoDir2();
void setup() {
  s.attach(12);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT); 
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ba1,OUTPUT);
  pinMode(ba2,OUTPUT); 
  Serial.begin(9600);
  Serial.println("WAR_START...");
  pinMode(13,OUTPUT);
  delay(500);
}


void loop() {
  if(Serial.available())
   {
    bluein=char(Serial.read());
    Serial.println(bluein);
    switch(bluein)
    {
      case 'F':goforward();break;
      case 'L':goleft();break;
      case 'R':goright();break;
      case 'B':goback();break;
      case 'D':stopcommand();break;
      case 'X':barelloff();break;
      case 'U':barelldir1();break;
      case 'u':barelldir2();break;
      case 'x':motoroff();break;
      case 'V':servoDir1();break;
      case 'v':servoDir2();break;
      default:Serial.println("error");
     }
    }
}
void servoDir1(){
  for(pos=0;pos<=45;pos+=1){
    s.write(pos);
    delay(100);
    }
    return;
  }
  void servoDir2(){
    for(pos=45;pos>=0;pos-=1){
      s.write(pos);
      delay(100);
      }
      return;
    }
void motoroff(){
Serial.println("motor off");
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
}
void barelldir1(){
Serial.println("barelldirl");
digitalWrite(ba2,LOW);
digitalWrite(ba1,HIGH);
return;
}
void barelldir2(){
Serial.println("barelldir2");
digitalWrite(ba1,LOW);
digitalWrite(ba2,HIGH);
return;
}
void barelloff(){
Serial.println("barelloff");
digitalWrite(ba1,LOW);
digitalWrite(ba2,LOW);
return;
}
void goforward(){
Serial.println("goforward");
digitalWrite(in2,LOW);
digitalWrite(in4,LOW);
digitalWrite(in1,HIGH);
digitalWrite(in3,HIGH);
}
void goback(){
Serial.println("goback");
digitalWrite(in1,LOW);
digitalWrite(in3,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in4,HIGH);
 
}
void goleft(){
Serial.println("goleft");
digitalWrite(in1,LOW);
digitalWrite(in4,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
 
}
void goright(){
Serial.println("goright");
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in1,HIGH);
digitalWrite(in4,HIGH);
 
}

void stopcommand(){
Serial.println("stopcommand");
digitalWrite(ba1,LOW);
digitalWrite(ba2,LOW);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
}

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

const int pingPin = 2;
int QTI1Val;
int QTI2Val;  
#define QTI1 A1
#define QTI2 A2


void setup()
{
  Serial.begin(9600);
  servoLeft.attach(12);
  servoRight.attach(13);
  pinMode(QTI1, INPUT);
  pinMode(QTI2, INPUT);

}

void loop(){
long duration, cm;
pinMode(pingPin,OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);

pinMode(pingPin, INPUT);
duration = pulseIn(pingPin, HIGH);
  
cm = microsecondsToCentimeters(duration);
Serial.print(cm);
Serial.print("cm");
Serial.println();
//delay(100);

digitalWrite(QTI1, HIGH);
digitalWrite(QTI2, HIGH);

QTI1Val = analogRead(QTI1);
QTI2Val = analogRead(QTI2);
Serial.println(QTI1Val);
Serial.println(QTI2Val);  
delay(100);

  
if (cm < 15)
  {servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);}  
  else {
    if ((QTI1Val<200) && (QTI2Val<200))
    {servoLeft.writeMicroseconds(1650);
    servoRight.writeMicroseconds(1350);}
    else if ((QTI1Val>200) && (QTI2Val<200))  //Left Turn
    {servoLeft.writeMicroseconds(1325);
    servoRight.writeMicroseconds(1325);
    delay(100);}
    else if ((QTI1Val<200) && (QTI2Val>200))  //Right Turn
    {servoLeft.writeMicroseconds(1675);
    servoRight.writeMicroseconds(1675);
    delay(100);}
    /*else if ((QTI1Val>500) && (QTI2Val>500))
    {servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1550);
    delay(500);}*/
    else
    {servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);}
  }
}


long microsecondsToCentimeters(long microseconds){
  return microseconds / 29/ 2;
}

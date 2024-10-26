int motorPinRightA=A4;
int motorPinRightB=A3;
int motorPinRightpwm=11;

int motorPinLeftA=A1;
int motorPinLeftB=A2;
int motorPinLeftpwm=10 ;

void setup() {
  pinMode(motorPinRightA,OUTPUT);
  pinMode(motorPinRightB,OUTPUT);
  pinMode(motorPinLeftA,OUTPUT);
 pinMode(motorPinLeftB,OUTPUT);
}
void loop() {
 digitalWrite(motorPinLeftA,HIGH);
 digitalWrite(motorPinLeftB,LOW);
 analogWrite(motorPinLeftpwm,255);
 
 digitalWrite(motorPinRightA,HIGH);
 digitalWrite(motorPinRightB,LOW);
 analogWrite(motorPinRightpwm,255);
 delay(3000);
 //stop
 
 digitalWrite(motorPinLeftA,0);
 digitalWrite(motorPinLeftB,0);
 digitalWrite(motorPinLeftpwm,255);
 
 digitalWrite(motorPinRightA,0);
 digitalWrite(motorPinRightB,0);
 digitalWrite(motorPinRightpwm,255);
 delay(3000);
 //back
 digitalWrite(motorPinLeftA,0);
 digitalWrite(motorPinLeftB,1);
 digitalWrite(motorPinLeftpwm,255);
 
 digitalWrite(motorPinRightA,0);
 digitalWrite(motorPinRightB,1);
 digitalWrite(motorPinRightpwm,255);
 delay(3000);
 
 
}

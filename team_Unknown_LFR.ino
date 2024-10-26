int motorLeftA = A1;
int motorLeftB = A2;
int motorLeftPWM = 10;

int motorRightA = A3;
int motorRightB = A4;
int motorRightPWM = 11;

int maxSpeed = 150;

int sensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int multiplier[] = { -4, -3, -2, -1, 1, 2, 3, 4};
int Position;
int lastPosition;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(motorLeftA, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  pinMode(motorLeftPWM, OUTPUT);
  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorRightPWM, OUTPUT);

  for (int c = 0; c < 8; c++) {
    pinMode(sensorPins[c], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //  driveWheel(100, 255);
  Position = findPosition();
  if ((Position == 0 && lastPosition == -8) || Position == 0 && lastPosition == 8)
    Position = lastPosition;
  Serial.println(Position);
  calculateSpeed(Position);

  lastPosition = Position;
}

void driveWheel(int leftSpeed, int RightSpeed) {
  //  if(leftSpeed<0){
  //      digitalWrite(motorLeftA, LOW);
  //      digitalWrite(motorLeftB, HIGH);
  //      analogWrite(motorLeftPWM, leftSpeed*-1);
  //    }else{
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);
  analogWrite(motorLeftPWM, leftSpeed);
  //      }

  //  if(RightSpeed<0){
  //        digitalWrite(motorRightA, LOW);
  //        digitalWrite(motorRightB, HIGH);
  //        analogWrite(motorRightPWM, RightSpeed*-1);
  //    }else{
  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  analogWrite(motorRightPWM, RightSpeed);
  //      }
}

int findPosition() {
  Position = 0;
  int rawSensorSum = 0;
  for (int c = 0; c < 8; c++) {
    int sensorData = digitalRead(sensorPins[c]);
    rawSensorSum += sensorData;
    Position += sensorData * multiplier[c];

    //    Serial.print(digitalRead(sensorPins[c]));
    //    Serial.print('\t');
  }//Serial.println();

  if (rawSensorSum == 1) {
    Position *= 2;
  }
  return Position;
}

void calculateSpeed(int Position) {
  int rightSpeed, leftSpeed;
  int division = maxSpeed / 5;
  int reduceSpeed = int(division * Position);

  rightSpeed = maxSpeed;
  leftSpeed = maxSpeed;
  if (Position > 0) {
    leftSpeed -= reduceSpeed;
  } else if (Position < 0) {
    rightSpeed += reduceSpeed;
  }
  if (rightSpeed < 0)
    rightSpeed = 0;
  if (leftSpeed < 0)
    leftSpeed = 0;
  //   Serial.print(leftSpeed);
  //   Serial.print('\t');
  //   Serial.println(rightSpeed);

  driveWheel(leftSpeed, rightSpeed);
}

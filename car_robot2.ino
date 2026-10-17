#define IR_SENSOR_RIGHT A0
#define IR_SENSOR_LEFT A1

int enableRightmotor=5;
int rightpin1=7;
int rightpin2=8;

int enableLeftmotor=6;
int leftpin1=10;
int leftpin2=11;

void setup() {

  pinMode(IR_SENSOR_RIGHT,INPUT);
  pinMode(IR_SENSOR_LEFT,INPUT);

  pinMode(enableRightmotor,OUTPUT);
  pinMode(rightpin1,OUTPUT);
  pinMode(rightpin2,OUTPUT);

  pinMode(enableLeftmotor,OUTPUT);
  pinMode(leftpin1,OUTPUT);
  pinMode(leftpin2,OUTPUT);

}

void rotatemotor(int rightspeed,int leftspeed)
{
  if(rightspeed<0)
  {
    digitalWrite(rightpin2,HIGH);
    digitalWrite(rightpin1,LOW);
  }
  else if(rightspeed>=0)
  {
    digitalWrite(rightpin1,HIGH);
    digitalWrite(rightpin2,LOW);
  }

  if(leftspeed<0)
  {
    digitalWrite(leftpin1,HIGH);
    digitalWrite(leftpin2,LOW);
  }
  
  else if(leftspeed>=0)
  {
    digitalWrite(leftpin2,HIGH);
    digitalWrite(leftpin1,LOW);
  }
  analogWrite(enableRightmotor,abs(rightspeed));
  analogWrite(enableLeftmotor,abs(leftspeed));
}

void loop()
{
  static int motor_speed=100;
  static int turning_motor_speed=200;

  int rightIRvalue=digitalRead(IR_SENSOR_RIGHT);
  int leftIRvalue=digitalRead(IR_SENSOR_LEFT);
  //HIGH means black line detected

  if(rightIRvalue==LOW && leftIRvalue==LOW)
  {
    rotatemotor(motor_speed,motor_speed);
  }
  else if(rightIRvalue==LOW && leftIRvalue==HIGH)
  {
    rotatemotor(turning_motor_speed,-turning_motor_speed);
  }
   else if(rightIRvalue==HIGH && leftIRvalue==LOW)
  {
    rotatemotor(-turning_motor_speed,turning_motor_speed);
  }
  else
  {
    rotatemotor(0,0);
  }



}
//   void loop() {
//FORWARD MOTION
//   analogWrite(enableRightmotor,200);
//   analogWrite(enableLeftmotor,200);
//   digitalWrite(rightpin2,LOW);
//   digitalWrite(leftpin1,LOW);
//   digitalWrite(rightpin1,HIGH);
//   digitalWrite(leftpin2,HIGH);
//   delay(2000);

//   analogWrite(enableRightmotor,0);
//   analogWrite(enableLeftmotor,0);
//   delay(1000);

//BACKWARD MOTION
//   analogWrite(enableRightmotor,200);
//   analogWrite(enableLeftmotor,200);
//   digitalWrite(rightpin1,LOW);
//   digitalWrite(leftpin2,LOW);
//   digitalWrite(rightpin2,HIGH);
//   digitalWrite(leftpin1,HIGH);
//   delay(2000);

   
//   analogWrite(enableRightmotor,0);
//   analogWrite(enableLeftmotor,0);
//   delay(1000);
// }

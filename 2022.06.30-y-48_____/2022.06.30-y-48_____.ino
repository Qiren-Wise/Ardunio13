#include<AccelStepper.h>

#define FULLSTEP 4  //全步进参数
#define HALFSTEP 8  //半步进

//定义步进电机引脚
#define motor1Pin1 8
#define motor1Pin2 9
#define motor1Pin3 10
#define motor1Pin4 11

#define motor2Pin1 4
#define motor2Pin2 5
#define motor2Pin3 6
#define motor2Pin4 7

AccelStepper stepper1(HALFSTEP,motor1Pin1,motor1Pin3,motor1Pin2,motor1Pin4);
AccelStepper stepper2(FULLSTEP,motor2Pin1,motor2Pin3,motor2Pin2,motor2Pin4);

void setup() {
  // put your setup code here, to run once:
  stepper1.setMaxSpeed(500.0);    //1号电机最大速度
  stepper1.setAcceleration(50.0); //加速度50.0

   stepper2.setMaxSpeed(500.0);
  stepper2.setAcceleration(50.0);
}

void loop() {
  // put your main code here, to run repeatedly:
if (stepper1.currentPosition() == 0 && stepper2.currentPosition() == 0)
   {
     //1号电机转半圈
     stepper1.moveTo(2048);
     //2号一周
     stepper2.moveTo(2048);
    } else if (stepper1.currentPosition() == 2048 && stepper2.currentPosition() == 2048)

      {
        // //1号电机转半圈
     stepper1.moveTo(0);
     //2号一周
     stepper2.moveTo(0);
        }

         stepper1.run(); //1号运行
         stepper2.run();
}

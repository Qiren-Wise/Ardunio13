#include <Stepper.h>



//电机转子旋转一周步数
const int STEPS_PER_POTOR_REV = 32;  //rev=revolution  一周

//减速比
const int GEAR_REDUCTION = 64;

//电机外部输出轴旋转一周步数（2048）
const float STEPS_PER_OUT_REV = STEPS_PER_POTOR_REV*GEAR_REDUCTION;

//电机旋转步数
int StepsRequired;

Stepper steppermotor(STEPS_PER_POTOR_REV,8,10,9,11);//in1,3，2,4  设置电机对象

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //极慢转动4步用于观察ULN2003电机驱动板LED变化
  steppermotor.setSpeed(1);  //库函数setSpeed  1为最慢
  StepsRequired = 4;         //走多少步
  steppermotor.step(StepsRequired);
  delay(1000);

  //慢速顺时针旋转一圈
  StepsRequired = STEPS_PER_OUT_REV;
  steppermotor.setSpeed(500);
  steppermotor.step(StepsRequired);
  delay(1000);

  //快速逆时针旋转一圈
  StepsRequired = - STEPS_PER_OUT_REV;
  steppermotor.setSpeed(800);
  steppermotor.step(StepsRequired);
  delay(2000);

}

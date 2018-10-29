#define MOT_A1 2
#define MOT_A2 3
#define MOT_B1 7
#define MOT_B2 4
#define MOT_C1 8
#define MOT_C2 9
#define MOT_D1 12
#define MOT_D2 13
#define PWM_A 5
#define PWM_B 6
#define PWM_C 10
#define PWM_D 11

void init_motors();
void test();
void left_motor(int speed);
void right_motor(int speed);
void arm_motor(int speed);
void claw_motor(int speed);

void init_motors() {
  pinMode(MOT_A1, OUTPUT);
  pinMode(MOT_A2, OUTPUT);
  pinMode(MOT_B1, OUTPUT);
  pinMode(MOT_B2, OUTPUT);
  pinMode(MOT_C1, OUTPUT);
  pinMode(MOT_C2, OUTPUT);
  pinMode(MOT_D1, OUTPUT);
  pinMode(MOT_D2, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(PWM_C, OUTPUT);
  pinMode(PWM_D, OUTPUT);
}

void test() {
  Serial.println("Left motor half speed, right motor stopped");
  left_motor(128);
  right_motor(0);
  delay(3000);

  Serial.println("Right motor half speed, left motor stopped");
  left_motor(0);
  right_motor(128);
  delay(3000);

  Serial.println("Right motor half speed reverse, left motor stop");
  left_motor(0);
  right_motor(-128);
  delay(3000);

  Serial.println("Left motor half speed reverse, right motor stop");
  left_motor(-128);
  right_motor(0);
  delay(3000);

  Serial.println("Full stop");
  left_motor(0);
  right_motor(0);
  delay(3000);
}


void left_motor(int speed) {
  if (speed > 255) speed = 255;
  if (speed < -255) speed = -255;
  if (speed > 0) { 
    digitalWrite(MOT_A1, HIGH);
    digitalWrite(MOT_A2, LOW);
  } else {
    digitalWrite(MOT_A1, LOW);
    digitalWrite(MOT_A2, HIGH);    
  }
  analogWrite(PWM_A, abs(speed));
}

void right_motor(int speed) {
  if (speed > 255) speed = 255;
  if (speed < -255) speed = -255;
  if (speed > 0) { 
    digitalWrite(MOT_B1, LOW);
    digitalWrite(MOT_B2, HIGH);
  } else {
    digitalWrite(MOT_B1, HIGH);
    digitalWrite(MOT_B2, LOW);    
  }
  analogWrite(PWM_B, abs(speed));
}

void arm_motor(int speed) {
  if (speed > 255) speed = 255;
  if (speed < -255) speed = -255;
  if (speed > 0) { 
    digitalWrite(MOT_C1, LOW);
    digitalWrite(MOT_C2, HIGH);
  } else {
    digitalWrite(MOT_C1, HIGH);
    digitalWrite(MOT_C2, LOW);    
  }
  analogWrite(PWM_C, abs(speed));
}

void claw_motor(int speed) {
  if (speed > 255) speed = 255;
  if (speed < -255) speed = -255;
  if (speed > 0) { 
    digitalWrite(MOT_D1, LOW);
    digitalWrite(MOT_D2, HIGH);
  } else {
    digitalWrite(MOT_D1, HIGH);
    digitalWrite(MOT_D2, LOW);    
  }
  analogWrite(PWM_D, abs(speed));
}

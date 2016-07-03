#include <NewPing.h>
NewPing sonar(11, 3, 100);
#include <Servo.h>
Servo pala;

#define HALT 0
#define FORWARD 1
#define BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define LEFT 1
#define RIGHT 2
#define BOTH 3

void setup() {
    //pulsadores
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    //LED
    pinMode(12, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    //servo
    pala.attach(2);
    pala.write(180);
    //motores
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(6, OUTPUT);
    moveRobot(HALT, BOTH, 0, 0);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    //start
    while (digitalRead(A3) == LOW) {
        digitalWrite(12, HIGH);
        digitalWrite(A0, HIGH);
        digitalWrite(A1, HIGH);
        delay(50);
        digitalWrite(12, LOW);
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        delay(50);
    }
    delay(1000);
    tone(4, 400, 100);
    digitalWrite(12, HIGH);
    delay(1000);
    tone(4, 800, 100);
    digitalWrite(A0, HIGH);
    delay(1000);
    tone(4, 1600, 250);
    digitalWrite(A1, HIGH);
    delay(250);
    noTone(4);
}

void loop() {
    if (search()) {
        attack();
        retreat();
    }
}

unsigned char search() {
    unsigned char stat = 0;
    static unsigned char lastStage = 0;

    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);
    digitalWrite(12, LOW);
    if (findOpponent()) stat = 1;
    else {
        if (lastStage == 0) {
            lastStage = 1;
            moveRobot(TURN_LEFT, BOTH, 255, 1000);
        }
        else if (lastStage == 1) {
            lastStage = 2;
            moveRobot(TURN_RIGHT, BOTH, 255, 1000);
        }
        else if (lastStage == 2) {
            lastStage = 3;
            moveRobot(TURN_RIGHT, BOTH, 255, 1000);
        }
        else if (lastStage == 3) {
            lastStage = 0;
            moveRobot(TURN_LEFT, BOTH, 255, 1000);
        }
    }
    digitalWrite(A0, LOW);
    return stat;
}

void attack() {
    digitalWrite(A1, HIGH);
    digitalWrite(A0, LOW);
    digitalWrite(12, LOW);
    moveRobot(FORWARD, BOTH, 255, 6000);
    //levantar y bajar servo 4x
    for (int i = 0; i < 5; i++){
        pala.write(150);
        delay(250);
        pala.write(180);
        delay(250);
    }
    digitalWrite(A1, LOW);
}

void retreat() {
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(12, HIGH);
    pala.write(150);
    moveRobot(BACKWARD, BOTH, 255, 6000);
    pala.write(180);
    digitalWrite(12, LOW);
}

void moveRobot(unsigned char course, unsigned char motor, unsigned char value, unsigned int distance) {
    switch (motor){
      case LEFT:
        if (course == HALT) {
            digitalWrite(5, LOW);
            digitalWrite(10, LOW);
        }
        else if (course == FORWARD) {
            digitalWrite(10, LOW);
            analogWrite(5, value);
            delay(distance);
            digitalWrite(5, LOW);
        }
        else if (course == BACKWARD) {
            digitalWrite(5, LOW);
            analogWrite(10, value);
            delay(distance);
            digitalWrite(10, LOW);
        }
        break;
      case RIGHT:
        if (course == HALT) {
            digitalWrite(6, LOW);
            digitalWrite(9, LOW);
        }
        else if (course == FORWARD) {
            digitalWrite(9, LOW);
            analogWrite(6, value);
            delay(distance);
            digitalWrite(6, LOW);
        }
        else if (course == BACKWARD) {
            digitalWrite(6, LOW);
            analogWrite(9, value);
            delay(distance);
            digitalWrite(9, LOW);
        }
        break;
      case BOTH:
        if (course == HALT) {
            digitalWrite(5, LOW);
            digitalWrite(10, LOW);
            digitalWrite(6, LOW);
            digitalWrite(9, LOW);
        }
        else if (course == FORWARD) {
            digitalWrite(10, LOW);
            analogWrite(5, value);
            digitalWrite(9, LOW);
            analogWrite(6, value);
            delay(distance);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
        }
        else if (course == BACKWARD) {
            digitalWrite(5, LOW);
            analogWrite(10, value);
            digitalWrite(6, LOW);
            analogWrite(9, value);
            delay(distance);
            digitalWrite(10, LOW);
            digitalWrite(9, LOW);
        }
        else if (course == TURN_LEFT) {
            digitalWrite(5, LOW);
            analogWrite(10, value);
            digitalWrite(9, LOW);
            analogWrite(6, value);
            delay(distance);
            digitalWrite(10, LOW);
            digitalWrite(6, LOW);
        }
        else if (course == TURN_RIGHT) {
            digitalWrite(10, LOW);
            analogWrite(5, value);
            digitalWrite(6, LOW);
            analogWrite(9, value);
            delay(distance);
            digitalWrite(5, LOW);
            digitalWrite(9, LOW);
        }
    }
}

unsigned char findOpponent() {
    unsigned char target = 0;
    unsigned int dist = 0;

    dist = sonar.ping_cm();
    if ((dist <= 50) && (dist >= 3)) target = 1;
    return target;
}


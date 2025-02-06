
#include <Arduino.h>
#include <NewPing.h>

#define FRONT_TRIG 2
#define FRONT_ECHO 3
#define BACK_TRIG 4
#define BACK_ECHO 11

#define ENA 5   
#define ENB 6  
#define N1 7    
#define N2 8    
#define N3 9    
#define N4 10 

// Define pins for buzzer and LEDs
#define BUZZER 12
#define RED_FRONT 13 
#define RED_BACK A0 

// Motor speed
#define MOTOR_SPEED 150
#define REVERSE_SPEED 120

// Define maximum distance for obstacle detection (in cm)
#define MAX_DISTANCE 40

NewPing frontSensor(FRONT_TRIG, FRONT_ECHO, MAX_DISTANCE);
NewPing backSensor(BACK_TRIG, BACK_ECHO, MAX_DISTANCE);

void setup() {
    // Set motor driver pins as outputs
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(N1, OUTPUT);
    pinMode(N2, OUTPUT);
    pinMode(N3, OUTPUT);
    pinMode(N4, OUTPUT);

    // Set buzzer and LEDs as outputs
    pinMode(BUZZER, OUTPUT);
    pinMode(RED_FRONT, OUTPUT);
    pinMode(RED_BACK, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int frontDistance = getAverageDistance(frontSensor);
    int backDistance = getAverageDistance(backSensor);

    Serial.print("Front Distance: ");
    Serial.print(frontDistance);
    Serial.print(" cm  |  Back Distance: ");
    Serial.println(backDistance);

    if (frontDistance > 0 && frontDistance < MAX_DISTANCE) {
        stopCar();
        warningSignal(RED_FRONT);
        delay(500);
        moveBackward();
    } 
    else if (backDistance > 0 && backDistance < MAX_DISTANCE) {
        stopCar();
        warningSignal(RED_BACK);
        delay(500);
        moveForward();
    } 
    else {
        moveForward();
        digitalWrite(RED_FRONT, LOW);
        digitalWrite(RED_BACK, LOW);
        digitalWrite(BUZZER, LOW);
    }

    delay(100);
}

void moveForward() {
    digitalWrite(N1, HIGH);
    digitalWrite(N2, LOW);
    digitalWrite(N3, HIGH);
    digitalWrite(N4, LOW);
    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
}

void moveBackward() {
    digitalWrite(N1, LOW);
    digitalWrite(N2, HIGH);
    digitalWrite(N3, LOW);
    digitalWrite(N4, HIGH);
    analogWrite(ENA, REVERSE_SPEED);
    analogWrite(ENB, REVERSE_SPEED);

    // Beep while reversing
    for (int i = 0; i < 3; i++) {
        digitalWrite(BUZZER, HIGH);
        delay(300);
        digitalWrite(BUZZER, LOW);
        delay(300);
    }
}

void stopCar() {
    digitalWrite(N1, LOW);
    digitalWrite(N2, LOW);
    digitalWrite(N3, LOW);
    digitalWrite(N4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void warningSignal(int ledPin) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(500);
    digitalWrite(BUZZER, LOW);
}

// Function to get an average distance reading for better accuracy
int getAverageDistance(NewPing &sensor) {
    int total = 0;
    int readings = 3; // Number of samples

    for (int i = 0; i < readings; i++) {
        total += sensor.ping_cm();
        delay(50); // Small delay for stability
    }

    return total / readings;
}


int motorA1 = 5; // Pin  2 of L293
int motorA2 = 6; // Pin  7 of L293
int motorB1 = 9; // Pin 10 of L293
int motorB2 = 10; // Pin 14 of L293
int vel = 255; // Speed Of Motors (0-255)
int state = '0'; // Initialise Motors
int a= 70;
int b= 66;
int c= 82;
int d= 76;
int e= 83;

void setup() { 
Serial.begin(9600); // Initialize serial communication at 9600 bits per second
   // Set pins as outputs
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);

} 

void loop() { 

if(Serial.available()>0){ // Reads from bluetooth and stores its value
state = Serial.read();
Serial.println(state);

}
if(state==b){ // Forward
  Serial.println("forward");
analogWrite(motorA1, vel); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, vel); 
analogWrite(motorB2, 0); 
}
if(state==a){ // Reverse
    Serial.println("reverse");
analogWrite(motorA1, 0); 
analogWrite(motorA2, vel);
analogWrite(motorB1, 0); 
analogWrite(motorB2, vel); 
}
if(state==d){ // Right
    Serial.println("right");
analogWrite(motorA1, vel); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, vel); 
}
if(state==c){ // Left
    Serial.println("left");
analogWrite(motorA1, 0); 
analogWrite(motorA2, vel);
analogWrite(motorB1, vel);
analogWrite(motorB2, 0); 
} 
if(state==e){ // Stop
    Serial.println("stop");
analogWrite(motorA1, 0); 
analogWrite(motorA2, 0); 
analogWrite(motorB1, 0); 
analogWrite(motorB2, 0); 

}

}

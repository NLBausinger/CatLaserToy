#include <Servo.h>  // Include the Servo library, which enables control of the servo motors

Servo laserMotor;     // Declare a Servo object for the laser motor
Servo xyPlaneMotor;   // Declare a Servo object for the motor controlling the XY plane of the laser

int pos = 0;          // Declare an integer variable to store the servo position

void setup() {
  laserMotor.attach(9);   // Attach the servo connected to pin 9 to the Servo object
  xyPlaneMotor.attach(10);   // Attach the servo connected to pin 10 to the Servo object
  Serial.begin(9600);   // Initialize the serial communication with a baud rate of 9600
}
  
void loop() {
  
  int oldVal = laserMotor.read();   // Read the current position of the laser motor
  int randVal = random(0,180);   // Generate a random target position for the laser motor
  int randVal2 = random(0,180);  // Generate a random position for the motor controlling the XY plane of the laser
  
  xyPlaneMotor.write(randVal2);   // Set the position of the motor controlling the XY plane to the random position generated above
  delay(50);   // Delay for 50ms
  
  Serial.println();   // Print a blank line to the serial monitor
  Serial.print("New Target: ");   // Print the label "New Target: " to the serial monitor
  Serial.print(randVal);   // Print the random target position to the serial monitor
  Serial.println();   // Print a blank line to the serial monitor
  delay(400);   // Delay for 400ms
  
  int randDelayTime = random(1, 30);   // Generate a random delay time for the laser motor movement
  
  if (oldVal < randVal){   // If the current position is less than the random target position...
    for (int x = oldVal; x< randVal; x++){   // Increment the position of the laser motor from the current position to the target position
      laserMotor.write(x);   // Set the position of the laser motor to the current increment value
      Serial.println(x);   // Print the current position of the laser motor to the serial monitor
      delay(randDelayTime);   // Delay for a random amount of time before the next increment
    }
  }
  
  else if (oldVal> randVal){   // If the current position is greater than the random target position...
    for (int x = oldVal; x> randVal; x--){   // Decrement the position of the laser motor from the current position to the target position
      laserMotor.write(x);   // Set the position of the laser motor to the current decrement value
      Serial.println(x);   // Print the current position of the laser motor to the serial monitor
      delay(randDelayTime);   // Delay for a random amount of time before the next decrement
    }
  }
  
  delay(400);   // Delay for 400ms before starting the next loop

}

# CatLaserToy
Two servo motors control a laser pointer, which point in random directions. Use this design I made to keep your cat entertained at home!
This code controls a laser toy that is built with two servo motors. The Servo library is used to control the servos, which are attached to pins 9 and 10 on the board. In the setup function, the two servo objects are created and the serial communication is initialized. The program generates two random values between 0 and 180, one for the x-axis and one for the y-axis, to move the laser in random directions. The xyPlaneMotor.write function is used to move the laser in the y-axis direction, and a delay of 50 milliseconds is added to ensure that the laser moves smoothly.The program then prints the new target position for the laser to the serial monitor, and a delay of 400 milliseconds is added. Another random value is generated to determine how long the laser will take to move to its new position. The program then checks if the current laser position is less than or greater than the new target position, and moves the laser accordingly by incrementing or decrementing the servo position. 

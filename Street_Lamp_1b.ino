/*
Street-Lamp, LED Sensor, Rev.B

StudentNumber:
StudentName:
Class: TEJ2O0-A/SHSM-ICT
Date: Month, Day, Year

Microprocessor Reqd. Arduino UNO R3.

Function: This program turns on an LED when ambient lighting gets low and turns off the LED when ambient light gets increases.

Vocabulary Reqd. for full understanding:

A. Ambient
B. Threshold
C. Analogue (Analog? Outside the U.S., analogue prevails for all senses of the word)
D. Digital
C. Variable
E. HIGH
F. LOW
G. Loop

Note: Because we are using the "serial monitor" function we are able to see that is coming into analogue port
      as a numeric value. To do this, upload this program to the arduino, which contains the 
      "serial monitor" functionality. Once upload is complete, then choose from the menu "Tools/Serial Monitor" to view the values.

      Observe the values for some time. choose a number that seems to best represent the ambient lighting conditions. 
      This will form the basis of our light threshold. subtract 5-15% to obtain a threshold that makes the system stable (off).

       e.g. (Ambient x 15%)-Ambient = Threshold (15% lower than Ambient)
       e.g. (270 x 0.15)-270 = 230    If the ambient value was stable at 270, the threshold is now 230.

1.   Create a variable called "LAMP" and assign it to Digital-Port-Twelve (12)
2.   Create a variable called "SENSOR" and assign it to Analogue-Port-Zero (A0)
3.   Create a variable called "Ambient" and assign it the value of Zero (0)
4.   Create a variable called "Threshold" and assign it a value of greater than Zero (0)
     This value will be determined by obtaining sensor data and then addeding or subtracting a "stability margin".
     Use the provided spreadsheet to help determine the threshold.

Setup is cleard from memory and Begins:  
 
2.   Use "pinMode" to tell the Arduino to set variable "LAMP" to be an "Output" (send power to 12)
3.   Set "Serial.Begin" to read at a baud-rate of 9600 Hz (same speed and arduino UNOr3)

Loop is cleared from memory and Begins:

4.   Define variable "AMBIENT" as the analogue reading from the "SENSOR"
5.   Print the "AMBIENT" value in the Seral Monitor
6.   If "AMBIENT" is less than "THRESHOLD" Set LAMP to HIGH (HIGH = ON).
7.   Or else, If "AMBIENT" is not less than "THRESHOLD" Set LAMP to LOW (LOW = OFF).
8.   END OF LOOP (Return to start of loop)

Created by/and shared by Mr. S. Anderson, Castlebrooke Secondary School, Brampton, ON Canada, 2021
*/


int LAMP = 12;// digital port 12
int SENSOR = A0;// + Anologue port A0 (LED - into GRD)
int AMBIENT = 0;
int THRESHOLD = 213;

void setup(){
  pinMode (LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  AMBIENT = analogRead(SENSOR);
  Serial.println(AMBIENT);
  if (AMBIENT < THRESHOLD)
  {
  digitalWrite (LAMP,HIGH);
}
  else
  {
  digitalWrite (LAMP,LOW);
}
}

  

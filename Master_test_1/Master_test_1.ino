// I2C, Master, Board 7
// Reference https://dronebotworkshop.com/i2c-arduino-arduino/
// Notes on Wire.requestFrom https://forum.arduino.cc/index.php?topic=624356.0
#include <Wire.h>

#define SLAVE_ADDR 9

#define ANSWERSIZE 5

//void setup() {
//Wire.begin(); // Initialize I2C communication as Master
//Serial.begin(9600);
//Serial.println("Master Node Ready");
//
//}
//
//void loop() {
//delay(50);
//
//// Write to Slave
//Serial.println("Sending 0XFF to Slave");
//Wire.beginTransmission(SLAVE_ADDR);
//Wire.write(0xFF);
//Wire.endTransmission();
//
//// Read back from Slave
//
//Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE); // Read back five characters
//String response = ""; // Creating an empty string
//while (Wire.available())
//  {
//    char b = Wire.read(); // Read one character at a time
//    response += b; // and then append to the String variable
//  }
//Serial.print("Received from Slave: "); Serial.println(response);
//}

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("AZMYIN MD KAMAL ");        // sends five bytes
 // Wire.write(3);              // sends one byte
  Wire.endTransmission(true);    // stop transmitting


  Wire.requestFrom(4, 6);    // request 6 bytes from slave device #2
  String response = "";
  while(Wire.available())    // slave may send less than requested
  {
    char b = Wire.read(); // receive a byte as character
    response += b;         // print the character
  }
  Serial.println(response);
  delay(500);
}

// I2C, Slave, Board 8

#include <Wire.h>

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent);
  Serial.begin(9600);           // start serial for output
}

long inCount = 0;
long outCount = 0;

void loop()
{
//  char c[200];
//  snprintf( c, 200, "%d,%d\n", inCount, outCount );
//  Serial.print( c );
//  delay(1000);

}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
inCount++;

  Serial.print( ">>> ");
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }

  Serial.println();         // print the integer
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  //Serial.println( "GOT DATA");

  outCount++;
  Wire.write("HELLO "); // respond with message of 6 bytes
                       // as expected by master
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//Library: TMRh20/RF24, https://github.com/tmrh20/RF24/ 
RF24 radio(7,8);  //CNS, CE
const byte address[6] = "00001";
// Left Potentiometer
int potValue1 = 0;
// Right Potentiometer
int potValue2 = 0;
int message = 0;

void setup() {
 radio.begin();
 radio.openWritingPipe(address);
 radio.setPALevel(RF24_PA_MIN);
 radio.stopListening();
}
void loop() {
  // Read the button and write 1 if button down
 // Reading and send the first potentiometer value mapped 1st half/255
 message = map(potValue1 = analogRead(A0), 0, 1023, 1, 127);
 radio.write(&message,sizeof(message));
 //Serial.write(message); // Sends potValue to servo motor
 delay(5);
 // Read  and send the second potentiometer value mapped 2nd half/255
 message = map(potValue2 = analogRead(A1), 0, 1023, 128, 254);
 radio.write(&message,sizeof(message));
 delay(5);
}

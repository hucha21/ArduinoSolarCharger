#include <Servo.h>
Servo servo ; // objekat za upravljanje servomotorom
 int eLDRPin = A0 ; // pinovi za LDR senzore
 int wLDRPin = A1 ;
 int eastLDR = 0 ; // varijable za citanje vrijednosti senzora
 int westLDR = 0 ;
 intrazlika = 0 ; // varijabla za komparaciju vrijednosti senzora
 int greska = 10; // prag tolerancije greske
 int servoSet = 130; // pozicija servomotora
 void setup ( ) {
 servo.attach(9) ; // postavljanje serva na PWM pin 9
 Serial.begin(9600) ;
 }
 void loop ( ) {
 eastLDR = analogRead (eLDRPin) ; // citanje vrijednosti LDR senzora
 westLDR = analogRead (wLDRPin) ;
 if( eastLDR < 400 && westLDR < 400) { // ukoliko nijedan nema znacajnu vrijednost svjetlosti
 while(servoSet <=180 && servoSet >50) { // vrati panel na pocetni
 servoSet ++;
 servo.write(servoSet) ;
 delay (100) ;
 }
 }
 razlika = eastLDR − westLDR ; // razlika mjerenja senzora
 if (razlika > 10) { // okreni panel prema senzoru sa vecom vrijednosti svjetlosti
 if(servoSet <= 160) {
 servoSet ++;
 servo.write (servoSet) ;
 }
 } elseif(razlika < −10) {
 if(servoSet >= 15) {
 servoSet −−;
 servo.write(servoSet) ;
 }
 }
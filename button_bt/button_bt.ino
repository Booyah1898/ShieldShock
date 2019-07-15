/*char data = 0;  //Variable for storing received data 
void setup() 
{
Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(data);        //Print Value inside data in Serial monitor
Serial.print("\n");        //New line 
if(data == '1')            //Checks whether value of data is equal to 1 
digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
else if(data == '0')       //Checks whether value of data is equal to 0
digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
}                            

}


int ledpin=11;            //definition digital 11 pins as pin to control the LED
int btnpin=2;             //Set the digital 2 to button interface 

volatile int state = LOW; // Defined output status LED Interface

void setup()
{
  pinMode(ledpin,OUTPUT);//Set digital 11 port mode, the OUTPUT for the output
  pinMode(btnpin,INPUT); //Set digital 2 port mode, the INPUT for the input
}

void loop()
{
  if(digitalRead(btnpin)==LOW)          //Detection button interface to low
  {   
      delay(10);                        //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btnpin)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btnpin)==LOW);//Wait for key interfaces to high
        delay(10);                      //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btnpin)==LOW);//Confirm button release
        state = !state;                 //Negate operation, each time you run the program here, state the HGIH becomes LOW, or the state becomes the LOW HGIH.
        digitalWrite(ledpin,state);     //Output control status LED, ON or OFF 
      }
   }
}*/


#include <SoftwareSerial.h>
// connect the STATE pin to Arduino pin D4
char data = 0;
const byte statepin = 4;
int btn=2; 
volatile int state = LOW; 
void setup() 
{
   
    pinMode(statepin, INPUT);   
    pinMode(btn,INPUT);
    pinMode(13,OUTPUT);
    digitalWrite(statepin,LOW);
    Serial.begin(9600);
}
void loop()
{

     if(digitalRead(btn)==LOW)      //Confirm button is pressed
      {     
        while(digitalRead(btn)==LOW);//Wait for key interfaces to high
        delay(10);                      //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btn)==LOW);//Confirm button release
        state = !state;                 //Negate operation, each time you run the program here, state the HGIH becomes LOW, or the state becomes the LOW HGIH.
        digitalWrite(statepin,state);     //Output control status LED, ON or OFF 
      }
   
if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();      //Read the incoming data and store it into variable data
Serial.print(data);        //Print Value inside data in Serial monitor
Serial.print("\n");        //New line 
if(data == '1')            //Checks whether value of data is equal to 1 
digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
else if(data == '0')       //Checks whether value of data is equal to 0
digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
} 
 
}



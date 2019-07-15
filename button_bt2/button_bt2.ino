#include <SoftwareSerial.h>
// connect the STATE pin to Arduino pin D4
char data = 0;
int btn=2;
int led=13; 
int bluetooth=8;
volatile int state=LOW;
void setup() 
{  
    pinMode(btn,INPUT);
    pinMode(led,OUTPUT);
    pinMode(bluetooth,OUTPUT);
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
        digitalWrite(bluetooth,state);     //TURN THE BLUTOOTH DEVICE ON OR OFF
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



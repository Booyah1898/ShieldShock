#include <SoftwareSerial.h>
char data = 0;
int btn=2;
int led=13; 
int bluetooth=8;
volatile int state=LOW;
int dc=4;
void setup() 
{  
    pinMode(btn,INPUT);              //PUSH BUTTON
    pinMode(led,OUTPUT);             //LED
    pinMode(bluetooth,OUTPUT);       //BLUETOOTH
    pinMode(dc,OUTPUT);              //XL6009
    Serial.begin(9600);
}
void loop()
{

     if(digitalRead(btn)==LOW)      
      {     
        while(digitalRead(btn)==LOW);
        delay(10);                      
        while(digitalRead(btn)==LOW);
        state = !state;              
        digitalWrite(bluetooth,state);     //TURN THE BLUTOOTH DEVICE ON OR OFF
        digitalWrite(dc,state);            //TURN THE DC-DC STEP UP POWER SUPPLY ON
      }
   
if(Serial.available() > 0)  // Send data only when you receive data:
{
data = Serial.read();    
Serial.print(data);        //Print Value inside data in Serial monitor
Serial.print("\n");       
if(data == '1')            //led app on and off
digitalWrite(led, HIGH); 
else if(data == '0')      
digitalWrite(led, LOW);   
} 
 
}



#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
char text[161]="Send help"; //buffer to store message
char number[11]=""; //phone number to send message
int cnt;
bool error; //to catch the response of sendSms

void setup(){
    Sim800l.begin(); // initializate the library. 
    Serial.begin(9600);
}

void loop(){  

      //Read the Number
      Serial.print("\nEnter 10 digit Phone Number:");
      while(Serial.available()<=0); // returns -1 if theres no data in the buffer.
      cnt = Serial.readBytesUntil('\n',number, 11); //character ,buffer,length.
      number[cnt] = '\0';
      Serial.println(number);

      //clear the serial input buffer so that no typed characters are pending
            
      delay(1000); //delay required before clearing the input buffer
      while(Serial.available()>0) //clear buffer
      {
        Serial.read();
      }

      //Send the message and display the status
      error = Sim800l.sendSms(number,text);
      if(error)
      Serial.println("Error Sending Message");
      Serial.println("Message Sent Successfully!");
/*Arduino: 1.8.5 (Windows 10), Board: "Arduino/Genuino Mega or Mega 2560, ATmega2560 (Mega 2560)"

Sketch uses 6596 bytes (2%) of program storage space. Maximum is 253952 bytes.
Global variables use 598 bytes (7%) of dynamic memory, leaving 7594 bytes for local variables. Maximum is 8192 bytes.
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_getsync(): timeout communicating with programmer
An error occurred while uploading the sketch
Exception in thread "Thread-59" java.lang.NullPointerException
  at cc.arduino.contributions.libraries.LibrariesIndexer.rescanLibraries(LibrariesIndexer.java:114)
  at cc.arduino.contributions.libraries.LibrariesIndexer.setLibrariesFolders(LibrariesIndexer.java:106)
  at processing.app.BaseNoGui.onBoardOrPortChange(BaseNoGui.java:682)
  at processing.app.Base.onBoardOrPortChange(Base.java:1313)
  at processing.app.Editor$DefaultExportHandler.run(Editor.java:2198)
  at java.lang.Thread.run(Thread.java:748)

This report would have more information with
"Show verbose output during compilation"
option enabled in File -> Preferences.*/

      
}

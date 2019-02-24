/*this code is for making the traffic lights mannulaly controlled 
 using the technology of internet of things as the data coming from 
 controller(in this case the mobile)can be monitored by the person
 sitting at the server and he can judge that if the traffic officer
 is at his/her place or not
 as the abscence of the traffic officer is one of the major problem
 becauze of which major traffic jam occurs  
 */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

char auth[]="27420328c6be4b13900f6f94130090d0";
char ssid[]="aniru";//hotspot name 
char pass[]="19778899";//password
int redled=D0;//(controls the red led) for controling big traffic light we can use relays
int yellowled=D1;//(controls the yellow led) 
int greenled=D2;//(controls the green led) 
int data;// all the controls come at this 

WiFiClient client; 
unsigned long myChannelNumber = 711791;
const char * myWriteAPIKey = "9NHXUAD30DNK0SLY";
void setup()
{
    ThingSpeak.begin(client);
  Serial.begin(9600);//initializing the baud rate
  Blynk.begin(auth, ssid, pass);//giving the servers auth code and node mcu connects to the hotspot and password for getting internet 
  
  pinMode(redled,OUTPUT);//voltage will writed out on this pin
  pinMode(yellowled,OUTPUT);//voltage will writed out on this pin
  pinMode(greenled,OUTPUT);//voltage will writed out on this pin
} 



BLYNK_WRITE(V1)// for red led
{
  data = param.asInt();
  Serial.println(data);
 if(data==1)
 {
  analogWrite(redled,255);
  Serial.print("red led is on\n");
 }
  if(data==0)
  {
    digitalWrite(redled,LOW);
 
  }
ThingSpeak.writeField(myChannelNumber, 1,data, myWriteAPIKey);
}

BLYNK_WRITE(V2)//for yellow led
{

  data = param.asInt();
  Serial.println(data);
 if(data==1)
 {
  analogWrite(redled,255);
  analogWrite(greenled,255);

   Serial.print("yellow led is on\n");
  }
  if(data==0)
  {
 
    analogWrite(redled,0);
  analogWrite(greenled,0);

    }
ThingSpeak.writeField(myChannelNumber, 2,data, myWriteAPIKey);
}


BLYNK_WRITE(V3)//for green led
{

  data = param.asInt();
  Serial.println(data);
 if(data==1)
 {
  analogWrite(greenled,255);
  Serial.print("green led is on\n");
 }
  if(data==0)
  {
    digitalWrite(greenled,LOW);
    
  }
ThingSpeak.writeField(myChannelNumber, 3,data, myWriteAPIKey);
}
void loop()
{
  Blynk.run();
}

/* this project is based on solving a subpart of the major problem traffic management as when an accident occurs the residual parts of the car cause the traffic jam in order to solve that
the towing vans should be fast at the place of the accident and for that they have to be informed first and in orderc to that we have connected these sensors to the iot for but later on we will
connect gsm module to it but for now the main moto is that as soon as the accident occurs and the peizo senses a pressure it sends the data  to the site of mathwork we can create our own site also
but for now we are using the mathworks channel system and continuously the sensor is updating the site */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
char auth[]="27420328c6be4b13900f6f94130090d0";//authentictaion token of blynk server
char ssid[]="aniru";//hotspot name 
char pass[]="19778899";//password
int peizodata;//stores the peizo sensors value
int peizopin=D7;//pin through which the sensor is connected
WiFiClient client; 
unsigned long myChannelNumber = 711791;
const char * myWriteAPIKey = "9NHXUAD30DNK0SLY";//api to that need to be updated for the site
void setup()
{
  Serial.begin(9600);//serial comunniation initialization
  Blynk.begin(auth, ssid, pass);//connnecting to the hotspot
  pinMode(peizopin,INPUT);//sensor that is kept at the major pressure consuming areas of a car
  ThingSpeak.begin(client);//accessing the thingspeak site 
}

void loop() 
{
peizodata=digitalRead(peizopin);//the data is going to the servser continuously and if pressure is applied the sensor sends 1 else if everything is normal it sends 0

  ThingSpeak.writeField(myChannelNumber, 1,peizodata, myWriteAPIKey);//if accident occurs the pressure senor will write a value on the site so that the towing van and ambulance could be send at that place of accident asap
  
  
Blynk.run();//running the blynk
}

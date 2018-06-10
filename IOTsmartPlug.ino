#include <Wire.h>
#include <UnoWiFiDevEd.h>
#include <dht.h>

                            //ThingSpeak Defines
#define CONNECTOR "rest"
#define SERVER_ADDR "api.thingspeak.com"
#define APIKEY_THINGSPEAK "****************" //Your API Key

                           //Pins Defines
#define DHT11PIN 3   //temp sensor
#define ldrPin  A1   //light sensor
#define relayPin 8   //5V relay
#define pirPin 12    //motion sensor 

dht DHT;       //For the DHT11 sensor


void setup() {
  Ciao.begin(); // CIAO INIT
  Serial.begin(9600);

                //Pins Mode
  pinMode(DHT11PIN, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
}

void loop() {
   
  int chk = DHT.read11(DHT11PIN);
  int Temp = DHT.temperature;
  int Humi = DHT.humidity;
  
  int Light = analogRead(ldrPin);
  int Motion = digitalRead(pirPin);

  
  Ciao.println(Temp);
  Ciao.println(Humi);
  Ciao.println(Light);
  Ciao.println(Motion);

                                  //Sending The Data to ThingSpeak
  String uri = "/update?api_key=";
    uri += APIKEY_THINGSPEAK;
    uri += "&field1=";
    uri += String(Temp);
    uri += "&field2=";
    uri += String(Humi);
    uri += "&field3=";
    uri += String(Light);


  Ciao.println("Send data on ThingSpeak Channel");

  CiaoData data = Ciao.write(CONNECTOR, SERVER_ADDR, uri);

  if (!data.isEmpty()){
  Ciao.println( "State: " + String (data.get(1)) );
  Ciao.println( "Response: " + String (data.get(2)) );
  }
  else{
  Ciao.println("Write Error");
  }



                           //Power Automation Controller
  if (Temp > 19)
    if(Light > 1500)
      if(Motion == 0)          //no movment
        digitalWrite(relayPin, LOW);    //disable the power socket
  else
    digitalWrite(relayPin, HIGH);


  delay(30000); // Thinkspeak policy for sending data

}


/* Extra Diteals
 *  Arduino uno Wifi
 *  
 *  Conected thro the web interface to the HotSpot created by my phone. 
 *  
 *  
 *  Using ThingSpeak for the cloud.
 *  Public ThingSpeak Cloud View:
 *  https://thingspeak.com/channels/453554
 *  
 * 
 * */
 */

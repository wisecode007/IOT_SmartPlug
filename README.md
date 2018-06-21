# IOT_SmartPlug

Using Arduino Uno WIFI with the following Components:
* DHT11 - Temperature & Humidity sensor
* LDR Light Sensor
* RIP Motion Sensor
* 5V Relay
# Connections Map
<img src="https://github.com/wisecode007/IOT_SmartPlug/blob/master/OthersFiles/SmartSocket.jpg" width="650" height="650">

# Code Review

In the following block of code, we are doing the automation of the power plug by 3 conditions:
* Temperature - The temperature is in c°
* Light - The light sensetivity is between 1 to 1023.
* Motion - 0 for no movment, 1 for movment
```C++
 if (Temp > /*wanted temperature*/){               
    if(Light > /*wanted light sensetivity*/){   
      if(Motion == /*0 OR 1*/){  
        digitalWrite(relayPin, LOW);    //disable the power socket
      }
    }
  }
  else
    digitalWrite(relayPin, HIGH);
```


In the next block of code, we can



IOT Course, College of Mangment Academic Studies, 2017-2018

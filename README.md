# IOT_SmartPlug

Using Arduino Uno WIFI with the following Components:
* DHT11 - Temperature & Humidity sensor
* LDR Light Sensor
* RIP Motion Sensor
* 5V Relay
# Connections Map
![](https://github.com/wisecode007/IOT_SmartPlug/blob/master/OthersFiles/SmartSocket.jpg)

# Code Review

In the following block of code, 
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




IOT Course, College of Mangment Academic Studies, 2017-2018

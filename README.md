# IOT_SmartPlug

Using Arduino Uno WIFI with the following Components:
* DHT11 - Temperature & Humidity sensor
* LDR Light Sensor
* RIP Motion Sensor
* 5V Relay
# Connections Map
<img src="https://github.com/wisecode007/IOT_SmartPlug/blob/master/OthersFiles/SmartSocket.jpg" width="750" height="750">

The connections pins as shown above in the image:
* DHT11 Signal - Digital 2      (INPUT): Blue Wire.
* RIP Signal - Digital 3        (INPUT): Yellow Wire.
* LDR Signal - Analog 4         (INPUT): Gray Wire.
* 5V Relay - Digital 5          (OUTPUT): Orange Wire.

They are all connected to 5V power - Red Wire, and ground - Black Wire.

(The LDR is connected to a 100K resistor for power redacting)



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



You Can see more pictures of the project in the OthersFiles folder.

IOT Course, College of Mangment Academic Studies, 2017-2018

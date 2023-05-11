# Catfish Embeded Client
This project is an embeded client for the Catfish project.
It collects data from the sensors connected to the Catfish Raspberry Pi(s) and sends it to the backend server using MQTT thanks to the Eclipse Paho MQTT C++ library.

# Usage
## Setup
### Eclipse Paho MQTT C++
First you need to install Eclipse Paho MQTT C++ using the [following instructions](https://github.com/eclipse/paho.mqtt.cpp#building-from-source).

### MQTT configuration
You then need to configure the connection to the MQTT broker by filling the `CLIENT_ID`, `BROKER_ADDRESS`, `BROKER_USER` and `BROKER_PASS`directives in the file `main.hpp`.

## Build
You can compile the project using the following command:
```
g++ -o catfish main.cpp mqtt_client.cpp -std=c++11 -lpaho-mqttpp3 -lpaho-mqtt3as
```

## Run
You can simply run the project by launching the created executable: `./catfish`

# Development
## Sensors
[//]: <> (TODO: Write this section explaining how is the data collected from the sensors.)
the `sensors_data_t` structure is used to store the data collected from the sensors, its method `toString` converts the data to a string that can be sent to the backend server.

## MQTT client
The `mqtt_client` class is used to connect to the MQTT broker thanks to its constructor and the `connect` method.
The `sendMessage` method is then used to publish a message to the `CLIENT_ID` topic containing the data collected from the sensors.

Message content EXAMPLE:
```json
{
  "TIME": "2023-04-27T04:20:00Z",
  "CDOM": 3,
  "NITRATE": 141,
  "DISSOLVED_OXYGEN": 59,
  "PH": 26,
  "INDUCTION": 535,
  "FISH_DEPTH": 8,
  "PRESSURE": 9,
  "DEPTH": 7
}
```

# License
This work is licensed under a [CreativeCreative Commons Attribution-NonCommercial 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/).

[//]: <> (TODO: Add your names below 😉)
Made with 💖 by: Valentin Sene,

![Creative Commons License](https://i.creativecommons.org/l/by-nc/4.0/88x31.png "Creative Commons License")

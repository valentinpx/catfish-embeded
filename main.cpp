#include "main.hpp"

int main(int argc, char** argv)
{
  mqttClient client(CLIENT_ID, BROKER_ADDRESS, BROKER_USER, BROKER_PASS);
  bool connected = client.connect();

  if (!connected) {
    return 1;
  }
  while (connected) {
    // TODO: Read data from sensors and replace the string below with the data struct toString funciton call
    client.sendMessage(CLIENT_ID, "{ \"TIME\": \"2023-04-27T04:20:00Z\", \"CDOM\": 3, \"NITRATE\": 141, \"DISSOLVED_OXYGEN\": 59, \"PH\": 26, \"INDUCTION\": 535, \"FISH_DEPTH\": 8, \"PRESSURE\": 9, \"DEPTH\": 7 }");
    sleep(MSG_INTERVAL);
  }
  return 0;
}

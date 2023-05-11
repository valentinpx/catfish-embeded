#ifndef MQTT_CLIENT_HPP
#define MQTT_CLIENT_HPP
#define TIMEOUT 30
#define QOS 1

#include <mqtt/client.h>

class mqttClient {
  public:
    mqttClient(const std::string &id, const std::string &address,
      const std::string &username, const std::string &password);
    bool connect();
    void sendMessage(const std::string &topic, const std::string &payload);
  private:
    mqtt::async_client client;
    mqtt::connect_options opt;
};

#endif

#include "mqtt_client.hpp"

mqttClient::mqttClient(const std::string &id, const std::string &address,
  const std::string &username, const std::string &password)
  : client(address, id), opt(username, password)
{
  opt.set_connect_timeout(TIMEOUT);
  opt.set_automatic_reconnect(true);
  opt.set_clean_session(true);
}

bool mqttClient::connect()
{
  try {
    mqtt::token_ptr token = client.connect(opt);

    token->wait();
    printf("Connection to the backend successful with client id: <%s>.\n",
      client.get_client_id().c_str());
    return true;
  }
  catch (const mqtt::exception& exc) {
    printf("Connection to the backend failed: %s\n", exc.what());
    return false;
  }
}

void mqttClient::sendMessage(const std::string &topic, const std::string &payload) {
  mqtt::message_ptr msg = mqtt::make_message(topic, payload);

  msg->set_qos(QOS);
  client.publish(msg)->wait();
}

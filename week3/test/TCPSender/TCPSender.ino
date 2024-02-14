#include <WiFiNINA.h>

WiFiClient client;

const char server[] = "10.23.10.107"; //local IP address of receiver device goes here
const int portNum = 2345; //desired port # goes here. Make sure the receiver is listening on the same port!

//be sure to remove WiFi network details before uploading this code!
const char WIFI_SSID[] = "sandbox370"; //WiFi network name goes here
const char WIFI_PASS[] = "+s0a+s03!2gether?"; //WiFi password goes here

void setup() {
  Serial.begin(9600);
  //retry connection until WiFi is connected successfully
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    // Attempt connection to WPA/WPA2 network.
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(3000);
  }
  Serial.println("connected!");
}

void loop() {
  //connect to client if disconnected, or send TCP message if conected
  if (!client.connected()) {
    Serial.println("connecting");
    client.connect(server, portNum);
    delay(1000);
    return;
  } else {
    //add something more interesting here
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    client.print(sensorValue);
    delay(300);
  }
}

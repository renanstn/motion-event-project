
#include <WiFi.h>
#include <HTTPClient.h>

const int signal_pin = 15;

const char* ssid = "*****";
const char* password = "*****";

void setup()
{
    pinMode(signal_pin, INPUT);
    delay(4000);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void loop()
{
    if ((WiFi.status() == WL_CONNECTED)) {
        HTTPClient http;
        http.begin("192.168.1.36", 5000, "/alert");
        int signal_on = digitalRead(signal_pin);
        if (signal_on == HIGH) {
            int httpCode = http.GET();
            delay(5000);
        }
        http.end();
    }
    delay(50);
}

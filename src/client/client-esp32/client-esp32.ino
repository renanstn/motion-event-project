#include <WiFi.h>
#include <HTTPClient.h>

const int touch_pin = 15;

const char* ssid = "******";
const char* password = "******";

void setup()
{
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
        int touchValue = touchRead(touch_pin);
        if (touchValue < 50) {
            int httpCode = http.GET();
        }
        http.end();
    }
    delay(500);
}

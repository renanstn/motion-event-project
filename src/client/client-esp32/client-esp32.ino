#include <WiFi.h>
#include <HTTPClient.h>

const int signal_pin = 15;

const char* ssid = "*****"; // Coloque aqui o nome da sua rede wifi
const char* password = "*****"; // Coloque aqui a senha da sua rede wifi

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
        http.begin("0.0.0.0", 5000, "/alert"); // Coloque aqui o IP do seu PC
        int signal_on = digitalRead(signal_pin);
        if (signal_on == HIGH) {
            int httpCode = http.GET();
            delay(5000);
        }
        http.end();
    }
    delay(50);
}

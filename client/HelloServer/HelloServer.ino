#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "********";
const char* password = "********";

void setup()
{
    Serial.begin(115200);
    delay(4000);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println("Connected to the WiFi network");
}
 
void loop()
{
    if ((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

        http.begin("192.168.1.34", 5000);
        int httpCode = http.GET();

        if (httpCode > 0) {
            String payload = http.getString();
            Serial.println(httpCode);
            Serial.println(payload);
    
        } else {
            Serial.println("Error on HTTP request");
        }

        http.end();
    }

    delay(5000); // Taxa de atualizacao: 1 seg
}

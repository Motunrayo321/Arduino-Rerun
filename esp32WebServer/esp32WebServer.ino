#include <WiFi.h>

String SSID = "UNILAG_DS_2.4";
String password = "$Uds@11_21";

const int RED = 2;
const int SPEAKER = 5;

WiFiServer server(80);

bool receiving = false;


void setup() {

  pinMode(RED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(115200);

  Serial.println("Connecting to: ");
  Serial.println(SSID);

  WiFi.begin(SSID, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.println("Connected!");
  server.begin();
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

  WiFiClient client = server.available();

  if (client) {
    Serial.println("Client connected");

    bool sentHeader = false;
    bool currentLineIsBlank = true;

    while (client.connected()) {
      if (client.available()) {

        char c = client.read();
        Serial.write(c);
        Serial.println();

        if (c == ' ' and receiving) receiving = false;
        if (c == '?') receiving = true;

        if (receiving) {

          if (c == 'L') {
            Serial.println("Toggling pin: ");
            int pin = client.parseInt();
            Serial.println(pin);
            digitalWrite(pin, !digitalRead(pin));
            break;
          }

          else if (c == 'S') {
            Serial.println("Adjusting frequency...");
            int pin = client.parseInt();
            int frequency = client.parseInt();

            if (frequency = 0) noTone(pin);
            else if (frequency > 0 && frequency <= 1000) tone(pin, frequency, 5000);
            break;
          }
        }

        if (!sentHeader) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html\n");

          client.println("<form action='' method='get'>");
          client.println("<input type='hidden' name='L' value='2' />");
          client.println("<input type='submit' value='Toggle Red' />");
          client.println("</form>");

          client.println("<form action='' method='get'>");
          client.println("<input type='range' name='S' min='0' max='1000' step='100' value='5'/>");
          client.println("<input type='submit' value='Set Frequency' />");
          client.println("</form>");

          sentHeader = true;
        }

        if (c == '\n' and currentLineIsBlank) break;
        if (c == '\n' and currentLineIsBlank) currentLineIsBlank = true;

        else if (c != '\r') currentLineIsBlank = false;
      }
    }

    delay(50);
    client.stop();

    Serial.println("Client disconnected");
  }
}

#include <WiFi.h>

String SSID = "UNILAG_DS_2.4";
String password = "$Uds@11_21";

const int RED = 2;
const int SPEAKER = 5;

WiFiServer server(80);

String header;
String currentLine = "";


void setup() {

  pinMode(RED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(115200);

  Serial.println("\nConnecting to: ");
  Serial.println(SSID);

  WiFi.begin(SSID, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.println("Connected!");
  server.begin();
  Serial.println("\nIP Address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

  WiFiClient client = server.available();

  if (client) {
    Serial.println("\nClient connected");

    bool sentHeader = false;
    bool currentLineIsBlank = true;

    while (client.connected()) {
      if (client.available()) {
        // Serial.println("Available");

        char c = client.read();
        Serial.write(c);

        currentLine += c;
        header += c;
        

        if (c == '\n') {
          
          if (currentLine != 0) {

            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("LED on");
              // output26State = "on";
              digitalWrite(RED, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
                Serial.println("LED off");
                // output26State = "off";
                digitalWrite(RED, LOW);
            }


            if (c == 'Q') {
              Serial.println("Toggling pin: ");
              int pin = client.parseInt();
              Serial.println(pin);
              digitalWrite(pin, !digitalRead(pin));
              break;
            }

          

            else if (c == 'Q') {
              Serial.println("Adjusting frequency...");
              int pin = client.parseInt();
              int frequency = client.parseInt();

              if (frequency = 0) noTone(pin);
              else if (frequency > 0 && frequency <= 1000) tone(pin, frequency, 5000);
              break;
            }
          }

        } else if (c != '\r') currentLine += c;

        if (!sentHeader) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html\n");
          
          client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");

          client.println("<form action='' method='get'>");
          client.println("<input type='range' name='S' min='0' max='1000' step='100' value='5'/>");
          client.println("<input type='submit' value='Set Frequency' />");
          client.println("</form>");

          sentHeader = true;
        }

        currentLine = "";
      }
    }

    // delay(50);
    client.stop();

    Serial.println("Client disconnected");
  }
}

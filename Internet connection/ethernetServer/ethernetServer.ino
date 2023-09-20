#include <Ethernet.h>   // Include Ethernet library
#include <SPI.h>

const int LED =2;
const int SPEAKER =3;

// Ethernet and server details
byte MAC[] = { 0*64, 0*59, 0*64, 0*56, 0*64, 0*56 };   // Define Mac address

EthernetServer server = EthernetServer(80);   // Start Ethernet on port 80 for web

bool receiving = true;   // Value to check if client is sending data


void setup() {

  pinMode(LED, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(112500);

  // Connect to Ethernet shield
  if (!Ethernet.begin(MAC)) {   // Start ethernet session with address
    Serial.println("Unable to connect!");
    return;   // Exit the program if connection is not made
  }
  else Serial.println("Connected!");

  // Start up server
  server.begin();   // Start server if connection is made
  Serial.println("IP Address: ");
  Serial.println(Ethernet.localIP());   // Print DHCP assigned ip address
}

void loop() {

  EthernetClient client = server.available();   // create client variable for server

  if (client) {   // If a client is available
    bool sentHeader = false;
    bool currentLineIsBlank = true;

    while (client.connected()) {   // Loop through if client is still connected

      if (client.available()) {   // If client is sending data

        char c = client.read();   // Read and store client data (in url)

        if (c == ' ' and receiving) receiving = false;   // If the data is empty, server is not receiving anything
        if (c == '?') receiving = true;   // If there is a ? (variable) command, server is receiving data

      // While client is interacting with webpage
        if (receiving) {
          if (c == 'L') {   // If the value of ? is L, we are focusing on the led
            Serial.println("Toggling light...");

            int pin = client.parseInt();   // Take the first (and last) integer from the url
            digitalWrite(pin, !digitalRead(pin));   // Write value to led and change state
            break;   // Exit loop and listen for commands again
          }

          else if (c == 'S') {
            Serial.println("Adjusting frequency...");

            int pin = client.parseInt();   // Take the first integer from the url
            int frequency = client.parseInt();   // Take the second integer from the url

            if (frequency == 0) noTone(pin);   //  Turn off speaker
            else if (frequency > 0 && frequency <= 1000) tone(pin, frequency, 5000);   // Write value to speaker and change frequency
            break;   // Exit loop and listen for commands again
          }
        }

        // Load webpage for client (Should come first?)
        if (!sentHeader) {   // If webpage has not been rendered before

          // Header info
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html\n");   // Don't forget blank line after header

          // Content of html page
          client.println("<form action='' method='get'>");   // Get info (shows in url)
          client.println("<input type='hidden' name='L' value='2' />");   // 2 is pin number, L for Led
          client.println("<input type='submit' value='Toggle led' />");
          client.println("</form>");

          client.println("<form action='' method='get'>");
          client.println("<input type='range' name='S' min='0' max='1000' step='100' value='3'/>");   // Slide for frequency, 3 is pin number
          client.println("<input type='submit' value='Set Frequency' />");
          client.println("</form>");

          sentHeader = true;   // Update value to indicate that webpage has been rendered to client
        }

        // Not entirely sure of the variable function
        if (c == '\n' && currentLineIsBlank) break;   // Update: That's 2 empty lines in a row. Ergo, end of http request
        if (c == '\n') currentLineIsBlank = true;

        if (c != '\r') currentLineIsBlank = false;
      }
    }

    delay(50);   // Leaves time between clients
    client.stop();   // Terminates client session if they are no longer connected
  }
}
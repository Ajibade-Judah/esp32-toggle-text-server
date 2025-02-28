#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Create WebServer object on port 80
WebServer server(80);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  Serial.println("ESP32 starting...");
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print ESP32 Local IP Address
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Add CORS headers to responses
  server.enableCORS(true);
  
  // Route for toggle state
  server.on("/toggle", HTTP_GET, []() {
    if (server.hasArg("state")) {
      String toggleState = server.arg("state");
      Serial.print("Toggle: ");
      Serial.println(toggleState);
      
      server.send(200, "text/plain", "OK");
    } else {
      server.send(400, "text/plain", "Missing state parameter");
    }
  });

  // Route for receiving text
  server.on("/text", HTTP_POST, []() {
    if (server.hasArg("message")) {
      String receivedText = server.arg("message");
      Serial.print("Text: ");
      Serial.println(receivedText);
      
      server.send(200, "text/plain", "OK");
    } else {
      server.send(400, "text/plain", "Missing message parameter");
    }
  });

  // Start server
  server.begin();
  Serial.println("Server ready");
}

void loop() {
  // Handle client requests
  server.handleClient();
  delay(2);
}
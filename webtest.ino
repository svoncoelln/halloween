#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Set WiFi credentials
#define WIFI_SSID "Virus.exe"
#define WIFI_PASS "goodpassword"

// Create a new web server
ESP8266WebServer webserver(80);

// Handle Root
void rootPage() { 
  webserver.send(200, "text/plain", "Hello World!"); 
}

// Handle 404
void notfoundPage(){ 
  webserver.send(404, "text/plain", "404: Not found"); 
}

void setup() {
  // Setup serial port
  Serial.begin(115200);
  Serial.println("setup");

  //Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.println("connecting...");
    delay(100); 
  }

  // WiFi Connected
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // Start Web Server
  webserver.on("/", rootPage);
  Serial.print("server.on");
  webserver.onNotFound(notfoundPage);
  webserver.begin();
}

// Listen for HTTP requests
void loop(void){ 
  webserver.handleClient(); 
}
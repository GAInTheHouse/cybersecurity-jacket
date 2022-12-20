#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h" 

#define WIFI_PIN 5
#define VIRUS_PIN 6 
#define ACCESS_PIN 9

char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key index number (needed only for WEP)
char website[60000];
IPAddress server(34,172,125,189);
WiFiClient client;
int status = WL_IDLE_STATUS;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
     Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
     Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the status:
  printWifiStatus();

  pinMode(WIFI_PIN, OUTPUT);
  pinMode(VIRUS_PIN, OUTPUT);
  pinMode(ACCESS_PIN, OUTPUT);
}


void readWebsite(){
  if (client.connect(server, 5000)) {
    Serial.println("connected to server");
    
    // Make a request:
    client.println("GET / HTTP/1.1");
    client.println("Host: www.example.com");
    client.println("Connection: close");
    client.println();
    delay(1250);
  }
  else{
    Serial.println('Connection Failed');
  }
  int ctr = 0;
  if (client) {
      while (client.available()) {
    website[ctr] = client.read();
    ctr += 1;
    }
  }
  website[ctr] = '\0';
  //Serial.println(website);

}

void loop() {
  Serial.println("First trial");
  readWebsite();
  //Serial.print(website);
  char s2[] = "raw-data";
  char *ptr;
  ptr = strstr(website, s2);
  //Serial.print(ptr);
  char *ptr2 = strstr(ptr, "<p>");
  char *pretext = strtok(ptr2, " ");
  char *c1 = strtok(NULL, " ");

  char *c2 = strtok(NULL, " ");
  char *c3 = strtok(NULL, " ");
    Serial.print(c1);
  Serial.print(c2);
  Serial.println(c3);
  if (strstr(c1, "red")){
  analogWrite(WIFI_PIN, 255);
  }
  if (strstr(c1, "yellow")){
  analogWrite(WIFI_PIN, 127);
  }
  if (strstr(c1, "green"))
  analogWrite(WIFI_PIN, 15);
  delay(250);

  if (strstr(c2, "red")){
  analogWrite(VIRUS_PIN, 255);
  }
  if (strstr(c2, "yellow"))
  analogWrite(VIRUS_PIN, 127);
  if (strstr(c2, "green"))
  analogWrite(VIRUS_PIN, 15);
  delay(250);
  
  if (strstr(c3, "red")){
  analogWrite(ACCESS_PIN, 255);
  }
  if (strstr(c3, "yellow"))
  analogWrite(ACCESS_PIN, 127);
  if (strstr(c3, "green"))
  analogWrite(ACCESS_PIN, 15);
  
  //free(ptr);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

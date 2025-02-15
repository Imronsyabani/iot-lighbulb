//D4, D5 & 19
#include <WiFi.h>
#include <WebServer.h>

// inisiati webserver yang akan berjalan di port 80
WebServer server(80);

// inisiasi semua variable disini
const char* ssid = "Hafizh";
const char* password = "Hafizzzh123";
const int espled = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;

bool dapurLedState = false;
bool kamarLedState = false;
bool tamuLedState = false;

void setup() {
  // put your setup code here, to run once:
  // sesuai komentar inisiasi semua kebutuhan di fungsi setup

  // Serial akan memonitoring semua yang menggunakan syntax Serial.print
  //115200 itu adalah angka baud rate pada serial monitor
  Serial.begin(115200);
  
  // inisiasi pin yang akan menjadi output
  pinMode(espled, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // pin yang sudah diinisiasi bisa dilakukan set value
  // HIGH lampu akan menyala & LOW lampu akan redup
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  // konek ke wifi menggunakan library WiFi dengan method begin(ssid wifi, password wifi)
  WiFi.begin(ssid, password);
  Serial.print("Connecting Wifi Hafizzzh");

  //checking connection
  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(espled, LOW);
    delay(1000);
    Serial.print(".");
  }

  //esp32 itu mempunyai pin bawaan dengan nomer pin 2
  digitalWrite(espled, HIGH);
  Serial.println("");
  Serial.println("Connected To Wifi Hafizzzh");
  Serial.println(WiFi.localIP()); // return ip yang didapat dari wifi

  // SET ROUTE menggunakan class server dengan method on yang akan menjadi api
  // method "on" mengisi 3 parameter utama
  // 1 route yang akan diisi '/dapur'
  // 2 http request method yang akan digunakan 'GET' = HTTP_GET & 'POST' = HTTP_POST
  // 3 callback fungsi yang akan ditrigger response

  server.on("/dapur", HTTP_GET, getDapurLed); 
  server.on("/kamar", HTTP_GET, getKamarLed); 
  server.on("/tamu", HTTP_GET, getTamuLed); 

  server.on("/dapur", HTTP_POST, setDapurLed); 
  server.on("/kamar", HTTP_POST, setKamarLed); 
  server.on("/tamu", HTTP_POST, setTamuLed); 
  server.begin();
  Serial.print("Server Started...");
}

void loop(){
  server.handleClient();
}

void setDapurLed(){
  dapurLedState = !dapurLedState;
  digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void setKamarLed(){
  kamarLedState = !kamarLedState;
  digitalWrite(ledPin2, kamarLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", kamarLedState ? "ON" : "OFF");
}

void setTamuLed(){
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin3, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void getDapurLed(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void getKamarLed(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", kamarLedState ? "ON" : "OFF");
}

void getTamuLed(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

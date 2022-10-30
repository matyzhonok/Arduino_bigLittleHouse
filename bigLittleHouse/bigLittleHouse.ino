/*
 * Это главный файл проекта
 * 
 */


#include <ESP8266WiFi.h>

// Настройки сети. TODO: вынести в отдельный файл
#ifndef STASSID
#define STASSID ""
#define STAPSK  ""
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// Устанавливаем, на какой порту будет работать наш веб-сервер
WiFiServer server(80);

/* 
 * МОИ ПЕРЕМЕННЫЕ 
 */

// IP-адрес сервера (платы)
String MyIP;


void setup() {
  Serial.begin(115200);
  delay(500);

  // Подключаемся к wi-fi сети
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Получаем ip-адрес от DHCP");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  
  // Запускаем web-сервер и запоминаем его IP-адрес
  server.begin();
  MyIP = WiFi.localIP().toString();
  Serial.print(F("Web-сервер запущен по адресу: "));
  Serial.println(MyIP);
}

void loop() {
    
  // Ждём подключения клиента
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F(""));
  Serial.println(F("Новый запрос"));
  
  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.print("Запрос от клиента: ");
  Serial.println(req);

  run_Request(req, client);

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
  Serial.println(F("-------------------------"));
}

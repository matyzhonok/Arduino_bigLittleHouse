
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

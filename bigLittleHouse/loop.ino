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



  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
  Serial.println(F("-------------------------"));
}

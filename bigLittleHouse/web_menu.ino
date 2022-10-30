void run_Request (String requestString, WiFiClient client) {
  // Целевая строка должна начинаться на "GET /?SetPin=""GET /?SetPin=" - проверяем это
  if (requestString.startsWith("GET /?SetPin=")) {
    // отрезаем проверенную часть
    requestString.remove(0,13);
    // и считываем, к какому пину запрос (номер пина - две цифры)
    int pin = requestString.substring(0,2).toInt();
    // дальше понимаем, какое действие нужно сделать
    if (requestString.indexOf("Value=ON") != -1) {
      // Нужно включить заданный пин
      setPinState(pin, "ON");
    } else if (requestString.indexOf("Value=OFF") != -1)  {
      // Нужно выключить заданный пин
      Serial.println("OFF");
      setPinState(pin, "OFF");
    } else {
      // Непонятно, что нужно сделать с пином
      Serial.println("Неизвестное требуемое состояние пина № " + pin);
    }
  } else {
    Serial.println("Неизвестный запрос");
  }
  
  

}

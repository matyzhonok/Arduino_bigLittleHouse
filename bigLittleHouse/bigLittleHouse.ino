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

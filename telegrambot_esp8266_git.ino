#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>


#define LED 1
// Initialize Wifi connection to the router
const char* ssid     = ;
const char* password = ;
//const char* ssid     = 
//const char* password = ;
const char BotToken[] = ;

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);
  
void setup() 
{  
  Serial.begin(115200);  
  while (!Serial) {}  //Start running when the serial is open 
  delay(1000);  
  // attempt to connect to Wifi network:  
  Serial.print("Connecting Wifi: ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){  
   Serial.println(".");   
   delay(1000);  
   }  
 Serial.println("");  
 Serial.println("WiFi connected");  
 bot.begin();  
 //pinMode(LED, OUTPUT);  
 Serial.println("Bot ready");
}  
void loop() 
{  
 message m = bot.getUpdates(); // Read new messages 
 
 Serial.println("New message detected: " + m.text); 
 
 if (m.text.equals("on")) {  
   //digitalWrite(LED, 1);   
   bot.sendMessage(m.chat_id, "The Led is now ON");  
 }else if (m.text.equals("off")){  
   //digitalWrite(LED, 0);   
   bot.sendMessage(m.chat_id, "The Led is now OFF");  
 }else {
  bot.sendMessage(m.chat_id, "Unknown command. Try on or off");
 } 
}
 

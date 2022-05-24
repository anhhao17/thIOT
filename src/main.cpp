#include <Arduino.h>
//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

#define dht_pin 1 //your pin config
// LCD, 0x27 address of PCF8..
LiquidCrystal_I2C lcd(0x27,16,2);
//DHT11
DHT dht(dht_pin,DHT11);


//read DHT show LCD and trigger Firebase to send data
void dhtApp(void *param){

}

//takeNotify from dhtApp and send to firebase
void FirebaseApp(void *param){


}
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  dht.begin();

  xTaskCreatePinnedToCore(
    dhtApp, "DHT", 8096, NULL, 1, NULL,app_cpu
  );
  xTaskCreatePinnedToCore(
    FirebaseApp, "Firebase", 8096, NULL, 1, NULL,app_cpu
  );
   


}


void loop() {
  


}
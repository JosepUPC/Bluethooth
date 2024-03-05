#include <Arduino.h>
#include <Adafruit_NeoPixel.h>  //Incluimos la librería Adafruit_NeoPixe

// pin del led RGB en PCB
#define PIN      48  // ESP32S3 Generic -n8r2-

// Un solo led en PCB
#define NUMPIXELS 1

// Inicializamos el objeto "pixels"
// Argumento 1 = número de pixeles 
// Argumento 2 = número del pin de datos
// Argumento 3 = tipo de pixel: NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);
// Time (en milliseconds) pausa entre pixels
#define DELAYVAL 500 

// x = operacion que deseas hacer
// y = primer valor
// z = segudo valor
int change (bool x, int y, int z);
int change (bool x, int y, int z);

uint16_t r=0;
uint16_t g=0;
uint16_t b=0;
boolean rr=true;
boolean gg=true;
boolean bb=true;

void change (boolean n);

void setup() {
  delay(500);
  // Inicializamos el objeto pixels
  pixels.begin(); 
  Serial.begin(115200);
  delay(500);
  // Información chip
  Serial.println("\n\n================================");
  Serial.printf("Chip Modelo: %s\n", ESP.getChipModel());
  Serial.printf("Chip Revision: %d\n", ESP.getChipRevision());
  Serial.printf("E %d core\n", ESP.getChipCores());
  Serial.printf("Flash Chip capacidad: %d \n", ESP.getFlashChipSize());
  Serial.printf("Flash Chip velocidad: %d \n", ESP.getFlashChipSpeed());

  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  Serial.printf("\nCaracteristicas:\n %s\n %s\n %s\n %s\n %s\n",
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "flash en ESP32" : "Sin flash en ESP32",
      (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "2.4GHz WiFi" : "Sin Wifi",
      (chip_info.features & CHIP_FEATURE_BLE) ? "Bluetooth LE" : "Sin Bluetooth LE",
      (chip_info.features & CHIP_FEATURE_BT) ? "Bluetooth" : "Sin Bluetooth",
      (chip_info.features & CHIP_FEATURE_IEEE802154) ? "IEEE 802.15.4" : "NO IEEE 802.15.4");
  // MAC Address
  String MACString = "";
  uint64_t chipid = ESP.getEfuseMac(); 
  for (int i=0; i<6; i++) {
    if (i > 0) MACString.concat(":");
    uint8_t Octet = chipid >> (i * 8);
    MACString.concat(String(Octet, HEX));
  }boolean rr=true;
  Serial.println("MAC: " + MACString);
}

void loop() {

  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show(); 
  delay(1);  

  if (r>250)
    rr = false;
  else if (r<1)
      rr = true;
    if (g>250)
    gg = false;
  else if (g<1)
      gg = true;
    if (b>250)
    bb = false;
  else if (b<1)
      bb = true;

  r= change (rr, r, 1);
  g= change (gg, g, 2);
  b= change (bb, b, 3);
  /*
  // encendemos con el color rojo
  pixels.setPixelColor(0, pixels.Color(150, 0, 0));
  // enviamos
  pixels.show();   
  Serial.println("R");
  delay(DELAYVAL); 
  
  // encendemos con el color verde, con brillo moderado
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();    
  Serial.println("G");
  delay(DELAYVAL); 
  
  // encendemos con el color azul, con brillo moderado
  pixels.setPixelColor(0, pixels.Color(0, 0, 150));
  pixels.show();     int change (bool x, int y);
  Serial.println("B");
  delay(DELAYVAL); */
  
}

int change (bool x, int y, int z){
  if (x)
    return y+z;
  else 
    return y-z;
}
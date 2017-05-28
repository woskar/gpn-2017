#include <GPNBadge.hpp>
#include <FS.h>
#include "rboot.h"
#include "rboot-api.h"
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/Picopixel.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Badge badge;

void setup() {
  badge.init();
  badge.setBacklight(true);
  delay(300);
  rboot_config rboot_config = rboot_get_config();
  SPIFFS.begin();
  File f = SPIFFS.open("/rom"+String(rboot_config.current_rom),"w");
  f.println("Hello World!\n");
  tft.begin();
  tft.setTextSize(3.5);
  tft.setRotation(2);
  tft.scroll(32);
  tft.fillScreen(BLACK);
  tft.setTextColor(RED);
  tft.print("Hello\nWorld!\n\nI am\nOskar.");
}

void loop() {
  tft.writeFramebuffer();
}

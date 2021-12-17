#include "Screen.h"

unsigned long now, last_time;

void setup_screen() {
  Heltec.display->clear();
  Heltec.display->setColor(WHITE);
  Heltec.display->drawRect(0, 0, 45, 12);  
#ifdef CLASSIC
  Heltec.display->drawString(2,0, "Classic");
#else
  Heltec.display->drawString(2,0, "NimBLE");
#endif

  for (int i = 0; i < NUM_CONNS ; i++) {
    Heltec.display->drawCircle(CON_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD);
    Heltec.display->drawCircle(TO_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD);
    Heltec.display->drawCircle(FROM_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD);
  }
  
  Heltec.display->drawString(CON_COL-10, TITLES, "Con  To  Frm"); 
  Heltec.display->drawString(0, SPK_TEXT, "Spark"); 
  Heltec.display->drawString(0, APP_TEXT, "App"); 
  Heltec.display->drawString(0, BLE_MIDI_TEXT, "BLE MIDI"); 
  Heltec.display->drawString(0, USB_MIDI_TEXT, "USB MIDI");
  Heltec.display->drawString(0, SER_MIDI_TEXT, "SER MIDI");
  Heltec.display->display();
  
  now = millis();
  last_time = millis();
}



void show_status() {
  int rad;

  if (millis() - now > 50) { // only do this evey 50ms so we don't keep redrawing!
    now = millis();
  
    for (int i = 0; i <= 1; i++) 
      for (int j = 0; j < NUM_CONNS; j++) 
        if (now - conn_last_changed[i][j] <= 900) {
          rad = FILL_RAD - int(FILL_RAD * (now - conn_last_changed[i][j]) / 800); 
          Heltec.display->setColor(BLACK);
          Heltec.display->fillCircle(i == TO ? TO_COL : FROM_COL, SPK_ICON + j * LINES_GAP, CIRC_RAD);
          Heltec.display->setColor(WHITE);
          Heltec.display->drawCircle(i == TO ? TO_COL : FROM_COL, SPK_ICON + j * LINES_GAP, CIRC_RAD);  
          if (rad > 0) {
            Heltec.display->fillCircle(i == TO ? TO_COL : FROM_COL, SPK_ICON + j * LINES_GAP, rad);  
            }
          Heltec.display->display();
        }

    for (int j = 0; j <= 2; j++) 
      if (conn_last_changed[STATUS][j] >= last_time)
        if (conn_status[j]) {
          Heltec.display->setColor(WHITE);
          Heltec.display->fillCircle(CON_COL, SPK_ICON + j * LINES_GAP, CIRC_RAD);
          Heltec.display->display();
        }
        else {
          Heltec.display->setColor(BLACK);
          Heltec.display->fillCircle(CON_COL, SPK_ICON + j * LINES_GAP, CIRC_RAD);
          Heltec.display->setColor(WHITE);
          Heltec.display->drawCircle(CON_COL, SPK_ICON + j * LINES_GAP, CIRC_RAD);
          Heltec.display->display();
        }
  
    last_time = now;
  }
}

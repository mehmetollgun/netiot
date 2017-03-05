#include <VirtualWire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
String kelime;
int sayac=0;
 char harf[32];
char*mesaj;

void setup() {
   Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_set_rx_pin(7);
    vw_setup(4000);
    vw_rx_start();
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if(vw_get_message(buf, &buflen))
    {
        for(int i=0;i<buflen;i++)
        {
          harf[i]=buf[i];
            sayac++;

        }
        lcd.begin(16,2);
lcd.clear();

        for(int j=0;j<sayac-1;j++)
        {
          lcd.print(harf[j]);
        }
    }
}

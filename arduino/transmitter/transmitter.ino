#include <VirtualWire.h>
char mesaj[32];
String kelime;
int sayac=0;
 char harf[32];
void setup() {
  // verici
Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(7);
  vw_setup(4000);
}
void islem()
{
   int gelen=Serial.read();



  harf[sayac]=gelen;
 


  kelime+=harf[sayac];
 
 

 mesaj[sayac]+=harf[sayac];
 sayac++;
vw_send((uint8_t *)mesaj,strlen(mesaj));
vw_wait_tx();



}
void loop() {
  // mehmet olgun




if(Serial.available())
{
islem();
 
delay(500);

}
else
{
   kelime="";
   
}

}

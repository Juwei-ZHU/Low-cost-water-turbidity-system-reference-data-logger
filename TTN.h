#include <MKRWAN_v2.h>

LoRaModem modem;

String appEui="0000000000000006";                                             
String appKey="05139E5BD2584561EAF416C92E527744"; 


void TTNsetup() {
   
   OLEDlms(" TTN setup "); 
   
  modem.begin(EU868);
  
  int connected = modem.joinOTAA(appEui, appKey);
   if(connected){
   OLEDlms(" TTN OK ");  
    delay(1000);  
   }
    else
    {
    OLEDlms(" TTN Failed "); 
    delay(3000); 
    }
}

void sendtoTTN(){ // function to send data to TTN
  
  byte payload[8];
  
  payload[0] = year-2000; 
  payload[1] = month;
  payload[2] = day; 
  payload[3] = hour;
  payload[4] = minute;
  payload[5] = second;
  payload[6] = count/256;
  payload[7] = count%256;

  modem.setPort(3);
  modem.beginPacket();
  modem.write(payload, sizeof(payload));   
  modem.endPacket(false);
  OLEDlms(" Send OK "); 
  delay(3000);
}

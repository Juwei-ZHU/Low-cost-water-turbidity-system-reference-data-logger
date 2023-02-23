#include <SPI.h>
#include <SD.h>

const char* SAVE_DATA_FILE_NAME = "DATA.CSV";
String DATA_Header = "DS3231 (UTC+2), Voltage count, Votage (count*0.1875 mV), Current=mV/250, NTU=(mV-1000)/4";
File SaveDATA;

const char* SAVE_TTN_FILE_NAME = "TTN.CSV";
String TTN_Header = "DS3231 (UTC+2), Voltage count, Votage (count*0.1875 mV), Current=mV/250, NTU=(mV-1000)/4";
File SaveTTN;

const int chipSelect = 4;

void SDsetup(){

 //   SD.begin(chipSelect);
  
   if (SD.begin(chipSelect)) {
     OLEDlms(" SD OK ");  
     delay(1000);
  }
  else{
     while(1)
   {   OLEDlms(" SD Failed ");  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second}
  }
}
}

void saveDATAln(String data) {

    SaveDATA = SD.open(SAVE_DATA_FILE_NAME, FILE_WRITE);
    
  if (SaveDATA.size() == 0){    
        SaveDATA.println(DATA_Header);
        SaveDATA.flush();
     }

  if (SaveDATA) {
    SaveDATA.println(data);
    SaveDATA.close();
    delay(1000);
    OLEDlms(" Save OK "); 
    delay(1000);

    
  }    
  else
  {
    while(1)
  {
   OLEDlms(" Save Failed ");  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    }
    }
}


void saveTTNln(String data) {

    SaveTTN = SD.open(SAVE_TTN_FILE_NAME, FILE_WRITE);
    
  if (SaveTTN.size() == 0){    
        SaveTTN.println(TTN_Header);
        SaveTTN.flush();
     }

  if (SaveTTN) {
    SaveTTN.println(data);
    SaveTTN.close();
  }    
//  Serial.println("Save TTN to SD card done!");
}

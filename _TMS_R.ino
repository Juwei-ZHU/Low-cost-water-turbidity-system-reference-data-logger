/* PROGRAM OF A LOW-COST TURBIDIMETER TEST PLATFORM
 * UINSING ARDUINO MKR WAN 1310, ADS1115, SEN0189, DS3231 
 * Mind4Stormwater project: http://mind4stormwater.org, , feel free to use, reuse, modify, share!!
 * INSA Lyon
 * ZHU Qingchuan - qingchuan.zhu@insa-lyon.fr
 * ----- last version May 2022 ----
 *  
 *  *  FUNCTIONS *  *
 *  
 *  Send data to The Things Network platform every 5 minutes
 *  Save data in SD card every minute
 *  
 //== all comments to check!!
*/ 
const String versioncode ="16 June 2022"; //version of the code
#include "0_Libraries.h"  

int i = 0; // Adding index for RG-15, ML8511 and SI1145

void setup () { 

  OLEDsetup();
  
  Serial.begin(9600); //Begin the Serial at 9600 Baud
//  OLEDlms(" Waite SM");
  
//  while(!Serial);
  Serial.println(printHeader);

  DS3231setup(); // Initialize RTC DS3231
  
  ADS1115setup();

  SDsetup(); // Initialize to use SD card

  TTNsetup(); // Initialize the connection to TTN

  pinMode(LED_BUILTIN, OUTPUT);


}

void loop () {
  
  DateTime now = rtc.now();
  delay(500);
  getRTC(now);
  OLEDlms(stringRTC());

 if(now.second() == 0) { // Get data every minute:    
// if(now.second()%10 == 0) { 

  
  getRTC(now); // get date and time from DS3231
  
  ADS1115get();
  
  preparePrint(); // Prepare the string to print in serial monitor
  
  Serial.println(allData);

  OLEDshow();
  delay(5000);


  saveDATAln(allData);
  

// if(now.second() == 0) {
  if(now.minute()%5 == 0) {  //send to TTN 5 every minute
   
      
   sendtoTTN();    

  saveTTNln(allData);

  }
  
  delay(1000);
   
  }
     
}

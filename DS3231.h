#include <Wire.h> //include Wire.h library
#include "RTClib.h" //include Adafruit RTC library

RTC_DS3231 rtc; //Make a RTC DS3231 object
 
int year;
int month;
int day;
int hour;
int minute;
int second;

String print2digits(int number) { //print correctly dates
  String numback="";
  if (number < 10) { numback="0";} // print a 0 before if the number is < than 10
  numback=numback+String(number);
  return numback;
}

void DS3231setup(){

    //  rtc.begin();
    if(rtc.begin()){
    OLEDlms(" RTC OK ");  
    delay(1000);    
    }
    else{
    OLEDlms(" RTC Failed "); 
    while(1) {}  
    }   
}

String stringRTC() {
  String time = print2digits(year)
  +'-'
  +print2digits(month)
  +'-'
  +print2digits(day)
  +' '
  +print2digits(hour)
  +':'
  +print2digits(minute)
  +':'
  +print2digits(second);
  return (time);
}

void getRTC(DateTime now) { // Prepare date string to print on the serial monitoring 
  year = now.year();
  month = now.month();
  day = now.day();
  hour = now.hour();
  minute = now.minute();
  second = now.second();
}

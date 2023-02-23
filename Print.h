
String printHeader = "DS3231 (UTC+2), Voltage (mV), Current=mV/250, NTU=(mV-1000)/4";
String allData;
String allShow;

void preparePrint(){
  allData = stringRTC()+", "+String(count)+", "+String(Pow)+", "+String(current,3)+", "+String(NTU,2);

  allShow = stringRTC()+", "+ String(Pow)+" mV, "+String(current,3)+" mA, "+String(NTU,2)+" NTU";
}

void OLEDshow()
{
  display.clearDisplay();
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(String(Pow)+"mV");
  display.setCursor(0, 20);  
  display.println(String(current,3)+"mA");  
  display.setCursor(0, 40);  
  display.println(String(NTU,2)+"NTU");  
  display.display();
}

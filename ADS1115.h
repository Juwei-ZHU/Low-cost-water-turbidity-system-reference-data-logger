// https://passionelectronique.fr/tutorial-ads1115/
#include "ADS1X15.h" //https://github.com/RobTillaart/ADS1X15
ADS1115 ADS(0x48);  // ADS1115 physically defined at address 0x48


int16_t count;
float Pow;
float current;
float NTU;


void ADS1115setup(void) 
{
  ADS.begin();
  ADS.setGain(0);      // We take the lowest gain index 0, to have the measurement range 6.144 volt and resolution 0.1875 mV
  ADS.setMode(1);      // The ADC is told that measurements will be taken on demand, not continuously (0 = CONTINUOUS, 1 = SINGLE)
  ADS.setDataRate(7);  // We specify the speed of voltage measurement we want, from 0 to 7 (7 being the fastest, that is 860 samples per second)
  ADS.readADC(0);      // And we do an empty reading, to send all these parameters
  
}

void ADS1115get(void) 
{
        count = ADS.readADC(0);
        Pow = count*0.1875;
        current = Pow/250.0;
        NTU = (Pow-1000.0)/4.0;


    delay(100);
}

/********************************************************
/ updated by karuuzo
/
/ updated version for I2C Scanner to work with ESP8266
/
/*********************************************************/
#ifdef ARDUINO_ARCH_ESP8266
  // For ESP use PIN constants instead PIN numbers
  #define SCL_PIN D2
  #define SDA_PIN D1
#else
  // Arduino use default PINs, constants not used
  #define SCL_PIN SCL
  #define SDA_PIN SDA
#endif

#include <Wire.h>

     
    void setup()
    {
      
      #ifdef ARDUINO_ARCH_ESP8266
        Wire.begin(SDA_PIN, SCL_PIN);
      #else
        Wire.begin();
      #endif
      
      Serial.begin(9600);
      while (!Serial);             // Leonardo: wait for serial monitor
      Serial.println("\nI2C Scanner");
    }
     
     
    void loop()
    {
      byte error, address;
      int nDevices;
     
      Serial.println("Scanning...");
     
      nDevices = 0;
      for(address = 1; address < 127; address++ )
      {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
     
        if (error == 0)
        {
          Serial.print("I2C device found at address 0x");
          if (address<16)
            Serial.print("0");
          Serial.print(address,HEX);
          Serial.println("  !");
     
          nDevices++;
        }
        else if (error==4)
        {
          Serial.print("Unknown error at address 0x");
          if (address<16)
            Serial.print("0");
          Serial.println(address,HEX);
        }    
      }
      if (nDevices == 0)
        Serial.println("No I2C devices found\n");
      else
        Serial.println("done\n");
     
      delay(5000);           // wait 5 seconds for next scan
    }


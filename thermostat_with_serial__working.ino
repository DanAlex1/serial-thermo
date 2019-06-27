#include <LiquidCrystal.h>

#include <OneWire.h>

#include <DallasTemperature.h>
#define ONE_WIRE_BUS 12

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
 
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Arduino Digital Temperature // Serial Monitor Version");
  sensors.begin();

  
   lcd.begin(16, 2);
  // put your setup code here, to run once:

}

void loop(void) 
{

  lcd.setCursor(0, 0);
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.println("     ");
  Serial.println(sensors.getTempCByIndex(0));
  

     if(temperature < 21)
     {
      Serial.println(" .   Heating");
      lcd.print("Heating");
     }

      else if(temperature > 21.1)
      {
        Serial.println("    Cooling ");
        lcd.print("Cooling");
        
      }
     }

  
 

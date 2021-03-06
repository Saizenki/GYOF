//SEED PFC V1_2 
//AM2315 Added
//DS18B20 Added
// DHT 22 Added

#include <Wire.h>
#include <Adafruit_AM2315.h>

#include <OneWire.h> 
#include <DallasTemperature.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>;

#define DHTPIN 5     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature ds18b20(&oneWire);

Adafruit_AM2315 am2315;
int chk;
float humdht22;  //Stores humidity value
float tempdht22; //Stores temperature value
int ctr=1;
void setup() {
  Serial.begin(9600);
  //Serial.println("AM2315 Test!");

  if (! am2315.begin()) {
     Serial.println("Sensor not found, check wiring & pullups!");
     while (1);
  }
  ds18b20.begin();
   dht.begin();
  
  
}

void loop() {
  if(ctr==1){
    delay(200);
    ctr++;
  }
  Serial.print("Humidity is "); 
  Serial.println(am2315.readHumidity());
  delay(100);
  Serial.print("Temperature is "); 
  Serial.println(am2315.readTemperature());
  delay(300);
  
  ds18b20.requestTemperatures(); // Send the command to get temperature readings 
  Serial.print("Temperature of water is: "); 
 Serial.print(ds18b20.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(300);
 Serial.println(); 
 humdht22 = dht.readHumidity();
    tempdht22 = dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Outside Humidity is: ");
    Serial.print(humdht22);
    Serial.print(" %,Outside Temp is: ");
    Serial.print(tempdht22);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.
}

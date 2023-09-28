#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
float voltage1 = 0.0;
float voltage2 = 0.0;
float temp1=0.0;
float temp2=0.0;
int value1,value2;
void setup() 
{
 lcd.init(); lcd.backlight(); 
}
void loop() 
{
 value1 = analogRead(A1); //Battery Voltage
 delay(10);
 temp1 = (value1 * 5.0) / 1024.0; 
 voltage1 = temp1/(0.0909;
 lcd.setCursor(0,0); //col,row
 lcd.print("Batt:");
 lcd.print(voltage1);
 lcd.print(" V ");
 if (voltage1 <= 3.0) 
 {
 lcd.print("Low");
} 
 
 if (voltage1 >= 3.7) 
 {
 lcd.print("Full");
 } 
 value2 = analogRead(A2); //Charging Voltage
 delay(10);
 temp2 = (value2 * 5.0) / 1024.0; 
 voltage2 = temp2/(0.0909); 
 
 if (voltage2 <= 3.1) 
 {
 lcd.setCursor(0,1); 
 lcd.print(" -Not Charging- ");
 } 
 
 if (voltage2 > 3.1) 
 {
 lcd.setCursor(0,1);
 lcd.print(voltage2);
 lcd.print(" V ");
 lcd.print("Charging");
 } 
 
 delay(500);
}
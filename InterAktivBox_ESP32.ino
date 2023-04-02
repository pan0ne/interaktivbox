/*
DUISentrieb Soundbox triggerd by motion and distance, Power ON/OFF latch
Author: Pan0rama 
Date: 16/12/2022
Hardware: 
- ESP32 WROOM-32
- PIR AM312 Motion Sensor (PIN 34)
- YX5300 UART MP3 Module (TX = 12 RX = 14)
- LD4060 Radar Sensort Sensor (RX2 = 16 , TX2 = 17)
- Mosfet Module (Pin 4)
*/

#include "SerialMP3Player.h"
#include <ld2410.h>
//RTC_DATA_ATTR int bootCount = 0;

ld2410 radar;
uint32_t lastReading = 0;
long randNumber;
int track = random(1, 4);
int playActive = 0;
int activeTrack;
int playedTrack;

int pirMotion;
int radarPresence;
int pirSensor = 34;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

const int mp3PowerSwitchPin = 2;
const int ampPowerSwitchPin = 4;
const int radarPowerSwitchPin = 15;


#define TX 12
#define RX 14

SerialMP3Player mp3(RX,TX);

void setup() {
  Serial.begin(115200); //Feedback over Serial Monitor  
  pinMode(pirSensor, INPUT);    // initialize sensor as an input
  pinMode (mp3PowerSwitchPin, OUTPUT);
  pinMode (ampPowerSwitchPin, OUTPUT);
  pinMode (radarPowerSwitchPin, OUTPUT);

  digitalWrite (mp3PowerSwitchPin, LOW);
  digitalWrite (ampPowerSwitchPin, HIGH);
  digitalWrite (radarPowerSwitchPin, LOW);
  
  delay(2000);             // wait for init
  
  //++bootCount; //Increment boot number and print it every reboot
  //Serial.println("Boot number: " + String(bootCount));

  //if(mp3PowerSwitchPin == LOW){
    mp3.begin(9600);        // start mp3-communication
    delay(500);             // wait for init
    mp3.sendCommand(CMD_SEL_DEV, 0, 2);   //select sd-card
  //}  
  
  delay(500);             // wait for init
  
  //if(radarPowerSwitchPin == LOW){
    //radar.debug(Serial); //Uncomment to show debug information from the library on the Serial Monitor. By default this does not show sensor reads as they are very frequent.
    Serial1.begin (256000, SERIAL_8N1, 17, 16); //UART for monitoring the radar
    delay(500);
    Serial.println(F("\nLD2410 radar sensor initialising: "));
      if(radar.begin(Serial1))
        {
          Serial.println(F("OK"));
        }
      else
        {
          Serial.println(F("not connected"));
        } 
  //}
  //Serial.println(esp_sleep_enable_ext0_wakeup(GPIO_NUM_34, 1)); //1 = High, 0 = Low
}

void loop(){
  
  radar.read();
    
    if(radar.isConnected() && millis() - lastReading > 500)  //Report every 1000ms
    {
      lastReading = millis();
      
      if(radar.presenceDetected())
      { 
        Serial.println(F("Bewegung registriert"));
        radarPresence = radar.presenceDetected();
        mp3.wakeup();
        if(playActive == 0)
        {
          digitalWrite (ampPowerSwitchPin, LOW);
          Serial.print(F("Play Track: "));
          Serial.println(activeTrack);
           mp3.setVol(25);                   
           mp3.play(activeTrack); 
           playActive = 1;                                  
        }
      }     
      else
      {
        mp3.stop();
        playActive = 0;
        activeTrack = random(1, 4);                                              
        Serial.println(F("No target"));
        mp3.sleep();
        digitalWrite (ampPowerSwitchPin, HIGH);
        
        if (radarPresence == 0 && pirMotion == 0 && playActive == 0){
          Serial.println(F("DeepSleep aktive..."));
          digitalWrite (ampPowerSwitchPin, HIGH);
          digitalWrite (mp3PowerSwitchPin, HIGH);
          digitalWrite (radarPowerSwitchPin, HIGH);
          //Serial.flush();
          //esp_deep_sleep_start();
        }
      }              
    } // end millis
} // end loop

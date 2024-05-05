// SEVEN SEGMENT DISPLAY --------------

#include "SevSeg.h"
SevSeg sevseg; 

// ------------------------------------


// SENSOR -----------------------------
#include <DHT.h>
#define DHTPIN 11         // PIN DIGITAL SENSOR
#define DHTTYPE DHT11     // TIPO SENSOR
DHT dht(DHTPIN, DHTTYPE);

// ------------------------------------


// BOTON -------------------------------

const int buttonPin = 6; 
int buttonState = 0; 

// ------------------------------------



void setup(){
    //  debug 
      // Inicializamos comunicación serie
    Serial.begin(9600);


    pinMode(buttonPin, INPUT);

    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {9, 10, 3, 4, 5, 8, 7, 2};    // A,b,c,d,e,f,g, dp
    bool resistorsOnSegments = true;
    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);

    dht.begin();
}

void loop(){
        buttonState = digitalRead(buttonPin);
        int i;
        if (buttonState == HIGH) {
            int t = int(dht.readTemperature());
            delay(2000);
            int decenas = t / 10;
            int unidades = t % 10;
                sevseg.setNumber(decenas);
                sevseg.refreshDisplay();
                delay(1000);
                sevseg.setNumber(unidades);
                sevseg.refreshDisplay();
                delay(1000);
                Serial.print("sensor\n");
                Serial.print(t);
                sevseg.blank();
        } else{

        }
}

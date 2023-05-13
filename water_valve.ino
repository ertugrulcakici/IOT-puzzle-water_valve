#include <Arduino.h>

// Define valve sensors and water pump pins
#define VALVE_SENSOR1 A0
#define VALVE_SENSOR2 A1
#define VALVE_SENSOR3 A2
#define VALVE_SENSOR4 A3
#define VALVE_SENSOR5 A4

#define WATER_PUMP_PIN 2

void setup()
{
    // Start serial communication for debugging
#ifdef DEBUG
    Serial.begin(9600);
#endif
    // Set the water pump pin mode to output
    pinMode(WATER_PUMP_PIN, OUTPUT);
}

void loop()
{
    // Read values from valve sensors
    int valve1Value = analogRead(VALVE_SENSOR1);
    int valve2Value = analogRead(VALVE_SENSOR2);
    int valve3Value = analogRead(VALVE_SENSOR3);
    int valve4Value = analogRead(VALVE_SENSOR4);
    int valve5Value = analogRead(VALVE_SENSOR5);

    // Print sensor values for debugging
#ifdef DEBUG
    Serial.println("Valve 1: " + String(valve1Value) +
                   " Valve 2: " + String(valve2Value) +
                   " Valve 3: " + String(valve3Value) +
                   " Valve 4: " + String(valve4Value) +
                   " Valve 5: " + String(valve5Value));
#endif

    // If all valves are below threshold, turn off the water pump, otherwise turn it on
    if (valve1Value < 950 && valve2Value < 950 && valve3Value < 950 && valve4Value < 950 && valve5Value < 950)
    {
        digitalWrite(WATER_PUMP_PIN, LOW);
    }
    else
    {
        digitalWrite(WATER_PUMP_PIN, HIGH);
    }

    // Wait before the next loop iteration
    delay(2000);
}

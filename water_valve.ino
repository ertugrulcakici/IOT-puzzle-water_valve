#define VANA_1 A0
#define VANA_2 A1
#define VANA_3 A2
#define VANA_4 A3
#define VANA_5 A4

#define SU_MOTORU 2

void setup()
{
#ifdef DEBUG
    Serial.begin(9600);
#endif
    pinMode(SU_MOTORU, OUTPUT);
}

void loop()
{
    int vana_1_value = analogRead(VANA_1);
    int vana_2_value = analogRead(VANA_2);
    int vana_3_value = analogRead(VANA_3);
    int vana_4_value = analogRead(VANA_4);
    int vana_5_value = analogRead(VANA_5);

#ifdef DEBUG
    Serial.println("Vana 1: " + String(vana_1_value) + " Vana 2: " + String(vana_2_value) + " Vana 3: " + String(vana_3_value) + " Vana 4: " + String(vana_4_value) + " Vana 5: " + String(vana_5_value));
#endif

    if ((vana_1_value < 950) && (vana_2_value < 950) && (vana_3_value < 950) && (vana_4_value < 950) && (vana_5_value < 950))
    {
        digitalWrite(SU_MOTORU, LOW);
    }
    else
    {
        digitalWrite(SU_MOTORU, HIGH);
    }

    delay(2000);
}

#define BLYNK_PRINT Serial
#include &amp;lt;ESP8266WiFi.h&amp;gt;
#include &amp;lt;BlynkSimpleEsp8266.h&amp;gt;

char auth[] = "XXXX";               // masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno";      //nama wifi
char pass[] = "Admin1234";          //password

const int tDelay = 500;
int ledPin = 12; 
int inputPin = 13;
int resPin = 14;
int counter = 0; 
int val;
int res;
int lastval;

void setup(){
    pinMode(ledPin, OUTPUT); 
    pinMode(resPin, INPUT_PULLUP);
    pinMode(inputPin, INPUT); 
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}

void loop(){
    val = digitalRead(inputPin); 
    res = digitalRead(resPin);
    if (val != lastval) { 
        if (val == HIGH) {  //Apabila ada benda masuk
        counter++;
        digitalWrite(ledPin, LOW);
        Blynk.virtualWrite(V5, counter);
        delay(tDelay);
        }
    }
    if (res == LOW) {  //Apabila tombol reset ditekan
        counter = 0;
        Blynk.virtualWrite(V5, counter);
        delay(tDelay);
    }
    else {
        digitalWrite(ledPin, HIGH);
    }
    lastval = val;
    Blynk.run();
}

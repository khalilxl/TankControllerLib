// Year-Month-Day Format for DateTime
// https://en.wikipedia.org/wiki/ISO_8601

#include <Arduino.h>
#include <RTClib.h>

class TC_Serial {
private:
  const float RREF = 430.0;
  // RTC_PCF8523 rtc;

public:
  TC_Serial() {
    Serial.begin(9600);
  }

  void print_PID(double Kp, double Ki, double Kd, double output) {
    Serial.print(F("Kp:"));
    Serial.print(Kp);
    Serial.print(F(" Ki:"));
    Serial.print(Ki);
    Serial.print(F(" Kd:"));
    Serial.println(Kd);
    Serial.print(F("PID output (s): "));
    Serial.println(output / 1000, 1);
  }

  void print_DateTime(DateTime now) {
    Serial.print(now.year(), DEC);
    Serial.print('-');
    Serial.print(now.month(), DEC);
    Serial.print('-');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    if (now.minute() < 10) {
      Serial.print('0');
    }
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    if (now.second() < 10) {
      Serial.print('0');
    }
    Serial.print(now.second(), DEC);
    Serial.println();
  }

  void print_mac(byte mac[]) {
    Serial.print(F("MAC Address: "));
    Serial.print(mac[0]);
    for (int i = 1; i < 6; ++i) {
      Serial.print(':');
      Serial.print(mac[i]);
    }
    Serial.println();
  }

  void print(String aString, String aString2) {
    Serial.println(aString);
    Serial.println(aString2);
  }

  void print(String aString, int anInt) {
    Serial.print(aString);
    Serial.println(anInt);
  }

  void print(String aString, int anInt, int format) {
    Serial.print(aString);
    Serial.println(anInt, format);
  }

  void print(String aString) {
    Serial.println(aString);
  }

  void write(byte aByte) {
    Serial.write(aByte);
  }

  void write(char arr[], int anInt) {
    Serial.write(arr, anInt);
  }
};

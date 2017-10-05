#include <TimeAlarms.h> // https://github.com/PaulStoffregen/TimeAlarms & https://github.com/PaulStoffregen/Time
#include <RTClib.h> // https://github.com/adafruit/RTClib

RTC_DS1307 rtc;
#define LEDPIN 9;

uint32_t sync_provider()
{
    /// sync provider for timelib sychronization
    return rtc.now().unixtime();
}

void sunrise()
{
    for(int i = 64; i <= 255; i++){
        analogWrite(LEDPIN, i);
        if (i == 255) digitalWrite(LEDPIN, HIGH);
        Alarm.delay(10);
   } 
}

void setup()
{
    /// rtc setup
    rtc.begin();
    // uncomment this line at first upload to set current ds1307 date & time
    // then comment it, build and upload sketch again
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    /// timelib setup
    setSyncProvider(sync_provider);
    setSyncInterval(60);
    pinMode(LEDPIN, OUTPUT);
    Alarm.alarmRepeat(6, 30, 0, sunrise);
    
void loop()
{
    Alarm.delay(0);
}

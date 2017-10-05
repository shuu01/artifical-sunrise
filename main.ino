#include <TimeAlarms.h> // https://github.com/PaulStoffregen/TimeAlarms & https://github.com/PaulStoffregen/Time
#include <RTClib.h> // https://github.com/adafruit/RTClib

RTC_DS1307 rtc;

uint32_t sync_provider()
{
    /// sync provider for timelib sychronization
    return rtc.now().unixtime();
}

void sunrise()
{
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
    
void loop()
{
    Alarm.delay(0);
}

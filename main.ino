#include <TimeAlarms.h> // https://github.com/PaulStoffregen/TimeAlarms & https://github.com/PaulStoffregen/Time
#include <RTClib.h> // https://github.com/adafruit/RTClib

#define LEDPIN 9
#define ON 8
#define SUN 7
RTC_DS1307 rtc;


int state = 0;
int laststate = 0;

uint32_t sync_provider()
{
    /// sync provider for timelib sychronization
    return rtc.now().unixtime();
}

void sunrise()
{
    if (digitalRead(SUN) == LOW){ 
        for(int i = 64; i <= 255; i++){
            analogWrite(LEDPIN, i);
            if (i == 255) digitalWrite(LEDPIN, HIGH);
            Alarm.delay(10000);
        }
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
    pinMode(ON, INPUT);
    pinMode(SUN, INPUT);
    
    Alarm.alarmRepeat(6, 0, 0, sunrise);
}

void loop()
{
    Alarm.delay(1000);
    state = digitalRead(ON);
    if (state != laststate){
        if (state == HIGH) {digitalWrite(LEDPIN, HIGH);}
        else {digitalWrite(LEDPIN, LOW);}
    }
    laststate = state;
}

/**
 * YouTube Subscriber counter
 * by stealthyV1per
 * 
 * Displays your current subscriber count in real time
 * 
 * Based on: https://www.instructables.com/id/YouTube-Subscriber-Counter-With-ESP8266-V2/
 **/
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Wire.h>

#include "confidentials.h"

/**
 * Additional Libraries - each one of these will need to be installed.
 **/
#include <YoutubeApi.h>
// Library for connecting to the Youtube API
// https://github.com/witnessmenow/arduino-youtube-api

#include <ArduinoJson.h>
// Library used for parsing Json from the API responses
// https://github.com/bblanchon/ArduinoJson

#include <LedControl.h>
// Library used for simple segmented display
// https://github.com/wayoda/LedControl

/**
 * Replace if needed
 * 
 * D6 => LOAD
 * D7 => CLK
 * D8 => DIN
 * 
 * 1 device
 */
LedControl lc = LedControl(D8, D6, D7, 1);

WiFiClientSecure client;
YoutubeApi api(API_KEY, client);

// API delay set to every ~15mins
unsigned long timeBetweenRequests = 900000;
unsigned long nextRunTime;
long subscribers = 0;

void setup()
{
  Serial.begin(115200);

  // Initialize the MAX7219 device

  // Enable display
  lc.shutdown(0, false);
  // Set brightness level (0 is min, 15 is max)
  lc.setIntensity(0, 15);
  // Clear display register
  lc.clearDisplay(0);

  // Set WiFi to station mode and disconnect from an AP if it was Previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Attempt to connect to Wifi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("");
  Serial.println("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  // Required if you are using ESP8266 V2.5 or above
  client.setInsecure();
}

void printNumber(int pos, int number)
{
  if (number > 0 || number < 100000000)
  {
    lc.setDigit(0, pos, number, false);
  }
  else
  {
    lc.setChar(0, pos, ' ', false);
  }
}

void loop()
{
  if (millis() > nextRunTime)
  {
    if (api.getChannelStatistics(CHANNEL_ID))
    {
      Serial.println("statistics");
      Serial.print("viewCount: ");
      Serial.println(api.channelStats.viewCount);
      Serial.print("commentCount: ");
      Serial.println(api.channelStats.commentCount);
      Serial.print("subscriberCount: ");
      Serial.println(api.channelStats.subscriberCount);
      Serial.print("videoCount: ");

      Serial.println(api.channelStats.videoCount);
      Serial.println("");

      // Chache subscriber count into variable, if WiFi might be down
      subscribers = api.channelStats.subscriberCount;
    }

    int digit;

    for (int i = 0; subscribers; i++)
    {
      digit = subscribers % 10;
      subscribers /= 10;
  
      printNumber(i, digit);
    }
    
    nextRunTime = millis() + timeBetweenRequests;
  }
}

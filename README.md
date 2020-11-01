# 203 SPIFFS vs LITTELFS
## A simple, on-board file system for your ESP32 &amp; ESP8266

So we have the equivalent of a very small SSD in each of our ESP8266s and ESP32s but it mostly remains unused. Instead of using SD cards for trivial files let's use the built in flash file store.

### JLCPCB Only $2 for PCB Prototype any colour https://jlcpcb.com/

### See the accompanying video https://youtu.be/4r6YZlLfKfw

**SPIFFS** stands for **SPI Flash File System**. 

**SPI** is a protocol that is often used in the Arduino arena (it stands for *Serial Peripheral Interface*, but that's why we call it SPI).

**Flash** is the memory on your μController. Yes, your sketch resides in Flash memory.

**File System** is the term for storing "files" in that memory. Yes, just like on that SD card.

So we can store files in this SSD-like memory on our ESP8266s and ESP32s? Yes, but not on an Arduino UNO or similar because we just don't have anywhere near the memory required for this.

The bad news is that SPIFFS has been deprecated by Espressif (the designers of ESP8266/ESP32) because it was not resilient enough. And relatively slow, too.

The replacement LITTLEFS is even power-interruption resilient and the File System will not be corrupted if the power disappears during a write operation. Allegedly. Even if one file gets corrupted, the rest are safe.

**Espressif** state: "**SPIFFS** is the original filesystem and is ideal for space and RAM constrained applications that utilize many small files and care about static and dynamic wear levelling and don’t need true directory support. Filesystem overhead on the flash is minimal as well."

The also say: "**LittleFS** is recently added and focuses on higher performance and directory support, but has higher filesystem and per-file overhead (4K minimum vs. SPIFFS’ 256 byte minimum file allocation unit)."

So for memory-lean ESP8266s you might want to stick with SPIFFS but for newer chips with a larger memory use the LITTLEFS implementation. Note that you CANNOT mix-and-match.

On that topic Espressif say: "They share a compatible API but have incompatible on-flash implementations, so it is important to choose one or the per project as attempting to mount a SPIFFS volume under LittleFS may result in a format operation and definitely will not preserve any files, and vice-versa."

### List of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon

Benny's Life Story, Best Cat Ever.  
https://wordpress.com/post/ralphbacon.blog/456  

-----------
INFORMATION
-----------
Official document regarding SPIFFS vs LITTLEFS  
https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html#uploading-files-to-file-system

All about the ESP32 - features guide  
https://www.exploreembedded.com/wiki/Overview_of_ESP32_features._What_do_they_practically_mean%3F


### List of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon

-----
ESP32
-----

ESP32 Universal SPIFFS, LITTELFS and FATFS tools for Arduino IDE  
https://github.com/lorol/arduino-esp32fs-plugin  
https://github.com/lorol/arduino-esp32fs-plugin/releases  

Note: You need the following 3 files:  
esp32fs.zip, mkfatfs.zip and x86_64-64.minw32-mklittlefs-....zip  

Above is a fork from the original code here:  
https://github.com/me-no-dev/arduino-esp32fs-plugin

**Dennis Phillips** (viewer) says:
I thought it might be worth mentioning that for users of PlatformIO the tools are also available. https://github.com/lorol/LITTLEFS/tree/master/examples/LITTLEFS_PlatformIO
Thanks Dennis!

-------
ESP8266
-------

Arduino IDE ESP8266 filesystem uploader by earlephilhower:  
https://github.com/earlephilhower/arduino-esp8266littlefs-plugin  
https://github.com/earlephilhower/arduino-esp8266littlefs-plugin/releases

Note: You need the following 1 file:
ESP8266LittleFS-2.6.0.zip (if there is a higher version, take it)

--------
PRODUCTS
--------
ESP32 modules are inexpensive these days. Here are a few examples. 

The links might be affiliate links which can earn my channel some money to buy more stuff. Just click on a link before you buy *anything* from Banggood, Aliexpress or Amazon (UK).

ESP32 Development Board WiFi+Bluetooth Ultra Low Power Consumption Dual Cores About $7 + shipping  
https://www.banggood.com/custlink/mvGhHywKDr

Similar board, but cheaper at $4.99 (on sale until 31 Dec 2020):  
https://www.banggood.com/custlink/DKGhPYTGdm
Note above board dispatched from China, USA and UK, latter two at higher prices but quicker delivery  

ESP8266 (bare - no USB socket) $3.99  
https://www.banggood.com/custlink/K33EVh7vRl  

ESP8266 by Geekcreit® NodeMcu Lua CH340G V3 with USB socket $4.99  
https://www.banggood.com/custlink/vDDEVYTvd0  

Two line (16 x 2) LCD display, Black/Green, very easy to use with I2C only £3.99  
https://amzn.to/34fEOhG  

ESP32-DevKitC core board ESP32 development board (ESP32-WROOM-32D or 32U) $3.99 plus shipping  
https://s.click.aliexpress.com/e/_AASDSr  

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite journey

My channel, GitHub and blog are here:  
\------------------------------------------------------------------  
https://www.youtube.com/RalphBacon  
https://ralphbacon.blog  
https://github.com/RalphBacon  
\------------------------------------------------------------------

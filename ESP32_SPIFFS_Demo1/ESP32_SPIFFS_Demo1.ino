/*
   Simple LittleFS (or SPIFFS) demo for ESP32 & ESP8266

   In this demo we will upload a file to the LittleFS on the ESP32
   (manually, from within the Arduino IDE) and then read it here
   in the sketch.

   Note that we are using the approved LittleFS instead of the now
   deprecated SPIFFS but both work in this simple demo.
*/
#include <LITTLEFS.h>

// If we cannot mount the LittleFS disk, shall we format one?
#define FORMAT_LITTLEFS_IF_FAILED false

void setup() {
  Serial.begin(115200);
  Serial.println("\n================================");

  // If we can't mount the file system (eg you've confused SPIFFS with LITTLEFS) abort here
  if (!LITTLEFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
    Serial.println("LITTLEFS Mount Failed.");
    return;
  } else {
    Serial.println("LITTLEFS Mount SUCCESSFUL.");
  }

  // List directory, from root, 2 levels deep
  Serial.println("\n================================");
  listDir(LITTLEFS, "/", 2);

  const char * path = "/SPIFFS_Demo.txt";
  Serial.println("\n================================");
  Serial.printf("Reading file: %s\r\n", path);
  File file = LITTLEFS.open(path, "r");

  // Could we open the file?
  if (!file) {
    Serial.println("File failed to open.");
    return;
  } else {
    Serial.println("File opened successfully.");
  }

  Serial.println("\n================================");
  Serial.println("Reading from file:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();

  // Add done. We must execute the "end" here to allow OTA updates.
  LITTLEFS.end();

}

// Nothing to do in the loop. Execute a yield to keep the WiFi alive.
void loop() {
  yield();
}

// Stolen from the example sketch on how to list files in a dir
void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\r\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

# ESP32 Toggle and Text WebServer

A simple ESP32 WebServer that receives toggle states and text messages from a mobile app and displays them on the Serial Monitor.

## Hardware Requirements

- ESP32 development board
- USB cable
- Computer with Arduino IDE

## Arduino IDE Setup

1. Install the ESP32 board in Arduino IDE
   - File > Preferences > Additional Board Manager URLs: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Tools > Board > Boards Manager > Search for ESP32 > Install

2. Required libraries
   - WiFi.h (included with ESP32 board package)
   - WebServer.h (included with ESP32 board package)

3. Configure WiFi Settings
   - Open the .ino file
   - Update the following lines with your WiFi credentials:
     ```cpp
     const char* ssid = "YOUR_WIFI_SSID";
     const char* password = "YOUR_WIFI_PASSWORD";
     ```

4. Upload the Code
   - Connect your ESP32 to your computer
   - Select the correct board and port in Arduino IDE
   - Click the Upload button

5. View Output
   - Open the Serial Monitor (Tools > Serial Monitor)
   - Set the baud rate to 115200
   - Note the IP address displayed
   - You'll see toggle and text messages as they are received

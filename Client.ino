#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <BLEEddystoneURL.h>
#include <BLEEddystoneTLM.h>
#include <BLEBeacon.h> 

int scanTime = 5;  // In seconds
BLEScan *pBLEScan;

class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    if (advertisedDevice.haveName()) {
      String name = advertisedDevice.getName().c_str();
      String toSearch = "Locator";
      if (name.indexOf(toSearch) >= 0) {
        Serial.print("Device name: ");
        Serial.println(name);
        Serial.print("RSSI: ");
        Serial.println(advertisedDevice.getRSSI());

        if (advertisedDevice.haveServiceUUID()) {
          Serial.print("Found ServiceUUID: ");
          Serial.println(advertisedDevice.getServiceUUID().toString().c_str());
        }
        Serial.println("");
      }
    }
  }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Scanning...");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();  //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);  //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value
}

void loop() {
  // Aaradhya : Ek baar check karle fns net se search karne pade shi hai ya nhi
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  
  int highestRSSI = -999;
  String closestDeviceName = "";
  String closestDeviceUUID = "";

  for (int i = 0; i < foundDevices.getCount(); i++) {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);
    if (device.haveName() && device.getName().indexOf("Locator") >= 0) {
      int rssi = device.getRSSI();
      if (rssi > highestRSSI) {
        highestRSSI = rssi;
        closestDeviceName = device.getName().c_str();
        closestDeviceUUID = device.haveServiceUUID() ? device.getServiceUUID().toString().c_str() : "No UUID";
      }
    }
  }

  if (highestRSSI > -999) {
    Serial.println("Closest device:");
    Serial.print("Device name: ");
    Serial.println(closestDeviceName);
    Serial.print("RSSI: ");
    Serial.println(highestRSSI);
    Serial.print("Service UUID: ");
    Serial.println(closestDeviceUUID);
    Serial.println("");
  } else {
    Serial.println("No 'Locator' devices found.");
  }

  pBLEScan->clearResults(); // delete results fromBLEScan buffer to release memory
  delay(500);
}

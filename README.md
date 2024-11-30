# **BLE-Based Student Location Tracking System**
A real-time Bluetooth Low Energy (BLE) tracking system designed to enhance student safety by monitoring their locations within school premises.



## **Overview**

The BLE-Based Student Location Tracking System is a cost-efficient
, scalable solution developed to improve student safety within educational institutions.
By leveraging BLE technology, the system tracks the proximity of students in real-time,
providing parents and school staff with actionable insights into student locations.
The system prioritizes energy efficiency and privacy, ensuring long-term usability and minimal maintenance.

## **Features**

Real-Time Tracking: Detects BLE-enabled tags worn by students and calculates proximity using RSSI values.
Secure BLE Communication: Encrypted communication between BLE devices and scanners.
Custom Advertising Service: BLE server simulates room-specific broadcasting for accurate tracking.
Low Power Consumption: Optimized BLE scanning and broadcasting mechanisms.
Dynamic Alerts: Notifications when students enter or leave designated zones.


## **Technologies Used**

Programming Language: C++ (Arduino Framework)
Hardware: BLE-compatible microcontrollers and beacons
Libraries:
Arduino BLE Library
BLEDevice, BLEUtils, BLEServer


## **Results**

Successfully detected BLE devices within school premises and prioritized the closest one.
Verified secure BLE communication using encryption.
Demonstrated scalability by expanding the system to multiple rooms with additional beacons.


## **Future Enhancements**

Dashboard Integration: Develop a web-based interface for real-time tracking and analytics.
Battery Optimization: Implement smarter power-saving mechanisms for BLE tags.
Zone Alerts: Introduce geofencing to alert staff or parents when students leave predefined zones.

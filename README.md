# Instrument Cluster HMI Design

This project involves the design of a **Cluster HMI (Human-Machine Interface)** for a vehicle’s instrument cluster. The system displays real-time alerts such as detected obstacles, lane departures, and vehicle status on the display using the **IMXRT board** and **Jetson Nano**. 

## Key Features:
- Designed and implemented a **Cluster HMI** in a **GUI-based environment**, displaying crucial alerts on the vehicle’s instrument cluster.
- Developed **user interfaces** for **critical alerts** such as:
  - Detected obstacles
  - Vehicle status (e.g., fuel level, engine temperature)
- Utilized the **IMXRT board** to drive the display, enabling **real-time rendering** of alerts and vehicle status on the instrument cluster.
- Worked with the **MCUXpresso IDE** to modify and update the **firmware** code for the IMXRT board, ensuring smooth integration of display functions and real-time data processing.
- Implemented **UART communication** between **Jetson Nano** and the IMXRT board to transfer real-time data to the cluster display.

## System Design Overview

### Hardware Components:
- **IMXRT Board**: Used to drive the display and process real-time data.
- **Jetson Nano**: Provides critical vehicle data and communicates with the IMXRT board.
- **Display Interface**: GUI environment for displaying alerts and vehicle information.

### Software Tools:
- **MCUXpresso IDE**: Development environment for the IMXRT board firmware.
- **UART Protocol**: Used for communication between Jetson Nano and IMXRT board.

## Step-1: (Set up Development Environment)
1. Install **MCUXpresso IDE** for **IMXRT board** firmware development.
2. Set up the necessary software tools for real-time data processing on **Jetson Nano**.
3. Ensure that both the **IMXRT board** and **Jetson Nano** are connected via **UART** for data communication.

## Step-2: (Design User Interfaces for Alerts)
Develop the user interface to display critical vehicle alerts:
- **Detected Obstacles**: Show a visual alert when an object is detected near the vehicle.
- **Lane Departure Warning**: Visual indication when the vehicle is about to depart from its lane.
- **Vehicle Status**: Display real-time information about the vehicle’s health, such as fuel levels, engine temperature, and other diagnostic data.

## Step-3: (Implement UART Communication)
1. **Jetson Nano to IMXRT**: Implement UART communication to send real-time data from the **Jetson Nano** to the **IMXRT board**.
2. Code for communication:
    ```python
    import serial
    # Setup UART communication with IMXRT board
    ser = serial.Serial('/dev/ttyUSB0', 115200)
    ser.write(b"Obstacle detected")
    ```
3. The **IMXRT board** receives the data and updates the display based on the incoming alerts.

## Step-4: (Modify Firmware for IMXRT Board)
Using **MCUXpresso IDE**, modify and update the firmware for the **IMXRT board**:
1. Initialize the **display** hardware.
2. Write code to handle incoming data over **UART** and update the display in real-time.
3. Ensure that the firmware supports rendering of all critical alerts.

## Step-5: (Testing & Integration)
Test the system for:
1. **Real-time data display**: Verify that the **IMXRT board** accurately receives and displays alerts from the **Jetson Nano**.
2. **Integration**: Ensure smooth integration of the **user interface** with the data communication between the two devices.
3. Test for edge cases such as rapid data changes and large data transmission.

## Step-6: (Final Testing and Deployment)
1. Deploy the system into the vehicle’s instrument cluster.
2. Verify the **real-time rendering** of all alerts in different driving conditions.

## Conclusion
This project integrates the **Jetson Nano** and **IMXRT board** to provide a real-time, responsive **Cluster HMI** that displays important vehicle alerts such as obstacles, lane departures, and vehicle status.


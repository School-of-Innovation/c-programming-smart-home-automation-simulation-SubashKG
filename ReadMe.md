[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jx3rng6H)
# Assignment | C Programming 

A Smart Home Automation System is being designed to manage and monitor different appliances and sensors in a house. Since the hardware is not available, You will simulate this system using standard C programming with GCC.
The Task is to develop a menu-driven program to control and monitor devices like lights, temperature sensors, motion sensors, and security locks using arrays and functions only.

## Devices & Sensors (Represented as Arrays) :

- **Light System**: Stores ON/OFF states for each room.
- **Temperature Sensors**: Stores temperature values for multiple rooms.
- **Motion Sensors**: Detects movement (1 for detected, 0 for no movement).
- **Security Locks**: Tracks lock/unlock states (1 for locked, 0 for unlocked).

## Functionalities to Implement :

- Initialize System: Set default states (Lights OFF, Doors Locked, No motion detected).
- Control Lights: User can toggle ON/OFF lights for any room.
- Read Temperature: Display stored temperature for any room.
- Detect Motion: Check if any motion is detected.
- Security System: Lock/Unlock doors manually.
- Analyze House Status: Generate a summary of active devices, unlocked doors, and recent motion detections.
- Exit Program: Stop execution.

## Constraints :

1.Must use only Arrays and Functions (No Structs, No Pointers, No Global Variables).
2.The entire system should be menu-driven (switch-case implementation).
3.Arrays should be dynamically sized based on user input (rooms & devices).
4.Only use basic C operations (No advanced data structures like linked lists or queues).

## Example (Output)

Enter number of rooms: 3  
Initializing system...  

===== Smart Home Menu =====  
1. Toggle Light  
2. Read Temperature  
3. Check Motion Sensor  
4. Lock/Unlock Security System  
5. House Status Summary  
6. Exit  
Enter your choice: 1  
Enter room number to toggle light (1-3): 2  
Light in Room 2 is now ON.  

Enter your choice: 5  
House Status:  

- Room 1: Light OFF, Temp 22°C, No Motion, Locked  
- Room 2: Light ON, Temp 25°C, Motion Detected, Locked  
- Room 3: Light OFF, Temp 24°C, No Motion, Unlocked  

Enter your choice: 6  
Exiting...  

## Additional Challenge (10 Marks ) :

- **Add Auto-Lock**: If no motion is detected for 5 inputs, the door locks automatically.
- **Temperature Alert System**: If any room’s temperature goes above 30°C, display a warning.
- **Energy Saving Mode**: If all lights are ON for too long, suggest turning them OFF.
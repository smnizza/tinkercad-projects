# Keypad-Based Door Lock System

This project implements a simple security system using an Arduino Uno, a 4x4 keypad, an LCD display, and a servo motor for door control.

## Components  
- 1 × Arduino Uno R3  
- 1 × Positional Micro Servo  
- 1 × Piezo Buzzer  
- 1 × PCF8574-based 16x2 LCD (I2C, address 0x20)  
- 1 × 100Ω Resistor  
- 1 × 4x4 Keypad  
- 1 × Red LED  
- 1 × Green LED  
- 2 × 220Ω Resistors  

## How It Works  
- The user sets a **PIN** using the keypad, which is displayed on the **LCD screen**.  
- To unlock the door, the user must re-enter the correct PIN.  
- If the entered PIN is incorrect, the **red LED** turns ON, and the user must try again.  
- If the PIN is correct, the **green LED** turns ON, and the **servo motor** unlocks the door.

## Folder Structure  
- **`door_lock.ino`** → Arduino code for the project.  
- **`door_lock.pdf`** → Schematic design in PDF format.  
- **`door_lock.png`** → Circuit diagram as an image.  

## Tinkercad Simulation  
You can view and simulate the project on Tinkercad:  
[**Tinkercad Link**](https://www.tinkercad.com/things/hb7KpEJaQpJ-smart-door-lock-with-keypad)

---

Feel free to modify and improve this project as needed! 😊

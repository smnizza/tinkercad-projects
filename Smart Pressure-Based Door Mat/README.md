# Smart Pressure-Based Door Mat

This project simulates a smart pressure-based door mat using Arduino Uno in Tinkercad. The system detects foot pressure and motion to trigger an alarm.

## How It Works  
- The force sensor detects pressure on the mat.
  - If pressure is detected, the system registers a **Step Detected** event.
- The PIR sensor detects motion.
  - If motion is detected, the system registers a **Motion Detected** event.
- If both pressure and motion are detected simultaneously:
  - **Alarm Triggered** state is activated.
  - The LED turns ON.
  - The buzzer sounds an alarm.

## Folder Structure  
- **`smart_door_mat.csv`** → List of components used in the project.  
- **`smart_door_mat.ino`** → Arduino code for the project.  
- **`smart_door_mat.pdf`** → Schematic design in PDF format.  
- **`smart_door_mat.png`** → Circuit diagram as an image.  

## Tinkercad Simulation  
You can view and simulate the project on Tinkercad:  
[**Tinkercad Link**](https://www.tinkercad.com/things/4GZCpizbhdG-smart-pressure-based-door-mat)

---

Feel free to modify and improve this project as needed! 😊


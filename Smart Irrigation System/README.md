# Smart Irrigation System

This project simulates a smart irrigation system using Arduino Uno in Tinkercad. The system automatically adjusts water flow based on soil moisture levels.

## How It Works  
- The soil moisture sensor measures soil humidity in percentages (0% - 100%).  
- 0% means the soil is very dry, and 100% means the soil is very moist.  
- The servo motor, acting as a water valve, adjusts its position based on the moisture level:
  - At 0% moisture, the servo opens fully at 90°.
  - At 100% moisture, the servo remains closed at 0°.
- If the moisture level is below 30%, the red LED and buzzer turn ON as an alert.  
- If the moisture level is above 30%, the blue LED turns ON.  
- The soil moisture percentage is displayed on the LCD screen.  

## Folder Structure
- **`smart_irrigation.csv`** → List of components used in the project.
- **`smart_irrigation.ino`** → Arduino code for the project.  
- **`smart_irrigation.pdf`** → Schematic design in PDF format.  
- **`smart_irrigation.png`** → Circuit diagram as an image

## Tinkercad Simulation  
You can view and simulate the project on Tinkercad:  
[**Tinkercad Link**](https://www.tinkercad.com/things/cKfHRCXsmAW-smart-trash-bin)

---

Feel free to modify and improve this project as needed! 😊
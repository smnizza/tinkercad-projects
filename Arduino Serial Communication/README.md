# Arduino Serial Communication

This project demonstrates serial communication between two Arduino boards in Tinkercad. A transmitter (slave) sends button state data to a receiver (master), which controls an LED accordingly.

## How It Works  
- The **transmitter (slave)** reads the button state.
  - If the button is pressed, it sends a signal to the receiver.
- The **receiver (master)** receives the signal and controls the LED.
  - If the button state is HIGH (pressed), the LED turns ON.
  - If the button state is LOW (released), the LED turns OFF.

## Folder Structure  
- **`arduino_serial_comm.csv`** → List of components used in the project.  
- **`arduino_slave.ino`** → Arduino code for the transmitter (slave).  
- **`arduino_master.ino`** → Arduino code for the receiver (master).  
- **`arduino_serial_comm.pdf`** → Schematic design in PDF format.  
- **`arduino_serial_comm.png`** → Circuit diagram as an image.  

## Tinkercad Simulation  
You can view and simulate the project on Tinkercad:  
[**Tinkercad Link**](https://www.tinkercad.com/)

---

Feel free to modify and improve this project as needed! 😊
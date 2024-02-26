# AVR-Atmega32-Simple-Calculator
This embedded project implementing a simple calculator using a keypad and an LCD screen. The project is developed for an AVR atmega32 microcontroller.
# Project Components:
1. Application Layer (APP)
  - **Main Function**: Controls the main program flow.
    
2. Hardware Abstraction Layer (HAL)
  - **LCD Driver**: Facilitates communication with the LCD display to numbers and results.
  - **KEYPAD Driver**: Facilitates communication with the KYEPAD and get numbers from user and operation signs.
    
3. Microcontroller Abstraction Layer (MCAL)
  - **GPIO Driver**: Manages the MCU PINS and PORTS and the communcation between any external device.

# Usage:
To use the calculator:

1. Connect the AVR microcontroller to the keypad and LCD screen according to the pin configurations specified in the code.
2. Compile the code using an AVR compiler toolchain compatible with your development environment.
3. Upload the compiled binary to the AVR microcontroller.
4. The calculator should be ready for use. Press keys on the keypad to perform arithmetic operations and see the results displayed on the LCD screen.
5. you can run the simulation of the project using proteus simulation.

# Notes:
- This code is designed for educational purposes and can be modified or extended according to specific project requirements.
- Make sure to adjust the pin configurations and LCD initialization settings as per your hardware setup.
- Feel free to extend and customize this project according to your needs!

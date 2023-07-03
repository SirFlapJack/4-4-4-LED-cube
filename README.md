This code is designed for controlling a 4x4x4 RGB LED cube using shift registers. The LED cube consists of a total of 64 RGB LEDs arranged in a 4x4x4 grid. The shift registers are used to reduce the number of pins required to control all the LEDs. The cube can display various lighting patterns and colors based on the selected mode.

Project Description:
The 4x4x4 RGB LED cube project is an interactive display that showcases visually appealing patterns and colors using a grid of 64 RGB LEDs. The cube is built using four layers, each containing 16 RGB LEDs, resulting in a cube-like structure. This project combines electronics, programming, and creativity to create stunning visual effects.

The shift register architecture employed in this project enables efficient control of a large number of LEDs while utilizing a limited number of microcontroller pins. In this particular setup, a total of 24 shift registers are utilized, divided into 8 groups. Each group consists of 3 shift registers, responsible for controlling the Red, Green, and Blue channels of the LEDs. Consequently, there are 8 shift register groups, each handling the RGB values for 8 LEDs. Altogether, this arrangement facilitates the management of a matrix of 64 LEDs within the RGB LED cube. By employing shift registers in this manner, the project optimizes pin usage and streamlines the control mechanism for the LED cube.

The code provided implements different modes for the LED cube. The available modes include:

All white LEDs: Sets all LEDs to display a bright white color.
Random rainbow colors: Assigns random colors from a predefined set of rainbow colors to each LED.
All black LEDs: Turns off all LEDs, resulting in a black appearance.
All blue LEDs: Sets all LEDs to display a blue color.
The code continuously loops, allowing the user to select a mode through a serial interface. Once a mode is selected, the corresponding function is called to update the LED values based on the chosen mode. The updateLEDs() function then sends the updated LED values to the shift registers, which in turn control the LEDs to display the desired patterns and colors.

Overall, this project offers an engaging visual experience by harnessing the power of RGB LEDs and utilizing shift registers for efficient control. It provides a platform for experimentation and creativity, allowing users to create their own lighting effects and patterns by modifying the code.

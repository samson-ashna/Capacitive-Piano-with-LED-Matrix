# Capacitive-Piano-with-LED-Matrix
This repository contains a Capacitive Piano with LED Matrix project built with the Arduino Due.


**A. SOFTWARE**

First, I began by importing the required libraries: a “CapacitiveSensor” library and a “NewToneLib” library into the cross-platform application widely known as Arduino IDE. Then I defined the buzzer pin as well as each note pin. A serial communication then begins for both the LEDs and the buzzer in the void setup(), which allows a timer to be written out in a void loop(), and then the sensitivity of the sensors is set. For the matrix, the pins for each row and column were defined as well as the tempo for how long the LED should flash for. When the user’s touch is detected, a tone is produced from the buzzer, which displays the animated letter of the key that was touched, which is shown in the code for the LED matrix which determines whether the LED light is on or off using binary. The main software design technique was implementing the new tone library and setting pitches for each key of the buzzer by using if-statements and for loops for the matrix letter display.

_The flowchart below of the software component describes the touch-sensitive principle of the Arduino piano when the user’s touch senses each key to produce a buzzer tone using the imported libraries:_

![image](https://github.com/samson-ashna/Capacitive-Piano-with-LED-Matrix/assets/46391817/06cde9fb-72ab-41f1-a942-fe8828d28b4d)

**B. HARDWARE**

Firstly, a microcontroller is required to control the function of the embedded system in this project, which is to play notes when they are touch-sensed. For this capacitive piano, an Arduino Due as a microcontroller was used. Some of the main electronic parts include the piezo buzzer, LEDs, microcontroller & circuit components such as resistors and box connectors. And lastly, the mechanical design would be the touch-sensitive component. The resistors, red LEDs, foiled paper keys, and the piezo buzzer all connect to the Arduino Due to ultimately produce each buzzer frequency. The main application of the Arduino paper piano is to simulate a real-life prototype of a playable electronic instrument device such as a piano. In the hardware component, each digital pin from the Arduino board is connected to a resistor and each key detected emits a frequency through the piezo buzzer. They are connected using jumper wires, paper clips, and highly capacitive aluminum foil. The touch-sensed notes are displayed in a 4x4 matrix with LEDs in its letter note formation simultaneously.

_In the circuit diagram below, each digital pin is connected to a resistor and each key emits a frequency through the buzzer. The notes are then displayed through the LED matrix:_

![image](https://github.com/samson-ashna/Capacitive-Piano-with-LED-Matrix/assets/46391817/4cf083a0-2699-49d1-bae0-1835a6b3e89c)

**C. HOW IT WORKS (THE SCIENCE BEHIND IT)**

The most interesting aspect is the main design tricks used for this project. Mainly, a capacitive sensor uses the characteristics of a capacitor and its electrical field to form a sensor. Capacitive sensors work by detecting any change in the electric field the sensor can register either by touch or proximity, displacement…etc. It's called capacitive because the technology is based on detecting anything conductive from air. In this case, the human body (one’s fingers) is being used as an electrical charge conductor. The mutual capacitive between the individual’s finger and the electrode allows a flow of current from the microcontroller.

_The final embedded system hardware after all the modifications:_

![image](https://github.com/samson-ashna/Capacitive-Piano-with-LED-Matrix/assets/46391817/3f077923-c183-4d71-aba8-8b2fac85569e)

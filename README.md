# Arduino Ultrasonic Radar

A radar-style scanner built with an Arduino Uno. A servo sweeps an ultrasonic sensor from 0° to 180° and back, and the distance at each angle is printed to the Serial Monitor.

## Demo
have to add a video link here

## Components I Used 
- Arduino Uno
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- Breadboard and jumper wires

## Pin Connections

 Servo signal - 8 
 HC-SR04 TRIG - 10 
 HC-SR04 ECHO - 11 
 VCC (servo and sensor) - 5V 
 GND - GND 

## How It Works
1. The servo rotates in 2° steps from 0° to 180°, then back.
2. At each angle, the Arduino sends a 10 µs pulse to the TRIG pin.
3. The sensor sends an ultrasonic signal through the TRIG . `pulseIn()` measures how long the ECHO takes to return.
4. Distance is calculated as: `distance (cm) = time (µs) × 0.0341 / 2`
5. The angle and distance are printed over serial at 9600 baud.

## How to Run
1. Wire the circuit as shown above.
2. Open the `.ino` file in the Arduino IDE.
3. Upload it to the Uno.
4. Open the Serial Monitor (9600 baud) to see the readings.

## Known Limitations
- If nothing is in range (about 5 m), the sensor times out and the output shows 0 cm.
- Readings can be unreliable on soft or angled surfaces.

## What I Learned
- Controlling a servo with the Servo library
- Triggering and reading an HC-SR04 using `pulseIn()`
- Converting echo time to distance
- Organizing code with functions and named constants

## Future Improvements
- Visual radar display on the PC
- Handling the no-echo case properly
- Non-blocking timing with `millis()`

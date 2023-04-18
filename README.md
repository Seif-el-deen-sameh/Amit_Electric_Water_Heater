# Amit Graduation Project 2: Water Electric Heater

Project Layout
![Untitled](https://user-images.githubusercontent.com/94634728/232644837-a6e7be5d-774d-439d-983c-25d34a684d0e.jpg)

Project Flowchart
![Amit_electric_heater_state_machine(1)](https://user-images.githubusercontent.com/94634728/232644919-31a16798-9209-4c79-9b59-b8bb85964048.jpeg)

Project 2:Electric Water Heater
Specifications –Temperature Setting
1. The “Up” or “Down” buttons are used to change the required water 
temperature (set temperature).
2. The first “Up” or “Down” button press, entersthe temperature setting mode.
3. After entering temperature setting mode, a single “Up” button press increase 
the set temperature by 5 degrees.
4. After entering temperature setting mode, a single “Down” button press 
decrease the set temperature by 5 degrees.
5. The minimum possible set temperature is 35 degrees.
6. The maximum possible set temperature is 75 degrees.
7. The “External E2PROM” should save the set temperature once set.
8. If the electric water heater is turned OFF then ON, the stored set temperature 
should be retrieved from the “External E2PROM”.
9. The initialset temperature is 60 degrees.

• Specifications –ON/OFF Behavior
1. If power is connected to the heater,the electric water heater is in OFF state.
2. If the “ON/OFF” button is released and the electric water heater is in OFF state, 
the electric water heater goesto ON state.
3. If the “ON/OFF” button is released and the electric water heater is in ON state, 
the electric water heater goesto OFF state.
4. In the OFF state, all display should be turned OFF.

• Specifications –Temperature Sensing
1. The temperature sensor measuresthe watertemperature.
2. The watertemperature should increase, if the “Heating Element” is ON.
3. The watertemperature should decrease, if the “Cooling Element” is ON.
4. Temperature should be sensed once every 100 ms.
5. The decision to turn ON or OFF either the “Heating Element” or the “Cooling 
Element” based on the average of the last 10 temperature readings.

• Specifications –Heating/Cooling Elements
1. The “Heating Element” should be turned ON, if the current watertemperature is less 
than the set temperature by 5 degrees.
2. The “Cooling Element” should be turned OFF, if the current watertemperature is less 
than the set temperature by 5 degrees.
3. The “Heating Element” should be turned OFF, if the current watertemperature is 
greaterthan the set temperature by 5 degrees.
4. The “Cooling Element” should be turned ON, if the current watertemperature is 
greater than the set temperature by 5 degrees.

• Specifications –Seven Segments
1. Seven segment by defaultshow the current watertemperature or the set 
temperature.
2. By default, the 2 seven segment display are show the current water 
temperature.
3. If the electric water heater is in the temperature setting mode, the 2 seven 
segment displaysshould blink every 1 second and show the set temperature.
4. In the temperature setting mode, every change in the set temperature should 
be reflected on the 2 seven segment displays.
5. The 2 seven segment display should exit the temperature setting mode, if the
“UP” and “Down” buttons are not pressed for 5 seconds.

• Specifications –Heating Element Led
1. If the “Heating Element” is ON, the “Heating Element Led” should blink every 1 
second.
2. If the “Cooling Element” is ON, the “Heating Element Led” should be ON.

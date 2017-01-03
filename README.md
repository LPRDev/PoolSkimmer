<a href="https://github.com/LPRDev/PoolSkimmer/blob/master/images/PoolRobot1.jpg">
<img src="https://github.com/LPRDev/PoolSkimmer/blob/master/images/PoolRobot1.jpg" align="right" width="50%" height="50%">
</a>
# PoolSkimmer
Transforms an RC Boat to autonomous robotic pool skimmer!
----

The PoolSkimmer project takes a standard RC Boat (e.g. the <a href=http://www.nikkorc.com/products-category/boats> Nikko Sea Racer</a>)  and transforms it into a semi autonomous drone that can clean debris from a the top surface of a pool. This is an Arduino based project that uses standard motor controllers to take over the speed and direction of the boat. A sonic sensor is used to detect pool walls and ladders so the Pool Skimmer can change direction to avoid the object.

# Parts List
Heres a brief list of the parts used:

* Nikko Sea Racer RC Boat (or any rc boat that does NOT have an EXC controller)
* Aruduino UNO (Any Aurdino should do)
* Any Arduino Uno case
* <a href=""http://playground.arduino.cc/Main/AdafruitMotorShield>Arduino Motor Shield (LD293)</a>
* <a href="http://www.micropik.com/PDF/HCSR04.pdf"> HC-SR04 Sonor Sensor</a>
* Breadboard jumper for Arduino
* 8" of 3/4" CPVC piping
* 4 45 degree CPVC connectors
* 4 90 degree CPVC connectors 
* 1 Pool noodle with 3/4" center (should fit snuggly over the CPVC pipe)
* Replacement head for pool skimmer (rectangular model)

Approxiamate cost of the project: $120, should be less that $40 if you have an old RC boat that can be sacraficed for the project.

# Assembly
<a href="https://github.com/LPRDev/PoolSkimmer/blob/master/images/100_7561.jpg">
<img src="https://github.com/LPRDev/PoolSkimmer/blob/master/images/100_7561.jpg" align="left" width="25%" height="25%">
</a>
Remove the top of the RC boat. The Arduino board will need to be mounted in a Arduino Case (case bottom only) and placed on top of the RC controller board. For the Sea Racer there is sufficient room for Arudino Case for the top of the RC Boat to be placed back on. The Motor Sheild mounts right on top of the Arduino Uno. This prevents the case top from be used. The LD293 pins line up with the Arduinos and some of them pass though for easy connections.

A Simple coat hanger can be used to mount the sonar sensor. Remove the black plastic rails on the top of the RC boat.The end of the coat hanger will fit snuggly into the rail holes on both sides of the boat seats. Bend the hanger so that the top of the hanger is about 8 to 10 inches over the boat surface. Use wire ties to secure the sonar sensor to the hanger (see picture on top of the page). Connect four of the jumers to the sonor sensor pins. Label the ends so they can be easily connected later on (sonor sensor has pin names on its circuit board).

# Power

The 6 batteries that power the RC boat are sufficient to power this project (including the Arduino board). Clip the end off of two of the breadboard jumpers (preferabbly one red and one black jumper) and solder the red jumper to the positive side of the battery terminal and the black the negative (you may have to remove the battery pack from the boat housing).

# Wiring
<a href="https://github.com/LPRDev/PoolSkimmer/blob/master/images/poolskimmerwiring.png">
<img src="https://github.com/LPRDev/PoolSkimmer/blob/master/images/poolskimmerwiring.png" align="right" width="50%" height="50%">
</a>
Unfortunately this project requires cutting wires on the RC boat. You will need to determine the wires that control the propeller motor and the rudder motor. This is easily accomplished by opening the boat and tracing the wires from the RC receiver (the circuit board in the picture) to the motors. Disconnect the two wires going to the Propeller motor (Black motor in the center of the boat) using a soldering iron. Repeat this for the wires going to the rudder motor as well. Label the wires so you can easly connect them in the following steps.

Connect the jumpers from the battery to the Motor sheild as shown in the wiring diagram (red to Vcc and black to ground). The jumper should slip snuggly over the power and ground pins. The Propeller wires should be connected to M1 and M2 on the motor sheild as shown. There may be a little trial and erro to determine forward and backward. Repeat the same for connecting the rudder pins to M3 and M4.

Connnect the jumpers from the sonar sensor as inidcated in the wiring diagram. Note that power and ground can be connected to Vcc and ground of the LD293 motoer sheild board.

Lastly connect the power and ground pins from the battert to the main power terminals on the LD293 motor sheild board. 

# Installing the software
Once this repo has been cloned, an arduino project can be created using the <a href="https://www.arduino.cc/en/main/software"> Arduino IDE </a>. The software can be downloaded into the Arduino from the IDE using a simple USB cable. Once the softare is loaded, power off the Arduino and it should be ready for it maiden voyage.  

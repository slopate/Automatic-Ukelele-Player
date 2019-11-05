# Automatic-Ukelele-Player

For this project, we wanted to use motors to actuate a physical instrument. We saw many of examples of this with percussion instruments in class, but we wanted to try something a bit more ambitious and went with a stringed instrument. We settled on a Ukelel because of it's portability, and because its strings are relatively easy to maniuplate. Originally, we thought we would change the pitch of the strings by adjust the tuning pegs, which would be clipped to Servo motors. However it quickly became apparent that this would not give us the level of control that we wanted, and so we decided to move a slider along the fretboard instead. 

Our custom hardware can be broadly broken down into two parts; the sliding mechanism and the strumming mechanism, which are each contained in their own project box and connected via a PVC pipe. The sliding mechanism uses a DC motor, which is attached to a threaded rod via a 3D printed mold that fits the shaft of the DC motor. On the threaded rod, there is a single nut, which is attached by popsicle sticks to a plastic sliding mechanism which rests on the fretboard of the ukelele. When the threaded rod spins, it causes the stationary nut to move along the axis of the rod, thus causing the sliding mechanism to move upwards and downwards on the fretboard. 

The strumming mechanism is controlled via a Servo motor. We attached a popsicle stick to the top of the servo motor, which has a guitar pick clipped to the end. This pick then strums accross the ukelele strings (in either direction) when the Servo is activated. 

The users controls the automatic player with two ultrasound sensors, which detects the distance at which the ultrasound waves are blocked. This allows the user to control the ukelele by moving their hands closer and further from the sensors. The sensor to the left of the ukelele controls the frequency of the strumming. The closer your move your hand to the sensor, the faster the strumming gets. The sensor to the right of the ukelele controls the speed and direction of the fretboard slider. At the closest hand position to the sensor, the slider moves down the fretbaord at the highest speed, 

## Some Photos

![Top down](assets/IMG_2763.jpg)

![Side](assets/IMG_5291.jpg)

![Sensor assembly](assets/IMG_6571.jpg)

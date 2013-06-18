MATLAB Project:		Kinect Fruit Ninja
By:			Hayyaan Ahmad

Video demonstration:
http://www.youtube.com/watch?v=hp7VQ7djSYU

Summary:
This game is an impletention of the popular game Fruit Ninja available for mobile devices. The unique aspect being its ability to use the Microsoft Kinect device as its input. In essence, you are playing Fruit Ninja, with your hands as controllers. [Adaption of Fruit Ninja for Kinect]

The rules are simple, cut/slice as many fruits as possible while avoiding bombs. Get maximum score.
You get 1 point for cutting a fruit. But you lose 1 point for letting a fruit out of your screen without slicing it, and you lose 10 points for cutting a bomb.

Usage:
Start the program by running RunMe.m. You will be required to choose your mode of play.

DEPENDANCIES:
Microsoft Kinect SDK (Optional)
Microsoft C++ Express
Microsoft SDK
Microsoft .NET Framework
Microsoft Visual Basic PROFESSIONAL
OpenNI
PrimeSense
KinectSensor for PrimeSense
Kinect Matlab API
IMPORTANT NOTE: YOU MAY BE REQUIRED TO COMPILE MEX FILES FOR PROPER EXECUTION OF KINECT MODES.



Options:
There are 2 main modes of play:
1. Arcade mode: Classic Fruit ninja rules. (as defined above)
2. Avoid the bombs: You need to avoid the bombs as they come onto your screen. 3 bomb hits and you lose

For each mode, you have multiple configurations of play:
1. Kinect mode: After launching the game, you take your position infront of the kinect sensor and wait for some time (around 1 minute maximum). After it loads, try to hold still for about 5-10 seconds to achieve best calibration.
	There is also a 2 player mode available for Kinect mode. This is essentially the same, but with two people playing at the same time.
2. Mouse mode: Instead of the kinect sensor, you need to use the mouse as your cursor.


Features:
The fruit generation and motion is completely random and easy to change.
When you hit a bomb, the whole screen shakes to emphasize the effect.
You get a trail behind your cursor, to track progress.



Programming:

Unusual Features:
Very simplified graphics are employed to keep the game fast and responsive. Sprites were slowing everything down to a standstill. The kinect in itself requires a lot of memory usage.

Structure:
The main program is started by RunMe.m

The executable files are all named according to the mode they represent PLAY(Kinect/Mouse)(mode).m.

The function fruitgenerator and fruitcutter, generate and cut the fruit respectively. The structure is such that adding/modifying fruits is a breeze.
The function Motiongenerator generates random speed/acceleration values for the fruit. Function bombexplode initiates the screen shaking effect. The function bombgenerator just generates bombs.
The function startposition generates random starting positions for the motion of the fruit.

The resources folder contains background images and sprites.

The Kinect folder stores all the kinect related files. The compiled MEX files and the generated functions to make use of the Kinect sensor.



� Kinect Matlab API from the internet.
� Hayyaan Ahmad

Thank you for downloading the "Jcam Engine 2D 2.0 ALPHA" devkit.

===========
CONTENTS:
	1. Installation
	2. Running games
	3. Creating games
	4. Troubleshooting
	5. Credits
	6. Engine Info (for nerds)
===========
1. Installation
	To install Jcam Engine 2D onto your computer, simply unzip the contents of the Jcam Engine 2D zip archive into it's own folder somewhere on your computer.
	To install games into Jcam Engine 2D, simply drag the resources and scripts into their respective folders. 

===========
2. Running games
	To run a game in Jcam Engine 2D,  simply make sure that the proper "startup.lua" is in the scripts folder and that all of the resources have been unpacked. Then you can launch "Jcam Engine 2D.exe" and your game will begin.

============
3. Making games
	To make a game with Jcam Engine 2D, you need a few tools.
	1. A good lua editor. We use Notepad++ at Jcam Technologies, but you can use whatever one you want.
	2. The Jcam Engine 2D map maker. This comes with the devkit. Look for "map maker.exe"
	3. A decent tile making program. We use everything from photoshop to paint.net across the team at Jcam Technologies.

	Once you have these tools, you can begin making your game. To learn how to use the map maker, open "Readme-maps.txt" and to learn how to script for Jcam Engine 2D, open "Readme-scripting.txt."

============
4. Troubleshooting
	If you are having problems getting your game to run, there are a few things you should check. First check the "EngineLog.txt" to see if anything failed on initialization. If there is nothing wrong there, then check your lua scripts. Be sure that they aren't referencing anything that doesn't exist. Double check all resource filenames and script filenames.
	Finally, if none of that works, you can email Seth at support@jcamtech.com for more help.

============
5. Credits
	Programmed by Seth Hope
	Using the Allegro 5.1.8 C++ library

============
6. Tech Info
	Jcam Engine 2D was written entirely in C++ with the Allegro 5.1 library. It defaults to running in DirectX unless it is not available, in which case it will run in OpenGL.
	Jcam Engine 2D is running the lua 5.1 library with a custom funciton and definition set.
============
Custom scripting definintions for Jcam Engine 2D
============
Contents
	1. Script requirements
	2. Custom functions

============
1. Script requirements
	For scripts to work with Jcam Engine 2D, every game must have a "startup.lua" file in the root of the "scripts" folder. The startup file must contain a function "update(lastKey, pressed)" and a function "render()." These functions are called at their respective times in the game loop.

============
2. Custom Functions

	TYPES:
		Sound - This is the sound class, it holds all the audio data for the game. Most commonly grabbed from the Scene class
		Image - This holds image data.
		Map - Holds the games map data. Most commonly grabbed from the Scene class
		Player - holds the player data. Most commonly grabbed from the Scene class
		Scene - Base class for the game. Needed for any integrated systems like collisions or map rendering.

Functions:

	function System_run(filename)
		Runs a lua script located at "filename"

Sound:
	funcion Sound.add(filename, id)
		loads a sound file at "filename" to the sound table. Accepts .wav and .ogg.
	
	function Sound.remove(id)
		Removes sound "ID" from the sound table.
	
	function Sound.play(id)
		Plays the sound "ID"

	function Sound.stop(id)
		Stops the sound "ID"
	
	function Sound.stopAll()
		Stops all sound from table current table.

Image:
	function Image.load(filename)
		Loads image at filename.
	
	function Image.draw(x, y)
		Draws image at point (x,y).

Map:
	function Map.load(filename)
		loads map at filename.
	
	function Map.save(filename)
		Saves current map at filename
	
	function Map.getTrigger(tilex, tiley)
		returns trigger script name at tilex, tiley.

	function map.editCollision(tilex, tiley, value)
		Changes collision map value at tilex, tiley to value

Player:
	function Player.getAttack()
		returns the attack value of the player.
	
	function Player.setAttack(value)
		sets the attack of the player to value.
	
	function Player.getDefence()
		returns the defence value of the player.
	
	function Player.setDefence(value)
		sets the defence of the player to value.

	function Player.getHealth()
		returns the health of the player.
	
	function Player.setHealth(value)
		sets the player health to value

	function Player.getSpeed()
		returns the speed of the player

	function Player.setSpeed(value)
		sets the player speed to value
	
	function Player.setPos(x, y)
		sets the player position to x, y

	function Player.getX()
		returns the player X value
	
	function Player.getY()
		returns the player Y value
		
	function Player.getTileX()
		returns the player X in tile units

	function Player.getTileY()
		returns the player Y in tile units

	function Player.render()
		**DEPRECATED**

	function Player.move(direction, amount)
		Moves player in (direction), (amount) pixels.

Scene:
	function Scene.addSound(filename, id)
		see Sound.add(filename, id)

	function Scene.loadMap(filename)
		see Map.load(filename)
	
	function Scene.getPlayer()
		returns Player

	function Scene.getMap()
		returns Map

	function Scene.getSound()
		returns Sound instance

	function Scene.setPlayerAnim(type, direction, frames, speed, filename)
		loads image (filename)  and sets as an animation with (frames) frame and plays at (speed) speed for player's (direction) (type movement=1/idle=0).

	function Scene.loadFont(filename)
		loads ttf font for GUI use
	
	function Scene.addText(text, x, y)
		adds text to GUI at x, y. returns text ID
	
	function Scene.addTextC(text, x, y, r, g, b)
		adds text to GUI at x, y, with color (rgb). Returns text ID.
	
	function Scene.addTimedText(text, x, y, time)
		adds text to GUI for time ticks at x, y.
	
	function Scene.addTimedTextC(text, x, y, time, r, g, b)
		adds text to GUI for time ticks at x, y, with color (rgb).
	function Scene.deleteText(textID)
		deletes textID from GUI

	function Scene.editText(textID, text)
		changes value of textID to text
	
	function Scene.editTextTime(textID, time)
		changes the timer of textID to time


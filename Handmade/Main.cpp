/*

  All code has been written by Karsten Vermeulen and may be used freely by anyone. It is by no
  means perfect and there is certainly room for improvement in some parts. As a whole, the code
  has been created as part of an engine for the purposes of educating other fellow programmers,
  and anyone else wishing to learn C++ and OOP. Feel free to use, copy, break, update and do as
  you wish with this code - it is there for all!

  UPDATED : February 2017

  -----------------------------------------------------------------------------------------------

- This is the main starting point for the game demo. The main game state is created here and added
  to the main game manager, from where it is run. Change the screen width and height accordingly, 
  and feel free to add more game states.

*/

//include SDL main header file to prevent 
//main lib conflicts in Release mode
#include <SDL.h> 

#include <iostream>
#include <string>
#include "Game.h"
//screen width and height values
int screenWidth = 1024;
int screenHeight = 668;

//variable for name of game demo
std::string gameName = "Save Us!";


//------------------------------------------------------------------------------------------------------
//main function that processes everything  
//------------------------------------------------------------------------------------------------------
int main(int argc, char* args[])
{
	if (!TheGame::Instance()->Initialise("Data/Game.ini"))
	{
		std::cout << "Something went wrong with INITIALISE" << std::endl;
	}
	
	//if (!TheGame::Instance()->Initialise(gameName, screenWidth, screenHeight, false))
	//{
	//	//Just a flag.
	//	std::cout << "Something went wrong with INITIALISE" << std::endl;
	//}

	//Setting a starting state.
	TheGame::Instance()->AddState(new MenuState(nullptr));

	//The actual LOOP.
	TheGame::Instance()->Run();

	return 0;

}
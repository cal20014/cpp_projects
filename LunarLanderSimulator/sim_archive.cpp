/**********************************************************************
 * LAB 06
 * Authors:
 *   Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *   Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include "lander.h"      // for the lander
#include "star.h"        // for the stars
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include <iostream>      // for COUT
#include <iomanip>       // for SETPERCISION
#include <thread>
using namespace std;

#define NUMBER_OF_STARS 50
#define DURATION 0.1
#define SIMULATION_SCREEN_WIDTH 400
#define SIMULATION_SCREEN_HEIGHT 400
#define lUNAR_GRAVITY -1.625

/**********

***************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   // set up the simulator
   Simulator(const Position& posUpperRight) :\
      phase(0), ground(posUpperRight), lander(posUpperRight)
   {
      position = posUpperRight;
      reset();
   }

   // display stuff on the screen
   void display();
   void drawText();
   bool detectCollision();
   void reset();
   void closeProgram();
   void handleInput(const Interface* pUI);
   void runSim(const Interface* pUI);

private:
   unsigned char phase;
   Ground ground;
   Lander lander;
   Position position;
   Star stars[NUMBER_OF_STARS];
   Thrust thrust;
   ogstream gout;
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display()
{
   // draw the lander
   lander.draw(thrust, gout);

   // draw the stars
   for (int i = 0; i < 50; i++)
   {
      stars[i].draw(gout);
   }

   // draw the ground
   ground.draw(gout);
   drawText();
}

/**********************************************************
 * DETECT COLLISION
 * Detects if the lander has crashed or landed
 **********************************************************/
bool Simulator::detectCollision() {
   if (ground.hitGround(lander.getPosition(), lander.getWidth()))
   {
      lander.crash();
      return false;
   }
   if (ground.onPlatform(lander.getPosition(), lander.getWidth()) && lander.getSpeed() <= lander.getMaxSpeed())
   {
      lander.land();
      return false;
   }
   if (ground.onPlatform(lander.getPosition(), lander.getWidth()) && lander.getSpeed() > lander.getMaxSpeed())
   {
      lander.crash();
      return false;
   }

   return true;
}

/**********************************************************
 * DRAW TEXT
 * Draw the text on the screen
 **********************************************************/
void Simulator::drawText()
{
   // Draw Text
   gout.setPosition(Position(5, 380));
   gout << "Fuel: " << fixed << setprecision(0) << lander.getFuel() << " lbs";
   gout.setPosition(Position(5, 360));
   gout << "Altitude: " << fixed << setprecision(0) << lander.getPosition().getY() << " meters";
   gout.setPosition(Position(5, 340));
   gout << "Speed: " << fixed << setprecision(2) << lander.getSpeed() << " m/s";
   gout.setPosition(Position(5, 320));
   gout << "Status: " << (lander.isDead() ? "Dead" : (lander.isLanded() ? "Landed" : "Flying"));

   // draw success message:
   if (lander.isLanded())
   {
      gout.setPosition(Position(150, 300));
      gout << "The Eagle has landed!";
   }
   else if (lander.isDead())
   {
      gout.setPosition(Position(150, 300));
      gout << "Houston, we have a problem!";
   }
}

/**********************************************************
 * RESET
 * Reset the game
 **********************************************************/
void Simulator::reset()
{
   // Initialize the lander
   lander.reset(position);

   // Initialize the stars
   for (int i = 0; i < 50; i++)
   {
      stars[i].reset(position.getX(), position.getY());
   }

   // Initialize the ground
   ground.reset();
}

/**********************************************************
 * CLOSE PROGRAM
 * Close the program
 **********************************************************/
void Simulator::closeProgram()
{
   exit(0);
}

/*************************************
 * HANDLE INPUT
 * Accept user input
 **************************************/
void Simulator::handleInput(const Interface* pUI)
{
   // set the thrusters based on user input
   thrust.set(pUI);

   if (pUI->isSpace())
   {
      reset();   
   }
      if (pUI->isQ())
   {
      gout.setPosition(Position(100, 300));
      gout << "The Simulation has ended.\n";
      gout << "Thank you for running the Lunar Lander Simulator!";
      
      closeProgram();
   }
}

/*************************************
 * RUN SIM
 * Run the simulation
 **************************************/
void Simulator::runSim(const Interface* pUI)
{
   // handle the input
   handleInput(pUI);

   // draw the game
   display();

   if (detectCollision())
   {
      lander.coast(lander.input(thrust, lUNAR_GRAVITY), DURATION);
   }
}

/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSimulator = (Simulator*)p;

   pSimulator->runSim(pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run the unit tests
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32
   testRunner();

   // Initialize OpenGL
   Position posUpperRight(SIMULATION_SCREEN_WIDTH, SIMULATION_SCREEN_HEIGHT);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   ogstream myStream;

   // set everything into action
   ui.run(callBack, (void*)&simulator);

   return 0;
}

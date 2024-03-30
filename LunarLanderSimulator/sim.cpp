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
using namespace std;

const double GRAVITY_CONSTANT = -1.625;

/*************************************************************************
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
   void display(Thrust thrust);
   void drawText();
   bool detectCollision();
   void reset();
   void runSim(const Interface* pUI);

private:
   unsigned char phase;
   Ground ground;
   Lander lander;
   Position position;
   Star stars[50];
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display(Thrust thrust)
{
   ogstream gout;

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


bool Simulator::detectCollision() {
   // cout << lander.getSpeed() << endl;
   if (ground.hitGround(lander.getPosition(), lander.getWidth()))
   {
      lander.crash();
      reset();
      // cout << "crash on ground" << endl;
      return false;
   }
   if (ground.onPlatform(lander.getPosition(), lander.getWidth()) && lander.getSpeed() <= lander.getMaxSpeed())
   {
      lander.land();
      // cout << "land" << endl;
      return false;
   }
   if (ground.onPlatform(lander.getPosition(), lander.getWidth()) && lander.getSpeed() > lander.getMaxSpeed())
   {
      lander.crash();
      reset();
      // cout << "crash on platform, too fast";
      return false;
   }

   return true;

}

void Simulator::drawText()
{
   ogstream gout;
   // Draw Text
   gout.setPosition(Position(5, 380));
   gout << "Fuel: " << fixed << setprecision(0) << lander.getFuel() << " gallons";
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
      gout << "Huston we have a problem!";
   }
}

void Simulator::reset()
{
   lander.reset(position);

   // Initialize the stars
   for (int i = 0; i < 50; i++)
   {
      stars[i].reset(position.getX(), position.getY());
   }

   // Initialize the ground
   ground.reset();
}

void Simulator::runSim(const Interface* pUI)
{
   Thrust thrust;
   thrust.set(pUI);

   // draw the game
   display(thrust);

   if (detectCollision())
   {
      lander.coast(lander.input(thrust, GRAVITY_CONSTANT), 0.06);
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
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   ogstream myStream;


   // set everything into action
   ui.run(callBack, (void*)&simulator);

   return 0;
}

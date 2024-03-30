/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
using namespace std;

 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   // Set the angle of the lander to straight up.
   angle.setUp();

   // Set the status of the lander to PLAYING.
   status = PLAYING;

   // Fill the fuel with 5000.0 units.
   fuel = 5000.0;

   // Set the horizontal velocity to a random value between -4m/s and -10m/s.
   velocity.setDX(-4.0 - (rand() % 7));

   // Set the vertical velocity to a random value between -2m/s and 2m/s.
   velocity.setDY(-2.0 + (rand() % 5));

   // Set the horizontal position to 1 pixel from the right of the screen.
   pos.setX(posUpperRight.getX() - 1);

   // Set the vertical position that is between 75% and 95% of the height of the screen. You will need to use the random() function to do that.
   pos.setY(posUpperRight.getY() * (75 + (rand() % 21)) / 100);
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   // Draw the lander
      gout.drawLander(pos, angle.getRadians());

      if (thrust.isMain() && fuel > 0)
      {
         // Draw the flames
         gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), thrust.isClock(), thrust.isCounter());
      }
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander :: input(const Thrust& thrust, double gravity)
{  
   Acceleration accel;
   double thrustValue = 0;
   if (thrust.isMain())
   {
      // You can only operate controls when there is fuel
      if (fuel >= 10)
      {
         fuel -= 10;
         thrustValue += thrust.mainEngineThrust();
      }
   }
   if (thrust.isClock())
   {
      if (fuel > 0) 
      {
         angle.setRadians(angle.getRadians() + 0.1);
         fuel -= 1;
      }
   }
   
   if (thrust.isCounter()) {
      if (fuel > 0)
      {
         angle.setRadians(angle.getRadians() - 0.1);
         fuel -= 1;
      }
   }

   accel.set(angle, thrustValue);

   // the direction of ddx is opposite for some reason
   accel.setDDX(-1 * accel.getDDX());

   // add gravity to ddy
   accel.addDDY(-1.0);


   return accel;

}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander :: coast(Acceleration & acceleration, double time)
{
   pos.setX(pos.getX() + ((velocity.getDX() + acceleration.getDDX() * time) * time) + (0.5 * acceleration.getDDX() * time * time));
   pos.setY(pos.getY() + ((velocity.getDY() + acceleration.getDDY() * time) * time) + (0.5 * acceleration.getDDY() * time * time));
   velocity.setDX(velocity.getDX() + acceleration.getDDX() * time);
   velocity.setDY(velocity.getDY() + acceleration.getDDY() * time);

   pos.getX();
   pos.getY();

}

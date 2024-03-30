/**********************************************************************
 * Suurce File:
 *    SIMULATION
 * Author:
 *    <your name here>
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

 #include "simulation.h"  // for SIMULATION

using namespace std;

 /**********************************************************
 * DRAW TEXT
 * Draw the text on the screen
 **********************************************************/
void Simulator::drawText(ogstream &gout)
{
   // Draw Text
   gout.setPosition(Position(STATS_TEXT_POSITION_X, STATS_TEXT_POSITION_Y));
   gout << "Altitude: " << fixed << setprecision(0) << projectile.getPosition().getMetersY() << " m\n";
   gout << "Speed: " << fixed << setprecision(2) << projectile.getSpeed() << " m/s\n";
   gout << "Distance: " << fixed << setprecision(0) << projectile.getPosition().getMetersX() << " m\n";
   gout << "Hang Time: " << fixed << setprecision(2) << projectile.getFlightTime() << " s\n";


   // draw success message:
   // if (lander.isLanded())
   // {
   //    gout.setPosition(Position(MESSAGE_TEXT_POSITION_X, MESSAGE_TEXT_POSITION_Y));
   //    gout << "The Eagle has landed!";
   // }

   // else if (lander.isDead())
   // {
   //    gout.setPosition(Position(MESSAGE_TEXT_POSITION_X, MESSAGE_TEXT_POSITION_Y));
   //    gout << "Houston, we have a problem!";
   // }

}

void Simulator::input(const Interface* pUI)
   {
      double radians = 0.1;
      if (pUI->isRight())
      {
         if (howitzer.getElevation().getRadians() >= M_PI_2)
         {
            radians = 0.0;
         }
         howitzer.rotate(radians);
      }
      else if (pUI->isLeft())
      {
         if (howitzer.getElevation().getRadians() <= -M_PI_2)
         {
            radians = 0.0;
         }
         else {
            radians = -0.1;
         }
         howitzer.rotate(radians);
      }
      else if (pUI->isUp() || pUI->isDown())
      {
         radians = 0.1;
         howitzer.raise(radians);

      }
      
   }

   void Simulator::advance(const Interface* pUI)
   {
      double simTime = 0.033;
      double startTime = 0.0;
      if (pUI->isSpace() && !projectile.flying(ground.getElevationMeters(projectile.getPosition()))) // this is the problem
      {
         projectile.fire(howitzer.getPosition(), startTime, howitzer.getElevation().getRadians(), howitzer.getMuzzleVelocity());
         projectile.advance(simTime);
      }
      else if (projectile.flying(ground.getElevationMeters(projectile.getPosition()))) // this is also the problem since flight path is empty
      {
         projectile.advance(simTime);
      }
   }

   void Simulator::display(ogstream & gout)
   {
      projectile.draw(gout);
      howitzer.draw(gout,projectile.getFlightTime());
      ground.draw(gout);
      drawText(gout);
   }
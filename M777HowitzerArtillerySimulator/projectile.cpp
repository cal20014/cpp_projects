/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

 #include "projectile.h"
 #include "angle.h"
 using namespace std;

   // fire the projectile
   void Projectile::fire(Position pos, double time, double angle, double vel) 
   {
      // Convert angle from degrees to radians using the angle class
      Angle a;
      a.setRadians(angle);
      // Calculate the velocity components using the velocity class
      Velocity v(vel * a.getDx(), vel * a.getDy());
      // Create a new PositionVelocityTime object and add it to the flight path
      PositionVelocityTime pvt;
      pvt.pos = pos;
      pvt.v = v;
      pvt.t = time;

      // Add the new PositionVelocityTime object to the flight path
      flightPath.push_back(pvt);
   }

   // advance the round forward until the next unit of time
   void Projectile::advance(double simulationTime) 
   {
      if (flightPath.size() > 0) 
      {
         PositionVelocityTime pvt = flightPath.back();
         double time = simulationTime;
         Angle a = pvt.v.getAngle();
         double gravity = -1 * gravityFromAltitude(pvt.pos.getMetersY());
         double machSpeed = speedSoundFromAltitude(pvt.pos.getMetersY());
         double currentMach = pvt.v.getSpeed() / machSpeed;
         double dragCoefficient = dragFromMach(currentMach);
         double airDensity = densityFromAltitude(pvt.pos.getMetersY());
         double dragForce = forceFromDrag(airDensity, dragCoefficient, radius, pvt.v.getSpeed());
         double dragAccelMag = -1 * (accelerationFromForce(dragForce, mass));
         Acceleration acc;
         acc.set(a, dragAccelMag);
         acc.addDDY(gravity);

         double first = pvt.v.getSpeed();
         pvt.v.add(acc, time);
         double second = pvt.v.getSpeed();
         pvt.pos.addMetersY(pvt.v.getDY() * simulationTime);
         pvt.pos.addMetersX(pvt.v.getDX() * simulationTime);
         pvt.t = simulationTime;
         flightPath.push_back(pvt);
      }
   }

   // draw the projectile
   void Projectile::draw(ogstream& gout) 
   {
      if (!flightPath.empty())
      {
         if (!flightPath.size() >= 5)
         {
            int count = 0;
            for (auto it = flightPath.rbegin(); it != flightPath.rend() && count < 5; ++it) {
               PositionVelocityTime& pvt = *it;
               gout.drawProjectile(pvt.pos, pvt.t);
               ++count;
            }
         }
         else {
            gout.drawProjectile(flightPath.back().pos, getFlightTime());
         }
      }   
   }

   // check if the projectile is flying
   bool Projectile::flying(double groundElevation) 
   {
      if (flightPath.empty())
         return false;
      double elevation = flightPath.back().pos.getMetersY();
      if (elevation <= groundElevation)
         return false;
      return true;
   }

   // get the altitude of the projectile
   double Projectile::getAltitude() { return flightPath.back().pos.getMetersY(); }

   // get the position of the projectile
   Position Projectile::getPosition() 
   { 
      Position pos;
      if (flightPath.empty())
      {
         return pos;
      }
      return flightPath.back().pos;
   }

   // get the flight time of the projectile
   double Projectile::getFlightTime() 
   { 
      if (flightPath.empty())
         return 0.0;
      return flightPath.back().t; 
   }

   // get the speed of the projectile
   double Projectile::getSpeed() 
   {
      if (flightPath.empty())
         return 0.0;
       return flightPath.back().v.getSpeed(); 
   }

   // set the mass of the projectile
   void Projectile::setMass(double mass) {this->mass = mass;}

   // set the radius of the projectile
   void Projectile::setRadius(double radius) {this->radius = radius;};
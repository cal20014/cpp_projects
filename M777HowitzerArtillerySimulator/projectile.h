/**********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include <list>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"
#include "angle.h"
#include "uiDraw.h"

#define DEFAULT_PROJECTILE_WEIGHT 46.7       // kg
#define DEFAULT_PROJECTILE_RADIUS 0.077545   // m

// forward declaration for the unit test class
class TestProjectile; 

 /**********************************************************************
  * Projectile
  *    Everything we need to know about a projectile
  ************************************************************************/
class Projectile
{
public:
   // Friend the unit test class
   friend ::TestProjectile;

   // create a new projectile with the default settings
   Projectile() : mass(DEFAULT_PROJECTILE_WEIGHT), radius(DEFAULT_PROJECTILE_RADIUS) {}

   // reset the projectile to the default settings
   void reset() 
   {
      mass = DEFAULT_PROJECTILE_WEIGHT;
      radius = DEFAULT_PROJECTILE_RADIUS;
      flightPath.clear();
   }

   // fire the projectile
   void fire(Position pos, double time, double angle, double vel);

   // advance the round forward until the next unit of time
   void advance(double simulationTime);

   // draw the projectile
   void draw(ogstream& gout);

   // check if the projectile is flying
   bool flying(double groundElevation);

   // get the altitude of the projectile
   double getAltitude();

   // get the position of the projectile
   Position getPosition();

   // get the flight time of the projectile
   double getFlightTime();

   // get the speed of the projectile
   double getSpeed();

   // set the mass of the projectile
   void setMass(double mass);

   // set the radius of the projectile
   void setRadius(double radius); 

private:

   // keep track of one moment in the path of the projectile
   struct PositionVelocityTime
   {
      PositionVelocityTime() : pos(), v(), t(0.0) {}
      Position pos;
      Velocity v;
      double t;
   };

   double mass;           // weight of the M795 projectile. Defaults to 46.7 kg
   double radius;         // radius of M795 projectile. Defaults to 0.077545 m
   std::list<PositionVelocityTime> flightPath;
};
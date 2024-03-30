/***********************************************************************
 * Source File:
 *    VELOCITY
 * Authors:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/ 

#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include <math.h>  // for sqrt()

/*********************************************
 * VELOCITY : ADD
 *  v = v_0 + a t
 *********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
   dx += acceleration.getDDX() * time;
   dy += acceleration.getDDY() * time;
}


void Velocity::add(const Velocity& v) 
{
   dx += v.getDX();
   dy += v.getDY();
}

void Velocity::reverse()
{
   dx = dx * -1.0;
   dy = dy * -1.0;
}

/*********************************************
 * VELOCITY : GET SPEED
 * find the magnitude of velocity
 *********************************************/
double Velocity::getSpeed() const
{
   return sqrt((dx * dx) + (dy * dy));
}

/*********************************************
 * VELOCITY : SET
 * set from angle and direction
 *********************************************/
void Velocity::set(const Angle & angle, double magnitude)
{
   double radians = angle.getRadians();
   dx = sin(radians) * magnitude;
   dy = cos(radians) * magnitude;
}

/************************************************
 * Velocity :: GET ANGLE
 * Determine the direction things are going
 * where 0 is up. This returns angle (clockwise) in radians
 *        dx
 *     +-------/
 *     |      /
 *  dy |     /
 *     |    /
 *     | a /
 *     |  /
 *     | /
 ************************************************/
Angle Velocity::getAngle() const
{
   Angle a;
   a.setRadians(atan2(dx, dy));
   return a;
}
Angle VelocityDummy::getAngle() const
{
   assert(false); 
   return Angle();
}

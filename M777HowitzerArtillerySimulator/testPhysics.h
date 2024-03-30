/***********************************************************************
 * Header File:
 *    TEST PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    All the automation for the physics functions
 ************************************************************************/


#pragma once

#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include "physics.h"
#include "unitTest.h"



/*******************************
 * TEST PHYSICS
 * A class containing automation for all the physics functions
 ********************************/
class TestPhysics : public UnitTest
{
public:
   void run()
   {

      // Ticket 1: Physics equations
      areaFromRadius_zero();
      areaFromRadius_one();
      areaFromRadius_two();
      areaFromRadius_projectile();

      forceFromDrag_noVelocity();
      forceFromDrag_noRadius();
      forceFromDrag_noDrag();
      forceFromDrag_noDensity();
      forceFromDrag_one();
      forceFromDrag_twoDensity();
      forceFromDrag_twoDrag();
      forceFromDrag_twoRadius();
      forceFromDrag_twoVelocity();
      forceFromDrag_projectile();

      accelerationFromForce_noForce();
      accelerationFromForce_ones();
      accelerationFromForce_twoForce();
      accelerationFromForce_twoMass();
      accelerationFromForce_projectile();

      velocityFromAcceleration_zeroAcceleration();
      velocityFromAcceleration_zeroTime();
      velocityFromAcceleration_ones();
      velocityFromAcceleration_twoAcceleration();
      velocityFromAcceleration_twoTime();

      // Ticket 2: Linear Interpolation equation
      linearInterpolation_coordinatesZero();
      linearInterpolation_coordinatesOne();
      linearInterpolation_coordinatesMiddle();
      linearInterpolation_coordinatesTop();
      linearInterpolation_coordinatesBackwards();

      // Ticket 3: Linear Interpolation with Mapping
      linearInterpolation_mappingZero();
      linearInterpolation_mappingTwo();
      linearInterpolation_mappingMid01();
      linearInterpolation_mappingTop01();
      linearInterpolation_mappinglower23();
      linearInterpolation_mappingSmall();
      linearInterpolation_mappingLarge();

      // Ticket 4: Gravity
      gravityFromAltitude_0();
      gravityFromAltitude_10000();
      gravityFromAltitude_80000();
      gravityFromAltitude_5500();
      gravityFromAltitude_43333();
      gravityFromAltitude_3666();
      gravityFromAltitude_8848();

      // Ticket 5: Density
      densityFromAltitude_0();
      densityFromAltitude_10000();
      densityFromAltitude_80000();
      densityFromAltitude_5500();
      densityFromAltitude_43333();
      densityFromAltitude_3666();
      densityFromAltitude_8848();

      // Ticket 6: Speed of Sound
      speedSoundFromAltitude_0();
      speedSoundFromAltitude_10000();
      speedSoundFromAltitude_80000();
      speedSoundFromAltitude_5500();
      speedSoundFromAltitude_43333();
      speedSoundFromAltitude_3666();
      speedSoundFromAltitude_8848();

      // Ticket 7: Drag
      dragFromMach_000();
      dragFromMach_500();
      dragFromMach_100();
      dragFromMach_060();
      dragFromMach_010();
      dragFromMach_314();

      report("Physics");
   }
private:


   /*****************************************************************
    *****************************************************************
    * AREA FROM RADIUS
    *    area = pi * radius ^ 2
    * double areaFromRadius(double radius);
    *****************************************************************
    *****************************************************************/

   /*******************************************************
    * AREA FROM RADIUS - zero
    * input: radius = 0
    * output: area = 0
    ********************************************************/
   void areaFromRadius_zero()
   {  // SETUP
      double radius = 0.0;
      double area = -999.99;
      // EXERCISE
      area = areaFromRadius(radius);
      // VERIFY
      assertEquals(area, 0.0);
   }  // TEARDOWN
   
   /*******************************************************
    * AREA FROM RADIUS - one
    *    area = pi * radius ^ 2
    * input: radius = 1.0
    * output: area = 3.1415926
    ********************************************************/
   void areaFromRadius_one()
   {  // SETUP
      double radius = 1.0;
      double area = -999.99;
      // EXERCISE
      area = areaFromRadius(radius);
      // VERIFY
      assertEquals(area, M_PI);
   }  // TEARDOWN

   /*******************************************************
    * AREA FROM RADIUS - two
    *    area = pi * radius ^ 2
    * input: radius = 2.0
    * output: area = 12.56637
    ********************************************************/
   void areaFromRadius_two()
   {  // SETUP
      double radius = 2.0;
      double area = -999.99;
      // EXERCISE
      area = areaFromRadius(radius);
      // VERIFY
      assertEquals(area, M_PI * 4.0);
   }  // TEARDOWN

   /*******************************************************
    * AREA FROM RADIUS - projectile
    *    area = pi * radius ^ 2
    * input: radius = 0.077545 the radius of the M795 projectile
    * output: area = 0.018891109
    ********************************************************/
   void areaFromRadius_projectile()
   {  // SETUP
      double radius = 0.077545; // radius of the M795 projectile
      double area = -999.99;
      // EXERCISE
      area = areaFromRadius(radius);
      // VERIFY
      assertEquals(area, .018891109);
   }  // TEARDOWN


   /*****************************************************************
    *****************************************************************
    * FORCE FROM DRAG
    * Determine the drag on a shell based on several things:
    *    density  : The density of the air ?
    *    drag     : The drag coefficient of the shell (no units)
    *    radius   : the radius of the shell (m)
    *    velocity : the velocity of the shell (m/s)
    * This force is determined by
    *    force = 1/2 density drag area velocity ^ 2
    * double forceFromDrag(double density, double drag,
    *                      double radius, double velocity)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * FORCE FROM DRAG - no velocity
     * input:  density=1 drag=1 radius=1 velocity=0
     * output: force=0
     ********************************************************/
   void forceFromDrag_noVelocity()
   {  // SETUP
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 0.0;
      double force = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - no radius
     * input:  density=1 drag=1 radius=0 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noRadius()
   {  // SETUP
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 0.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - no drag
     * input:  density=1 drag=0 radius=1 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noDrag()
   {  // SETUP
      double density  = 1.0;
      double drag     = 0.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - no density
     * input:  density=0 drag=1 radius=1 velocity=1
     * output: force=0
     ********************************************************/
   void forceFromDrag_noDensity()
   {  // SETUP
      double density  = 0.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - one of all
     * input:  density=1 drag=1 radius=1 velocity=1
     * output: force=pi/2
     ********************************************************/
   void forceFromDrag_one()
   {  // SETUP
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 0.5 * M_PI);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - two density
     * input:  density=2 drag=1 radius=1 velocity=1
     * output: force=pi
     ********************************************************/
   void forceFromDrag_twoDensity()
   {  // SETUP
      double density  = 2.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, M_PI);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - two drag
     * input:  density=0 drag=2 radius=1 velocity=1
     * output: force=pi
     ********************************************************/
   void forceFromDrag_twoDrag()
   {  // SETUP
      double density  = 1.0;
      double drag     = 2.0;
      double radius   = 1.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, M_PI);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - two radius
     * input:  density=0 drag=1 radius=2 velocity=1
     * output: force=2pi
     ********************************************************/
   void forceFromDrag_twoRadius()
   {  // SETUP
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 2.0;
      double velocity = 1.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, M_PI * 2.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - two velocity
     * input:  density=0 drag=1 radius=1 velocity=2
     * output: force=2pi
     ********************************************************/
   void forceFromDrag_twoVelocity()
   {  // SETUP
      double density  = 1.0;
      double drag     = 1.0;
      double radius   = 1.0;
      double velocity = 2.0;
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, M_PI * 2.0);
   }  // TEARDOWN

    /*******************************************************
     * FORCE FROM DRAG - projectile
     * input:  density=0.4135000  density of air at 10,000 meters
     *         drag=0.4258        drag coefficient at mach 1 
     *         radius=0.077545    radius of the M795 projectile
     *         velocity=827       muzzle velocity
     * output: force=1137.416876
     ********************************************************/
   void forceFromDrag_projectile()
   {  // SETUP
      double density  = 0.4135000; // 10,000 meters
      double drag     = 0.4258;    // mach 1
      double radius   = 0.077545;  // radius of the M795 projectile
      double velocity = 827.0;     // muzzle velocity
      double force    = -999.99;
      // EXERCISE
      force = forceFromDrag(density, drag, radius, velocity);
      // VERIFY
      assertEquals(force, 1137.4168762);
   }  // TEARDOWN


   /*****************************************************************
    *****************************************************************
    * ACCELERATION FROM FORCE
    * How much acceleration can we expect from a given force
    *    force        : N
    *    mass         : kg
    *    acceleration : m / s^2
    * Equation:
    *    f = m a
    * double accelerationFromForce(double force, double mass)
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * ACCELERATION FROM FORCE - zero force
     * input:  force=0 mass=1
     * output: acceleration=0
     ********************************************************/
   void accelerationFromForce_noForce()
   {  // SETUP
      double force        = 0.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // EXERCISE
      acceleration = accelerationFromForce(force, mass);
      // VERIFY
      assertEquals(acceleration, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * ACCELERATION FROM FORCE - ones
     * input:  force=1 mass=1
     * output: acceleration=1
     ********************************************************/
   void accelerationFromForce_ones()
   {  // SETUP
      double force        = 1.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // EXERCISE
      acceleration = accelerationFromForce(force, mass);
      // VERIFY
      assertEquals(acceleration, 1.0);
   }  // TEARDOWN

    /*******************************************************
     * ACCELERATION FROM FORCE - two force
     * input:  force=2 mass=1
     * output: acceleration=2
     ********************************************************/
   void accelerationFromForce_twoForce()
   {  // SETUP
      double force        = 2.0;
      double mass         = 1.0;
      double acceleration = -9999.99;
      // EXERCISE
      acceleration = accelerationFromForce(force, mass);
      // VERIFY
      assertEquals(acceleration, 2.0);
   }  // TEARDOWN

    /*******************************************************
     * ACCELERATION FROM FORCE - two mass
     * input:  force=1 mass=2
     * output: acceleration=1/2
     ********************************************************/
   void accelerationFromForce_twoMass()
   {  // SETUP
      double force        = 1.0;
      double mass         = 2.0;
      double acceleration = -9999.99;
      // EXERCISE
      acceleration = accelerationFromForce(force, mass);
      // VERIFY
      assertEquals(acceleration, 0.5);
   }  // TEARDOWN

    /*******************************************************
     * ACCELERATION FROM FORCE - projectile
     * input:  force=1137.4168762     // force at mach 1 at 10,000meters at muzzle velocity
     *         mass=46.7kg            // mass of the M795 projectile
     * output: acceleration=24.35582
     ********************************************************/
   void accelerationFromForce_projectile()
   {  // SETUP
      double force        = 1137.4168762;
      double mass         = 46.7;
      double acceleration = -9999.99;
      // EXERCISE
      acceleration = accelerationFromForce(force, mass);
      // VERIFY
      assertEquals(acceleration, 24.355821);
   }  // TEARDOWN


   /*****************************************************************
    *****************************************************************
    * VELOCITY FROM ACCELERATION
    * Determine how much velocity will be imparted in a given amount of time
    * from a given acceleration
    *    acceleration : m / s^2
    *    time         : s
    * Equation:
    *    v = a t
    *  double velocityFromAcceleration(double acceleration,
    *                                  double time)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * VELOCITY FROM ACCELERATION - zero acceleration
     * input:  a=0 t=1
     * output: v=0
     ********************************************************/
   void velocityFromAcceleration_zeroAcceleration()
   {  // SETUP
      double acceleration = 0.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // EXERCISE
      velocity = velocityFromAcceleration(acceleration, time);
      // VERIFY
      assertEquals(velocity, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * VELOCITY FROM ACCELERATION - zero time
     * input:  a=1 t=0
     * output: v=0
     ********************************************************/
   void velocityFromAcceleration_zeroTime()
   {  // SETUP
      double acceleration = 1.0;
      double time         = 0.0;
      double velocity     = -9999.99;
      // EXERCISE
      velocity = velocityFromAcceleration(acceleration, time);
      // VERIFY
      assertEquals(velocity, 0.0);
   }  // TEARDOWN

    /*******************************************************
     * VELOCITY FROM ACCELERATION - ones
     * input:  a=1 t=1
     * output: v=1
     ********************************************************/
   void velocityFromAcceleration_ones()
   {  // SETUP
      double acceleration = 1.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // EXERCISE
      velocity = velocityFromAcceleration(acceleration, time);
      // VERIFY
      assertEquals(velocity, 1.0);
   }  // TEARDOWN

    /*******************************************************
     * VELOCITY FROM ACCELERATION - two acceleration
     * input:  a=2 t=1
     * output: v=2
     ********************************************************/
   void velocityFromAcceleration_twoAcceleration()
   {  // SETUP
      double acceleration = 2.0;
      double time         = 1.0;
      double velocity     = -9999.99;
      // EXERCISE
      velocity = velocityFromAcceleration(acceleration, time);
      // VERIFY
      assertEquals(velocity, 2.0);
   }  // TEARDOWN

    /*******************************************************
     * VELOCITY FROM ACCELERATION - two time
     * input:  a=1 t=2
     * output: v=2
     ********************************************************/
   void velocityFromAcceleration_twoTime()
   {  // SETUP
      double acceleration = 1.0;
      double time         = 2.0;
      double velocity     = -9999.99;
      // EXERCISE
      velocity = velocityFromAcceleration(acceleration, time);
      // VERIFY
      assertEquals(velocity, 2.0);
   }  // TEARDOWN


   /*****************************************************************
    *****************************************************************
    * LINEAR INTERPOLATION (coordinates version)
    * From a pair of domain/range values, interpolate
    *
    *    |        *(d1,r1)
    *    |       /
    *    |      *(d,r)
    *   r|     /
    *    |    *(d0,r0)
    *    |
    *    +-------------
    *           d
    * equation:
    *   (r - r0) / (d - d0) = (r1 - r0) / (d1 - d0)
    * Thus
    *   r  = r0 + (r1 - r0) (d - d0) / (d1 - d0)
    *
    * linearInterpolation(double d0, double r0,
    *                     double d1, double r1,
    *                     double d)
    *****************************************************************
    *****************************************************************/

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is (d0,r0)
    *
    *    |     8,8 * (d1,r1)
    *    |        /
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0) (d,r)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesZero()
   {
      // SETUP
      double d0 = 0.0;
      double r0 = 0.0;
      double d1 = 8.0;
      double r1 = 8.0;
      double d = 0.0;
      // EXERCISE
      double r = linearInterpolation(d0, r0, d1, r1, d);
      // VERIFY
      assertEquals(d0, 0.0);
      assertEquals(r0, 0.0);
      assertEquals(d1, 8.0);
      assertEquals(r1, 8.0);
      assertEquals(d, 0.0);
      assertEquals(r, 0.0);
      // TEARDOWN
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is (d1,r1)
    *
    *    |     8,8 * (d1,r1) (d,r)
    *    |        /
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0) 
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesOne()
   {
      // SETUP
      double d0 = 0.0;
      double r0 = 0.0;
      double d1 = 8.0;
      double r1 = 8.0;
      double d = 8.0;
      // EXERCISE
      double r = linearInterpolation(d0, r0, d1, r1, d);
      // VERIFY
      assertEquals(d0, 0.0);
      assertEquals(r0, 0.0);
      assertEquals(d1, 8.0);
      assertEquals(r1, 8.0);
      assertEquals(d, 8.0);
      assertEquals(r, 8.0);
      // TEARDOWN      
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is in middle
    *
    *    |     8,8 * (d1,r1)
    *    |        /
    *    |  4,4  * (d,r)
    *   r|      /
    *    | 0,0 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesMiddle()
   {
      // SETUP
      double d0 = 0.0;
      double r0 = 0.0;
      double d1 = 8.0;
      double r1 = 8.0;
      double d = 4.0;
      // EXERCISE
      double r = linearInterpolation(d0, r0, d1, r1, d);
      // VERIFY
      assertEquals(d0, 0.0);
      assertEquals(r0, 0.0);
      assertEquals(d1, 8.0);
      assertEquals(r1, 8.0);
      assertEquals(d, 4.0);
      assertEquals(r, 4.0);
      // TEARDOWN      
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is near one
    *
    *    |     8,8 * (d1,r1)
    *    |    6,6 * (d,r)
    *    |       /
    *   r|      /
    *    | 0,0 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesTop()
   {
      // SETUP
      double d0 = 0.0;
      double r0 = 0.0;
      double d1 = 8.0;
      double r1 = 8.0;
      double d = 6.0;
      // EXERCISE
      double r = linearInterpolation(d0, r0, d1, r1, d);
      // VERIFY
      assertEquals(d0, 0.0);
      assertEquals(r0, 0.0);
      assertEquals(d1, 8.0);
      assertEquals(r1, 8.0);
      assertEquals(d, 6.0);
      assertEquals(r, 6.0);
      // TEARDOWN  
   }

   /*********************************************************
    * LINEAR INTERPOLATION - coordinate version where (d,r) is near one
    *
    *    | 1,9 * (d0,r0)
    *    |      \
    *    |   3,5 * (d,r)
    *    |        \
    *   r|         \
    *    |      7,-3 * (d0,r0)
    *    +-------------
    *         d
    *********************************************************/
   void linearInterpolation_coordinatesBackwards()
   {
      // SETUP
      double d0 = 1.0;
      double r0 = 9.0;
      double d1 = 7.0;
      double r1 = -3.0;
      double d = 3.0;
      // EXERCISE
      double r = linearInterpolation(d0, r0, d1, r1, d);
      // VERIFY
      assertEquals(d0, 1.0);
      assertEquals(r0, 9.0);
      assertEquals(d1, 7.0);
      assertEquals(r1, -3.0);
      assertEquals(d, 3.0);
      assertEquals(r, 5.0);
      // TEARDOWN      
   }


   /*****************************************************************
    *****************************************************************
    * LINEAR INTERPOLATION (mapping version)
    * From a list of domains and ranges, linear interpolate
    * double linearInterpolation(const Mapping mapping[], int numMapping, double domain);
    * 
    *     +---------------------+
    *     | Mapping             |
    *     +---------------------+
    *     | + domain : Double   |
    *     | + range : Double    |
    *     +---------------------+
    *****************************************************************
    *****************************************************************/

   /*********************************************************
    * LINEAR INTERPOLATION - mapping at [0]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]  (d,r)
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingZero()
   {  
      // SETUP
      const Mapping mapping[] = 
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 1.0;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 2.0);
      // TEARDOWN
   }  

   /*********************************************************
    * LINEAR INTERPOLATION - mapping at [2]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2] (d,r)
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0] 
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingTwo()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 7.0;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 5.0);
      // TEARDOWN
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping midway between [0]and[1]
    *
    *    |        8,6.5 * mapping[3]
    *    |            /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|2,2.5* (d,r)
    *    |1,2 * mapping[0]  
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingMid01()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 2.0;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 2.5);
      // TEARDOWN
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping closer to [1] than [0]
    *
    *    |           8,6.5 * mapping[3]
    *    |               /
    *    |         7,5   * mapping[2]
    *    |             /
    *    |          /
    *    |     3,3 * mapping[1]
    *   r|2.8,2.9 * (d,r)
    *    |   1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingTop01()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 2.8;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 2.9);
      // TEARDOWN
   }


   /*********************************************************
    * LINEAR INTERPOLATION - mapping closer to [2] than [3]
    *
    *    |        8,6.5 * mapping[3]
    *    |     7.3,5.45 * (d,r)
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappinglower23()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 7.3;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 5.45);
      // TEARDOWN      
   }


   /*********************************************************
    * LINEAR INTERPOLATION - too small - off the end on the low side
    *
    *    |        8,6.5 * mapping[3]
    *    |             /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    |0,2 * (d,r)
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingSmall()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 0.0;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 2.0);
      // TEARDOWN      
   }


   /*********************************************************
    * LINEAR INTERPOLATION - too large - off the end on the high side
    *
    *    |       50,6.5 * (d,r)
    *    |        8,6.5 * mapping[3]
    *    |             /
    *    |      7,5   * mapping[2]
    *    |          /
    *    |       /
    *    |  3,3 * mapping[1]
    *   r|     /
    *    |1,2 * mapping[0]
    *    +-------------
    *       d
    *********************************************************/
   void linearInterpolation_mappingLarge()
   {
      // SETUP
      const Mapping mapping[] =
      { // d    r
         {1.0, 2.0},   // mapping[0]
         {3.0, 3.0},   // mapping[1]
         {7.0, 5.0},   // mapping[2]
         {8.0, 6.5}    // mapping[3]
      };
      double d = 50.0;
      double r = -999.999;  // output
      // EXERCISE
      r = linearInterpolation(mapping, 4 /*numMapping*/, d);
      // VERIFY
      assertEquals(r, 6.5);
      // TEARDOWN      
   }


   /*****************************************************************
    *****************************************************************
    * GRAVITY FROM ALTITUDE
    * Determine gravity coefficient based on the altitude
    *   double gravityFromAltitude(double altitude)
    *****************************************************************
    *****************************************************************/


    /*******************************************************
     * GRAVITY FROM ALTITUDE - at the low range, 0 meters
     * input:  altitude=0
     * output: gravity=9.807
     ********************************************************/
   void gravityFromAltitude_0()
   {
      // SETUP
      double altitude = 0.0;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.807);
      assertEquals(altitude, 0.0);
      // TEARDOWN      
   }


    /*******************************************************
     * GRAVITY FROM ALTITUDE - exactly on 10,000 meters
     * input:  altitude=10,000m
     * output: gravity=9.776
     ********************************************************/
   void gravityFromAltitude_10000()
   {
      // SETUP
      double altitude = 10000.0;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.776);
      assertEquals(altitude, 10000.0);
      // TEARDOWN
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - at the high range, 80,000m
     * input:  altitude=80,000m
     * output: gravity=9.73
     ********************************************************/
   void gravityFromAltitude_80000()
   {
      // SETUP
      double altitude = 80000.0;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.73);
      assertEquals(altitude, 80000.0);
      // TEARDOWN      
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - exactly between two values, 5,5000m
     * input:  altitude=5,500m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_5500()
   {
      // SETUP
      double altitude = 5500.0;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.7895);
      assertEquals(altitude, 5500.0);
      // TEARDOWN      
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - one-third between two values, 43,333.3m
     * input:  altitude=43,333m
     * output: gravity=9.73
     ********************************************************/
   void gravityFromAltitude_43333()
   {
      // SETUP
      double altitude = 43333.0;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.73);
      assertEquals(altitude, 43333.0);
      // TEARDOWN      
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - two-third between two values, 3,666.6m
     * input:  altitude=3,666.6m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_3666()
   {
      // SETUP
      double altitude = 3666.6;
      // EXERCISE
      double gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.795);
      assertEquals(altitude, 3666.6);
      // TEARDOWN      
   }

    /*******************************************************
     * GRAVITY FROM ALTITUDE - elevation of Mt Everest, 8,848.86m
     * input:  altitude=8,848.86m
     * output: gravity=9.795
     ********************************************************/
   void gravityFromAltitude_8848()
   {  // SETUP
      double altitude = 8848.86;
      double gravity = -999.999;
      // EXERCISE
      gravity = gravityFromAltitude(altitude);
      // VERIFY
      assertEquals(gravity, 9.77945);
   }  // TEARDOWN



   /*****************************************************************
    *****************************************************************
    * DENSITY FROM ALTITUDE
    * Determine the density of air based on the altitude
    *    densityFromAltitude(double altitude);
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * DENSITY FROM ALTITUDE - at the low range, 0 meters
     * input:  altitude=0
     * output: density=1.225
     ********************************************************/
   void densityFromAltitude_0()
   {
      // SETUP
      double altitude = 0.0;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 1.225);
      assertEquals(altitude, 0.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - exactly on 10,000 meters
     * input:  altitude=10,000m
     * output: density=0.4135000
     ********************************************************/
   void densityFromAltitude_10000()
   {
      // SETUP
      double altitude = 10000.0;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.4135000);
      assertEquals(altitude, 10000.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - at the high range, 80,000m
     * input:  altitude=80,000m
     * output: density=0.0000185
     ********************************************************/
   void densityFromAltitude_80000()
   {
      // SETUP
      double altitude = 80000.0;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.0000185);
      assertEquals(altitude, 80000.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - exactly between two values, 5,5000m
     * input:  altitude=5,5000m
     * output: density=0.69825
     ********************************************************/
   void densityFromAltitude_5500()
   {
      // SETUP
      double altitude = 5500.0;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.69825);
      assertEquals(altitude, 5500.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - one-third between two values, 43,333.3m
     * input:  altitude=43,333m
     * output: density=0.0030063   almost a vacuum
     ********************************************************/
   void densityFromAltitude_43333()
   {
      // SETUP
      double altitude = 43333.0;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.0030063);
      assertEquals(altitude, 43333.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - two-third between two values, 3,666.6m
     * input:  altitude=3,666.6m
     * output: density=0.849372
     ********************************************************/
   void densityFromAltitude_3666()
   {
      // SETUP
      double altitude = 3666.6;
      // EXERCISE
      double density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.849372);
      assertEquals(altitude, 3666.6);
      // TEARDOWN      
   }

    /*******************************************************
     * DENSITY FROM ALTITUDE - elevation of Mt Everest, 8,848.86m
     * input:  altitude=8,848.86m
     * output: density= 0.4759719  1/3 that of sea level
     ********************************************************/
   void densityFromAltitude_8848()
   {  // SETUP
      double altitude = 8848.86;
      double density = -999.999;
      // EXERCISE
      density = densityFromAltitude(altitude);
      // VERIFY
      assertEquals(density, 0.4759719);
   }  // TEARDOWN
   

   /*****************************************************************
    *****************************************************************
    * SPEED OF SOUND FROM ALTITUDE
    * determine the speed of sound for a given altitude.
    * double speedSoundFromAltitude(double altitude);
    *****************************************************************
    *****************************************************************/

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : sea level
     * input:  altitude=0m
     * output: 340m/s
     ********************************************************/
   void speedSoundFromAltitude_0()
   {
      // SETUP
      double altitude = 0.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 340.0);
      assertEquals(altitude, 0.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 10,000m
     * input:  altitude=10,000m
     * output: 299m/s
     ********************************************************/
   void speedSoundFromAltitude_10000()
   {
      // SETUP
      double altitude = 10000.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 299.0);
      assertEquals(altitude, 10000.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 80,000m
     * input:  altitude=80,000m
     * output: 324m/s
     ********************************************************/
   void speedSoundFromAltitude_80000()
   {
      // SETUP
      double altitude = 80000.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 324.0);
      assertEquals(altitude, 80000.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 5,500m
     * input:  altitude=5,500
     * output: 318.0m/s
     ********************************************************/
   void speedSoundFromAltitude_5500()
   {
      // SETUP
      double altitude = 5500.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 318.0);
      assertEquals(altitude, 5500.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 43,333m
     * input:  altitude=43,333m
     * output: 324.0m/s
     ********************************************************/
   void speedSoundFromAltitude_43333()
   {
      // SETUP
      double altitude = 43333.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 324.0);
      assertEquals(altitude, 43333.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : 3,666m
     * input:  altitude=3,666m
     * output: 325.336m/s
     ********************************************************/
   void speedSoundFromAltitude_3666()
   {
      // SETUP
      double altitude = 3666.0;
      // EXERCISE
      double speedOfSound = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speedOfSound, 325.336); 
      assertEquals(altitude, 3666.0);
      // TEARDOWN      
   }

    /*******************************************************
     * SPEED OF SOUND FROM ALTITUDE : on top of Mount Everest
     * input:  altitude=8,848m
     * output: 303.76m/s
     ********************************************************/
   void speedSoundFromAltitude_8848()
   {  // SETUP
      double altitude = 8848.0;
      double speed = -99.99;
      // EXERCISE
      speed = speedSoundFromAltitude(altitude);
      // VERIFY
      assertEquals(speed, 303.76);
   }  // TEARDOWN

   /*****************************************************************
    *****************************************************************
    * DRAG FROM MACH
    * Determine the drag coefficient for a M795 shell given speed in Mach
    * double dragFromMach(double speedMach)
    *****************************************************************
    *****************************************************************/
   
    /*******************************************************
     * DRAG FROM MACH : not moving
     * input:  speed=0mach
     * output: 0
     ********************************************************/
   void dragFromMach_000()
   {
      // SETUP
      double speed = 0.0;
      // EXERCISE
      double drag = dragFromMach(speed);
      // VERIFY
      assertEquals(drag, 0.0);
      assertEquals(speed, 0.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DRAG FROM MACH : top speed
     * input:  speed=5.00mach
     * output: 0.2656
     ********************************************************/
   void dragFromMach_500()
   {
      // SETUP
      double speed = 5.00;
      // EXERCISE
      double drag = dragFromMach(speed);
      // VERIFY
      assertEquals(drag, 0.2656);
      assertEquals(speed, 5.00);
      // TEARDOWN      
   }

    /*******************************************************
     * DRAG FROM MACH : speed of sound
     * input:  speed=1.00mach
     * output: 0.4258
     ********************************************************/
   void dragFromMach_100()
   {
      // SETUP
      double speed = 1.0;
      // EXERCISE
      double drag = dragFromMach(speed);
      // VERIFY
      assertEquals(drag, 0.4258);
      assertEquals(speed, 1.0);
      // TEARDOWN      
   }

    /*******************************************************
     * DRAG FROM MACH : halfway between 0.5 and 0.7
     * input:  speed=0.6mach
     * output: 0.1845
     ********************************************************/
   void dragFromMach_060()
   {
      // SETUP
      double speed = 0.6;
      // EXERCISE
      double drag = dragFromMach(speed);
      // VERIFY
      assertEquals(drag, 0.1845);
      assertEquals(speed, 0.6);
      // TEARDOWN      
   }

    /*******************************************************
     * DRAG FROM MACH : one third between 0 and .3
     * input:  speed=0.1mach
     * output: 00.0543
     ********************************************************/
   void dragFromMach_010()
   {
      // SETUP
      double speed = 0.1;
      // EXERCISE
      double drag = dragFromMach(speed);
      // VERIFY
      assertEquals(drag, 0.0543);
      assertEquals(speed, 0.1);
      // TEARDOWN      
   }

    /*******************************************************
     * DRAG FROM MACH : random spot
     * input:  speed=3.14159mach
     * output: 00.0543
     ********************************************************/
   void dragFromMach_314()
   {  // SETUP
      double speedMach = 0.1;
      double drag = -99.99;
      // EXERCISE
      drag = dragFromMach(speedMach);
      // VERIFY
      assertEquals(drag, 0.0543);
   }  // TEARDOWN

};

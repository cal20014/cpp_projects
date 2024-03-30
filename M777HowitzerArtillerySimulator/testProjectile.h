/***********************************************************************
 * Header File:
 *    TEST PROJECTILE
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/


#pragma once

#include "projectile.h"
#include "unitTest.h"

using namespace std;

/*******************************
 * TEST PROJECTILE
 * A friend class for Projectile which contains the Projectile unit tests
 ********************************/
class TestProjectile : public UnitTest
{
public:
   void run()
   {
      // Ticket 3: Setup
      defaultConstructor();
      reset_empty();
      reset_full();
      fire_right();
      fire_left();
      fire_up();

      // Ticket 4: Advance
      advance_nothing();
      advance_fall();
      advance_horizontal();
      advance_up();
      advance_diagonalUp();
      advance_diagonalDown();
      flying_false_equal();
      flying_true_greater();
      flying_false_lesser();
      altitude_large();
      altitude_small();
      position_100_200();
      position_0_0();
      time_0();
      time_100();
      speed_50();
      speed_0();
      set_mass_50();
      set_mass_0();
      set_radius_20();
      set_radius_0();

      report("Projectile");
   }

private:
   double metersFromPixels = -1.0;


   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  mass=46.7, radius=0.077545 flightPath={}
    *********************************************/
   void defaultConstructor()
   {
      // SETUP
      // EXERCISE
      Projectile p;
      //assert(p.flightPath.empty() == true);

      // VERIFY
      assertEquals(p.mass, 46.7);
      assertEquals(p.radius, 0.077545);
      assertUnit(p.flightPath.empty());

      // TEARDOWN
   }

   /*********************************************
    * name:    RESET from empty
    * input:   mass=-99, radius=-99, flightPath={}
    * output:  mass=46.7, radius=0.077545 flightPath={}
    *********************************************/
   void reset_empty()
   {
      // SETUP
      Projectile p;
      p.mass = -99;
      p.radius = -99;
      assert(p.flightPath.empty() == true);
      
      // EXERCISE
      
      // VERIFY
      assertUnit(p.flightPath.empty() == true);

      // TEARDOWN
   }

   /*********************************************
    * name:    RESET with a non-zero flight path
    * input:   mass=-99, radius=-99, flightPath={0,1,2}
    * output:  mass=46.7, radius=0.077545 flightPath={}
    *********************************************/
   void reset_full()
   {
      // SETUP
      Projectile p;
      p.mass = -99;
      p.radius = -99;
      Projectile::PositionVelocityTime pvt1, pvt2, pvt3;
      // Set the properties of pvt1, pvt2, pvt3
      p.flightPath = {pvt1, pvt2, pvt3};

      // EXERCISE
      p.reset();

      // VERIFY
      assertEquals(p.mass, 46.7);
      assertEquals(p.radius, 0.077545);
      assertUnit(p.flightPath.empty());

      // TEARDOWN
   }


   /*****************************************************************
    *****************************************************************
    * FIRE
    *****************************************************************
    *****************************************************************/  

   /*********************************************
    * name:    FIRE horizontally right
    * input:   angle=90  pos=(111,222) muzzleVelocity=100
    * output:  flightPath={pos=111,222 v=100,0 t=1}
    *********************************************/
   void fire_right()
   {
      // SETUP
      Projectile p;
      Position pos;
      pos.x = 111;
      pos.y = 222;
      double angle = M_PI_2;
      double muzzleVelocity = 100;
      int time = 1;

      // EXERCISE
      p.fire(pos, time, angle, muzzleVelocity);

      // VERIFY
      assertUnit(p.flightPath.size() == 1);
      //if (p.flightPath.size() == 1)
      //{
         assertEquals(p.flightPath.front().pos.x, 111);
         assertEquals(p.flightPath.front().pos.y, 222);
         assertEquals(p.flightPath.front().v.dx, 100);
         assertEquals(p.flightPath.front().v.dy, 0);
         assertEquals(p.flightPath.front().t, 1);
      //}

      // TEARDOWN
   }

   /*********************************************
    * name:    FIRE horizontally left
    * input:   angle=-90  pos=(111,222) muzzleVelocity=100
    * output:  flightPath={pos=111,222 v=-100,0 t=1}
    *********************************************/
   void fire_left()
   {
      // SETUP
      Projectile p;
      Position pos;
      pos.x = 111;
      pos.y = 222;
      double angle = -M_PI_2;
      double muzzleVelocity = 100;
      int time = 1;

      // EXERCISE
      p.fire(pos, time, angle, muzzleVelocity);

      // VERIFY
      assertUnit(p.flightPath.size() == 1);
      //if (p.flightPath.size() == 1)
      //{
         assertEquals(p.flightPath.front().pos.x, 111);
         assertEquals(p.flightPath.front().pos.y, 222);
         assertEquals(p.flightPath.front().v.dx, -100);
         assertEquals(p.flightPath.front().v.dy, 0);
         assertEquals(p.flightPath.front().t, 1);
      //}

      // TEARDOWN
   }

   /*********************************************
    * name:    FIRE straight up
    * input:   angle=0  pos=(111,222) muzzleVelocity=100
    * output:  flightPath={pos=111,222 v=0,100 t=1}
    *********************************************/
   void fire_up()
   {
      // SETUP
      Projectile p;
      Position pos;
      pos.x = 111;
      pos.y = 222;
      double angle = 0;
      double muzzleVelocity = 100;
      int time = 1;

      // EXERCISE
      p.fire(pos, time, angle, muzzleVelocity);

      // VERIFY
      assertUnit(p.flightPath.size() == 1);
      //if (p.flightPath.size() == 1)
      //{
         assertEquals(p.flightPath.front().pos.x, 111);
         assertEquals(p.flightPath.front().pos.y, 222);
         assertEquals(p.flightPath.front().v.dx, 0);
         assertEquals(p.flightPath.front().v.dy, 100);
         assertEquals(p.flightPath.front().t, 1);
      //}

      // TEARDOWN
   }

   /*****************************************************************
    *****************************************************************
    * ADVANCE
    *****************************************************************
    *****************************************************************/ 

   /*********************************************
    * name:    ADVANCE : the projectile is not fired. Nothing will happen
    * input:   flightPath={}
    * output:  flightPath={}
    *********************************************/
   void advance_nothing()
   {
      // SETUP
      Projectile p;
      //assert(p.flightPath.empty() == true);
      int t = 1;

      // EXERCISE
      p.advance(t);

      // VERIFY
      assertEquals(t, 1);
      assertUnit(p.flightPath.empty() == true);

      // TEARDOWN
   }

   /*********************************************
    * name:    ADVANCE : the projectile is stationary and falls down
    * input:   flightPath={pos=100,200 v=0,0 t=100}
    * output:  flightPath={}{pos=100,190 v=0,-9.8 t=101}
    *********************************************/
   void advance_fall()
   {
      // SETUP
      Projectile p;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.x = 100.0;
      pvt.pos.y = 200.0;
      pvt.v.dx = 0.0;
      pvt.v.dy = 0.0;
      pvt.t = 100.0;
      p.flightPath.push_back(pvt);
      int t = 1.0;

      // EXERCISE
      p.advance(t);

      // VERIFY
      assertEquals(t, 1.0);
      assertUnit(p.flightPath.size() == 2);
      if (p.flightPath.size() == 2)
      {
         assertEquals(p.flightPath.back().pos.x, 100);
         assertEquals(p.flightPath.back().pos.y, 190.1936);
         assertEquals(p.flightPath.back().v.dx, 0);
         assertEquals(p.flightPath.back().v.dy, -9.8064);
         assertEquals(p.flightPath.back().t, 101.0);
      }

      // TEARDOWN
   }

   /*********************************************
    * name:    ADVANCE : the projectile is traveling horizontally
    * input:   flightPath={pos=100,200 v=50,0 t=100}
    * output:  flightPath={}{pos=149.9513,190 
    *                        v=49.9513,-9.8 
    *                        t=101}
    *********************************************/
   void advance_horizontal()
   {
      // SETUP
      Projectile p;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.x = 100.0;
      pvt.pos.y = 200.0;
      pvt.v.dx = 50.0;
      pvt.v.dy = 0.0;
      pvt.t = 100.0;
      p.flightPath.push_back(pvt);
      int t = 1.0;

      // EXERCISE
      p.advance(t);

      // VERIFY
      assertEquals(t, 1.0);
      assertUnit(p.flightPath.size() == 2);
      if (p.flightPath.size() == 2)
      {
         assertEquals(p.flightPath.back().pos.x, 149.9513);
         assertEquals(p.flightPath.back().pos.y, 190.1936);
         assertEquals(p.flightPath.back().v.dx, 49.9513);
         assertEquals(p.flightPath.back().v.dy, -9.8064);
         assertEquals(p.flightPath.back().t, 101);
      }
      // TEARDOWN
   }

   /*********************************************
    * name:    ADVANCE : the projectile is traveling up, no horizontal position change
    * input:   flightPath={pos=100,200 v=0,100 t=100}
    * output:  flightPath={}{pos=100,289.8042 
    *                        v=0,89.8042 
    *                        t=101}
    *********************************************/
   void advance_up()
   {
      // SETUP
      Projectile p;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.x = 100.0;
      pvt.pos.y = 200.0;
      pvt.v.dx = 0.0;
      pvt.v.dy = 100.0;
      pvt.t = 100.0;
      p.flightPath.push_back(pvt);
      int t = 1.0;

      // EXERCISE
      p.advance(t);

      // VERIFY
      assertEquals(t, 1.0);
      assertUnit(p.flightPath.size() == 2);
      if (p.flightPath.size() == 2)
      {
         assertEquals(p.flightPath.back().pos.x, 100.0);
         assertEquals(p.flightPath.back().pos.y, 289.8042);
         assertEquals(p.flightPath.back().v.dx, 0);
         assertEquals(p.flightPath.back().v.dy, 89.8042);
         assertEquals(p.flightPath.back().t, 101);
      }
      // TEARDOWN
   }

   /*********************************************
    * name:    ADVANCE : the projectile is traveling up and across
    * input:   flightPath={pos=100,200 v=50,40 t=100}
    * output:  flightPath={}{pos149.9201,230.1297 
    *                        v=49.9201,30.1297 
    *                        t=101}
    *********************************************/
   void advance_diagonalUp()
   {
      // SETUP
      Projectile p;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.x = 100.0;
      pvt.pos.y = 200.0;
      pvt.v.dx = 50.0;
      pvt.v.dy = 40.0;
      pvt.t = 100.0;
      p.flightPath.push_back(pvt);
      int t = 1.0;

      // EXERCISE
      p.advance(t);

      // VERIFY
      assertEquals(t, 1.0);
      assertUnit(p.flightPath.size() == 2);
      if (p.flightPath.size() == 2)
      {
         assertEquals(p.flightPath.back().pos.x, 149.9201);
         assertEquals(p.flightPath.back().pos.y, 230.1297);
         assertEquals(p.flightPath.back().v.dx, 49.9201);
         assertEquals(p.flightPath.back().v.dy, 30.1297);
         assertEquals(p.flightPath.back().t, 101.0);
      }
      //TEARDOWN
   }

   /*********************************************
    * name:    ADVANCE : the projectile is traveling down and across
    * input:   flightPath={}{}{pos=100,200 v=50,-40 t=100}
    * output:  flightPath={}{}{}{pos149.9201,150.2574
    *                            v=49.9201,-49.7425
    *                            t=101}
    *********************************************/
   void advance_diagonalDown()
   {// setup
      setupStandardFixture();
      Position pos;
      Projectile p;
      Projectile::PositionVelocityTime pvt;
      p.flightPath.push_back(pvt);
      p.flightPath.push_back(pvt);
      pvt.pos.x = 100.0;
      pvt.pos.y = 200.0;
      pvt.v.dx = 50.0;
      pvt.v.dy = -40.0;
      pvt.t = 100.0;
      p.flightPath.push_back(pvt);
      // exercise
      p.advance(1.0);
      // verify
      assertUnit(p.flightPath.size() == 4);
      assertEquals(p.mass, 46.7);
      assertEquals(p.radius, 0.077545);
      assertUnit(!p.flightPath.empty());
      if (!p.flightPath.empty())
      {
         assertEquals(p.flightPath.back().pos.x, 149.9201);
         assertEquals(p.flightPath.back().pos.y, 150.2574);
         assertEquals(p.flightPath.back().v.dx, 49.9201);
         assertEquals(p.flightPath.back().v.dy, -49.7425);
         assertEquals(p.flightPath.back().t, 101.0);
      }
      // teardown
      teardownStandardFixture();
   }

    /*********************************************
    * name:    FLYING : the projectile is not flying when it equals groundElevation
    * input:   flightPath={pos=100,200 v=50,40 t=100}
    *          groundElevation = 200
    * output:  false
    *********************************************/
   void flying_false_equal()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      double groundElevation = 200.0;
      //EXERCISE
      bool isFlying = proj.flying(groundElevation);
      //VERIFY
      assertEquals(isFlying, false);
      //TEARDOWN
   }

    /*********************************************
    * name:    FLYING : the projectile is flying when it is above groundElevation
    * input:   flightPath={pos=100,201 v=50,40 t=100}
    *          groundElevation = 200
    * output:  false
    *********************************************/
   void flying_true_greater()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 201;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      double groundElevation = 200.0;
      //EXERCISE
      bool isFlying = proj.flying(groundElevation);
      //VERIFY
      assertEquals(isFlying, true);
      //TEARDOWN
   }

   /*********************************************
   * name:    FLYING : the projectile is flying when it is above groundElevation
   * input:   flightPath={pos=100,199 v=50,40 t=100}
   *          groundElevation = 200
   * output:  false
   *********************************************/
   void flying_false_lesser()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 199;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      double groundElevation = 200.0;
      //EXERCISE
      bool isFlying = proj.flying(groundElevation);
      //VERIFY
      assertEquals(isFlying, false);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET ALTITUDE : get the altitude of the projectile
   * input:   flightPath={pos=100,1001 v=50,40 t=100}
   * output:  altitude,1001
   *********************************************/
   void altitude_large()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 1001;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double altitude = proj.getAltitude();
      //VERIFY
      assertEquals(altitude, 1001);
      assertEquals(pvt.pos.y, 1001);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }


   /*********************************************
   * name:    GET ALTITUDE : get the altitude of the projectile
   * input:   flightPath={pos=100,1 v=50,40 t=100}
   * output:  altitude,1
   *********************************************/
   void altitude_small()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 1;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double altitude = proj.getAltitude();
      //VERIFY
      assertEquals(altitude, 1);
      assertEquals(pvt.pos.y, 1);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET POSITION : get the position of the projectile
   * input:   flightPath={pos=0,0 v=50,40 t=100}
   * output:  pos = {100,200}
   *********************************************/
   void position_0_0()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 0;
      pvt.pos.x = 0;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      Position pos = proj.getPosition();
      //VERIFY
      assertEquals(pos.x, 0);
      assertEquals(pos.y, 0);
      assertEquals(pvt.pos.y, 0);
      assertEquals(pvt.pos.x, 0);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET POSITION : get the position of the projectile
   * input:   flightPath={pos=100,200 v=50,40 t=100}
   * output:  pos = {100,200}
   *********************************************/
   void position_100_200()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      Position pos = proj.getPosition();
      //VERIFY
      assertEquals(pos.x, 100);
      assertEquals(pos.y, 200);
      assertEquals(pvt.pos.y, 200);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET FLIGHT TIME : get the flight time of the projectile
   * input:   flightPath={pos=100,200 v=50,40 t=0}
   * output:  time = 100
   *********************************************/
   void time_0()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 0;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double time = proj.getFlightTime();
      //VERIFY
      assertEquals(time, 0);
      assertEquals(pvt.pos.y, 200);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 0);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET FLIGHT TIME : get the flight time of the projectile
   * input:   flightPath={pos=100,200 v=50,40 t=100}
   * output:  time = 100
   *********************************************/
   void time_100()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 50;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double time = proj.getFlightTime();
      //VERIFY
      assertEquals(time, 100);
      assertEquals(pvt.pos.y, 200);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 50);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET Velocity : get the speed of the projectile
   * input:   flightPath={pos=100,200 v=0,0 t=100}
   * output:  pos = {100,200}
   *********************************************/
   void speed_0()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 0;
      pvt.v.dy = 0;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double speed = proj.getSpeed();
      //VERIFY
      assertEquals(speed, 0);
      assertEquals(pvt.pos.y, 200);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 0);
      assertEquals(pvt.v.dy, 0);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    GET Velocity : get the speed of the projectile
   * input:   flightPath={pos=100,200 v=30,40 t=100}
   * output:  pos = {100,200}
   *********************************************/
   void speed_50()
   {
      //SETUP
      Projectile proj;
      Projectile::PositionVelocityTime pvt;
      pvt.pos.y = 200;
      pvt.pos.x = 100;
      pvt.v.dx = 30;
      pvt.v.dy = 40;
      pvt.t = 100;
      proj.flightPath.push_back(pvt);
      //EXERCISE
      double speed = proj.getSpeed();
      //VERIFY
      assertEquals(speed, 50);
      assertEquals(pvt.pos.y, 200);
      assertEquals(pvt.pos.x, 100);
      assertEquals(pvt.v.dx, 30);
      assertEquals(pvt.v.dy, 40);
      assertEquals(pvt.t, 100);
      //TEARDOWN
   }

   /*********************************************
   * name:    SET MASS : set the mass of the projectile
   * input:   0.0
   * output:  mass = 0.0
   *********************************************/
   void set_mass_0()
   {
      //SETUP
      Projectile proj;
      proj.radius = 20.0;
      double mass = 0.0;
      //EXERCISE
      proj.setMass(mass);
      //VERIFY
      assertEquals(proj.mass, 0.0);
      assertEquals(proj.radius, 20.0);
      //TEARDOWN
   }

   /*********************************************
   * name:    SET MASS : set the mass of the projectile
   * input:   50.0
   * output:  mass = 50.0
   *********************************************/
   void set_mass_50()
   {
      //SETUP
      Projectile proj;
      proj.radius = 20.0;
      double mass = 50.0;
      //EXERCISE
      proj.setMass(mass);
      //VERIFY
      assertEquals(proj.mass, 50.0);
      assertEquals(proj.radius, 20.0);
      //TEARDOWN
   }

   /*********************************************
   * name:    SET Radius : set the radius of the projectile
   * input:   0.0
   * output:  radius = 0.0
   *********************************************/
   void set_radius_0()
   {
      //SETUP
      Projectile proj;
      proj.mass = 50.0;
      double radius = 0.0;
      //EXERCISE
      proj.setRadius(radius);
      //VERIFY
      assertEquals(proj.mass, 50.0);
      assertEquals(proj.radius, 0.0);
      //TEARDOWN
   }

   /*********************************************
   * name:    SET Radius : set the radius of the projectile
   * input:   20.0
   * output:  radius = 20.0
   *********************************************/
   void set_radius_20()
   {
      //SETUP
      Projectile proj;
      proj.mass = 50.0;
      double radius = 20.0;
      //EXERCISE
      proj.setRadius(radius);
      //VERIFY
      assertEquals(proj.mass, 50.0);
      assertEquals(proj.radius, 20.0);
      //TEARDOWN
   }

   /*****************************************************************
    *****************************************************************
    * STANDARD FIXTURE
    *****************************************************************
    *****************************************************************/
// setup standard fixture - set the zoom to 1100m per pixel
   void setupStandardFixture()
   {
      Position p;
      metersFromPixels = p.metersFromPixels;
      p.metersFromPixels = 1.0;
   }

   // teardown the standard fixture - reset the zoom to what it was previously
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position p;
      p.metersFromPixels = metersFromPixels;
   }

};


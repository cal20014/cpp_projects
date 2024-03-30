/***********************************************************************
 * Header File:
 *    TEST HOWITZER
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include "howitzer.h"
#include "unitTest.h"

/*******************************
 * TEST HOWITZER
 * A friend class for Howitzer which contains the Howitzer unit tests
 ********************************/
class TestHowitzer : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Getters
      defaultConstructor();
      getPosition_zero();
      getPosition_middle();
      getMuzzleVelocity_slow();
      getMuzzleVelocity_standard();
      getElevation_up();
      getElevation_right();
      getElevation_left();

      // Ticket 2: Setters
      generatePosition_small();
      generatePosition_large();
      raise_rightDown();
      raise_rightUp();
      raise_leftDown();
      raise_leftUp();
      rotate_clock();
      rotate_counterClock();
      rotate_wrapClock();
      rotate_wrapCounterClock();

      report("Howitzer");
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
     * output:  zeros
     *********************************************/
   void defaultConstructor()
   {
      // SETUP
      // EXERCISE
      Howitzer h;
      // VERIFY
      assertEquals(h.muzzleVelocity, 827.0);
      assertEquals(h.elevation.radians, 0.0);
      //TEARDOWN
   }

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GET POSITION ZERO
     * input:   h.pos=(0,0)
     * output:  pos=(0,0)
     *********************************************/
   void getPosition_zero()
   {
      //SETUP
      Howitzer h;
      h.position.y = 0.0;
      h.position.x = 0.0;
      //EXERCISE
      Position pos = h.getPosition();
      //VERIFY
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      //TEARDOWN
   }

   /*********************************************
    * name:    GET POSITION MIDDLE
     * input:   h.pos=(123.4, 567.8)
     * output:  pos=(123.4, 567.8)
    *********************************************/
   void getPosition_middle()
   {
      //SETUP
      Howitzer h;
      h.position.x = 123.4;
      h.position.y = 567.8;
      //EXERCISE
      Position pos = h.getPosition();
      //VERIFY
      assertEquals(pos.x, 123.4);
      assertEquals(pos.y, 567.8);
      //TEARDOWN
   }

   /*********************************************
    * name:    GET MUZZLE VELOCITY - SLOW SPEED
     * input:   h.muzzleVelocity=(24.68)
     * output:  m=24.68
    *********************************************/
   void getMuzzleVelocity_slow()
   {
      // SETUP
      Howitzer h;
      h.muzzleVelocity = 24.68;
      h.position.x = 123.4;
      h.position.y = 567.8;
      //EXERCISE
      double m = h.getMuzzleVelocity();
      //VERIFY
      assertEquals(m, 24.68);
      assertEquals(h.position.x, 123.4);
      assertEquals(h.position.y, 567.8);
      //TEARDOWN
   }

   /*********************************************
    * name:    GET MUZZLE VELOCITY - STANDARD SPEED
     * input:   h.muzzleVelocity=(827.00)
     * output:  m=827
    *********************************************/
   void getMuzzleVelocity_standard()
   {
      //SETUP
      Howitzer h;
      h.muzzleVelocity = 827.00;
      h.position.x = 123.4;
      h.position.y = 567.8;
      //EXERCISE
      double m = h.getMuzzleVelocity();
      //VERIFY
      assertEquals(m, 827.00);
      assertEquals(h.position.x, 123.4);
      assertEquals(h.position.y, 567.8);
      //TAKEDOWN
   }

   /*********************************************
    * name:    GET ELEVATION - up
     * input:   h.elevation=0
     * output:  e=0
    *********************************************/
   void getElevation_up()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 0.0;
      //EXERCISE
      Angle e = h.getElevation();
      //VERIFY
      assertEquals(e.radians, 0.0);
      //TEARDOWN
   }

   /*********************************************
    * name:    GET ELEVATION - right
     * input:   h.elevation=0.4
     * output:  e=0.4
    *********************************************/
   void getElevation_right()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 0.4;
      //EXERCISE
      Angle e = h.getElevation();
      //VERIFY
      assertEquals(e.radians, 0.4);
      //TEARDOWN
   }

   /*********************************************
    * name:    GET ELEVATION - left
     * input:   h.elevation=5.8
     * output:  e=5.8
    *********************************************/
   void getElevation_left()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 5.8;
      //EXERCISE
      Angle e = h.getElevation();
      //VERIFY
      assertEquals(e.radians, 5.8);
      //TEARDOWN
   }

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GENERATE POSITION small board
     * input:   (10px, 10px)
     * output:  0 <= x <= 9
     *********************************************/
   void generatePosition_small()
   {
      //SETUP
      Howitzer h;
      Position posUpperRight;
      posUpperRight.x = 10;
      posUpperRight.y = 10;
      //EXERCISE
      h.generatePosition(posUpperRight);
      //VERIFY
      assertUnit(h.position.x <= 9);
      assertUnit(h.position.x >= 0);
      assertEquals(h.position.y, 0);
      //TEARDOWN
   }

    /*********************************************
    * name:    GENERATE POSITION large board
    * input:   (1000px, 1000px)
    * output:  0 <= x <= 900
    *********************************************/
   void generatePosition_large()
   {
      //SETUP
      Howitzer h;
      Position posUpperRight;
      posUpperRight.x = 1000;
      posUpperRight.y = 1000;
      //EXERCISE
      h.generatePosition(posUpperRight);
      //VERIFY
      assertUnit(h.position.x <= 900);
      assertUnit(h.position.x >= 0);
      assertEquals(h.position.y, 0);
      //TEARDOWN
   }

   /*********************************************
    * name:    RAISE to the right/down
    * input:   h.elevation=0.5radians  raise(-0.1)
    * output:  h.elevation=0.6radians
    *********************************************/
   void raise_rightDown()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 0.5;
      //EXERCISE
      h.raise(-0.1);
      //VERIFY
      assertEquals(h.elevation.radians, 0.6);
      //TEARDOWN
   }

   /*********************************************
    * name:    RAISE to the right/up
    * input:   h.elevation=0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_rightUp()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 0.5;
      //EXERCISE
      h.raise(0.1);
      //VERIFY
      assertEquals(h.elevation.radians, 0.4);
      //TEARDOWN
   }

   /*********************************************
    * name:    RAISE to the left down
    * input:   h.elevation=-0.5radians  raise(-0.1)
    * output:  h.elevation=-0.6radians
    *********************************************/
   void raise_leftDown()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = -0.5;
      //EXERCISE
      h.raise(-0.1);
      //VERIFY
      assertEquals(h.elevation.radians, -0.6);
      //TEARDOWN
   }

   /*********************************************
    * name:    RAISE to the left up
    * input:   h.elevation=-0.5radians  raise(0.1)
    * output:  h.elevation=-0.4radians
    *********************************************/
   void raise_leftUp()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = -0.5;
      //EXERCISE
      h.raise(0.1);
      //VERIFY
      assertEquals(h.elevation.radians, -0.4);
      //TEARDOWN
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=.3
    * output:  h.elevation=1.53
    *********************************************/
   void rotate_clock()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 1.23;
      //EXERCISE
      h.rotate(0.3);
      //VERIFY
      assertEquals(h.elevation.radians, 1.53);
      //TEARDOWN
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=-.3
    * output:  h.elevation=0.93
    *********************************************/
   void rotate_counterClock()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 1.23;
      //EXERCISE
      h.rotate(-0.3);
      //VERIFY
      assertEquals(h.elevation.radians, 0.93);
      //TEARDOWN
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE CLOCKWISE WRAP BY 2PI
    * input:   h.elevation=6.1 rotate=.2
    * output:  h.elevation=.01681469
    *********************************************/
   void rotate_wrapClock()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 6.1;
      //EXERCISE
      h.rotate(0.2);
      //VERIFY
      assertEquals(h.elevation.radians, 0.01681469);
      //TEARDOWN
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE WRAP BY 4PI
    * input:   h.elevation=0.1 rotate=-.2 - 4PI
    * output:  h.elevation= -0.1

    *********************************************/
   void rotate_wrapCounterClock()
   {
      //SETUP
      Howitzer h;
      h.elevation.radians = 0.1;
      //EXERCISE
      h.rotate(-0.2 - (M_PI * 4));
      //VERIFY
      assertEquals(h.elevation.radians, -0.1);
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
      p.metersFromPixels = 1100.0;
   }

   // teardown the standard fixture - reset the zoom to what it was previously
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position p;
      p.metersFromPixels = metersFromPixels;
   }
};

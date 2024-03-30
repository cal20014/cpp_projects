/***********************************************************************
 * Header File:
 *    TEST VELOCITY
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    Unit tests for the Velocity class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "velocity.h"

/*********************************************
 * TEST VELOCITY
 * Unit tests for Velocity
 *********************************************/
class TestVelocity : public UnitTest
{
public:
   void run()
   {
      // Ticket 5: From before
      constructor_default();
      constructor_nonDefault();
      getDX();
      getDY();
      getSpeed_up();
      getSpeed_down();
      getSpeed_left();
      getSpeed_right();
      getSpeed_diagonal();
      setDX();
      setDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();
      addDX_zero();
      addDX_value();
      addDY_zero();
      addDY_value();
      add_stationary();
      add_noTime();
      add_moving4Seconds();
      add_moving1Second();

      // Ticket 6: Reverse and add
      reverse_stationary();
      reverse_up();
      reverse_down();
      reverse_left();
      reverse_right();
      reverse_diagonal();
      addV_stationary();
      addV_nothing();
      addV_moving();

      report("Velocity");
   }

private:

   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/
   
   
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  zero
    *********************************************/
   void constructor_default()
   {  // SETUP
      // EXERCISE
      Velocity v;

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
   }  // TEARDOWN
      
   /*********************************************
    * name:    NON DEFAULT CONSTRUCTOR
    * input:   2.3, 4.5
    * output:  (2.3, 4.5)
    *********************************************/
   void constructor_nonDefault()
   {  // SETUP
      double dx = 2.3;
      double dy = 4.5;
      
      // EXERCISE
      Velocity v(dx, dy);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(dx, 2.3);
      assertEquals(dy, 4.5);
   }  // TEARDOWN

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    GET DX
    * input:   (2.3, 4.5)
    * output:  2.3
    *********************************************/
   void getDX()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dx = 99.9;

      // EXERCISE
      dx = v.getDX();

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(dx, 2.3);
   }  // TEARDOWN

   /*********************************************
    * name:    GET DY
    * input:   (2.3, 4.5)
    * output:  4.5
    *********************************************/
   void getDY()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dy = 99.9;

      // EXERCISE
      dy = v.getDY();

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(dy, 4.5);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET SPEED ZERO
    * input:   (0.0, 0.0)
    * output:  0.0
    *********************************************/
   void getSpeed_zero()
   {  // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(s, 0.0);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET SPEED RIGHT
    * input:   (2.3, 0.0)
    * output:  2.3
    *********************************************/
   void getSpeed_right()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 0.0;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 0.0);
      assertEquals(s, 2.3);
   }  // TEARDOWN

   /*********************************************
    * name:    GET SPEED UP
    * input:   (0.0, 4.5)
    * output:  4.5
    *********************************************/
   void getSpeed_up()
   {  // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = 4.5;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 4.5);
      assertEquals(s, 4.5);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET SPEED LEFT
    * input:   (-2.3, 0.0)
    * output:  2.3
    *********************************************/
   void getSpeed_left()
   {  // SETUP
      Velocity v;
      v.dx = -2.3;
      v.dy = 0.0;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, -2.3);
      assertEquals(v.dy, 0.0);
      assertEquals(s, 2.3);
   }  // TEARDOWN

   /*********************************************
    * name:    GET SPEED DOWN
    * input:   (0.0, -4.5)
    * output:  4.5
    *********************************************/
   void getSpeed_down()
   {  // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = -4.5;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, -4.5);
      assertEquals(s, 4.5);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET SPEED DIAGONAL
    * input:   (3.0, -4.0)
    * output:  5.0
    *********************************************/
   void getSpeed_diagonal()
   {  // SETUP
      Velocity v;
      v.dx = 3.0;
      v.dy = -4.0;
      double s = 99.9;

      // EXERCISE
      s = v.getSpeed();

      // VERIFY
      assertEquals(v.dx, 3.0);
      assertEquals(v.dy, -4.0);
      assertEquals(s, 5.0);
   }  // TEARDOWN
   
   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    SET DX
    * input:   (99.9, 88.8) -1.1
    * output:  (-1.1, 88.8)
    *********************************************/
   void setDX()
   {  // SETUP
      Velocity v;
      v.dx = 99.9;
      v.dy = 88.8;
      double dx = -1.1;

      // EXERCISE
      v.setDX(dx);

      // VERIFY
      assertEquals(v.dx, -1.1);
      assertEquals(v.dy, 88.8);
      assertEquals(dx, -1.1);
   }  // TEARDOWN

   /*********************************************
    * name:    SET DY
    * input:   (99.9, 88.8) -1.1
    * output:  (99.9, -1.1)
    *********************************************/
   void setDY()
   {  // SETUP
      Velocity v;
      v.dx = 99.9;
      v.dy = 88.8;
      double dy = -1.1;

      // EXERCISE
      v.setDY(dy);

      // VERIFY
      assertEquals(v.dx, 99.9);
      assertEquals(v.dy, -1.1);
      assertEquals(dy, -1.1);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET UP
    * input:   (-99.9, -88.8) 0 degreess, 3.3
    * output:  (0.0, 3.3)
    *********************************************/
   void set_up()
   {  // SETUP
      Velocity v;
      v.dx = -99.9;
      v.dy = -88.8;
      Angle angle;
      angle.radians = 0.0; // up
      double magnitude = 3.3;

      // EXERCISE
      v.set(angle, magnitude);

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 3.3);
      assertEquals(angle.radians, 0.0);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET DOWN
    * input:   (-99.9, -88.8) 180 degreess, 3.3
    * output:  (0.0, -3.3)
    *********************************************/
   void set_down()
   {  // SETUP
      Velocity v;
      v.dx = -99.9;
      v.dy = -88.8;
      Angle angle;
      angle.radians = M_PI; // DOWN
      double magnitude = 3.3;

      // EXERCISE
      v.set(angle, magnitude);

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, -3.3);
      assertEquals(angle.radians, M_PI);
      assertEquals(magnitude, 3.3);
   }

   /*********************************************
    * name:    SET RIGHT
    * input:   (-99.9, -88.8) 90 degreess, 3.3
    * output:  (3.3, 0.0)
    *********************************************/
   void set_right()
   {  // SETUP
      Velocity v;
      v.dx = -99.9;
      v.dy = -88.8;
      Angle angle;
      angle.radians = M_PI_2; // RIGHT
      double magnitude = 3.3;

      // EXERCISE
      v.set(angle, magnitude);

      // VERIFY
      assertEquals(v.dx, 3.3);
      assertEquals(v.dy, 0.0);
      assertEquals(angle.radians, M_PI_2);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET LEFT
    * input:   (-99.9, -88.8) 270 degreess, 3.3
    * output:  (-3.3, 0.0)
    *********************************************/
   void set_left()
   {  // SETUP
      Velocity v;
      v.dx = -99.9;
      v.dy = -88.8;
      Angle angle;
      angle.radians = M_PI_2 + M_PI; // LEFT
      double magnitude = 3.3;

      // EXERCISE
      v.set(angle, magnitude);

      // VERIFY
      assertEquals(v.dx, -3.3);
      assertEquals(v.dy, 0.0);
      assertEquals(angle.radians, M_PI_2 + M_PI);
      assertEquals(magnitude, 3.3);
   }
   
   /*********************************************
    * name:    SET DIAGONAL
    * input:   (-99.9, -88.8) ~57 degreess, 1.0
    * output:  (0.84, 0.54)
    *********************************************/
   void set_diagonal()
   {  // SETUP
      Velocity v;
      v.dx = -99.9;
      v.dy = -88.8;
      Angle angle;
      angle.radians = 1.0; // up and right somewhat
      double magnitude = 1.0;

      // EXERCISE
      v.set(angle, magnitude);

      // VERIFY
      assertEquals(v.dx, 0.8414);
      assertEquals(v.dy, 0.5403);
      assertEquals(angle.radians, 1.0);
      assertEquals(magnitude, 1.0);
   }
   
   /*********************************************
    * name:    REVERSE STATIONARY
    * input:   (0, 0)
    * output:  (0, 0)
    *********************************************/
   void reverse_stationary()
   {
      // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    REVERSE UP
    * input:   (0,  10)
    * output:  (0, -10)
    *********************************************/
   void reverse_up()
   {
      // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = 10.0;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, -10.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    REVERSE DOWN
    * input:   (0, -12.34)
    * output:  (0,  12.34)
    *********************************************/
   void reverse_down()
   {
      // SETUP
      Velocity v;
      v.dx = 0.0;
      v.dy = -12.34;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 12.34);

      // TEARDOWN
   }

   /*********************************************
    * name:    REVERSE LEFT
    * input:   (-300, 0)
    * output:  ( 300, 0)
    *********************************************/
   void reverse_left()
   {
      // SETUP
      Velocity v;
      v.dx = -300.0;
      v.dy = 0.0;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, 300.0);
      assertEquals(v.dy, 0.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    REVERSE RIGHT
    * input:   ( 0.0123, 0)
    * output:  (-0.0123, 0)
    *********************************************/
   void reverse_right()
   {
      // SETUP
      Velocity v;
      v.dx = 0.0123;
      v.dy = 0.0;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, -0.0123);
      assertEquals(v.dy, 0.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    REVERSE DIAGONAL
    * input:   ( 123.456, -7.89)
    * output:  (-123.456,  8.89)
    *********************************************/
   void reverse_diagonal()
   {
      // SETUP
      Velocity v(123.456, -7.89);
      v.dx = 123.456;
      v.dy = -7.89;

      // EXERCISE
      v.reverse();

      // VERIFY
      assertEquals(v.dx, -123.456);
      assertEquals(v.dy, 7.89);
   }

   /*****************************************************************
    *****************************************************************
    * ADD
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    ADD DX  zero
    * input:   (2.3, 4.5) 0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void addDX_zero()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dx = 0.0;

      // EXERCISE
      v.addDX(dx);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(dx, 0.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD DX  VALUE
    * input:   (2.3, 4.5) 4.1
    * output:  (6.4, 4.5)
    *********************************************/
   void addDX_value()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dx = 4.1;

      // EXERCISE
      v.addDX(dx);

      // VERIFY
      assertEquals(v.dx, 6.4);
      assertEquals(v.dy, 4.5);
      assertEquals(dx,  4.1);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD DY  zero
    * input:   (2.3, 4.5) 0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void addDY_zero()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dy = 0.0;

      // EXERCISE
      v.addDY(dy);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(dy, 0.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD DY  VALUE
    * input:   (2.3, 4.5) 4.1
    * output:  (2.3, 8.6)
    *********************************************/
   void addDY_value()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      double dy = 4.1;

      // EXERCISE
      v.addDY(dy);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 8.6);
      assertEquals(dy, 4.1);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD  STATIONARY
    * input:   v=(2.3, 4.5) a=(0.0, 0.0) t=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_stationary()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      double t = 0.0;

      // EXERCISE
      v.add(a, t);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(t, 0.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD  TIME IS ZERO
    * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_noTime()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 7.0;
      double t = 0.0;

      // EXERCISE
      v.add(a, t);

      // VERIFY
      assertEquals(v.dx, 2.3);
      assertEquals(v.dy, 4.5);
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 7.0);
      assertEquals(t, 0.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD  ONE SECOND
    * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=1.0
    * output:  (8.3, 11.5)
    *********************************************/
   void add_moving1Second()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 7.0;
      double t = 1.0;

      // EXERCISE
      v.add(a, t);

      // VERIFY
      assertEquals(v.dx, 8.3);  // 2.3 + 6.0*1
      assertEquals(v.dy, 11.5); // 4.5 + 7.0*1
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 7.0);
      assertEquals(t, 1.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD  FOUR SECONDS
    * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=4.0
    * output:  (14.3, 24.5)
    *********************************************/
   void add_moving4Seconds()
   {  // SETUP
      Velocity v;
      v.dx = 2.3;
      v.dy = 4.5;
      Acceleration a;
      a.ddx = 3.0;
      a.ddy = 5.0;
      double t = 4.0;

      // EXERCISE
      v.add(a, t);

      // VERIFY
      assertEquals(v.dx, 14.3); // 2.3 + 3.0*4
      assertEquals(v.dy, 24.5); // 4.5 + 5.0*4
      assertEquals(a.ddx, 3.0);
      assertEquals(a.ddy, 5.0);
      assertEquals(t, 4.0);
   }  // TEARDOWN

   /*********************************************
    * name:    ADD  STATIONARY
    * input:   vLHS=(0, 0) vRHS=(2.3, 4.5)
    * output:  vLHS=(2.3, 4.5)
    *********************************************/
   void addV_stationary()
   {
      // SETUP
      Velocity vLHS;
      vLHS.dx = 0.0;
      vLHS.dy = 0.0;
      Velocity vRHS(2.3, 4.5);
      vRHS.dx = 2.3;
      vRHS.dy = 4.5;

      // EXERCISE
      vLHS.add(vRHS);

      // VERIFY
      assertEquals(vLHS.dx, 2.3);
      assertEquals(vLHS.dy, 4.5);
      assertEquals(vRHS.dx, 2.3);
      assertEquals(vRHS.dy, 4.5);

      // TEARDOWN

   }

   /*********************************************
    * name:    ADD  NOTHING
    * input:   vLHS=(2.3, 4.5) vRHS=(0, 0)
    * output:  vLHS=(2.3, 4.5)
    *********************************************/
   void addV_nothing()
   {
      // SETUP
      Velocity vLHS(2.3, 4.5);
      vLHS.dx = 2.3;
      vLHS.dy = 4.5;
      Velocity vRHS(0.0, 0.0);
      vRHS.dx = 0.0;
      vRHS.dy = 0.0;

      // EXERCISE
      vLHS.add(vRHS);

      // VERIFY
      assertEquals(vLHS.dx, 2.3);
      assertEquals(vLHS.dy, 4.5);
      assertEquals(vRHS.dx, 0.0);
      assertEquals(vRHS.dy, 0.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    ADD  MOVING
    * input:   vLHS=(2.3, 4.5) vRHS=(100, 200)
    * output:  vLHS=(102.3, 204.5)
    *********************************************/
   void addV_moving()
   {
      // SETUP
      Velocity vLHS;
      vLHS.dx = 2.3;
      vLHS.dy = 4.5;
      Velocity vRHS;
      vRHS.dx = 100;
      vRHS.dy = 200;

      // EXERCISE
      vLHS.add(vRHS);
      
      // VERIFY
      assertEquals(vLHS.dx, 102.3);
      assertEquals(vLHS.dy, 204.5);
      assertEquals(vRHS.dx, 100);
      assertEquals(vRHS.dy, 200);

      // TEARDOWN
   }

};

/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    All the unit tests for ANGLE
 ************************************************************************/

#pragma once


#include "angle.h"
#include "unitTest.h"

/*******************************
 * TEST ANGLE
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: From before
      defaultConstructor();
      setUp();
      setDown();
      setRight();
      setLeft();
      reverse();
      setRadians_noNormalize();
      setDegrees_noNormalize();
      getDegrees_0();
      getDegrees_270();
      getRadians_0();
      getRadians_270();
      add_0();
      add_value();
      setRadians_oneLap();
      setRadians_sixLaps();
      setDegrees_oneLap();
      setDegrees_sixLaps();
      add_positiveLap();

      // Ticket 2: Components
      getDx_up();
      getDx_down();
      getDx_left();
      getDx_right();
      getDx_diagonal();
      getDy_up();
      getDy_down();
      getDy_left();
      getDy_right();
      getDy_diagonal();
      isRight_right();
      isRight_left();
      isLeft_right();
      isLeft_left();
      setDxDy_up();
      setDxDy_right();
      setDxDy_left();
      setDxDy_diagonal();

      report("Angle");
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
   void defaultConstructor()
   {  // SETUP
      // EXERCISE
      Angle a;
      // VERIFY
      assertUnit(a.radians == 0.0);
   }  // TEARDOWN

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    SET UP
    * input:   nothing
    * output:  0 degrees
    *********************************************/
   void setUp()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setUp();
      // VERIFY
      assertEquals(a.radians, 0.0);
   }  // TEARDOWN

   /*********************************************
    * name:    SET DOWN
    * input:   nothing
    * output:  180 degrees
    *********************************************/
   void setDown()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setDown();
      // VERIFY
      assertEquals(a.radians, M_PI);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET RIGHT
    * input:   nothing
    * output:  90 degrees
    *********************************************/
   void setRight()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setRight();
      // VERIFY
      assertEquals(a.radians, M_PI_2);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET LEFT
    * input:   nothing
    * output:  270 degrees
    *********************************************/
   void setLeft()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setLeft();
      // VERIFY
      assertEquals(a.radians, M_PI + M_PI_2);
   }  // TEARDOWN
   
   /*********************************************
    * name:    REVERSE
    * input:   90
    * output:  270 degrees
    *********************************************/
   void reverse()
   {  // SETUP
      Angle a;
      a.radians = M_PI_2; // 90 degrees
      // EXERCISE
      a.reverse();
      // VERIFY
      assertEquals(a.radians, M_PI_2 + M_PI);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET RADIANS - NO NORMALIZATION
    * input:   45 degrees
    * output:  45 degrees
    *********************************************/
   void setRadians_noNormalize()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setRadians(0.785398);
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET RADIANS - ONE LAP
    * input:   45 + 360 degrees
    * output:  45 degrees
    *********************************************/
   void setRadians_oneLap()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setRadians(0.785398 + (M_PI * 2.0));
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET RADIANS - SIX LAP
    * input:   45 + (6 x 360) degrees
    * output:  45 degrees
    *********************************************/
   void setRadians_sixLaps()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setRadians(0.785398 + (M_PI * 2.0) * 6.0);
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN

   /*********************************************
    * name:    SET DEGREES - NO NORMALIZATION
    * input:   45 degrees
    * output:  45 degrees
    *********************************************/
   void setDegrees_noNormalize()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setDegrees(45.0);
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET DEGREES - ONE LAP
    * input:   45 + 360 degrees
    * output:  45 degrees
    *********************************************/
   void setDegrees_oneLap()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setDegrees(45.0 + 360.0);
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN
   
   /*********************************************
    * name:    SET DEGREES - SIX LAP
    * input:   45 + (6 x 360) degrees
    * output:  45 degrees
    *********************************************/
   void setDegrees_sixLaps()
   {  // SETUP
      Angle a;
      a.radians = -99.9;
      // EXERCISE
      a.setDegrees(45.0 + 360.0 * 6.0);
      // VERIFY
      assertEquals(a.radians, 0.785398);
   }  // TEARDOWN
   
   /*****************************************************************
    *****************************************************************
    * ADD
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    ADD ZERO
    * input:   (45 degrees) 0
    * output:  45 degrees
    *********************************************/
   void add_0()
   {  // SETUP
      Angle a;
      a.radians = 0.785398;
      double r = 0.0;
      
      // EXERCISE
      a.add(r);
      
      // VERIFY
      assertEquals(a.radians, 0.785398);
      assertEquals(r, 0.0);
   }  // TEARDOWN
   
   /*********************************************
    * name:    ADD VALUE
    * input:   (45 degrees) 180 degrees
    * output:  45 degrees
    *********************************************/
   void add_value()
   {  // SETUP
      Angle a;
      a.radians = 0.785398;
      double r = M_PI;
      
      // EXERCISE
      a.add(r);

      // VERIFY
      assertEquals(a.radians, 0.785398 + M_PI);
      assertEquals(r, M_PI);
   }  // TEARDOWN
   
   /*********************************************
    * name:    ADD POSITIVE ONE LAP
    * input:   (45 degrees) 180 + 360 degrees
    * output:  45 degrees
    *********************************************/
   void add_positiveLap()
   {  // SETUP
      Angle a;
      a.radians = 0.785398;
      double r = M_PI + M_PI * 2.0;
      
      // EXERCISE
      a.add(r);

      // VERIFY
      assertEquals(a.radians, 0.785398 + M_PI);
      assertEquals(r, M_PI + M_PI * 2.0);
   }  // TEARDOWN
    
   /*********************************************
    * name:    SET DX DY  UP
    * input:   dx=0 dy=1
    * output:  0 degrees
    *********************************************/
   void setDxDy_up()
   {
      // SETUP
      Angle a;
      a.radians = 1.234567;
      double dx = 0.0;
      double dy = 1;

      // EXERCISE
      a.setDxDy(dx, dy);
      
      // VERIFY
      assertEquals(a.radians, 0.0);

      // TEARDOWN
   }


   /*********************************************
    * name:    SET DX DY  RIGHT
    * input:   dx=4 dy=0
    * output:  90 degrees
    *********************************************/
   void setDxDy_right()
   {
      // SETUP
      Angle a;
      a.radians = 1.234567;
      double dx = 4.0;
      double dy = 0.0;

      // EXERCISE
      a.setDxDy(dx, dy);

      // VERIFY
      assertEquals(a.radians, M_PI_2);

      // TEARDOWN
   }

   /*********************************************
    * name:    SET DX DY  LEFT
    * input:   dx=-0.01 dy=0
    * output:  270 degrees
    *********************************************/
   void setDxDy_left()
   {
      // SETUP
      Angle a;
      a.radians = 1.234567;
      double dx = -0.01;
      double dy = 0.0;

      // EXERCISE
      a.setDxDy(dx, dy);
      
      // VERIFY
      assertEquals(a.radians, M_PI + M_PI_2);

      // TEARDOWN
   }

   /*********************************************
    * name:    SET DX DY  DIAGONAL
    * input:   dx= 5.0 dy=8.6602
    * output:  30 degrees
    *********************************************/
   void setDxDy_diagonal()
   {  
      // SETUP
      Angle a;
      a.radians = 1.234567;
      double dx = 5.0;
      double dy = 8.6602;

      // EXERCISE
      a.setDxDy(dx, dy);

      // VERIFY
      assertEquals(a.radians, M_PI / 6.0);

      // TEARDOWN
   }  

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    GET DEGREES - 0
    * input:   0 degrees
    * output:  0 degrees
    *********************************************/
   void getDegrees_0()
   {  
      // SETUP
      Angle a;
      a.radians = 0.0;
      double d = -99.9;
      // EXERCISE
      d = a.getDegrees();
      // VERIFY
      assertEquals(d, 0.0);
      assertEquals(a.radians, 0.0);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET DEGREES - 270
    * input:   270 degrees
    * output:  270 degrees
    *********************************************/
   void getDegrees_270()
   {  // SETUP
      Angle a;
      a.radians = M_PI + M_PI_2;
      double d = -99.9;
      // EXERCISE
      d = a.getDegrees();
      // VERIFY
      assertEquals(d, 270.0);
      assertEquals(a.radians, M_PI + M_PI_2);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET RADIANS - 0
    * input:   0 degrees
    * output:  0 degrees
    *********************************************/
   void getRadians_0()
   {  // SETUP
      Angle a;
      a.radians = 0.0;
      double r = -99.9;
      // EXERCISE
      r = a.getRadians();
      // VERIFY
      assertEquals(r, 0.0);
      assertEquals(a.radians, 0.0);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET RADIANS - 270
    * input:   270 degrees
    * output:  270 degrees
    *********************************************/
   void getRadians_270()
   {  // SETUP
      Angle a;
      a.radians = M_PI + M_PI_2;
      double r = -99.9;
      // EXERCISE
      r = a.getRadians();
      // VERIFY
      assertEquals(r, M_PI + M_PI_2);
      assertEquals(a.radians, M_PI + M_PI_2);
   }  // TEARDOWN
   
   /*********************************************
    * name:    GET DX - UP
    * input:   0 degrees
    * output:  0 
    *********************************************/
   void getDx_up()
   { 
      // SETUP
      Angle a;
      a.radians = 0.0;

      // EXERCISE
      double dx = a.getDx();

      // VERIFY
      assertEquals(dx, 0.0);
      assertEquals(a.radians, 0.0);

      // TEARDOWN
   }

   /*********************************************
    * name:    GET DX - DOWN
    * input:   180 degrees
    * output:  0
    *********************************************/
   void getDx_down()
   {
      // SETUP
      Angle a;
      a.radians = M_PI;

      // EXERCISE
      double dx = a.getDx();

      // VERIFY
      assertEquals(dx, 0.0);
      assertEquals(a.radians, M_PI);

      // TEARDOWN
   }


   /*********************************************
    * name:    GET DX - LEFT
    * input:   270 degrees
    * output:  -1
    *********************************************/
   void getDx_left()
   {
      // SETUP
      Angle a;
      a.radians = M_PI + M_PI_2;

      // EXERCISE
      double dx = a.getDx();

      // VERIFY
      assertEquals(dx, -1.0);
      assertEquals(a.radians, M_PI + M_PI_2);
   }

   /*********************************************
    * name:    GET DX - RIGHT
    * input:   90 degrees
    * output:  1
    *********************************************/
   void getDx_right()
   {
      // SETUP
      Angle a;
      a.radians = M_PI_2;

      // EXERCISE
      double dx = a.getDx();

      // VERIFY
      assertEquals(dx, 1.0);
      assertEquals(a.radians,M_PI_2);

      // TEARDOWN
   }

   /*********************************************
    * name:    GET DX - DIAGONAL
    * input:   30 degrees
    * output:  0.5
    *********************************************/
   void getDx_diagonal()
   {  // SETUP
      Angle a;
      a.radians = M_PI / 6.0; // 30 degrees
      double dx = -99.9;
      // EXERCISE
      dx = a.getDx();
      // VERIFY
      assertEquals(dx, 0.5);
      assertEquals(a.radians, M_PI / 6.0);
   }  // TEARDOWN


   /*********************************************
    * name:    GET DY - UP
    * input:   0 degrees
    * output:  1
    *********************************************/
   void getDy_up()
   {
      Angle a;
      a.radians = 0;
      double dx = a.getDy();
      assertEquals(dx, 1.0);
      assertEquals(a.radians, 0);
   }

   /*********************************************
    * name:    GET DY - DOWN
    * input:   180 degrees
    * output:  -1
    *********************************************/
   void getDy_down()
   {
      // SETUP
      Angle a;
      a.radians = M_PI;

      // EXERCISE
      double dx = a.getDy();

      // VERIFY
      assertEquals(dx, -1.0);
      assertEquals(a.radians, M_PI);

      // TEARDOWN
   }


   /*********************************************
    * name:    GET DY - LEFT
    * input:   270 degrees
    * output:  0
    *********************************************/
   void getDy_left()
   {
      // SETUP
      Angle a;
      a.radians = M_PI + M_PI_2;

      // EXERCISE
      double dx = a.getDy();

      // VERIFY
      assertEquals(dx, 0);
      assertEquals(a.radians, M_PI + M_PI_2);

      // TEARDOWN
   }

   /*********************************************
    * name:    GET DY - RIGHT
    * input:   90 degrees
    * output:  0
    *********************************************/
   void getDy_right()
   {
      // SETUP
      Angle a;
      a.radians = M_PI_2;

      // EXERCISE
      double dx = a.getDy();

      // VERIFY
      assertEquals(dx, 0);
      assertEquals(a.radians, M_PI_2);

      // TEARDOWN
   }

   /*********************************************
    * name:    GET DY - DIAGONAL
    * input:   30 degrees
    * output:  0.5
    *********************************************/
   void getDy_diagonal()
   {  // SETUP
      Angle a;
      a.radians = M_PI / 6.0; // 30 degrees
      double dy = -99.9;
      // EXERCISE
      dy = a.getDy();
      // VERIFY
      assertEquals(dy, 0.866025);
      assertEquals(a.radians, M_PI / 6.0);
   }  // TEARDOWN

   /*********************************************
    * name:    IS RIGHT - right
    * input:   30 degrees
    * output:  true
    *********************************************/
   void isRight_right()
   {
      // SETUP
      Angle a;
      double degrees = 30.0;
      double radians = degrees / 360.0 * TWO_PI;
      a.radians = radians;

      // EXERCISE
      bool isRight = a.isRight();

      // VERIFY
      assertEquals(degrees, 30.0);
      assertEquals(radians, (degrees / 360.0 * TWO_PI));
      assertEquals(a.radians, radians);
      assertEquals(isRight, true);

      // TEARDOWN
   }

   /*********************************************
    * name:    IS RIGHT - LEFT
    * input:   -70.0 degrees
    * output:  false
    *********************************************/
   void isRight_left()
   {
      // SETUP
      Angle a;
      double degrees = -70.0;
      double radians = degrees / 360.0 * TWO_PI;
      a.radians = radians;

      // EXERCISE
      bool isRight = a.isRight();

      // VERIFY
      assertEquals(degrees, -70.0);
      assertEquals(radians, (degrees / 360.0 * TWO_PI));
      assertEquals(a.radians, radians);
      assertEquals(isRight, false);

      // TEARDOWN
   }

   /*********************************************
    * name:    IS LEFT - right
    * input:   30 degrees
    * output:  false
    *********************************************/
   void isLeft_right()
   {  
      // SETUP
      Angle a;
      double degrees = 30.0;
      double radians = degrees / 360.0 * TWO_PI;
      a.radians = radians;

      // EXERCISE
      bool isLeft = a.isLeft();

      // VERIFY
      assertEquals(degrees, 30.0);
      assertEquals(radians, (degrees / 360.0 * TWO_PI));
      assertEquals(a.radians, radians);
      assertEquals(isLeft, false);

      // TEARDOWN
   }

      /*********************************************
    * name:    IS LEFT - LEFT
    * input:   -70 degrees
    * output:  true
    *********************************************/
   void isLeft_left()
   {
      // SETUP
      Angle a;
      double degrees = -70.0;
      double radians = degrees / 360.0 * TWO_PI;
      a.radians = radians;

      // EXERCISE
      bool isLeft = a.isLeft();

      // VERIFY
      assertEquals(degrees, -70.0);
      assertEquals(radians, (degrees / 360.0 * TWO_PI));
      assertEquals(a.radians, radians);
      assertEquals(isLeft, true);

      // TEARDOWN
   }

};

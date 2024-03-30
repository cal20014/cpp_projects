/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:

   // constructors
   // Default constructor. Initializes both components of the acceleration to zero
   Acceleration() : ddx(0.0), ddy(0.0)   { }

   // Non-default Constructor. Initializes the acceleration with the provided values
   Acceleration(double ddx, double ddy) {this->ddx = ddx; this->ddy = ddy;}

   /*****************************************
   ******************************************
   * GETTERS
   ******************************************
   ******************************************/

   // Returns the horizontal component of the acceleration
   double getDDX() const {return ddx;}

   // Returns the vertical component of the acceleration
   double getDDY() const {return ddy;}
                                     
   /*****************************************
   ******************************************
   * SETTERS
   ******************************************
   ******************************************/

   // Sets the horizontal component of the acceleration                     
   void setDDX(double ddx) {this->ddx = ddx;}

   // Sets the vertical component of the acceleration
   void setDDY(double ddy) {this->ddy = ddy;}

   // Sets the acceleration from an angle and magnitude
   void set(const Angle & a, double magnitude);

   // Adds to the horizontal component of the acceleration
   void addDDX(double ddx) {this->ddx += ddx;}

   // Adds to the vertical component of the acceleration
   void addDDY(double ddy) {this->ddy += ddy;}

   // Adds another Acceleration object to this one
   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};



/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call, GitHub Copilot
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once 

#define _USE_MATH_DEFINES // for M_PI
#include <cmath>   // for M_PI, sin(), cos()
#include <math.h>
#define TWO_PI (M_PI * 2.0) // Define constant for 2*pi (full circle in radians)

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestProjectile;
class TestHowitzer;

/*******************************************************************
 * ANGLE
 * This class represents an angle stored in radians. It provides 
 * methods to get and set the angle in both degrees and radians. 
 * Additional methods are included to set the angle to specific 
 * cardinal directions (up, down, left, right), reverse the angle, 
 * and add a change in value (delta). The class also declares 
 * several friend classes for testing purposes.
 *******************************************************************/
class Angle
{
public:
   // Friend classes for testing
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestProjectile;
   friend TestHowitzer;
   
   // Constructors
   // Default constructor, initializes angle to 0.0 radians
   Angle()                 : radians(0.0)                        {}

   // Copy constructor, copies the angle from another Angle object
   Angle(const Angle& rhs) : radians(rhs.radians)                {}

   // Non-default constructor:
   // Initializes the angle with a specified value in degrees.
   // The input degrees are converted to radians.
   Angle(double degrees)   : radians(convertToRadians(degrees))  {}

   /*****************************************
   ******************************************
   * GETTERS
   ******************************************
   ******************************************/
   double getDx() const { return sin(radians); }
   double getDy() const { return cos(radians); }

   bool   isRight() const 
   { 
      if (radians > 0 && radians < M_PI_2) 
         return true;
      return false;
   }

   bool   isLeft() const 
   { 
      if (radians >= -M_PI_2 && radians < 0.0)
         return true;
      return false;
   }  
   // Returns the angle in degrees
   double getDegrees() const {return convertToDegrees(this->radians);}

   // Returns the angle in radians
   double getRadians() const {return this->radians;}

   /*****************************************
   ******************************************
   * SETTERS
   ******************************************
   ******************************************/     

   // Sets the angle in radians from an input
   // in degrees, after normalization.
   void setDegrees(double degrees) {this->radians = normalize(convertToRadians(degrees));}

   // Sets and normalizes the angle in radians.
   void setRadians(double radians) {this->radians = normalize(radians);}

   // Sets the angle up (0.0 radians)
   void setUp() {radians = 0.0;}

   // Sets the angle down (PI radians)
   void setDown() {radians = M_PI;}

   // Sets the angle right (PI/2 radians)
   void setRight() {radians = M_PI_2;}

   // Sets the angle left (3PI/2 radians)
   void setLeft() {radians = M_PI + M_PI_2;}

   // Reverses the angle (adds pi radians)
   void reverse() {radians += M_PI;}

   // Adds a delta to the angle, normalizes it,
   // and returns the updated Angle.
   Angle& add(double delta) 
   {
      radians = normalize(radians + delta);
      return *this;
   }

   void setDxDy(double dx, double dy)  
   { 
      radians = atan2(dx, dy);
      if (radians < 0) {
         radians += (2 * M_PI);
      }
   }
   Angle operator+(double degrees) const { return Angle(); }

private:

   // Normalizes the angle to be between 0 and 2 PI
   double normalize(double radians) const;

   // Converts an angle from radians to degrees
   double convertToDegrees(double radians) const   {return radians / TWO_PI * 360.0;}

   // Converts an angle from degrees to radians
   double convertToRadians(double degrees) const   {return degrees / 360.0 * TWO_PI;}

   // The angle in radians
   double radians;
};

#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
   out << rhs.getDegrees() << "degree";
   return out;
}


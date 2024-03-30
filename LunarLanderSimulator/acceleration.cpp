/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/

#include "acceleration.h" // The Header file for the Acceleration class
#include "angle.h" // The Header file for the Angle class
#include <cassert> // For ASSERT
#include <cmath> // For sin() and cos() functions

/*********************************************
 * ACCELERATION : ADD
 * Add the components of the provided Acceleration object to the current object.
 * This is equivalent to a += a operation for Acceleration objects.
 *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   this->ddx += acceleration.ddx; // Add the horizontal component
   this->ddy += acceleration.ddy; // Add the vertical component
}

/*********************************************
 * ACCELERATION : SET
 * Set the components of the current Acceleration object based on a given angle 
 * and magnitude. This uses the trigonometric functions sin() and cos() to 
 * calculate the components based on the angle and magnitude.
 *********************************************/
void Acceleration::set(const Angle & angle, double magnitude)
{
   // Get the angle in radians
   double radians = angle.getRadians();

   // Magnitude must be positive
   assert(magnitude >= 0.0);

   // Angle must be between 0 and 2pi (0 and 360 degrees)
   // assert(radians >= 0.0 && radians < TWO_PI);

   // Set the horizontal component
   this->ddx = sin(radians) * magnitude; 

   // Set the vertical component
   this->ddy = cos(radians) * magnitude;
}
/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call, GitHub Copilot
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h" // Include the header file for the Angle class
#include <cassert> // For ASSERT

using namespace std; // Use the standard namespace So we don't have to use std::

 /************************************
  * ANGLE : NORMALIZE
  * This function normalizes an angle in radians to the range 0 to 2PI
  ************************************/
double Angle::normalize(double radians) const
{
   // fmod was suggested by GitHub Copilot. We submitted this function to Copilot
   // and asked how we could make it more efficient and it suggested fmod.
   // Use fmod to bring the angle within the range -2PI to 2PI
   // fmod is the floating point modulus function. It takes two arguments
   // that are doubles and returns the remainder of the first argument
   // after being divided by the second argument.
   radians = fmod(radians, TWO_PI);

   // If the angle is negative, add 2PI to bring it within the range 0 to 2PI
   if (radians < 0.0)
   {
      radians += TWO_PI; 
   }

   // Angle must be between 0 and 2PI (0 and 360 degrees)
   // assert(radians >= 0.0 && radians < TWO_PI);

   return radians;
}

/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "thrust.h"
using namespace std;

/*********************************************
* SET
* Sets the thrust attributes based on user input
***********************************************/
void Thrust::set(const Interface* pUI)
{
   if (pUI->isRight())
      counterClockwise = true;
   else
      counterClockwise = false;

   if (pUI->isLeft())
      clockwise = true;
   else
      clockwise = false;

   if (pUI->isDown())
      mainEngine = true;
   else
      mainEngine = false;
}

/*********************************************
* ROTATION
* Calculates velocity of rotatation based on clockwise
* and counter clockwise rotation and returns it in radians
* per second
***********************************************/
double Thrust::rotation() const
{
   double magnitude = 0.0;
   if (clockwise == true)
   {
      magnitude += 0.1;
   }

   if (counterClockwise == true)
   {
      magnitude -= 0.1;
   }
   return magnitude;
}
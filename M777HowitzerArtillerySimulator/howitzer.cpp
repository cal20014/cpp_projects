/***********************************************************************
 * Source File:
 *    HOWITZER
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    verything we need to know about a howitzer (aka the gun)
 ************************************************************************/

#include "howitzer.h"
using namespace std;

// draw
void Howitzer::draw(ogstream& gout, double flightTime) const
{
   gout.drawHowitzer(position,
      elevation.getRadians(),
      flightTime);
}

// generate a new position for the howitzer
void Howitzer::generatePosition(const Position& posUpperRight)
{
   double xPixels = random(posUpperRight.getPixelsX() * 0.1,
      posUpperRight.getPixelsX() * 0.9);
   position.setPixelsX(xPixels);
   position.setPixelsY(0);
}
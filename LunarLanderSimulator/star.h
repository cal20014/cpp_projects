/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

/*****************************************************
 * STAR
 *    A star that twinkles
 *    The star will be drawn at a random x and y coordinates
 *    The star will receive a random phase and will increment to twinkle
 * Methods:
 *    reset:  Set the position of the star to random x and y coordinates
 *            Set the phase of the star to a random number between 0 and 255
 *    draw:   Draw the star at the current position and phase
 * Members:
 *    pos:    The position of the star
 *    phase:  The phase of the star
 * 
 *****************************************************/
class Star
{
public:
   void reset (double width, double height)
   {
     // Cast the width and height to integers
     int w = (int)width;
     int h = (int)height;

     // Generate a random x-coordinate between 0 and the width
     double x = rand() % w;

     // Generate a random y-coordinate between 0 and the height
     double y = rand() % h;

     // Set the position of the star to random x and y coordinates
     pos.setX(x);
     pos.setY(y);

     // Generate a random phase for the star to twinkle between 0 and 255
     phase = rand() % 256;
   }

   void draw(ogstream& gout) 
   {
      // Draw the star at the current position and phase.
      // Incrementing the phase to make the star twinkle
      gout.drawStar(pos, phase++);
   }

private:
   Position pos;
   unsigned char phase;
};

/**********************************************************************
 * Header File:
 *    SIMULATION
 * Author:
 *    Isaac Huffman, Grant Call, Br. Helfrich
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

#pragma once
#include "position.h"
#include "projectile.h"
#include "howitzer.h"
#include "ground.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <cassert>       // for ASSERT
#include <iostream>      // for COUT
#include <iomanip>       // for setprecision

#define SIMULATOR_NAME "Howitzer M777 Simulator"
#define DURATION 0.1
#define SIMULATION_SCREEN_WIDTH 400
#define SIMULATION_SCREEN_HEIGHT 400
#define STATS_TEXT_POSITION_X 23000
#define STATS_TEXT_POSITION_Y 19200
#define MESSAGE_TEXT_POSITION_X 300
#define MESSAGE_TEXT_POSITION_Y 500

 /*********************************************
  * Simulation
  * Execute one simulation of a projectile being fired.
  *********************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight)  : posUpperRight(posUpperRight), ground(posUpperRight)
   {
      // sets the position of the howitzer
      howitzer.generatePosition(posUpperRight);

      // resets the ground of the simulation
      ground.reset(howitzer.getPosition());
   }

   void drawText(ogstream &gout);
   
   void input(const Interface* pUI);

   void advance(const Interface* pUI);

   void display(ogstream & gout);

   Position posUpperRight;
   Ground ground;
   Howitzer howitzer;
   Projectile projectile;
};

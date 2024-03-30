/***********************************************************************
 * Header File:
 *    POSITION 
 * Authors:
 *    Br. Helfrich, Isaac Huffman, Grant Call
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#pragma once
#include <iostream> 
#include <cmath>
#define DEFAULT_ZOOM 1000.0

class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestGround;
class TestHowitzer;
class TestProjectile;

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
   friend ::TestPosition;    // for the unit tests
   friend ::TestGround;
   friend ::TestHowitzer;
   friend ::TestProjectile;
   
public:
   // constructors
   Position()                     : x(0.0),   y(0.0) { }
   Position(const Position & pos) : x(pos.x), y(pos.y) { }
   Position(double x, double y)   : x(x),     y(y)     { }

   // getters
   double getMetersX() const { return x; }
   double getMetersY() const { return y; }
   double getPixelsX() const { return x/metersFromPixels; }
   double getPixelsY() const { return y/metersFromPixels; }

   bool operator == (const Position & rhs) const
   {
      if (x != rhs.x || y != rhs.y)
         return false;
      else
         return true;
   }
   bool operator != (const Position & rhs) const
   {
      if (x == rhs.x && y == rhs.y)
         return false;
      else
         return true;
   }

   // setters
   void setZoom(double z) { metersFromPixels = z; }
   double getZoom() { return metersFromPixels; }

   void setMeters(double xMeters, double yMeters) { }
   void setMetersX(double x) { this->x = x; }
   void setMetersY(double y) { this->y = y; }
   void setPixelsX(double xPixels) { x = xPixels * metersFromPixels;}
   void setPixelsY(double yPixels) { y = yPixels * metersFromPixels;}
   double addMetersX(double x) { return (this->x += x); }
   double addMetersY(double y) { return (this->y += y); }
   double addPixelsX(double x) { return this->x += x * metersFromPixels; }
   double addPixelsY(double y) { return this->y += y * metersFromPixels; }
   void add (const Acceleration & a, const Velocity & v, double t);

   Position & operator = (const Position & rhs)
   {
      x = rhs.x;
      y = rhs.y;
      return *this;
   }

private:
   double x;           // horizontal position
   double y;           // vertical position
   static double metersFromPixels;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};
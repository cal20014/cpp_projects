/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes

Mapping gravityFromAltitudeMap[] = 
{ 
   {0.0, 9.807}, { 1000.0, 9.804 }, 
   { 2000.0, 9.801 }, { 3000.0, 9.797 },
   { 4000.0, 9.794 }, { 5000.0, 9.791 },
   { 6000.0, 9.788 }, { 7000.0, 9.785 },
   { 8000.0, 9.782 }, { 9000.0, 9.779 },
   { 10000.0, 9.776 }, { 15000.0, 9.761 },
   { 20000.0, 9.745 }, { 25000.0, 9.73 } 
};

Mapping dragFromMachMap[] = 
{
   {0.0, 0.0}, {0.3, 0.1629},
   { 0.5, 0.1659 }, { 0.7, 0.2031 },
   { 0.89, 0.2597 }, { 0.92, 0.301 },
   { 0.96, 0.3287 }, { 0.98, 0.4002 },
   { 1.0, 0.4258 }, { 1.02, 0.4335 },
   { 1.06, 0.4483 }, { 1.24, 0.4064 }, 
   { 1.53, 0.3663 }, { 1.99, 0.2897 }, 
   { 2.87, 0.2297 }, { 2.89, 0.2306 }, 
   { 5.0, 0.2656 }
};

Mapping speedSoundFromAltitudeMap[] = 
{ 
   {0.0, 340.0}, { 1000.0, 336.0 },
   { 2000.0, 332.0 }, { 3000.0, 328.0 }, 
   { 4000.0, 324.0 }, { 5000.0, 320.0 },
   { 6000.0, 316.0 }, { 7000.0, 312.0 },
   { 8000.0, 308.0 }, { 9000.0, 303.0 }, 
   { 10000.0, 299.0 }, { 15000.0, 295.0 },
   { 20000.0, 295.0 }, { 25000.0, 295.0 },
   { 30000.0, 305.0 }, { 40000.0, 324.0 }
};

Mapping densityFromAltitudeMap[] = 
{
   {0.0, 1.225}, { 1000.0, 1.112 },
   { 2000.0, 1.007 }, { 3000.0, 0.9093 },
   { 4000.0, 0.8194 }, { 5000.0, 0.7364 },
   { 6000.0, 0.6601 }, { 7000.0, 0.59 },
   { 8000.0, 0.5258 }, { 9000.0, 0.4671 }, 
   { 10000.0, 0.4135 }, { 15000.0, 0.1948 },
   { 20000.0, 0.08891 }, { 25000.0, 0.04008 },
   { 30000.0, 0.01841 }, { 40000.0, 0.003996 },
   { 50000.0, 0.001027 }, { 60000.0, 0.0003097 },
   { 70000.0, 8.28e-05 }, { 80000.0, 1.85e-05 }
};
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   // Find the index just below the given x value
   int i = 0;
   while (i < numMapping && mapping[i].domain <= domain) {
      i++;
   }

   // If x is below the lowest value, return the value at the lowest x
   if (i == 0) {
      return mapping[0].range;
   }

   if (i == numMapping) 
   {
      return mapping[i-1].range;
   }

   // Find the x value just above the given x
   double x1 = mapping[i].domain;
   double y1 = mapping[i].range;

   // Move to the x value just below the given x
   double x0 = mapping[i - 1].domain;
   double y0 = mapping[i - 1].range;

   // Perform linear interpolation
   return linearInterpolation(x0, y0, x1, y1, domain);
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   int sizeofMap = sizeof(gravityFromAltitudeMap) / sizeof(gravityFromAltitudeMap[0]);
   return linearInterpolation(gravityFromAltitudeMap, sizeofMap, altitude);
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   int sizeofMap = sizeof(densityFromAltitudeMap) / sizeof(densityFromAltitudeMap[0]);
   return linearInterpolation(densityFromAltitudeMap, sizeofMap, altitude);
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   int sizeofMap = sizeof(speedSoundFromAltitudeMap) / sizeof(speedSoundFromAltitudeMap[0]);
   return linearInterpolation(speedSoundFromAltitudeMap, sizeofMap, altitude);
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   int sizeofMap = sizeof(dragFromMachMap) / sizeof(dragFromMachMap[0]);
   return linearInterpolation(dragFromMachMap, sizeofMap, speedMach);
}


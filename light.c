/*
 * Copyright (c) 1991, 1993 Antonio Costa, INESC-Norte.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Antonio Costa, at INESC-Norte. The name of the author and
 * INESC-Norte may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
#include "extern.h"

/**********************************************************************
 *    SCENE - Lights - Version 1.6.2                                  *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, September 1993         *
 **********************************************************************/

/***** Lights *****/
void
create_point_light(point, color)
  xyz_ptr          point;
  rgb_ptr          color;
{
  DEFINE(buffer, "1 %g %g %g %g %g %g", point->x, point->y, point->z,
         color->r, color->g, color->b);
  CREATE(lights_max, lights, light_list, buffer);
}

void
create_dir_light(direct, color)
  xyz_ptr          direct;
  rgb_ptr          color;
{
  /*
   * A directional light is simulated by a far away light with
   * no attenuation
   */
  NORMALIZE(*direct);
  DEFINE(buffer, "1 %g %g %g %g %g %g",
         -direct->x * X_MAX, -direct->y * Y_MAX, -direct->z * Z_MAX,
         -color->r, -color->g, -color->b);
  CREATE(lights_max, lights, light_list, buffer);
}

void
create_spot_light(point, color, direct, angle, factor)
  xyz_ptr          point;
  rgb_ptr          color;
  xyz_ptr          direct;
  real             angle, factor;
{
  DEFINE(buffer, "2 %g %g %g %g %g %g %g %g %g %g %g",
         point->x, point->y, point->z, color->r, color->g, color->b,
         direct->x, direct->y, direct->z, angle, factor);
  CREATE(lights_max, lights, light_list, buffer);
}

void
create_ext_light(point, color, radius, samples)
  xyz_ptr          point;
  rgb_ptr          color;
  real             radius;
  int              samples;
{
  DEFINE(buffer, "3 %g %g %g %g %g %g %g %d", point->x, point->y, point->z,
         color->r, color->g, color->b, radius, samples);
  CREATE(lights_max, lights, light_list, buffer);
}

void
create_linear_light(point, color, vector, samples)
  xyz_ptr          point;
  rgb_ptr          color;
  xyz_ptr          vector;
  int              samples;
{
  DEFINE(buffer, "4 %g %g %g %g %g %g %g %g %g 0 0 0 %d 0",
         point->x, point->y, point->z, color->r, color->g, color->b,
         vector->x, vector->y, vector->z, samples);
  CREATE(lights_max, lights, light_list, buffer);
}

void
create_planar_light(point, color, vector1, vector2, samples1, samples2)
  xyz_ptr          point;
  rgb_ptr          color;
  xyz_ptr          vector1, vector2;
  int              samples1, samples2;
{
  DEFINE(buffer, "4 %g %g %g %g %g %g %g %g %g %g %g %g %d %d",
         point->x, point->y, point->z, color->r, color->g, color->b,
         vector1->x, vector1->y, vector1->z,
         vector2->x, vector2->y, vector2->z, samples1, samples2);
  CREATE(lights_max, lights, light_list, buffer);
}

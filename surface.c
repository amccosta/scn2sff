/*
 * Copyright (c) 1991, 1992 Antonio Costa, INESC-Norte.
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
 *    SCENE - Surfaces - Version 1.6.1                                *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, July 1993              *
 **********************************************************************/

#define ATTRIBUTE(a, b) (a ? (b > 0.001 ? -b : -0.001) : b)

/***** Surfaces *****/
#define NOTFOUND 0

static int
find_surface()
{
  int             i;

  for (i = surfaces - 1; i >= 0; i--)
    if (NOT strcmp(buffer, surface_list[i]))
      return i + 1;
  return NOTFOUND;
}

void
create_surface1(color, diffuse, specular, phong, factor, transp,
		emitter, noshadow)
  rgb_ptr         color, diffuse, specular;
  real            phong, factor;
  rgb_ptr         transp;
  boolean         emitter, noshadow;
{
  DEFINE(buffer, "1 %g %g %g %g %g %g %g %g %g %g %g %g %g %g",
         ATTRIBUTE(emitter, color->r), ATTRIBUTE(noshadow, color->g), color->b,
	 diffuse->r, diffuse->g, diffuse->b,
         specular->r, specular->g, specular->b, phong, factor,
         transp->r, transp->g, transp->b);
  current_surface = find_surface();
  if (current_surface == NOTFOUND)
  {
    CREATE(surfaces_max, surfaces, surface_list, buffer);
    current_surface = surfaces;
  }
}

void
create_surface2(color, smooth, metal, transp, emitter, noshadow)
  rgb_ptr         color, smooth, metal, transp;
  boolean         emitter, noshadow;
{
  DEFINE(buffer, "2 %g %g %g %g %g %g %g %g %g %g %g %g",
         ATTRIBUTE(emitter, color->r), ATTRIBUTE(noshadow, color->g), color->b,
	 smooth->r, smooth->g, smooth->b,
         metal->r, metal->g, metal->b, transp->r, transp->g, transp->b);
  current_surface = find_surface();
  if (current_surface == NOTFOUND)
  {
    CREATE(surfaces_max, surfaces, surface_list, buffer);
    current_surface = surfaces;
  }
}

void
create_text_surface1(color, diffuse, specular, phong, factor, transp,
		     emitter, noshadow)
  rgb_ptr         color, diffuse, specular;
  real            phong, factor;
  rgb_ptr         transp;
  boolean         emitter, noshadow;
{
  DEFINE(buffer, "1 %g %g %g %g %g %g %g %g %g %g %g %g %g %g",
         ATTRIBUTE(emitter, color->r), ATTRIBUTE(noshadow, color->g), color->b,
         diffuse->r, diffuse->g, diffuse->b,
         specular->r, specular->g, specular->b, phong, factor,
         transp->r, transp->g, transp->b);
  current_text_surface = find_surface();
  if (current_text_surface == NOTFOUND)
  {
    CREATE(surfaces_max, surfaces, surface_list, buffer);
    current_text_surface = surfaces;
  }
}

void
create_text_surface2(color, smooth, metal, transp, emitter, noshadow)
  rgb_ptr         color, smooth, metal, transp;
  boolean         emitter, noshadow;
{
  DEFINE(buffer, "2 %g %g %g %g %g %g %g %g %g %g %g %g",
         ATTRIBUTE(emitter, color->r), ATTRIBUTE(noshadow, color->g), color->b,
         smooth->r, smooth->g, smooth->b,
         metal->r, metal->g, metal->b, transp->r, transp->g, transp->b);
  current_text_surface = find_surface();
  if (current_text_surface == NOTFOUND)
  {
    CREATE(surfaces_max, surfaces, surface_list, buffer);
    current_text_surface = surfaces;
  }
}

void
create_surface_default()
{
  rgb_struct	  tc, td, ts, tt;

  tc.r = 0.9;
  tc.g = 0.9;
  tc.b = 0.9;
  td.r = 0.9;
  td.g = 0.9;
  td.b = 0.9;
  ts.r = 1.0 - td.r;
  ts.g = 1.0 - td.g;
  ts.b = 1.0 - td.b;
  tt.r = 0.0;
  tt.g = 0.0;
  tt.b = 0.0;
  create_surface1(&tc, &td, &ts, 4.0, 0.0, &tt, FALSE, FALSE);
}

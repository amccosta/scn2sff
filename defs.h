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
#include "config.h"
#include "alloc.h"

/**********************************************************************
 *    SCENE - Defs and Typedefs - Version 1.6.4                       *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, October 1993           *
 **********************************************************************/

#define STRING_MAX (8192)

#define CHAR_MAX (25)

#define ROUNDOFF ((real) 1.0e-12)
#define INFINITY ((real) 1.0e+50)

#ifndef PI
#ifdef M_PI
#define PI ((real) M_PI)
#else
#define PI ((real) 3.1415926535897932)
#endif
#endif

#define SCREEN_SIZE_X_MAX (2049)/* Screen width maximum + 1  */
#define SCREEN_SIZE_Y_MAX (2049)/* Screen height maximum + 1 */

#define X_MAX ((real) 100000.0)
#define X_MIN (-X_MAX)
#define Y_MAX (X_MAX)
#define Y_MIN (X_MIN)
#define Z_MAX (X_MAX)
#define Z_MIN (X_MIN)
#define W_MAX (X_MAX)
#define W_MIN (X_MIN)

#define LIGHTING_FACTOR_MAX   ((real) 300.0)
#define SPECULAR_FACTOR_MAX   ((real) 300.0)
#define REFRACTION_FACTOR_MAX ((real) 300.0)

#define OBJECTS_TEMP_MAX    (5000)

#define LIGHTS_MAX     (12)
#define OBJECTS_MAX    OBJECTS_TEMP_MAX
#define SURFACES_MAX   (512)
#define TEXTURES_MAX   (64)
#define TRANSFORMS_MAX (64)
#define LEVELS_MAX     (32)

#define SCALE_MIN ((real) 0.0)
#define SCALE_MAX ((real) MAXINT)

/***** Typedefs *****/
typedef
struct
{
  real            x, y, z;
} xyz_struct;
typedef
xyz_struct     *xyz_ptr;

typedef
struct
{
  real            r, g, b;
} rgb_struct;
typedef
rgb_struct     *rgb_ptr;

/***** Macros *****/
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DOT_PRODUCT(p0, p1)\
((p0).x * (p1).x + (p0).y * (p1).y + (p0).z * (p1).z)

#define LENGTH(p) (SQRT(DOT_PRODUCT(p, p)))
#define NORMALIZE(p)\
do {\
  REG real        d_TEMP;\
\
  d_TEMP = LENGTH(p);\
  if (d_TEMP < ROUNDOFF)\
    yyerror("cannot normalize a NULL VECTOR");\
  d_TEMP = 1.0 / d_TEMP;\
  (p).x *= d_TEMP;\
  (p).y *= d_TEMP;\
  (p).z *= d_TEMP;\
} while (0)

#define CROSS_PRODUCT(p, p0, p1)\
do {\
  (p).x = (p0).y * (p1).z - (p0).z * (p1).y;\
  (p).y = (p0).z * (p1).x - (p0).x * (p1).z;\
  (p).z = (p0).x * (p1).y - (p0).y * (p1).x;\
} while (0)

#define ALLOCATE(left, type, size)\
do {\
  (left) = (type) Alloc(size);\
  if ((left) == (type) NULL)\
    yyerror("cannot allocate MEMORY");\
} while (0)

#define DEFINE sprintf
#define APPEND sprintf

#define END(buffer) &(buffer)[strlen(buffer)]

#define CREATE(counter_max, counter, list, data)\
do {\
  int		  s_TMP;\
\
  s_TMP = strlen(data);\
  if (counter >= counter_max)\
    yyerror("maximum number of ENTITIES exceeded");\
  ALLOCATE(list[counter], char_ptr, s_TMP + 1);\
  strncpy(list[counter], data, s_TMP + 1);\
  ((char *) list[counter])[s_TMP] = '\0';\
  counter++;\
} while (0)

#define DEGREE_TO_RADIAN(angle) ((angle) / 180.0 * PI)

#define ABORT(message)\
{\
  fprintf(stderr, "Error: %s\n", message);\
  exit(1);\
}

#ifdef NO_ALLOCA
#define alloca Alloca
#endif

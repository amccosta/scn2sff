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

/**********************************************************************
 *    SCENE - Configuration - Version 1.6.4                           *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, October 1993           *
 **********************************************************************/

#define PROGRAM_VERSION "1.6.4"

#include <stdio.h>
#include <math.h>

/***** Constants *****/
#ifndef NULL
#define NULL (0)
#endif
#ifdef TRUE
#undef TRUE
#endif
#define TRUE (1)
#ifdef FALSE
#undef FALSE
#endif
#define FALSE (0)
#ifndef MAXINT
#define MAXINT (~(1 << (sizeof(int) * 8 - 1)))
#endif

/***** Types *****/
typedef
int             boolean;

typedef
double          real;

typedef
char           *char_ptr;

typedef
FILE           *file_ptr;

/***** Boolean operators *****/
#define NOT !
#define AND &&
#define OR  ||

#define BIT_NOT ~
#define BIT_AND &
#define BIT_OR  |
#define BIT_XOR ^

/***** Integer operators *****/
#define DIV /
#define MOD %

#define SHL <<
#define SHR >>

/***** Others *****/
#define PREINC(x) (++(x))
#define POSINC(x) ((x)++)
#define PREDEC(x) (--(x))
#define POSDEC(x) ((x)--)

#define SUCC(x) ((x) + 1)
#define PRED(x) ((x) - 1)
#define ODD(x)  ((x) & 1)

#define TRUNC(x) ((long int) floor((double) (x)))
#define ROUND(x) ((long int) floor((double) (x) + 0.5))

#define ABS(x)      ((real) fabs((double) (x)))
#define FRAC(x)     ((real) ((double) (x) - floor((double) (x))))
#define SIN(x)      ((real) sin((double) (x)))
#define COS(x)      ((real) cos((double) (x)))
#define SQR(x)      ((real) ((double) (x) * (double) (x)))
#define SQRT(x)     ((real) sqrt((double) (x)))
#define POWER(x, y) ((real) pow((double) (x), (double) (y)))
#define ARCCOS(x)   ((real) acos((double) (x)))

#define EXIT exit(0)
#define HALT exit(1)

/***** Compiler stuffs *****/
#ifdef vms
#include <string.h>
#include <stdlib.h>
#ifdef TIME
#undef TIME
#endif
#ifndef TIMES
#define TIMES
#endif
#define RANDOM_START srand(1)
#define RANDOM       ((real) rand() / (real) MAXINT)
#else

#ifdef _transputer
#include <string.h>
#ifdef TIMES
#undef TIMES
#endif
#ifndef TIME
#define TIME
#endif
#define RANDOM_START srand(1)
#define RANDOM       ((real) rand() / 32767.0)
#undef __DATE__
#undef __TIME__
#else

#ifdef dos
#include <stdlib.h>
#include <string.h>
#ifndef __HIGHC__
#ifndef __STDC__
#include <alloc.h>
#include <dos.h>
#endif
#endif
#ifdef TIMES
#undef TIMES
#endif
#ifndef TIME
#define TIME
#endif
#ifndef __HIGHC__
#ifdef MAIN_MODULE
extern unsigned int _stklen = 65000U;
#endif
#endif
#define RANDOM_START srand(1)
#define RANDOM       ((real) rand() / (real) MAXINT)
#else

#ifdef hpux
#include <memory.h>
#ifdef TIME
#undef TIME
#endif
#ifndef TIMES
#define TIMES
#endif
#define RANDOM_START srand(1)
#define RANDOM       ((real) rand() / 32767.0)
#else

#include <memory.h>
#ifdef TIME
#undef TIME
#endif
#ifndef TIMES
#define TIMES
#endif
#define RANDOM_START srandom(1)
#define RANDOM       ((real) random() / (real) MAXINT)
#endif
#endif
#endif
#endif

#ifndef __DATE__
#define __DATE__ "Oct 12 1993"
#endif
#ifndef __TIME__
#define __TIME__ "12:00:00"
#endif

/***** If there is no void type, define NOVOID *****/
#ifdef NOVOID
#define void char
#define void_ptr char_ptr
#else
typedef
void           *void_ptr;
#endif

/***** If there are no register variables, define NOREGISTERS *****/
#ifdef NOREGISTERS
#define REG
#undef NOREGISTERS
#else
#define REG register
#endif

/***** If there are function prototypes, define PROTOTYPES *****/
#ifndef PROTOTYPES
#if __STDC__
#ifndef NOVOID
#define PROTOTYPES
#endif
#endif
#endif

#ifdef NOVOID
#undef NOVOID
#endif

/***** If there is a function that gives time, define TIME or TIMES *****/
#ifndef TIME
#ifndef TIMES
#define CPU_CLOCK ((real) 0)
#endif
#endif
/* Using time() function */
#ifdef TIME
#include <time.h>
/* CPU_CLOCK must return time in milliseconds */
#define CPU_CLOCK ((real) ((double) time(0) * 1000.0))
#undef TIME
#endif
/* Using times() function */
#ifdef TIMES
#ifdef vms                      /* VAX-VMS */
#include <time.h>
#define tms_utime proc_user_time
#define tms_stime proc_system_time
#define tms tbuffer_t
#else
#include <sys/types.h>
#include <sys/times.h>
#ifndef CLK_TCK
#ifdef ultrix                   /* ULTRIX */
#define CLK_TCK (60)
#else                           /* Others */
#define CLK_TCK (100)
#endif
#endif
#endif
/* CPU_CLOCK must return time in milliseconds */
#define CPU_CLOCK cpu_clock()
static real
cpu_clock()
{
#ifdef vms
  tms             cpu_time;
#else
  struct tms      cpu_time;
#endif
  (void) times(&cpu_time);
  return (real) ((double) cpu_time.tms_utime * 1000.0 / (double) CLK_TCK);
}
#undef TIMES
#endif

/***** If cannot assign structs to structs, define NOSTRUCTASSIGN *****/
#ifdef NOSTRUCTASSIGN
#define STRUCT_ASSIGN(d, s)\
(void) memcpy((char_ptr) &(d), (char_ptr) &(s), sizeof(d))
#undef NOSTRUCTASSIGN
#else
#define STRUCT_ASSIGN(d, s) (d) = (s)
#endif

#define ARRAY_ASSIGN(d, s, c)\
(void) memcpy((char_ptr) (d), (char_ptr) (s), (c) * sizeof(d))

/***** Memory allocation *****/
#define ALLOC(p, s, c)\
(p) = (s *) Alloc((int) ((c) * sizeof(s)))

/* #define FREE(p) free((char_ptr) (p)) */
#define FREE(p)

/* #define ALLOC_INIT() */
#define ALLOC_INIT() (void) AllocInit()

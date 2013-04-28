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
#ifdef TURBOC
#define MAIN_MODULE
#endif
#include "extern.h"

/**********************************************************************
 *    SCENE - SFF output - Version 1.6.0                              *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, July 1993              *
 **********************************************************************/

static void
read_scene_file(name, preprocessor)
  char            name[];
  char            preprocessor[];
{
  char            command[STRING_MAX];
  char            message[STRING_MAX];

#ifndef dos
  if (preprocessor != NULL)
  {
    if (name == NULL)
    {
      sprintf(command, "%s 2>/dev/null", preprocessor);
      if ((yyin = popen(command, "r")) == NULL)
      {
        sprintf(message, "cannot use \"%s\"", preprocessor);
	ABORT(message);
      }
    } else
    {
      if ((yyin = fopen(name, "r")) == NULL)
      {
        sprintf(message, "cannot open \"%s\"", name);
	ABORT(message);
      }
      fclose(yyin);
      sprintf(command, "%s %s 2>/dev/null", preprocessor, name);
      if ((yyin = popen(command, "r")) == NULL)
      {
        sprintf(message, "cannot use \"%s\"", preprocessor);
	ABORT(message);
      }
    }
  } else
#endif
  {
    if (name == NULL) 
      yyin = stdin;
    else
    {
      if ((yyin = fopen(name, "r")) == NULL)
      {
        sprintf(message, "cannot open \"%s\"", name);
	ABORT(message);
      }
    }
  }
  if (yyparse())
    ABORT("invalid input specification");
#ifndef dos
  if (preprocessor != NULL)
    pclose(yyin);
#endif
  if (csg_level != -1)
    ABORT("incomplete CSG tree");
  /*****
  if (lights == 0)
    ABORT("no lights");
  *****/
  if (objects == 0)
    ABORT("no objects");
}

static void
defaults()
{
  from.x = 5.0;
  from.y = 0.0;
  from.z = 0.0;

  at.x = 0.0;
  at.y = 0.0;
  at.z = 0.0;

  up.x = 0.0;
  up.y = 1.0;
  up.z = 0.0;
 
  angle_h = 22.5;
  angle_v = 22.5;

  background.r = 0.2;
  background.g = 0.5;
  background.b = 0.7;

  ambient.r = 0.1;
  ambient.g = 0.1;
  ambient.b = 0.1;
}

static void
write_sff()
{
  int             i;

  printf("+L%d +S%d +O%d - view\n", lights, surfaces, objects);
  printf("%g %g %g\n", from.x, from.y, from.z);
  printf("%g %g %g\n", at.x, at.y, at.z);
  printf("%g %g %g\n", up.x, up.y, up.z);
  printf("%g %g\n", angle_h, angle_v);

  printf("colors\n");
  printf("%g %g %g\n", background.r, background.g, background.b);
  printf("%g %g %g\n", ambient.r, ambient.g, ambient.b);

  printf("lights\n");
  for (i = 0; i < lights; i++)
    printf("%s\n", light_list[i]);
  printf("\n");

  printf("surfaces\n");
  for (i = 0; i < surfaces; i++)
    printf("%s\n", surface_list[i]);
  printf("\n");

  printf("objects\n");
    write_objects();
  printf("\n");

  printf("end\n");
}

static void
credits()
{
  fprintf(stderr, "Copyright (c) 1990, 1993 Antonio Costa, INESC-Norte.\n");
  fprintf(stderr, "All rights reserved.\n");
  fprintf(stderr, "Version %s created on %s %s.\n",
          PROGRAM_VERSION, __DATE__, __TIME__);
}

/***** Main *****/
#define MIN_OPTIONS 1

#ifndef dos
#define M4_PREPROCESSOR  "/usr/bin/m4"
#ifdef hpux
#define CPP_PREPROCESSOR "/lib/cpp -P"
#else
#define CPP_PREPROCESSOR "/usr/lib/cpp -P"
#endif
#endif

main(argc, argv)
  int             argc;
  char_ptr        argv[];
{
  int             options, option_index;
  char_ptr       *option, preprocessor;
  char            message[STRING_MAX], letter;
  real            start_time;
  double          value;

  options = argc - 1;
  preprocessor = NULL;
  if (options < MIN_OPTIONS)
  {
    credits();
    ABORT("too few PARAMETERS");
  }
  option = &(argv[1]);
  ALLOC_INIT();
  objects_max = OBJECTS_MAX;
  lights_max = LIGHTS_MAX;
  surfaces_max = SURFACES_MAX;
  textures_max = TEXTURES_MAX;
  transforms_max = TRANSFORMS_MAX;
  for (option_index = 0; option_index < options - MIN_OPTIONS; option_index++)
  {
    switch (option[option_index][0])
    {
#ifndef dos
    case 'C':
      if (preprocessor != NULL)
        ABORT("PREPROCESSOR already set");
      if (option[option_index][1] == NULL)
      {
        ALLOCATE(preprocessor, char_ptr, strlen(CPP_PREPROCESSOR));
        strcpy(preprocessor, CPP_PREPROCESSOR);
      } else
	ABORT("bad [C] OPTION");
      break;

    case 'M':
      if (preprocessor != NULL)
        ABORT("PREPROCESSOR already set");
      if (option[option_index][1] == NULL)
      {
        ALLOCATE(preprocessor, char_ptr, strlen(M4_PREPROCESSOR));
        strcpy(preprocessor, M4_PREPROCESSOR);
      } else
	ABORT("bad [M] OPTION");
      break;

    case 'P':
      if (preprocessor != NULL)
        ABORT("PREPROCESSOR already set");
      if (option[option_index][1] == NULL)
      {
        ALLOCATE(preprocessor, char_ptr, strlen(CPP_PREPROCESSOR));
        strcpy(preprocessor, CPP_PREPROCESSOR);
      } else
        preprocessor = &(option[option_index][1]);
      break;
#endif

    case '+':
      letter = option[option_index][1];
      if (letter != 'O' AND letter != 'L' AND letter != 'S'
	  AND letter != 'T' AND letter != 'M')
      {
        sprintf(message, "bad option [+%c]", option[option_index][1]);
        ABORT(message);
      }
      if (sscanf(&(option[option_index][2]), "%lf", &value) != 1 OR
          value < 1.0)
        ABORT("VALUE too low");
      switch (letter)
      {
      case 'O':
        objects_max = ROUND(value);
        if (objects_max < 16 OR objects_max > OBJECTS_TEMP_MAX)
          objects_max = 0;
        break;
      case 'L':
        lights_max = ROUND(value);
        break;
      case 'S':
        surfaces_max = ROUND(value);
        break;
      case 'T':
        textures_max = ROUND(value);
        break;
      case 'M':
        transforms_max = ROUND(value);
        break;
      }
      break;

    default:
      sprintf(message, "bad option [%c]", option[option_index][0]);
      ABORT(message);
      break;
    }
  }

  if (objects_max > 0)
    ALLOCATE(object_list, char_ptr *, objects_max * sizeof(char_ptr));
  ALLOCATE(light_list, char_ptr *, lights_max * sizeof(char_ptr));

  ALLOCATE(surface_list, char_ptr *, surfaces_max * sizeof(char_ptr));
  ALLOCATE(texture_list, char_ptr *, textures_max * sizeof(char_ptr));
  ALLOCATE(transform_list, char_ptr *, transforms_max * sizeof(char_ptr));
  defaults();
  start_time = CPU_CLOCK;
  if (NOT strcmp(option[option_index], "-"))
    read_scene_file(NULL, preprocessor);
  else
    read_scene_file(option[option_index], preprocessor);
  write_sff();
  fprintf(stderr, "%d light(s)\n", lights);
  fprintf(stderr, "%d surface(s)\n", surfaces);
  fprintf(stderr, "%d object(s)\n", objects);
  fprintf(stderr, "Info: translating - %g second(s) CPU time\n",
        (CPU_CLOCK - start_time) / 1000.0);
  if (objects_max > 0)
    FREE(object_list);
  FREE(light_list);
  FREE(surface_list);
  FREE(texture_list);
  FREE(transform_list);
  exit(0);
}

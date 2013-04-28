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
#include "defs.h"

/**********************************************************************
 *    SCENE - External declarations - Version 1.6.2                   *
 *                                                                    *
 *    MADE BY    : Antonio Costa, INESC-Norte, November 1991          *
 *    MODIFIED BY: Antonio Costa, INESC-Norte, September 1993         *
 **********************************************************************/

extern FILE    *yyin;
extern int      yylinecount;
extern int      yyerror();
extern int      yyparse();

/***** Others *****/
extern boolean  from_defined;
extern boolean  at_defined;
extern boolean  up_defined;
extern boolean  angle_defined;
extern boolean  ambient_defined;
extern boolean  background_defined;

extern xyz_struct from, at, up;
extern real     angle_h, angle_v;
extern rgb_struct background, ambient;

extern int      lights;
extern int      surfaces;
extern int      objects;
extern int      transforms;
extern int      textures;
extern int      csg_level;
extern int      list_level;

extern int      objects_max, lights_max, surfaces_max;
extern int      textures_max, transforms_max;

extern int      current_surface;
extern int      current_text_surface;

extern real     current_refraction;

extern char     buffer[STRING_MAX];

extern char_ptr *light_list;
extern char_ptr *surface_list;
extern char_ptr *object_list;
extern char_ptr *texture_list;
extern char_ptr *transform_list;

extern int      level_scene;
extern char     level_type[LEVELS_MAX];
extern int      level_textures[LEVELS_MAX];
extern int      level_transforms[LEVELS_MAX];
extern int      level_current_surface[LEVELS_MAX];
extern int      level_current_text_surface[LEVELS_MAX];
extern real     level_current_refraction[LEVELS_MAX];

extern FILE    *temp_file;

/***** Functions *****/
boolean         find_color_by_name();
void            create_point_light();
void            create_dir_light();
void            create_spot_light();
void            create_ext_light();
void            create_linear_light();
void            create_planar_light();
void            create_sphere();
void            create_box();
void            create_open_cone();
void            create_disc();
void            create_ring();
void            create_cone();
void            create_open_cylinder();
void            create_cylinder();
void            create_open_truncated_cone();
void            create_truncated_cone();
void            create_patch();
void            create_patch_file();
void            create_polygon();
void            create_polygon_file();
void            create_triangle_normal();
void            create_triangle_general();
void            create_triangle_normal_file();
void            create_wedge();
void            create_tetra();
void            create_triangle();
void            create_quadrangle();
void            create_open_truncated_pyramid();
void            create_open_prism();
void            create_prism();
void            create_open_pyramid();
void            create_pyramid();
void            create_open_torus();
void            create_torus();
void            create_csg_begin();
void            create_csg_next();
void            create_csg_end();
void            create_list_begin();
void            create_list_end();
void            create_surface_default();
void            create_text_transf_scale();
void            create_text_transf_translate();
void            create_text_transf_rotatex();
void            create_text_transf_rotatey();
void            create_text_transf_rotatez();
void            create_text_transf_rotate();
void            create_text_transf_general();
void            create_text_transf_local();
void            create_text_transf_default();
void            define_text_transform();
void            remove_text_level();
void            create_text_null();
void            create_text_checkers();
void            create_text_blotch();
void            create_text_bump();
void            create_text_marble();
void            create_text_fbm();
void            create_text_fbmbump();
void            create_text_wood();
void            create_text_round();
void            create_text_bozo();
void            create_text_ripples();
void            create_text_waves();
void            create_text_spotted();
void            create_text_dents();
void            create_text_agate();
void            create_text_wrinkles();
void            create_text_granite();
void            create_text_gradient();
void            create_text_imagemap();
void            create_text_gloss();
void            create_text_bump3();
void            remove_transf_level();
void            create_transf_scale();
void            create_transf_translate();
void            create_transf_rotatex();
void            create_transf_rotatey();
void            create_transf_rotatez();
void            create_transf_rotate();
void            create_transf_general();
void            save_level();
void            restore_level();
void            write_objects();
void            remove_temp_file();

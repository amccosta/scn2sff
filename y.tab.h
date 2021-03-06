typedef union {
	int			int_type;
	real			real_type;
	xyz_struct		xyz_type;
	rgb_struct		rgb_type;
	char_ptr		char_ptr_type;
	char			char_type[CHAR_MAX];
} YYSTYPE;
#define	NUM	258
#define	NUMINT	259
#define	TOKEN	260
#define	FILETOKEN	261
#define	FROM	262
#define	AT	263
#define	UP	264
#define	ANGLE	265
#define	BACKGROUND	266
#define	AMBIENT	267
#define	REFRACTION	268
#define	LIGHT	269
#define	POINTLIGHT	270
#define	DIRLIGHT	271
#define	SPOTLIGHT	272
#define	EXTLIGHT	273
#define	LINEARLIGHT	274
#define	PLANARLIGHT	275
#define	SURFACE	276
#define	STRAUSS	277
#define	MONO	278
#define	MATTE	279
#define	PLASTIC	280
#define	METAL	281
#define	DIELECTRIC	282
#define	GLASS	283
#define	EMITTER	284
#define	NOSHADOW	285
#define	OPEN	286
#define	TRUNCATED	287
#define	FILENAME	288
#define	NORMAL	289
#define	DATA	290
#define	BEGINGROUP	291
#define	ENDGROUP	292
#define	NEXT	293
#define	SPHERE	294
#define	BOX	295
#define	CUBE	296
#define	CONE	297
#define	CYLINDER	298
#define	WEDGE	299
#define	TETRA	300
#define	PRISM	301
#define	PYRAMID	302
#define	DISC	303
#define	RING	304
#define	PATCH	305
#define	POLYGON	306
#define	TRIANGLE	307
#define	QUADRANGLE	308
#define	TORUS	309
#define	HEMISPHERE	310
#define	TEXT3D	311
#define	CSG	312
#define	LIST	313
#define	TRANSFORM	314
#define	NONE	315
#define	SCALE	316
#define	TRANSLATE	317
#define	ROTATE	318
#define	GENERAL	319
#define	NULLTEXTURE	320
#define	LOCALTEXTURE	321
#define	CHECKERSTEXTURE	322
#define	BLOTCHTEXTURE	323
#define	BUMPTEXTURE	324
#define	MARBLETEXTURE	325
#define	FBMTEXTURE	326
#define	FBMBUMPTEXTURE	327
#define	WOODTEXTURE	328
#define	ROUNDTEXTURE	329
#define	BOZOTEXTURE	330
#define	RIPPLESTEXTURE	331
#define	WAVESTEXTURE	332
#define	SPOTTEDTEXTURE	333
#define	DENTSTEXTURE	334
#define	AGATETEXTURE	335
#define	WRINKLESTEXTURE	336
#define	GRANITETEXTURE	337
#define	GRADIENTTEXTURE	338
#define	IMAGEMAPTEXTURE	339
#define	GLOSSTEXTURE	340
#define	BUMP3TEXTURE	341
#define	SINFUNCTION	342
#define	COSFUNCTION	343
#define	TANFUNCTION	344
#define	ASINFUNCTION	345
#define	ACOSFUNCTION	346
#define	ATANFUNCTION	347
#define	SQRTFUNCTION	348
#define	INTFUNCTION	349
#define	RTODFUNCTION	350
#define	DTORFUNCTION	351
#define	EXPFUNCTION	352
#define	LOGFUNCTION	353
#define	ABSFUNCTION	354
#define	MAXFUNCTION	355
#define	MINFUNCTION	356
#define	DOT3FUNCTION	357
#define	ADD3FUNCTION	358
#define	DIFF3FUNCTION	359
#define	SCALE3FUNCTION	360
#define	CROSS3FUNCTION	361
#define	NORM3FUNCTION	362
#define	CSGUNION	363
#define	CSGSUBTRACTION	364
#define	CSGINTERSECTION	365
#define	UMINUS	366


extern YYSTYPE yylval;

/* alloc.h
 *
 * Header for alloc.c
 *
 * The type alloc_handle_t provides an opaque reference to the
 * alloc pool - only the alloc routines know its structure.
 */

typedef
struct { int dummy; }
alloc_handle_t;

extern alloc_handle_t *AllocInit();
extern char           *Alloc();
extern alloc_handle_t *AllocSetPool();
extern void           AllocReset();
extern void           AllocFreePool();

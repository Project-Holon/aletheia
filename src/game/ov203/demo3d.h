#ifndef GAME_OV203_DEMO3D_H
#define GAME_OV203_DEMO3D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d.c, prototypes copied from their definitions. */

struct Demo3dArg;
struct Demo3dWork;
struct Demo3dContext;
typedef struct Demo3dArg Demo3dArg;
typedef struct Demo3dWork Demo3dWork;
typedef struct Demo3dContext Demo3dContext;

#include "../types.h"

int DEMO3D_Init(void *manager, int unused, Demo3dArg *p);
int DEMO3D_Exit(void *a, void *b, void *c, Demo3dWork *work);
int DEMO3D_Main(void *unused, int *state, void *c, Demo3dWork *work);
int DEMO3D_StartWipe(u32 id, unsigned mode, unsigned heap);
int DEMO3D_CheckSkip(Demo3dWork *p);
Demo3dContext *DEMO3D_CreateContext(int mode, void *a, void *b, unsigned heap);
void DEMO3D_DeleteContext(Demo3dContext *a);
void DEMO3D_UpdateContext(Demo3dContext *a);
void DEMO3D_SetupGx(void);
/* END mkheaders: generated region */

#endif

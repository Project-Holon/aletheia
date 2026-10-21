#ifndef GAME_OV215_EGG_DEMO_GRAPHIC_H
#define GAME_OV215_EGG_DEMO_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of egg_demo_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

char *EGG_DEMO_GRAPHIC_Create(unsigned mode,u16 heapId);
void EGG_DEMO_GRAPHIC_Delete(char *work);
void EGG_DEMO_GRAPHIC_Draw(char *work);
void EGG_DEMO_GRAPHIC_Draw3d(char *work);
void EGG_DEMO_GRAPHIC_DrawEnd(char *work);
struct Bank *EGG_DEMO_GRAPHIC_GetClactBank2(char *work);
void EGG_DEMO_GRAPHIC_VBlank(int unused, char *work);
void EGG_DEMO_GRAPHIC_InitBg(void *bgWork,u16 heapId);
void EGG_DEMO_GRAPHIC_DeleteBg(void *bgWork);
void EGG_DEMO_GRAPHIC_Noop(void *unused);
void EGG_DEMO_GRAPHIC_TickDisplay(void *unused);
void EGG_DEMO_GRAPHIC_InitClact(unsigned char *clact, struct DispVramCfg *resource, u32 heapId);
void EGG_DEMO_GRAPHIC_DeleteClact(char *clact);
void EGG_DEMO_GRAPHIC_DrawClact(void *unused);
void EGG_DEMO_GRAPHIC_VBlankClact(void *unused);
struct Bank *EGG_DEMO_GRAPHIC_GetClactBank(void *clact);
void EGG_DEMO_GRAPHIC_InitG3d(void **g3d,u16 heapId);
void EGG_DEMO_GRAPHIC_DeleteG3d(int *g3d);
void EGG_DEMO_GRAPHIC_DrawG3d(void *g3d);
void EGG_DEMO_GRAPHIC_DrawG3dEnd(void *unused);
/* END mkheaders: generated region */

#endif

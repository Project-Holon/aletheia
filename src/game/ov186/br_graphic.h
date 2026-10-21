#ifndef GAME_OV186_BR_GRAPHIC_H
#define GAME_OV186_BR_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_graphic.c, prototypes copied from their definitions. */

struct BrGraphic;
struct TcbTask;
struct BrActorSys;

#include "../types.h"

void *BR_GRAPHIC_Create(unsigned mode,int vramSetting,u16 heapId);
void BR_GRAPHIC_Destroy(struct BrGraphic *gfx);
void BR_GRAPHIC_Draw(struct BrGraphic *gfx);
u32 BR_GRAPHIC_GetActorUnit(struct BrGraphic *gfx);
void BR_GRAPHIC_VBlankTask(struct TcbTask *taskId, void *gfxArg);
void BR_GRAPHIC_InitBgWindows(void *bgState,u16 heapId);
void BR_GRAPHIC_ExitBgWindows(void *bgState);
void BR_GRAPHIC_DrawBg(void *bgState);
void BR_GRAPHIC_VBlankBg(void *bgState);
void BR_GRAPHIC_InitActors(int *actorSys, int vramConfig, int heapId);
void BR_GRAPHIC_ExitActors(struct BrActorSys *actorSys);
void BR_GRAPHIC_DrawActors(void *actorSys);
void BR_GRAPHIC_VBlankActors(void *actorSys);
u32 BR_GRAPHIC_GetUnitFromActorSys(u32 *actorSys);
void BR_GRAPHIC_Begin3d(void *graphicHandle, u16 unusedB);
void BR_GRAPHIC_End3d(void *graphicHandle, u16 heap);
/* END mkheaders: generated region */

#endif

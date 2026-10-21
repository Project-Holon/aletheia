#ifndef GAME_OV135_WORLDTRADE_SUBLCD_H
#define GAME_OV135_WORLDTRADE_SUBLCD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_sublcd.c, prototypes copied from their definitions. */

struct ClactActor;

#include "../ov135/worldtrade_types.h"
#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"
#include "../arm9/mcss_types.h"

void WORLDTRADE_SUBLCD_CreateActors(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_StartAnimTaskA(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_SetActorAnim(u32 *p, u32 animSeq);
void WORLDTRADE_SUBLCD_StartAnimTaskB(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_SetActorSurfacePos(struct ClactActor *obj, int x, int y);
int WORLDTRADE_SUBLCD_CheckButtonTouch(int count);
void WORLDTRADE_SUBLCD_UpdateSlotPalettes(WorldtradeWork *p, int count, int flag);
int WORLDTRADE_SUBLCD_GetSlotAnimBase(int slot);
void WORLDTRADE_SUBLCD_UpdateSlotAnims(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_LoadPalette(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_LoadSlotPalette(NNSG2dCharacterData **chr, McssPlttData *plttData, int slot, int iconIndex, int unused4);
void WORLDTRADE_SUBLCD_FreeResources(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_MoveArrowToSlot(WorldtradeWork *p, int slot, int dy);
void WORLDTRADE_SUBLCD_SetSlotActorPositions(WorldtradeWork *p);
void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif

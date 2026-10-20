#ifndef GAME_OV112_STA_ACT_LIGHT_H
#define GAME_OV112_STA_ACT_LIGHT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_light.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/sta_act_types.h"
#include "../ov112/sta_act_light_shared_types.h"

void STA_ACT_LIGHT_SetElemVisible(char *p,u32 *q,u32 flag);
StaActLightObject *STA_ACT_LIGHT_CreateUnit(u16 heap,void *a);
void STA_ACT_LIGHT_DeleteUnit(char *p);
void STA_ACT_LIGHT_UpdateElemActors(char *p);
void STA_ACT_LIGHT_PlaceActor(char *p, char *q);
void STA_ACT_LIGHT_UpdateActor(char *p);
void STA_ACT_LIGHT_NoOp(void *unit);
u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);
void STA_ACT_LIGHT_DeleteActor(void *unused,u8 *p);
void STA_ACT_LIGHT_CopyElemA(void *unused,u32 *p,const u32 *q);
void STA_ACT_LIGHT_GetElemPos(void *ctx,char *p,StaActLightVec3 *out);
void STA_ACT_LIGHT_SetElemA(void *a,char *p,u16 b,u8 c);
void STA_ACT_LIGHT_SetElemB(void *a,char *p,u32 b,u32 c);
/* END mkheaders: generated region */

#endif

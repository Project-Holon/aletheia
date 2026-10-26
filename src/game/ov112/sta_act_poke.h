#ifndef GAME_OV112_STA_ACT_POKE_H
#define GAME_OV112_STA_ACT_POKE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_poke.c, prototypes copied from their definitions. */

#include "../ov112/sta_act_types.h"
#include "../types.h"

StaActBillboardImage *STA_ACT_LIGHT_AddBillboardImage(u16 heap, void *b, void *c, void *d, void *e);
void STA_ACT_LIGHT_DeleteBillboardImage(StaActBillboardImage *p);
void STA_ACT_LIGHT_UpdateBillboard(StaActBillboardImage *p);
void STA_ACT_LIGHT_UpdateSprite(StaActBillboardImage *p);
void STA_ACT_LIGHT_CalcSpriteXform(StaActBillboardImage *p,StaActPokeElem *elem);
void STA_ACT_LIGHT_SetSpritePos(StaActBillboardImage *self, StaActPokeElem *q);
void STA_ACT_LIGHT_UpdateElem(StaActBillboardImage *p);
void STA_ACT_LIGHT_CopyElemB(StaActBillboardImage *unused, StaActPokeElem *elem);
void STA_ACT_LIGHT_SetElemFrame(StaActBillboardImage *p, u16 v);
StaActPokeElem *STA_ACT_LIGHT_AddPokemonElem(StaActBillboardImage *image,u8 *input);
void STA_ACT_LIGHT_FreeElem(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_SetupElem(StaActBillboardImage *unused, StaActPokeElem *elem, u32 v);
void STA_ACT_LIGHT_HandleElemAnim(StaActBillboardImage *image,StaActPokeElem *elem,int index);
int STA_ACT_LIGHT_IsElemActive(StaActBillboardImage *p,StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimNone(StaActBillboardImage *p,StaActPokeElem *q);
void STA_ACT_LIGHT_StopSe(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimA(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimB(StaActBillboardImage *image,StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimC(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimD(StaActBillboardImage *p,StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimE(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimF(StaActBillboardImage *image,StaActPokeElem *elem);
void STA_ACT_LIGHT_AnimG(StaActBillboardImage *unused0, StaActPokeElem *unused1);
void STA_ACT_LIGHT_AnimH(StaActBillboardImage *image, StaActPokeElem *elem);
void STA_ACT_LIGHT_CopyActorPos(void *unused,StaActPokeElem *p,u32 *q);
void STA_ACT_LIGHT_SetActorPos(void *unused,StaActPokeElem *p,const u32 *q);
void STA_ACT_LIGHT_SetActorAngle(int self, StaActPokeElem *elem, u16 v);
void STA_ACT_LIGHT_SetActorOffset(void *unused,StaActPokeElem *p,const u32 *q);
void STA_ACT_LIGHT_StartRenderAnim(int unused,StaActPokeElem *elem);
void STA_ACT_LIGHT_ResetRenderAnim(void *unused, StaActPokeElem *elem);
void STA_ACT_LIGHT_SetRenderAnim(int unused, StaActPokeElem *elem, unsigned int anim);
void STA_ACT_LIGHT_SetSlotVisible(StaActBillboardImage *p, StaActPokeElem *q, int v);
int STA_ACT_LIGHT_IsRenderVisible(StaActBillboardImage *a,StaActPokeElem *elem);
int STA_ACT_LIGHT_SetActorFlagB(int unused, StaActPokeElem *p, int flag);
void STA_ACT_LIGHT_SetActorVisible(int unused,StaActPokeElem *elem,int visible);
int STA_ACT_LIGHT_SetElemValue(void *unused, StaActPokeElem *elem, int value);
/* END mkheaders: generated region */

#endif

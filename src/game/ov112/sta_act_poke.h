#ifndef GAME_OV112_STA_ACT_POKE_H
#define GAME_OV112_STA_ACT_POKE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_poke.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/sta_act_types.h"

u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);
void STA_ACT_LIGHT_DeleteBillboardImage(char *p);
void STA_ACT_LIGHT_UpdateBillboard(u8 *p);
void STA_ACT_LIGHT_UpdateSprite(char *p);
void STA_ACT_LIGHT_CalcSpriteXform(u8 *p,u8 *elem);
void STA_ACT_LIGHT_SetSpritePos(u8 *self, u8 *q);
void STA_ACT_LIGHT_UpdateElem(u8 *p);
void STA_ACT_LIGHT_CopyElemB(u8 *unused, u8 *elem);
void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);
u8 *STA_ACT_LIGHT_AddPokemonElem(u8 *image,u8 *input);
void STA_ACT_LIGHT_FreeElem(char *image, char *elem);
void STA_ACT_LIGHT_SetupElem(u32 unused, u8 *elem, u32 v);
void STA_ACT_LIGHT_HandleElemAnim(char *image,char *elem,int index);
int STA_ACT_LIGHT_IsElemActive(char *p,char *elem);
void STA_ACT_LIGHT_AnimNone(char *p,char *q);
void STA_ACT_LIGHT_StopSe(char *image, char *elem);
void STA_ACT_LIGHT_AnimA(char *image, char *elem);
void STA_ACT_LIGHT_AnimB(u8 *image,u8 *elem);
void STA_ACT_LIGHT_AnimC(char *image, char *elem);
void STA_ACT_LIGHT_AnimD(u8 *p,u8 *elem);
void STA_ACT_LIGHT_AnimE(char *image, char *elem);
void STA_ACT_LIGHT_AnimF(char *image,char *elem);
void STA_ACT_LIGHT_AnimG(char *unused0, char *unused1);
void STA_ACT_LIGHT_AnimH(char *image, char *elem);
void STA_ACT_LIGHT_CopyActorPos(void *unused,u32 *p,u32 *q);
void STA_ACT_LIGHT_SetActorPos(void *unused,u32 *p,const u32 *q);
void STA_ACT_LIGHT_SetActorAngle(int self, char *elem, u16 v);
void STA_ACT_LIGHT_SetActorOffset(void *unused,u32 *p,const u32 *q);
void STA_ACT_LIGHT_StartRenderAnim(int unused,u8 *elem);
void STA_ACT_LIGHT_ResetRenderAnim(void *unused, StaActPokeElem *elem);
void STA_ACT_LIGHT_SetRenderAnim(int unused, StaActPokeElem *elem, unsigned int anim);
void STA_ACT_LIGHT_SetSlotVisible(StaActBillboardImage *p, StaActPokeElem *q, int v);
int STA_ACT_LIGHT_IsRenderVisible(int a,u8 *elem);
int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);
void STA_ACT_LIGHT_SetActorVisible(int unused,u8 *elem,int visible);
int STA_ACT_LIGHT_SetElemValue(void *unused, int *elem, int value);
/* END mkheaders: generated region */

#endif

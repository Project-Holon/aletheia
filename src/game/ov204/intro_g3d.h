#ifndef GAME_OV204_INTRO_G3D_H
#define GAME_OV204_INTRO_G3D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intro_g3d.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov204/intro_types.h"

void INTRO_G3D_AddPokemonSlot(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index);
void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v);
unsigned int INTRO_G3D_GetSlotAnimFinished(char *p, u8 i);
void INTRO_G3D_ClearSlotAnimFinished(u8 *p, u8 index);
void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha);
void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag);
void INTRO_G3D_OnAnimEnd(IntroMcssSlot *slot);
int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit);
int INTRO_G3D_MoveSlot1(char *p,int delta,int limit);
void INTRO_G3D_UpdateIdleAnim(char *p);
char *INTRO_G3D_Create(void *owner,int kind,u32 heap);
void INTRO_G3D_Delete(char *p);
void INTRO_G3D_Draw(char *p);
int INTRO_G3D_UpdateIntro(char *p);
void INTRO_G3D_SetVisible(char *p, int v);
void INTRO_G3D_SetAnimMode(char *p, unsigned int v);
int INTRO_G3D_UpdateAnimMode(char *p);
int INTRO_G3D_UpdateAnimFrame(int *p);
void INTRO_G3D_SetAnimFrame(char *p,unsigned value);
/* END mkheaders: generated region */

#endif

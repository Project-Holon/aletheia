#ifndef GAME_ARM9_GX_VRAMCNT_H
#define GAME_ARM9_GX_VRAMCNT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gx_vramcnt.c, prototypes copied from their definitions. */

#include "../types.h"

void GX_SetBankForBG(GXVRamBG bg);
void GX_SetBankForOBJ(GXVRamOBJ obj);
void GX_SetBankForBGExtPltt(int bgExtPltt);
void GX_SetBankForOBJExtPltt(int objExtPltt);
void GX_SetBankForTex(GXVRamTex tex);
void GX_SetBankForTexPltt(int texPltt);
void GX_SetBankForClearImage(int clrImg);
void GX_SetBankForARM7(int arm7);
void GX_SetBankForLCDC(int lcdc);
void GX_SetBankForSubBG(int sub_bg);
void GX_SetBankForSubOBJ(int sub_obj);
void GX_SetBankForSubBGExtPltt(int sub_bgExtPltt);
void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt);
int resetBankForX_(u16 *g3bit);
int GX_ResetBankForBG(void);
int GX_ResetBankForOBJ(void);
int GX_ResetBankForBGExtPltt(void);
int GX_ResetBankForOBJExtPltt(void);
int GX_ResetBankForTex(void);
int GX_ResetBankForTexPltt(void);
int GX_ResetBankForClearImage(void);
int GX_ResetBankForSubBG(void);
int GX_ResetBankForSubOBJ(void);
int GX_ResetBankForSubBGExtPltt(void);
int GX_ResetBankForSubOBJExtPltt(void);
int disableBankForX_(u16 *g3bit);
GXVRam GX_DisableBankForBG(void);
GXVRam GX_DisableBankForOBJ(void);
GXVRam GX_DisableBankForBGExtPltt(void);
GXVRam GX_DisableBankForOBJExtPltt(void);
GXVRam GX_DisableBankForTex(void);
GXVRam GX_DisableBankForTexPltt(void);
GXVRam GX_DisableBankForClearImage(void);
GXVRam GX_DisableBankForARM7(void);
void GX_DisableBankForLCDC(void);
void GX_DisableBankForSubBG(void);
void GX_DisableBankForSubOBJ(void);
GXVRam GX_DisableBankForSubBGExtPltt(void);
GXVRam GX_DisableBankForSubOBJExtPltt(void);
u16 GX_GetBankForOBJ(void);
u16 GX_GetBankForOBJExtPltt(void);
u16 GX_GetBankForTex(void);
u16 GX_GetBankForLCDC(void);
u16 GX_GetBankForSubOBJ(void);
u16 GX_GetBankForSubOBJExtPltt(void);
/* END mkheaders: generated region */

#endif

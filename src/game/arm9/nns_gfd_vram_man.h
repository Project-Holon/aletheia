#ifndef GAME_ARM9_NNS_GFD_VRAM_MAN_H
#define GAME_ARM9_NNS_GFD_VRAM_MAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_gfd_vram_man.c, prototypes copied from their definitions. */

struct Arena02146B74;

#include "../types.h"

u32 NNS_GfdAllocVram(u32 size, u32 flag, u32 dir);
void NNSi_GfdGetVramManagerWork(struct Arena02146B74 *dst);
void NNSi_GfdSetVramManagerWork(void *pWork);
u32 NNSi_GfdRingNextIndex(u8 *p, u32 v);
int NNSi_GfdRingIsFull(u8 *p);
int NNSi_GfdRingIsEmpty(void *p);
void NNS_GfdFuncLoadTex(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadTexPltt(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadClearImageColor(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadClearImageDepth(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG0Char(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG1Char(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2Char(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3Char(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG0Scr(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG1Scr(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2Scr(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3Scr(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG2ScrDup(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBG3ScrDup(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadOBJPltt(void *a, u32 b, u32 c);
void NNS_GfdFuncLoadBGPltt(void *a, u32 b, u32 c);
/* END mkheaders: generated region */

#endif

/*
 * function: DENDOU_VIEW_IsPaletteFadeBusy
 * address: 0x021DCBE8
 * packet: pkt_ov171_021DCBE8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 */
#include "../include/Obj14284.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PALANM_GetFadeRequestBits(const char*);
struct Obj02021EE4;
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
int DENDOU_VIEW_IsPaletteFadeBusy(u8*p){if(PALANM_GetFadeRequestBits(*(char* *)&((struct Obj14284 *)p)->fB30))return 1;PALANM_SetAutoTransfer((struct Obj02021EE4 *)(*(u32 *)&((struct Obj14284 *)p)->fB30),0);return 0;}

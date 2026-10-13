/*
 * function: PMSIV_CATEGORY_StartFadeIn
 * address: 0x021BB76C
 * packet: pkt_ov110_021BB76C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 */
#include "../include/Obj22365.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMSIV_FADE_StartBrightness(u8 *,int,int,int,int);
void PMSIV_CATEGORY_StartFadeIn(u8 *p) { ((struct Obj22365 *)p)->f10=0; PMSIV_FADE_StartBrightness(p+24,2,-10,0,16); }

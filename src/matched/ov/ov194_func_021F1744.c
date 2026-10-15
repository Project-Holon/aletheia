/*
 * function: NAMEIN_GRAPHIC_Main
 * address: 0x021F1744
 * packet: pkt_ov194_021F1744
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NAMEIN_GRAPHIC_RunCallback 0x021F4614 thumb ov194
 *   NAMEIN_GRAPHIC_DrawDisplay 0x021F4BD8 thumb ov194
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   NAMEIN_GRAPHIC_FlushIconOam 0x021F436C thumb ov194
 *   NAMEIN_GRAPHIC_GetCallbackState 0x021F4628 thumb ov194
 */
#include "../include/Obj14494.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern void NAMEIN_GRAPHIC_RunCallback(u8 *);
extern void NAMEIN_GRAPHIC_DrawDisplay(u8 *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void NAMEIN_GRAPHIC_FlushIconOam(u8 *);
extern unsigned NAMEIN_GRAPHIC_GetCallbackState(unsigned char *p);
int NAMEIN_GRAPHIC_Main(int a,int b,int c,u8 *p) { NAMEIN_GRAPHIC_RunCallback(p+0x2a0);NAMEIN_GRAPHIC_DrawDisplay(*(u8 * *)&((struct Obj14494 *)p)->f0);PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj14494 *)p)->f2B4));NAMEIN_GRAPHIC_FlushIconOam(p+0x264);if(NAMEIN_GRAPHIC_GetCallbackState(p+0x2a0))return 1;return 0; }

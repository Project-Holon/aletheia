/*
 * function: BOX2_SEQ_LoadIconPalette
 * address: 0x021ED058
 * packet: pkt_ov170_021ED058
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02214.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern unsigned func_02020E60(unsigned,unsigned);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern void ARC_TOOL_DeleteHandle(void*);
void BOX2_SEQ_LoadIconPalette(u8*p){void*h;h=func_020490F4(25,76);*(void* *)&((struct Obj02214 *)p)->fA114=(void *)CLACT_RegisterPalette(h,func_02020E60(0,2),0,0x180,76);ARC_TOOL_DeleteHandle(h);}

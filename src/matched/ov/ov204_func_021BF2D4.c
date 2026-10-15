/*
 * function: func_021BF2D4
 * address: 0x021BF2D4
 * packet: pkt_ov204_021BF2D4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj25385.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BMP_MENUWORK_DrawWindowBorder(void*,u32);
void func_021BF2D4(u8*p){BMP_MENUWORK_DrawWindowBorder(*(void* *)&((struct Obj25385 *)p)->f1C,0);}

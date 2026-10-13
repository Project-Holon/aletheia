/*
 * function: PMS_SELECT_GRAPHIC_UpdateDraw
 * address: 0x021C0C38
 * packet: pkt_ov110_021C0C38
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 */
#include "../include/Obj22410.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void PMS_DRAW_Main(u8 *p);
void PMS_SELECT_GRAPHIC_UpdateDraw(u8 *p) { PMS_DRAW_Main(((struct Obj22410 *)p)->f8C); }

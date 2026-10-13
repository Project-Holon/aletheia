/*
 * function: func_021C1440
 * address: 0x021C1440
 * packet: pkt_ov110_021C1440
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 */
#include "../include/Obj22413.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void TOUCHBAR_SetAllButtonsVisible(u8 *,u32);
int func_021C1440(void *a, u8 *p) { TOUCHBAR_SetAllButtonsVisible(*(u8 * *)&((struct Obj22413 *)p)->f54,0); return 1; }

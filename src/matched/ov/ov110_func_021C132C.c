/*
 * function: func_021C132C
 * address: 0x021C132C
 * packet: pkt_ov110_021C132C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 */
#include "../include/Obj22412.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void TOUCHBAR_SetAllButtonsVisible(u8 *,u32);
int func_021C132C(void *unused,u8 *p) { TOUCHBAR_SetAllButtonsVisible(*(u8 * *)&((struct Obj22412 *)p)->f54,1); return 1; }

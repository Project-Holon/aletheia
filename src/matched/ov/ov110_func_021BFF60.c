/*
 * function: PMSIV_WORDWIN_ResetScroll
 * address: 0x021BFF60
 * packet: pkt_ov110_021BFF60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
#include "../include/Obj02166.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
void PMSIV_WORDWIN_ResetScroll(u8 *p) { ((struct Obj02166 *)p)->f94=0; ((struct Obj02166 *)p)->f98=0; BG_SYS_ChangeScrollImmediate(2,3,8); }

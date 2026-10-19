/*
 * function: MONOLITH_TOOL_UpdateBgScroll
 * address: 0x021BA11C
 * packet: pkt_ov071_021BA11C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 */
#include "../include/Obj20758.h"

extern void BG_SYS_ChangeScroll(unsigned, unsigned, unsigned);
void MONOLITH_TOOL_UpdateBgScroll(char *p) { BG_SYS_ChangeScroll(6, 3, (((struct Obj20758 *)p)->f2D8 >> 8) % 64); }

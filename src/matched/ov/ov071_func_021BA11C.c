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
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj20758.h"

extern void func_02041EE4(unsigned, unsigned, unsigned);
void MONOLITH_TOOL_UpdateBgScroll(char *p) { func_02041EE4(6, 3, (((struct Obj20758 *)p)->f2D8 >> 8) % 64); }

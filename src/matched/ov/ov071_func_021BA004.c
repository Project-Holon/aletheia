/*
 * function: MONOLITH_TOOL_ClearPrevHighlight
 * address: 0x021BA004
 * packet: pkt_ov071_021BA004
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MONOLITH_TOOL_ClearRowHighlight 0x021B9FF8 thumb ov071
 */
#include "../include/Obj00044.h"

extern void MONOLITH_TOOL_ClearRowHighlight(void *, int);
void MONOLITH_TOOL_ClearPrevHighlight(char *p) { if (((struct Obj00044 *)p)->f304 == 1) MONOLITH_TOOL_ClearRowHighlight(p, ((struct Obj00044 *)p)->f2F8); }

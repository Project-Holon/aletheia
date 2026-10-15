/*
 * function: MONOLITH_TOOL_STATS_CreateCursor
 * address:  0x021B8EC4
 * packet:   pkt_ov071_021B8EC4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x48).
 *
 * symbols:
 *   MONOLITH_TOOL_CreateBlink  0x021B7070  thumb  ov071
 */
#include "../include/Obj06188.h"

void MONOLITH_TOOL_STATS_CreateCursor(void *p, int a)
{
    void MONOLITH_TOOL_CreateBlink(int *p, int *out);
    MONOLITH_TOOL_CreateBlink(((struct Obj06188 *)p)->f4, (int *)(a + 0x48));
}

/*
 * function: MONOLITH_TOOL_MENU_CreateCursor
 * address:  0x021B82E4
 * packet:   pkt_ov071_021B82E4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x34).
 *
 * symbols:
 *   MONOLITH_TOOL_CreateBlink  0x021B7070  thumb  ov071
 */
#include "../include/Obj04337.h"

void MONOLITH_TOOL_MENU_CreateCursor(void *p, int a)
{
    void MONOLITH_TOOL_CreateBlink(int *p, int *out);
    MONOLITH_TOOL_CreateBlink(((struct Obj04337 *)p)->f4, (int *)(a + 0x34));
}

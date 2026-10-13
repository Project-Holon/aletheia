/*
 * unit:     yes
 * function: MONOLITH_TOOL_StartBlink, MONOLITH_TOOL_IsBlinking
 * address:  0x021B7108
 * packet:   pkt_ov071_021B7108
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte initialiser and its getter.
 */
#include "../include/Obj09886.h"
#include "../include/Obj20689.h"

void MONOLITH_TOOL_StartBlink(void *p)
{
    ((struct Obj09886 *)p)->f4 = 1;
    ((struct Obj09886 *)p)->f5 = 0;
    ((struct Obj09886 *)p)->f6 = 1;
}

int MONOLITH_TOOL_IsBlinking(void *p)
{
    return ((struct Obj20689 *)p)->f4;
}

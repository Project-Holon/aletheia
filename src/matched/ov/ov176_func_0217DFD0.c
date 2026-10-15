/*
 * function: LIVEBATTLEMATCH_IRC_SetMenuValue
 * address:  0x0217DFD0
 * packet:   pkt_0217DFD0
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 */
#include "../include/Obj00348.h"

extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);

void LIVEBATTLEMATCH_IRC_SetMenuValue(int *p, int a, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(*(int *)&((struct Obj00348 *)p)->f18), *(int *)&((struct Obj00348 *)p)->f0, a, b);
}

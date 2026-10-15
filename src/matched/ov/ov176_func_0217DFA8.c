/*
 * function: LIVEBATTLEMATCH_IRC_DeleteWindow
 * address:  0x0217DFA8
 * packet:   pkt_0217DFA8
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu  0x021E89D0  thumb  ov177
 */
#include "../include/Obj00348.h"

extern void WIFIBATTLEMATCH_UTIL_DeleteMenu(int);

void LIVEBATTLEMATCH_IRC_DeleteWindow(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu(*(int *)&((struct Obj00348 *)p)->fC);
        *(int *)&((struct Obj00348 *)p)->fC = 0;
    }
}

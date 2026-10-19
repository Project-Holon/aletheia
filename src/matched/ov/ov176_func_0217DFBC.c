/*
 * function: LIVEBATTLEMATCH_IRC_PollWindowResult
 * address:  0x0217DFBC
 * packet:   pkt_0217DFBC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu  0x021E8A00  thumb  ov177
 */
#include "../include/Obj00348.h"

extern int WIFIBATTLEMATCH_UTIL_UpdateMenu(int);

int LIVEBATTLEMATCH_IRC_PollWindowResult(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu(*(int *)&((struct Obj00348 *)p)->fC);
    return -1;
}

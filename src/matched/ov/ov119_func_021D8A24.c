/*
 * function: POKETRADE_PROC_IsNetSession
 * address:  0x021D8A24
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True when the object has a session and its state index is in range.
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm  arm9
 *   (none)
 */
#include "../include/Obj00001.h"

extern int GFL_NET_GetRunState(void);

int POKETRADE_PROC_IsNetSession(void *p)
{
    int v;

    if (*(int *)&((struct Obj00001 *)p)->f8 == 0)
        return 0;
    v = ((struct Obj00001 *)p)->f118C;
    if (v >= 4)
        return 0;
    return GFL_NET_GetRunState() != 0;
}


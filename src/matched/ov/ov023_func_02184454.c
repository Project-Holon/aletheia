/*
 * function: OEKAKI_RecvAck
 * address:  0x02184454
 * packet:   pkt_02184454
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 */
#include "../include/Obj20339.h"

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

void OEKAKI_RecvAck(int a0, int a1, int a2, char *a3)
{
    if (GFL_NET_SYSTEM_GetCurrentAid())
        return;
    ((struct Obj20339 *)a3)->f9280 |= 1 << a0;
}

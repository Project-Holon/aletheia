/*
 * function: STA_NET_NotifyHostKind6
 * address:  0x021FD6F0
 * packet:   pkt_021FD6F0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUS_COMM_FUNC_SendCommandWait  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23294.h"

typedef unsigned int   u32;
extern u32 MUS_COMM_FUNC_SendCommandWait(int unused, int kind, u32 value, u32 id);

int STA_NET_NotifyHostKind6(char *p)
{
    return MUS_COMM_FUNC_SendCommandWait((int)p, 6, *(int *)(((struct Obj23294 *)p)->f140 + 0x28), 0xff);
}

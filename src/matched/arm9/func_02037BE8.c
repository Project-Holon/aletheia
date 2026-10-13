/*
 * function: GFL_NET_SYSTEM_ResetMachineBuffer
 * address:  0x02037BE8
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_ResetRecvBuffer  0x02037680  arm
 *   _pNetSys     0x021469D0  data
 *
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches GFL_NET_SYSTEM_ResetRecvBuffer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ResetMachineBuffer.c \
 *       --func GFL_NET_SYSTEM_ResetMachineBuffer --addr 0x02037BE8 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned int u32;

extern void GFL_NET_SYSTEM_ResetRecvBuffer(int i);
extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_ResetMachineBuffer(u32 a)
{
    if ((*(u32 *)&_pNetSys) == 0)
        return;
    if (a >= 8)
        return;
    GFL_NET_SYSTEM_ResetRecvBuffer(a);
}

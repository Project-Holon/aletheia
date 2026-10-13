/*
 * function: GFL_NET_SYSTEM_ResetAll
 * address:  0x02037D78
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_ResetBuffers  0x02037478  arm
 *   _pNetSys     0x021469D0  data
 *
 * Teardown hook for the same global src/matched/GFL_NET_SYSTEM_ResetMachineBuffer.c guards: the
 * armed pointer goes to GFL_NET_SYSTEM_ResetBuffers, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ResetAll.c \
 *       --func GFL_NET_SYSTEM_ResetAll --addr 0x02037D78 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned int u32;

extern void GFL_NET_SYSTEM_ResetBuffers(void);
extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_ResetAll(void)
{
    u32 v;

    v = (*(u32 *)&_pNetSys);
    if (v == 0)
        return;
    GFL_NET_SYSTEM_ResetBuffers();
}

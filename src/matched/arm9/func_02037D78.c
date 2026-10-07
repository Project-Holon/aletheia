/*
 * function: func_02037D78
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
 *   func_02037478  0x02037478  arm
 *   g_021469D0     0x021469D0  data
 *
 * Teardown hook for the same global src/matched/func_02037BE8.c guards: the
 * armed pointer goes to func_02037478, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037D78.c \
 *       --func func_02037D78 --addr 0x02037D78 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned int u32;

extern void func_02037478(void);
extern struct LinkState *g_021469D0;

void func_02037D78(void)
{
    u32 v;

    v = (*(u32 *)&g_021469D0);
    if (v == 0)
        return;
    func_02037478();
}

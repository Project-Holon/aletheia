/*
 * function: func_020370F4
 * address:  0x020370F4
 * packet:   pkt_020370F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02036E74  0x02036E74  arm
 *   g_021469C8     0x021469C8  data
 *
 * Forwards the argument to the handler held in the second word of the global
 * at 0x021469C8, but only when that handler is armed; an unarmed handler is
 * the `popeq` that returns 0 without touching r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370F4.c \
 *       --func func_020370F4 --addr 0x020370F4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 func_02036E74(u32 handler, u32 a);
extern u32 g_021469C8[];

u32 func_020370F4(u32 a)
{
    u32 v;

    v = g_021469C8[1];
    if (v == 0)
        return v;
    return func_02036E74(v, a);
}

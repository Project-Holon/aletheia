/*
 * function: GFL_NET_WM_ICON_EasySetLevel
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
 *   GFL_NET_WM_ICON_SetLevel  0x02036E74  arm
 *   g_021469C8     0x021469C8  data
 *
 * Forwards the argument to the handler held in the second word of the global
 * at 0x021469C8, but only when that handler is armed; an unarmed handler is
 * the `popeq` that returns 0 without touching r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_EasySetLevel.c \
 *       --func GFL_NET_WM_ICON_EasySetLevel --addr 0x020370F4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int *GFL_NET_WM_ICON_SetLevel(int *p, int v);
extern u32 g_021469C8[];

u32 GFL_NET_WM_ICON_EasySetLevel(u32 a)
{
    u32 v;

    v = g_021469C8[1];
    if (v == 0)
        return v;
    return (u32)GFL_NET_WM_ICON_SetLevel((int *)v, a);
}

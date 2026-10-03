/*
 * function: func_02037BE8
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
 *   func_02037680  0x02037680  arm
 *   g_021469D0     0x021469D0  data
 *
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches func_02037680.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BE8.c \
 *       --func func_02037BE8 --addr 0x02037BE8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02037680(int i);
extern u32  g_021469D0;

void func_02037BE8(u32 a)
{
    if (g_021469D0 == 0)
        return;
    if (a >= 8)
        return;
    func_02037680(a);
}

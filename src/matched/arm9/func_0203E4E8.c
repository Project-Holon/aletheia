/*
 * function: func_0203E4E8
 * address:  0x0203E4E8
 * packet:   pkt_0203E484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203CEAC  0x0203CEAC  arm
 *   g_021469F0     0x021469F0  data
 *
 * Gated state step: only a context whose +0x109 state is 0x10 advances, and
 * it does so by seeding +0x107 from +0x108, re-entering the sub-state and
 * parking the state byte at 9.  The final store re-reads the global, because
 * the call in between may have replaced the context pointer - the same
 * reload the store-after-a-call shape produces.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203E4E8.c \
 *       --func func_0203E4E8 --addr 0x0203E4E8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_0203CEAC(int a0);
extern u8  *g_021469F0;

u32 func_0203E4E8(void)
{
    u8 *p = g_021469F0;

    if (p == 0)
        return 0;
    if (p[0x109] != 0x10)
        return 0;
    p[0x107] = p[0x108] + 1;
    func_0203CEAC(0);
    g_021469F0[0x109] = 9;
    return 1;
}

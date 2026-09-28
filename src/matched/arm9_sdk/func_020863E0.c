/*
 * function: func_020863E0
 * address:  0x020863E0
 * packet:   pkt_02086374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02151264  0x02151264  data
 */

typedef unsigned int u32;

extern u32 g_02151264;

extern u32  func_02086594(u32 a0);
extern void func_02086760(u32 a0, u32 a1);
extern u32  func_02086694(u32 a0);
extern void func_02086774(u32 a0, u32 a1);

void func_020863E0(void)
{
    u32 r5;
    u32 r4;

    if (g_02151264 != 0) {
        return;
    }
    r5 = 0;
    g_02151264 = 1;

    func_02086760(r5, func_02086594(r5));
    func_02086774(r5, func_02086694(r5));

    r4 = 2;
    func_02086774(r4, r5);
    func_02086760(r4, r5);

    r4 = 3;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 4;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 5;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 6;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));
}

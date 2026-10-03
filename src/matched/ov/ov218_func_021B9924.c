/*
 * function: func_021B9924
 * address:  0x021B9924
 * packet:   pkt_ov218_021B9924
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of func_021BA0B0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_02023F98(u32 mask);
extern int func_02023EF4(int a, int b, int c, int d, int e);

int func_021B9924(void)
{
    func_02023F98(1);
    return func_02023EF4(8, -8, 0, 0x3c, 1);
}

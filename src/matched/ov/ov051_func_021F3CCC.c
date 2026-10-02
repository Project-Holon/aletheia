/*
 * function: func_021F3CCC
 * address: 0x021F3CCC
 * packet: pkt_ov051_021F3CCC
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 * symbols:
 *   func_02164280 0x02164280 thumb ov010
 *   func_02188CD0 0x02188CD0 thumb ov021
 *   func_021C9258 0x021C9258 thumb ov021
 */

extern void func_02164280(int, int, int *);
extern int func_02188CD0(int);
extern unsigned func_021C9258(unsigned, int *);

void func_021F3CCC(int *a, unsigned *b, int x, int y, int z)
{
    int v[3];
    func_02164280((short)x, (short)z, v);
    v[1] = (int)(((unsigned)y << 16) + 0x8000u);
    *b = func_021C9258(func_02188CD0(a[2]), v);
}

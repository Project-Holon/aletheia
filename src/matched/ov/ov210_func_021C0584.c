/*
 * function: func_021C0584
 * address:  0x021C0584
 * packet:   pkt_ov210_021C0584
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BEC60 0x021BEC60 thumb ov210
 *   func_021BF7B0 0x021BF7B0 thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_021BEC60(int p, int *a, u32 b);
extern void func_021BF7B0(char *p, int idx, int y, int flag);

void func_021C0584(int p, unsigned a, int b, int c, int d)
{
    func_021BEC60(p, (int *)b, *(int *)(p + a * 4 + 0x1e4));
    if ((*(u8 **)(*(int **)p + 2))[1] == a)
        func_021BF7B0((char *)p, 0, c, d);
}

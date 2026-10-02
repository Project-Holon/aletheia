/*
 * function: func_021C1CCC
 * address: 0x021C1CCC
 * packet: pkt_ov093_021C1CCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7664 0x021C7664 thumb ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021C7664(u8 *, u32, u8 *);
extern int func_021C1D60(u8 *, u8 *, u32);
int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(p, *x, a);
    return func_021C1D60(p, q, n);
}

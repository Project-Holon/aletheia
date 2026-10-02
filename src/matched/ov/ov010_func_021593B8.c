/*
 * function: func_021593B8
 * address: 0x021593B8
 * packet: pkt_ov010_021593B8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215932C 0x0215932C thumb ov010
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern u16 *func_02159AE8(void *, void *);
extern int func_0215932C(unsigned int, unsigned int);
int func_021593B8(u8 *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    a[14] = func_0215932C(*p, *q);
    return 0;
}

/*
 * function: func_021BEA98
 * address:  0x021BEA98
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEA20  0x021BEA20  arm  ov114
 *
 *
 * Clears the +0x0c queue of `p` and re-arms the +0x1c resource.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEA20(void);
extern void func_02085800(void *, int);

void func_021BEA98(u8 *p)
{
    u8 *q = func_021BEA20();
    *(u32 *)(p + 0xc) = 0;
    func_02085800(q + 0x1c, 0);
}

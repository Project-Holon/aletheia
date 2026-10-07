/*
 * function: func_021BEA64
 * address:  0x021BEA64
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
 * Drains the +0x0c queue of `p` by releasing the +0x1c resource each time.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEA20(void);
extern void func_020857B0(void *);

void func_021BEA64(u8 *p)
{
    u8 *q = func_021BEA20();
    while (*(u32 *)(p + 0xc) != 0)
        func_020857B0(q + 0x1c);
}

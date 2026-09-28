/*
 * function: func_021BEFA4
 * address:  0x021BEFA4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B4C  0x021B9B4C  arm  ov114
 *
 *
 * One-shot bring-up: zeroes the +0x18 block once and latches the flag.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9B4C(u8 *);

void func_021BEFA4(u8 *p)
{
    if (*(u32 *)(p + 0x18) != 0)
        return;
    func_021B9B4C(p);
    *(u32 *)(p + 0x18) = 1;
}

/*
 * function: func_021BA644
 * address:  0x021BA644
 * packet:   pkt_ov068_021BA644
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028178  0x02028178  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02028178(u8 *p);

void func_021BA644(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02028178((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
}

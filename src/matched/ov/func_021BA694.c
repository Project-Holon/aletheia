/*
 * function: func_021BA694
 * address:  0x021BA694
 * packet:   pkt_021BA694
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020282A4  0x020282A4  thumb
 *   func_02028218  0x02028218  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020282A4(u32 a);
extern void func_02028218(u32 a, u32 b);

void func_021BA694(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_020282A4(*(u32 *)(p + i * 4 + 0x34));
        func_02028218(*(u32 *)(p + i * 4 + 0x34), 0);
    }
}

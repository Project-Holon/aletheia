/*
 * function: func_021C06C8
 * address:  0x021C06C8
 * packet:   pkt_ov217_021C06C8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025538  0x02025538  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02025538(u16 heap, int a);

void func_021C06C8(u8 *p)
{
    *(int *)(p + 0x3A4) = func_02025538(*(u16 *)(p + 4), *(int *)(p + 0x38C));
}

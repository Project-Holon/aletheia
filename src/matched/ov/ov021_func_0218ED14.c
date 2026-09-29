/*
 * function: func_0218ED14
 * address:  0x0218ED14
 * packet:   pkt_ov021_0218ED14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards field 0xc and the second argument.
 *
 * symbols:
 *   func_02048B20  0x02048B20  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02048B20(u32 a, u32 b);

void func_0218ED14(u8 *p, u32 q)
{
    func_02048B20(*(u32 *)(p + 0xc), q);
}

/*
 * function: func_021B868C
 * address:  0x021B868C
 * packet:   pkt_021B868C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B87D8  0x021B87D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 *func_021B87D8(u8 *p, u32 idx);

int func_021B868C(u8 *p, u32 *q, void *v)
{
    return func_021B87D8(p, q[1]) == (u8 *)v;
}

/*
 * function: func_021C8300
 * address:  0x021C8300
 * packet:   pkt_021C8300
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9010  0x021B9010  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021B9010(u8 *p, u8 k);

u32 func_021C8300(int *p, u8 k)
{
    return func_021B9010((u8 *)p[1], k);
}

/*
 * function: func_021B8C50
 * address:  0x021B8C50
 * packet:   pkt_021B8C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8C20  0x021B8C20  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 func_021B8C20(int kind, u32 flags, u32 v);

u8 func_021B8C50(char **p, u32 v, int k)
{
    return func_021B8C20(*(int *)(*p + 4), v, k);
}

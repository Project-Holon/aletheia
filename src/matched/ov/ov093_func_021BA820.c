/*
 * function: func_021BA820
 * address:  0x021BA820
 * packet:   pkt_021BA820
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB964  0x021BB964  thumb  ov093
 */

typedef unsigned int   u32;
struct Q5;
u32 func_021BB964(struct Q5 *p);

u32 func_021BA820(int *p)
{
    return func_021BB964((struct Q5 *)p[2]);
}

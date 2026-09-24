/*
 * function: func_021D9124
 * address:  0x021D9124
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Encoder session getter on the byte pointed at by the third argument.
 *
 * symbols:
 *   func_021D90E8  0x021D90E8  thumb  ov119
 */

extern int func_021D90E8(int a, int b, int c, int d, int e);

int func_021D9124(int a, int b, int c, int d, int e)
{
    return func_021D90E8(*(unsigned char *)c, 0, a, d, e);
}


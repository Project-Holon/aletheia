/*
 * function: func_021EF8E8
 * address:  0x021EF8E8
 * packet:   pkt_ov093_021EF8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFA94  0x021EFA94  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

extern char d_021F63F4;
extern int func_021EFA94(void *mem, int a);

int func_021EF8E8(int a)
{
    return func_021EFA94(&d_021F63F4, a);
}

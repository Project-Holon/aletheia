/*
 * function: func_021EB670
 * address:  0x021EB670
 * packet:   pkt_ov093_021EB670
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB5B4  0x021EB5B4  thumb  ov093
 *   d_021F38AE  0x021F38AE  data  a4
 */
typedef unsigned char u8;
extern int func_021EB5B4(u8 *, int *, u8 *, u8);
extern u8 d_021F38AE[];
int func_021EB670(u8 *p, int *state)
{
    return func_021EB5B4(p, state, d_021F38AE, 4);
}

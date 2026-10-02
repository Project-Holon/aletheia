/*
 * function: func_021EB660
 * address:  0x021EB660
 * packet:   pkt_ov093_021EB660
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB5B4  0x021EB5B4  thumb  ov093
 *   d_021F38AC  0x021F38AC  data  a4
 */
typedef unsigned char u8;
extern int func_021EB5B4(u8 *, int *, u8 *, u8);
extern u8 d_021F38AC[];
int func_021EB660(u8 *p, int *state)
{
    return func_021EB5B4(p, state, d_021F38AC, 2);
}

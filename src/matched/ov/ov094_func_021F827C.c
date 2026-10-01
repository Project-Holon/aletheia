/*
 * function: func_021F827C
 * address: 0x021F827C
 * packet: pkt_ov094_021F827C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Leaf blocking ov093 func_021EB870.
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_022090A4 0x022090A4 thumb ov094
 */
typedef unsigned int u32;
extern char *d_0220AF20;
extern int func_022090A4(int *);
int func_021F827C(u32 i)
{
    return func_022090A4(*(int **)(d_0220AF20 + i * 4 + 0x1a8));
}

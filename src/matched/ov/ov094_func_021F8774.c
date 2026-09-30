/*
 * function: func_021F8774
 * address: 0x021F8774
 * packet: pkt_ov094_021F8774
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_022088F4 0x022088F4 thumb ov094
 */
typedef unsigned int u32;
extern char *d_0220AF20;
extern int func_022088F4(u32);

int func_021F8774(void)
{
    return func_022088F4(*(u32 *)(d_0220AF20 + 0x1a4));
}

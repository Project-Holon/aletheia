/*
 * function: func_021F8180
 * address: 0x021F8180
 * packet: pkt_ov094_021F8180
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02207C94 0x02207C94 thumb ov094
 *   d_0220AF20 0x0220AF20 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02207C94(u8 *);
extern u8 *d_0220AF20;
int func_021F8180(void)
{
    return func_02207C94(*(u8 **)(d_0220AF20 + 0x1a4));
}

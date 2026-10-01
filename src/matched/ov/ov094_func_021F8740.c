/*
 * function: func_021F8740
 * address: 0x021F8740
 * packet: pkt_ov094_021F8740
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent-cleared blocker of 0x021FDBB0; show proves 20-byte Thumb extent
 *       ending 0x021F8754 before another getter.
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094
 */
typedef unsigned short u16;
extern char *d_0220AF20;
int func_021F8740(int i)
{
    return *(u16 *)(d_0220AF20 + i * 2 + 0x1d4);
}

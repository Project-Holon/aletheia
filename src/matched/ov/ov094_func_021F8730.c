/*
 * function: func_021F8730
 * address: 0x021F8730
 * packet: pkt_ov094_021F8730
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent-cleared blocker of 0x021FDBB0; show proves 16-byte Thumb extent.
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094
 */
typedef struct { char pad[0x1dc]; int f1dc; } Work;
extern Work *d_0220AF20;
int func_021F8730(void)
{
    return d_0220AF20->f1dc;
}

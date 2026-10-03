/*
 * function: func_06898F04
 * address: 0x06898F04
 * packet: pkt_ov095_06898F04
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Unlabelled follower after the 0x06898EF4 interworking veneer.
 * symbols:
 *   d_0689D748 0x0689D748 data a4
 */
typedef unsigned int u32;
extern u32 d_0689D748;
u32 *func_06898F04(u32 *p)
{
    *p = 2;
    return &d_0689D748;
}

/*
 * function: func_06898B60
 * address: 0x06898B60
 * packet: pkt_ov095_06898B60
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0689D690 0x0689D690 data a4
 * note: Unlabelled follower after the non-C veneer at 0x06898B50.
 */
typedef unsigned int u32;
extern const u32 d_0689D690;
const u32 *func_06898B60(u32 *p)
{
    *p = 1;
    return &d_0689D690;
}

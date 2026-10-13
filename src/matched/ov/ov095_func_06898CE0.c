/*
 * function: HAND_SIDE_GetStackCount
 * address: 0x06898CE0
 * packet: pkt_ov095_06898CE0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0689E7EC 0x0689E7EC data a4
 * note: Unlabelled follower of veneer 0x06898CD0, ending with alignment padding.
 */
typedef unsigned int u32;
extern const u32 d_0689E7EC[];
u32 HAND_SIDE_GetStackCount(u32 a, u32 b)
{
    return *(const u32 *)((u32)d_0689E7EC + a * 224 + b * 16);
}

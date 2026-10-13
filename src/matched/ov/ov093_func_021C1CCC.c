/*
 * function: BTL_SERVER_FLOW_ProcFlinchChance
 * address: 0x021C1CCC
 * packet: pkt_ov093_021C1CCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_CalcFlinchChance 0x021C7664 thumb ov093
 *   BTL_SERVER_FLOW_RollFlinch 0x021C1D60 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_CalcFlinchChance(u8 *, u32, u8 *);
extern int BTL_SERVER_FLOW_RollFlinch(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_ProcFlinchChance(u8 *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = BTL_SERVER_FLOW_CalcFlinchChance(p, *x, a);
    return BTL_SERVER_FLOW_RollFlinch(p, q, n);
}

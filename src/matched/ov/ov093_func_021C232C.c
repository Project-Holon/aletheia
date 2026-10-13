/*
 * function: BTL_SERVER_FLOW_ProcMoveAddedSick
 * address:  0x021C232C
 * packet:   pkt_ov093_021C232C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_RollMoveAddedSick  0x021C236C  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveSickOnTarget  0x021C25A4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 BTL_SERVER_FLOW_RollMoveAddedSick(u8 *p, u32 v, u32 b, u8 *c, u32 *out);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int BTL_SERVER_FLOW_ProcMoveSickOnTarget(u8 *p, u32 a, u32 b, u32 unused, u32 s0, u32 s1, u32 s2);

void BTL_SERVER_FLOW_ProcMoveAddedSick(u8 *p, const u16 *a, u32 b, u8 *c)
{
    u32 loc;
    u32 r;
    r = BTL_SERVER_FLOW_RollMoveAddedSick(p, *a, b, c, &loc);
    if (r != 0 && BTL_POKEPARAM_IsFainted(c) == 0)
        BTL_SERVER_FLOW_ProcMoveSickOnTarget(p, b, (u32)c, *a, r, loc, 0);
}

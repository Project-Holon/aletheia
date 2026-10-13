/*
 * function: BTL_SERVER_FLOW_ApplyMoveSick
 * address:  0x021C2758
 * packet:   pkt_ov093_021C2758
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_TryApplySick  0x021C27A0  thumb  ov093
 *   BTL_SERVER_FLOW_ProcSickAdded  0x021C2910  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_SERVER_FLOW_TryApplySick(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 zero, u32 b);
extern void BTL_SERVER_FLOW_ProcSickAdded(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 c, u32 d, u32 e);

int BTL_SERVER_FLOW_ApplyMoveSick(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 b, u32 c)
{
    if (BTL_SERVER_FLOW_TryApplySick(p, x, y, z, a, 0, b) == 0) {
        BTL_SERVER_FLOW_ProcSickAdded(p, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}

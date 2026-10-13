/*
 * function: BTL_SERVER_FLOW_RunDamageDealtEventLocked
 * address: 0x021C18D4
 * packet: pkt_ov093_021C18D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_RunDamageDealtEvent 0x021C1910 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021CC8D8(void *, int);
extern void BTL_SERVER_FLOW_RunDamageDealtEvent(u8 *p, u8 *a, u8 *q, u32 v);
extern void func_021CC95C(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_RunDamageDealtEventLocked(u8 *p, u8 *a, u8 *q, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6802);
    BTL_SERVER_FLOW_RunDamageDealtEvent(p, a, q, v);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6802 + 3);
}

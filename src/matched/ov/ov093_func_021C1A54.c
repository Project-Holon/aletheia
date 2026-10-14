/*
 * function: BTL_SERVER_FLOW_ProcMoveAfterDamageEvents
 * address: 0x021C1A54
 * packet: pkt_ov093_021C1A54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_ThawTargetsHitByFireMove 0x021C1CE4 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_RunMoveDamageGroupEvent 0x021C1B5C thumb ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   CircleGraph_GetRimColor 0x021C1B4C thumb ov093
 *   BTL_SERVER_FLOW_ProcDamagedItemReaction 0x021C195C thumb ov093
 *   BTL_SERVER_FLOW_RunMoveDamageEndEvent 0x021C1C88 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_ThawTargetsHitByFireMove(u8 *p, u8 *q, u32 unused, u8 *w);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_RunMoveDamageGroupEvent(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *CircleGraph_GetRimColor(u8 *);
extern void BTL_SERVER_FLOW_ProcDamagedItemReaction(u8 *p, u8 *q, u32 n);
extern void BTL_SERVER_FLOW_RunMoveDamageEndEvent(u8 *p, u8 *a, u32 unused, u8 *q, u32 v);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
void BTL_SERVER_FLOW_ProcMoveAfterDamageEvents(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    BTL_SERVER_FLOW_ThawTargetsHitByFireMove(p, a, (u32)b, c);
    lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x1b07);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(p, b, c, a, d, 0, 0x84);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(p, b, c, a, d, 1, 0x83);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(p, b, c, a, d, 0, 0x85);
    func_021C1B2C(c);
    x = func_021C1B3C(c);
    while (x) {
        BTL_SERVER_FLOW_ProcDamagedItemReaction(p, x, 1);
        x = CircleGraph_GetRimColor(c);
    }
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(p, b, c, a, d, 0, 0x86);
    BTL_SERVER_FLOW_RunMoveDamageGroupEvent(p, b, c, a, d, 1, 0x87);
    BTL_SERVER_FLOW_RunMoveDamageEndEvent(p, b, (u32)c, a, d);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 0x1b1b);
}

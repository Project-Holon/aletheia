/*
 * function: BTL_SERVER_FLOW_ProcDamageRecordIfAny
 * address:  0x021C11A4
 * packet:   pkt_ov093_021C11A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetHitFlagsByte2  0x021C0C34  thumb  ov093
 *   BTL_SERVER_FLOW_ApplyDamageRecord  0x021C11F0  thumb  ov093
 *   BTL_SERVER_FLOW_RunDamageDealtEventLocked  0x021C18D4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_GetHitFlagsByte2(u8 *d);
extern u32 BTL_SERVER_FLOW_ApplyDamageRecord(u8 *p, u32 b, u32 c, u8 *d, u32 a, u32 e, u32 f, u32 g);
extern void BTL_SERVER_FLOW_RunDamageDealtEventLocked(u8 *p, u8 *a, u8 *q, u32 v);

u32 BTL_SERVER_FLOW_ProcDamageRecordIfAny(u8 *p, u32 a, u32 b, u32 c, u8 *d, u32 e, u32 f, u32 g)
{
    u32 r;
    if ((u8)BTL_SERVER_FLOW_GetHitFlagsByte2(d) != 0) {
        r = BTL_SERVER_FLOW_ApplyDamageRecord(p, b, c, d, a, e, f, g);
        BTL_SERVER_FLOW_RunDamageDealtEventLocked(p, (u8 *)b, (u8 *)a, r);
        return r;
    }
    return 0;
}

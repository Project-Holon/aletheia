/*
 * function: BTL_SERVER_FLOW_RollFlinch
 * address:  0x021C1D60
 * packet:   pkt_ov093_021C1D60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_POKEPARAM_SetTurnFlag  0x021D5FC0  thumb  ov093
 *   BTL_SERVER_FLOW_RollFlinchChance  0x021C76F4  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyFlinchEvent  0x021C7780  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct UtilWork;
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_RollFlinchChance(u8 *p, u8 *q, u32 n);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_NotifyFlinchEvent(u8 *p, u8 *q);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_RollFlinch(u8 *p, u8 *q, u32 n)
{
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 5)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 6);
        return 1;
    }
    if (BTL_SERVER_FLOW_RollFlinchChance(p, q, n)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 7085);
        BTL_SERVER_FLOW_NotifyFlinchEvent(p, q);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 7087);
    }
    return 0;
}

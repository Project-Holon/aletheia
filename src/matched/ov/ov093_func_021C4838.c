/*
 * function: BTL_SERVER_FLOW_ProcTurnCheckPhase
 * address:  0x021C4838
 * packet:   pkt_ov093_021C4838
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C48E0  0x021C48E0  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchTurnCheckEvent  0x021C4910  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdown  0x021BC2B0  thumb  ov093
 *   func_021C48F0  0x021C48F0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke  0x021C4F64  thumb  ov093
 *   func_021C4900  0x021C4900  thumb  ov093
 *   BTL_SERVER_FLOW_ProcFaintRewards  0x021C5200  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C48E0(u8 *a);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchTurnCheckEvent(u8 *p, u32 a, int k);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);
extern u8 *func_021C48F0(u8 *a);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *p, u8 *a);
extern u8 *func_021C4900(u8 *a);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p);

int BTL_SERVER_FLOW_ProcTurnCheckPhase(u8 *p, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_021C48E0(a);
    s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 9644);
    BTL_SERVER_FLOW_DispatchTurnCheckEvent(p, 0x1f, (int)b);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 9646);
    if (BTL_SERVER_FLOW_CheckShowdown(p) == 0) {
        q = func_021C48F0(a);
        if (q != 0) {
            do {
                s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 9652);
                BTL_SERVER_FLOW_DispatchTurnCheckEvent(p, BTL_POKEPARAM_GetPokeId(q), (int)b);
                BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 9654);
                BTL_SERVER_FLOW_ProcFaintedPoke(p, q);
                if (BTL_SERVER_FLOW_CheckShowdown(p) != 0) {
                    break;
                }
                q = func_021C4900(a);
            } while (q != 0);
        }
    }
    return BTL_SERVER_FLOW_ProcFaintRewards(p);
}

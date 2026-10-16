/*
 * function: BTL_SERVER_FLOW_ItemEffectTriggerEntryEvent
 * address:  0x021CC508
 * packet:   pkt_ov093_021CC508
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk  0x021C84D0  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockStateThunk  0x021C8910  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk(u8 *p, u8 *a);
extern int BTL_SERVER_FLOW_GetLockStateThunk(u8 *p);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_ItemEffectTriggerEntryEvent(char *p, void *m)
{
    u32 s;
    int r;

    if (BTL_POKEPARAM_GetValue(m, 16) != 150) {
        s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 1921);
        BTL_SERVER_FLOW_DispatchPokeEntryEventToType4Thunk((u8 *)p, m);
        r = BTL_SERVER_FLOW_GetLockStateThunk((u8 *)p);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 1926);
        if (r == 2)
            return 1;
    }
    return 0;
}

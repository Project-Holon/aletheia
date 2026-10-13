/*
 * function: BTL_SERVER_FLOW_GetEffectiveWeather
 * address:  0x021C2AB0
 * packet:   pkt_ov093_021C2AB0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_FIELD_GetCountdownValue  0x021EF884  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern int BTL_FIELD_GetCountdownValue(void);

int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *p)
{
    int r;
    int t;
    BTL_EVENT_PushVarFrame(7971);
    BTL_EVENT_SetVarOnce(0x41, 0);
    r = 0;
    BTL_EVENT_DispatchEventChecked(p, 0x7a);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(7975);
    if (t == 0)
        r = BTL_FIELD_GetCountdownValue();
    return r;
}

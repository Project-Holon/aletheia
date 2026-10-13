/*
 * function: BTL_SERVER_FLOW_CalcWeatherDamage
 * address:  0x021C4E38
 * packet:   pkt_ov093_021C4E38
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_CalcWeatherDamage(u8 *p, u8 *a, u32 b, u32 c)
{
    u8 f;
    int r;
    int s;
    BTL_EVENT_PushVarFrame(9960);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x39, b);
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVar(0x32, c);
    BTL_EVENT_DispatchEventChecked(p, 0x7f);
    s = BTL_EVENT_GetVar(0x32);
    f = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(9969);
    if (f == 0) {
        r = s;
    }
    return r;
}

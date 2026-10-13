/*
 * function: BTL_SERVER_FLOW_QueryMoveRankEffectEvent
 * address:  0x021C2F70
 * packet:   pkt_ov093_021C2F70
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 WAZA_TOOL_GetRankEffect(u16 id, u32 idx, s32 *out);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

void BTL_SERVER_FLOW_QueryMoveRankEffectEvent(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = WAZA_TOOL_GetRankEffect(x, y, s2);
    BTL_EVENT_PushVarFrame(8275);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(s0));
    BTL_EVENT_SetVar(0x1F, *s1);
    BTL_EVENT_SetVar(0x20, *s2);
    BTL_EVENT_SetVar(0x35, 1);
    BTL_EVENT_DispatchEventChecked(p, 0x59);
    *s1 = BTL_EVENT_GetVar(0x1F);
    *s2 = BTL_EVENT_GetVar(0x20);
    m = (u8)BTL_EVENT_GetVar(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    BTL_EVENT_PopVarFrame(8290);
    if (*s1 == 8)
        *s1 = 0;
}

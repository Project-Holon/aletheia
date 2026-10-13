/*
 * function: BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent
 * address:  0x021C68A8
 * packet:   pkt_ov093_021C68A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6928  0x021C6928  thumb  ov093
 *   func_021C6938  0x021C6938  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021C6928(u8 *d);
extern u8 *func_021C6938(u8 *d, u32 i);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(u8 *p, u8 *a, u8 *d, u16 a3)
{
    u32 n;
    u32 i;
    u8 t;
    n = func_021C6928(d);
    BTL_EVENT_PushVarFrame(11731);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_021C6938(d, i)));
    }
    BTL_EVENT_DispatchEventChecked(p, 0x98);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(11742);
    return t == 0;
}

/*
 * function: BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent
 * address:  0x021BEB14
 * packet:   pkt_ov093_021BEB14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEBB8  0x021BEBB8  thumb  ov093
 *   func_021BEBC8  0x021BEBC8  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021BEBB8(int d);
extern u8 *func_021BEBC8(int d, u32 i);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent(int a, u8 *b, int c, int d, u8 *e, u8 *g)
{
    u32 n;
    u32 i;
    n = func_021BEBB8(d);
    BTL_EVENT_PushVarFrame(4136);
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++)
        BTL_EVENT_SetVarReadOnly(6 + i, BTL_POKEPARAM_GetPokeId(func_021BEBC8(d, i)));
    BTL_EVENT_SetVarOnce(2, 0x1f);
    BTL_EVENT_SetVar(4, 0x1f);
    BTL_EVENT_DispatchEventChecked((void *)a, 0x1a);
    *e = BTL_EVENT_GetVar(2);
    *g = BTL_EVENT_GetVar(4);
    BTL_EVENT_PopVarFrame(4155);
    if (*e != 0x1f)
        return 1;
    return 0;
}

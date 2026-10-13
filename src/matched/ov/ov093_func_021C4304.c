/*
 * function: BTL_SERVER_FLOW_DispatchMoveFailCheck
 * address:  0x021C4304
 * packet:   pkt_ov093_021C4304
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
 *   func_021C43C0  0x021C43C0  thumb  ov093
 *   func_021C43D0  0x021C43D0  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   func_021C43E0  0x021C43E0  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockState  0x021C88E4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern int func_021C43C0(u8 *c);
extern int func_021C43D0(u8 *c);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern u8 *func_021C43E0(u8 *c, u8 i);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern int BTL_SERVER_FLOW_GetLockState(u8 *p);

int BTL_SERVER_FLOW_DispatchMoveFailCheck(u8 *p, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    BTL_EVENT_PushVarFrame(9370);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    n1 = func_021C43C0(c);
    n2 = func_021C43D0(c);
    BTL_EVENT_SetVarReadOnly(5, n2);
    BTL_EVENT_SetVarOnce(0x51, 1);
    for (i = 0; i < n2; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_021C43E0(c, i)));
    }
    BTL_EVENT_SetVarReadOnly(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            BTL_EVENT_DispatchEventChecked(p, 0xa0);
        }
    } else {
        BTL_EVENT_DispatchEventChecked(p, 0xa1);
    }
    *out = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(9402);
    if (BTL_SERVER_FLOW_GetLockState(p) != 0) {
        return 1;
    }
    return 0;
}

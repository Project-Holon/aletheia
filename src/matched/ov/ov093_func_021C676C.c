/*
 * function: BTL_SERVER_FLOW_QueryMoveRedirectEvent
 * address:  0x021C676C
 * packet:   pkt_ov093_021C676C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3DOBJ_SetObjectRedrawFlag  0x021C6828  thumb  ov093
 *   func_021C6838  0x021C6838  thumb  ov093
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

extern u32 FIELD_G3DOBJ_SetObjectRedrawFlag(u8 *d);
extern u8 *func_021C6838(u8 *d, u32 i);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryMoveRedirectEvent(u8 *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32)
{
    u32 n;
    u32 i;
    int t;
    n = FIELD_G3DOBJ_SetObjectRedrawFlag(d);
    BTL_EVENT_PushVarFrame(11648);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(func_021C6838(d, i)));
        }
    } else {
        BTL_EVENT_SetVarReadOnly(6, 0x1F);
    }
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_SetVarOnce(0x4F, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x95);
    if (BTL_EVENT_GetVar(0x51) != 0) {
        *out8 = BTL_EVENT_GetVar(6);
    } else {
        *out8 = 0x1F;
    }
    *out32 = BTL_EVENT_GetVar(0x4F);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(11677);
    return t == 0;
}

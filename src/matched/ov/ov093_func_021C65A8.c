/*
 * function: BTL_SERVER_FLOW_QueryMoveExecuteEvent
 * address:  0x021C65A8
 * packet:   pkt_ov093_021C65A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6648  0x021C6648  thumb  ov093
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
#include "../include/Obj21104.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021C6648(u8 *d);
extern u8 *FIELD_G3DOBJ_GetObjectTrans(u8 *d, u32 i);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryMoveExecuteEvent(u8 *p, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_021C6648(d);
    BTL_EVENT_PushVarFrame(11533);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, e);
    BTL_EVENT_SetVarReadOnly(5, n);
    for (i = 0; i < n; i++) {
        BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(FIELD_G3DOBJ_GetObjectTrans(d, i)));
    }
    BTL_EVENT_SetVarOnce(0x3E, 0);
    BTL_EVENT_SetVarOnce(0x13, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x24);
    r = BTL_EVENT_GetVar(0x3E);
    t = BTL_EVENT_GetVar(0x13);
    BTL_EVENT_PopVarFrame(11550);
    if (t != 0) {
        **(u16 * *)&((struct Obj21104 *)p)->f4A8 = t;
    }
    return r;
}

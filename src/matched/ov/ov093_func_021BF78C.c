/*
 * function: BTL_SERVER_FLOW_RunTargetNoEffectEvent
 * address:  0x021BF78C
 * packet:   pkt_ov093_021BF78C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_ReadSlotTableEntry  0x021CC8C0  thumb  ov093
 *   BTL_SERVER_FLOW_ClearMsgRecord  0x021C8810  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
#include "../include/Obj13317.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Bf { u8 pad[0x10]; u32 f : 1; };
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 BTL_SERVER_FLOW_ReadSlotTableEntry(u32 *p, u32 i);
extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *p);
extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_RunTargetNoEffectEvent(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h)
{
    u32 t;
    int r;
    t = BTL_SERVER_FLOW_ReadSlotTableEntry(f, BTL_POKEPARAM_GetPokeId(e));
    BTL_SERVER_FLOW_ClearMsgRecord(g);
    BTL_EVENT_PushVarFrame(4834);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(d));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(e));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj13317 *)b)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, b[6]);
    BTL_EVENT_SetVarReadOnly(0x4e, ((struct Bf *)b)->f);
    BTL_EVENT_SetVarReadOnly(0x3f, (u32)g);
    BTL_EVENT_SetVarReadOnly(0x38, t);
    BTL_EVENT_SetVarOnce(0x40, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_DispatchEventChecked(p, c);
    r = BTL_EVENT_GetVar(0x40);
    *h = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(4847);
    return r;
}

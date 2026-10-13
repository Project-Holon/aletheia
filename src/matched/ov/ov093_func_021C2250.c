/*
 * function: BTL_SERVER_FLOW_SetHeldItem
 * address:  0x021C2250
 * packet:   pkt_ov093_021C2250
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_SetItem  0x021D5B44  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   BTL_SERVER_FLOW_SetContFlag  0x021C60EC  thumb  ov093
 *   BTL_SERVER_FLOW_SetTurnFlag  0x021C6134  thumb  ov093
 *   BTL_HANDLER_ITEM_RemoveUnforcedFactors  0x021DCF24  thumb  ov093
 *   BTL_HANDLER_ITEM_AddHeldItemFactor  0x021DCF5C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_ConsumeHeldItem  0x021D6730  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
struct QI;
extern void BTL_POKEPARAM_SetItem(struct QI *p, u16 v);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C7AD0(u8 *p, u8 *a, u32 b);
extern void func_021C7B0C(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_SetContFlag(u8 *p, u8 *a, u32 n);
extern void BTL_SERVER_FLOW_SetTurnFlag(u8 *p, u8 *a, unsigned int n);
extern void BTL_HANDLER_ITEM_RemoveUnforcedFactors(u8 *a);
extern void *BTL_HANDLER_ITEM_AddHeldItemFactor(void *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct QK;
extern void BTL_POKEPARAM_ConsumeHeldItem(struct QK *p, u16 v);

void BTL_SERVER_FLOW_SetHeldItem(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = BTL_POKEPARAM_GetPokeId(a);
    t = (u16)(int)BTL_POKEPARAM_GetItem((struct QI *)a);
    s = func_021CC8D8(p + 0x1D74, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7471);
    if (b == 0)
        BTL_SERVER_FLOW_SetContFlag(p, a, 15);
    BTL_HANDLER_ITEM_RemoveUnforcedFactors(a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x1E, name, b);
    BTL_POKEPARAM_SetItem((struct QI *)a, b);
    if (b != 0)
        BTL_HANDLER_ITEM_AddHeldItemFactor(a);
    s = func_021CC8D8(p + 0x1D74, 7485);
    func_021C7B0C(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7487);
    if (c != 0) {
        BTL_POKEPARAM_ConsumeHeldItem((struct QK *)a, t);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x17, name, t);
        BTL_SERVER_FLOW_SetTurnFlag(p, a, 8);
    }
}

/*
 * function: BTL_SERVER_FLOW_ProcRotation
 * address:  0x021BC418
 * packet:   pkt_ov093_021BC418
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SLOT_Rotate  0x021B9C50  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_ProcPokeLeaveField  0x021C5108  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_CureSick  0x021C5620  thumb  ov093
 *   HAND_TOKUSEI_EnableAbilityHandlers  0x021D8548  thumb  ov093
 *   HAND_ITEM_EnablePokeFactors  0x021DCFB4  thumb  ov093
 *   func_021BC4CC  0x021BC4CC  thumb  ov093
 */
#include "../include/Obj00003.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Slot {
    u32 kind : 3;
    u32 rest : 29;
};

extern u8 *BTL_SIDE_GetSlotOfClient(u8 *p, int i);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SLOT_Rotate(u8 **p, int k, u8 **o1, u8 **o2);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_SERVER_FLOW_ProcPokeLeaveField(u8 *p, u8 *a, int b);
extern int BTL_FIELD_GetStaticSlotObject(int k);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void HAND_TOKUSEI_EnableAbilityHandlers(void *p);
extern void HAND_ITEM_EnablePokeFactors(void *p);
extern void func_021BC4CC(u8 *p, int a, int b, u8 *c, u8 *d);

void BTL_SERVER_FLOW_ProcRotation(u8 *p, int a, int b)
{
    u8 *t;
    u8 *v1;
    u8 *v2;
    int k;

    if (b == 1)
        return;
    if (b == 0)
        return;
    t = BTL_SIDE_GetSlotOfClient(*(u8 * *)&((struct Obj00003 *)p)->f8, a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x48, a, b);
    BTL_SLOT_Rotate((u8 **)t, b, &v1, &v2);
    if (BTL_POKEPARAM_IsFainted(v1) == 0)
        BTL_SERVER_FLOW_ProcPokeLeaveField(p, v1, 1);
    if (BTL_POKEPARAM_IsFainted(v2) == 0) {
        if (BTL_FIELD_GetStaticSlotObject(2) != 0) {
            k = 0x20;
            if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)v2, k) != 0)
                BTL_SERVER_FLOW_CureSick(p, v2, k, 0);
            k = 0x1e;
            if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)v2, k) != 0)
                BTL_SERVER_FLOW_CureSick(p, v2, k, 0);
        }
        HAND_TOKUSEI_EnableAbilityHandlers(v2);
        HAND_ITEM_EnablePokeFactors(v2);
    }
    func_021BC4CC(p + 0x1ab8, b, a, v2, *(u8 * *)&((struct Obj00003 *)p)->f8);
}

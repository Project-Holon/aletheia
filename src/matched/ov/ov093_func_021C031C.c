/*
 * function: BTL_SERVER_FLOW_CheckConfusionFail
 * address:  0x021C031C
 * packet:   pkt_ov093_021C031C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_TickConfusionTurn  0x021D61A8  thumb  ov093
 *   BTL_SERVER_FLOW_CureSick  0x021C5620  thumb  ov093
 *   BTL_SERVER_FLOW_PushConfusionMessage  0x021C54C8  thumb  ov093
 *   BTL_CALC_RollPercent  0x021D7AF0  thumb  ov093
 */
#include "../include/Obj04359.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Slot;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
struct Unk021D62A8;
struct UtilSlots;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_TickConfusionTurn(struct UtilSlots *p);
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_SERVER_FLOW_PushConfusionMessage(u8 *p, u8 *a);
extern int BTL_CALC_RollPercent(u32 pct);
int BTL_SERVER_FLOW_CheckConfusionFail(u8 *p, u8 *a)
{
    int k = 6;
    if (((struct Obj04359 *)p)->f1F78 == 3) {
        BTL_SERVER_CMD_PushVariable(((struct Obj04359 *)p)->fC, 0x5a, 0xbc, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
        return 1;
    }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, k) != 0) {
        if (BTL_POKEPARAM_TickConfusionTurn((struct UtilSlots *)a) != 0) {
            BTL_SERVER_FLOW_CureSick(p, a, k, 0);
            BTL_SERVER_CMD_PushVariable(((struct Obj04359 *)p)->fC, 0x5b, 0x15f, BTL_POKEPARAM_GetPokeId(a), 0xffff0000);
            return 0;
        }
        BTL_SERVER_FLOW_PushConfusionMessage(p, a);
        return BTL_CALC_RollPercent(50);
    }
    return 0;
}

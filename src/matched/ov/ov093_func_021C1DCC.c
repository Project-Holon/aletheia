/*
 * function: BTL_SERVER_FLOW_ProcDrainHeal
 * address:  0x021C1DCC
 * packet:   pkt_ov093_021C1DCC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   BTL_CALC_MulPercent  0x021D7B3C  thumb  ov093
 *   BTL_SERVER_FLOW_RecoverHpFromDrain  0x021C1E14  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 */
#include "../include/Obj09967.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u32 BTL_CALC_MulPercent(u32 a, u32 b);
extern int BTL_SERVER_FLOW_RecoverHpFromDrain(u8 *p, u8 *q, u32 a, u32 b);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);

void BTL_SERVER_FLOW_ProcDrainHeal(u8 *p, u8 *q, u32 a, u8 *b, u32 s)
{
    if (WAZA_TOOL_GetCategory(((struct Obj09967 *)q)->f0) == 8) {
        if (BTL_SERVER_FLOW_RecoverHpFromDrain(p, (u8 *)a, (u32)b, (u16)BTL_CALC_MulPercent(s, WAZA_TOOL_GetParam(((struct Obj09967 *)q)->f0, 0x19)))) {
            BTL_SERVER_FLOW_PushMsgSetPoke(p, b, 0x383);
        }
    }
}

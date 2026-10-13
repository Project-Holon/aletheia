/*
 * function: BTL_SERVER_FLOW_ProcMoveCategoryEffect
 * address:  0x021C1880
 * packet:   pkt_ov093_021C1880
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   BTL_SERVER_FLOW_ProcMoveAddedRankEffect  0x021C2CD8  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveAddedSick  0x021C232C  thumb  ov093
 */
#include "../include/Obj09968.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 WAZA_TOOL_GetCategory(u16 move);
extern void BTL_SERVER_FLOW_ProcMoveAddedRankEffect(u8 *p, u16 *q, u8 *a, u8 *b);
extern void BTL_SERVER_FLOW_ProcMoveAddedSick(u8 *p, const u16 *a, u32 b, u8 *c);

void BTL_SERVER_FLOW_ProcMoveCategoryEffect(u8 *p, u8 *q, u32 a, u32 b, u32 s0, int s1)
{
    switch (WAZA_TOOL_GetCategory(((struct Obj09968 *)q)->f0)) {
    case 7:
        BTL_SERVER_FLOW_ProcMoveAddedRankEffect(p, (u16 *)q, (u8 *)a, (u8 *)a);
        break;
    case 6:
        if (s1 == 0) {
            BTL_SERVER_FLOW_ProcMoveAddedRankEffect(p, (u16 *)q, (u8 *)a, (u8 *)b);
        }
        break;
    case 4:
        if (s1 == 0) {
            BTL_SERVER_FLOW_ProcMoveAddedSick(p, (const u16 *)q, a, (u8 *)b);
        }
        break;
    }
}

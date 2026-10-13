/*
 * function: BTL_SERVER_FLOW_RemoveSubstitute
 * address:  0x021C41C0
 * packet:   pkt_ov093_021C41C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C4208  0x021C4208  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 *   BTL_POKEPARAM_ClearSubstitute  0x021D6D70  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021C4208(u8 *p, int i);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);
extern void BTL_POKEPARAM_ClearSubstitute(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);

void BTL_SERVER_FLOW_RemoveSubstitute(u8 *p, u8 *a)
{
    int i = BTL_POKEPARAM_GetPokeId(a);
    int r = func_021C4208(p + 0x1ab8, i);
    BTL_SERVER_FLOW_PushMsgSetPoke(p, a, 0x31a);
    BTL_POKEPARAM_ClearSubstitute(a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x28, i);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x52, r);
}

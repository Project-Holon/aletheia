/*
 * function: BTL_SERVER_FLOW_ProcShift
 * address:  0x021BD3E8
 * packet:   pkt_ov093_021BD3E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_FindPoke  0x021B9C98  thumb  ov093
 *   BTL_SERVER_FLOW_ShiftPokes  0x021BD43C  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgSetPoke  0x021C5D88  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchShiftEvents  0x021BD4E4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern char *BTL_SIDE_GetSlotOfClient(char *p, int i);
extern int BTL_SLOT_FindPoke(u8 *p, u32 v);
extern void BTL_SERVER_FLOW_ShiftPokes(u8 *p, int i, u8 a, u8 b, int c);
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *p, u8 *a, int b);
extern void BTL_SERVER_FLOW_DispatchShiftEvents(u8 *p, int i, u8 a, u8 b);

void BTL_SERVER_FLOW_ProcShift(u8 *p, u8 *a)
{
    int i;
    int r;
    i = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
    r = BTL_SLOT_FindPoke((u8 *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, i), (u32)a);
    if (r == 0 || r == 2) {
        BTL_SERVER_FLOW_ShiftPokes(p, i, r, 1, 0);
        BTL_SERVER_FLOW_PushMsgSetPoke(p, a, 0xe7);
        BTL_SERVER_FLOW_DispatchShiftEvents(p, i, r, 1);
    }
}

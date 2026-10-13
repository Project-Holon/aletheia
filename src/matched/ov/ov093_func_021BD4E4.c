/*
 * function: BTL_SERVER_FLOW_DispatchShiftEvents
 * address: 0x021BD4E4
 * packet: pkt_ov093_021BD4E4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_SERVER_FLOW_DispatchShiftInEventLocked 0x021BD518 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
typedef unsigned int u32;
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern void BTL_SERVER_FLOW_DispatchShiftInEventLocked(u8 *, u8 *);
void BTL_SERVER_FLOW_DispatchShiftEvents(u8 *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, i);
    first = BTL_SLOT_GetPokeParam((struct S2 *)arr, a);
    second = BTL_SLOT_GetPokeParam((struct S2 *)arr, b);
    BTL_SERVER_FLOW_DispatchShiftInEventLocked(p, first);
    BTL_SERVER_FLOW_DispatchShiftInEventLocked(p, second);
}

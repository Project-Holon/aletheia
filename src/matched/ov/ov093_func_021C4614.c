/*
 * function: BTL_SERVER_FLOW_ProcTripleShift
 * address: 0x021C4614
 * packet: pkt_ov093_021C4614
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: first index declared before other indices; byte results of 021B8DEC.
 * symbols:
 *  BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *  BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *  BTL_MAIN_GetOpponentClient 0x021B9064 thumb ov093
 *  BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *  BTL_SLOT_CountLiving 0x021B9B98 thumb ov093
 *  BTL_SLOT_GetFirstLiving 0x021B9CE8 thumb ov093
 *  BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *  func_021C4724 0x021C4724 thumb ov093
 *  func_021C4734 0x021C4734 thumb ov093
 *  BTL_MAIN_GetSlotNthOfClient 0x021B8DEC thumb ov093
 *  BTL_MAIN_IsBackRowPos 0x021B99F0 thumb ov093
 *  BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *  BTL_SERVER_FLOW_ShiftPokes 0x021BD43C thumb ov093
 *  BTL_SERVER_FLOW_DispatchShiftEvents 0x021BD4E4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern u8 BTL_SLOT_CountLiving(u8 *p);
extern void *BTL_SLOT_GetFirstLiving(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 func_021C4724(u8 *, u32);
extern u32 func_021C4734(u8 *, u32);
extern u8 BTL_MAIN_GetSlotNthOfClient(void *, int);
extern u32 BTL_MAIN_IsBackRowPos(u32);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ShiftPokes(u8 *, int, u8, u8, int);
extern void BTL_SERVER_FLOW_DispatchShiftEvents(u8 *, int, u8, u8);
void BTL_SERVER_FLOW_ProcTripleShift(u8 *p)
{
    u32 first, a, b;
    char *x, *y;
    u8 *m, *n;
    u32 mi, ni, s, t;
    u8 v, w;
    if (BTL_MAIN_GetRule(((struct Obj00003 *)p)->f4) != 2) return;
    a = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00003 *)p)->f4);
    first = a;
    b = (u8)BTL_MAIN_GetOpponentClient(((struct Obj00003 *)p)->f4, a, 0);
    if (a > b) { first = b; b = a; }
    x = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, first);
    y = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, b);
    if (BTL_SLOT_CountLiving((u8 *)x) != 1) return;
    if (BTL_SLOT_CountLiving((u8 *)y) != 1) return;
    m = BTL_SLOT_GetFirstLiving((u8 *)x);
    n = BTL_SLOT_GetFirstLiving((u8 *)y);
    mi = BTL_POKEPARAM_GetPokeId(m);
    ni = BTL_POKEPARAM_GetPokeId(n);
    s = func_021C4724(p + 0x1ab8, mi);
    t = func_021C4734(p + 0x1ab8, ni);
    if (s == 6 || t == 6) return;
    v = BTL_MAIN_GetSlotNthOfClient(((struct Obj00003 *)p)->f4, s);
    w = BTL_MAIN_GetSlotNthOfClient(((struct Obj00003 *)p)->f4, t);
    if (v != w) return;
    if (BTL_MAIN_IsBackRowPos(s) != 0) return;
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x50, first, v, b, w);
    BTL_SERVER_FLOW_ShiftPokes(p, first, v, 1, 1);
    BTL_SERVER_FLOW_ShiftPokes(p, b, w, 1, 1);
    BTL_SERVER_FLOW_DispatchShiftEvents(p, first, v, 1);
    BTL_SERVER_FLOW_DispatchShiftEvents(p, b, w, 1);
}

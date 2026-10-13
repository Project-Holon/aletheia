/*
 * function: BTL_SERVER_FLOW_RunEscapeFromLead
 * address: 0x021BC360
 * packet: pkt_ov093_021BC360
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021BC38E, then BTL_SERVER_FLOW_RunBagModeSetup.
 * Lever: bind the first call result before initializing the boolean result.
 * symbols:
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   BTL_SERVER_FLOW_ProcEscape 0x021BD584 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8FF4(u8 *);
extern void *func_021B990C(char *, u32, u32);
extern int BTL_SERVER_FLOW_ProcEscape(u8 *, u8 *);
int BTL_SERVER_FLOW_RunEscapeFromLead(u8 *p)
{
    u8 *a;
    u32 side;
    int result;
    u32 *out;
    side = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    result = 0;
    a = func_021B990C(*(char * *)&((struct Obj00003 *)p)->f8, side, 0);
    out = *(u32 * *)&((struct Obj00003 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    if (BTL_SERVER_FLOW_ProcEscape(p, a)) result = 1;
    return result;
}

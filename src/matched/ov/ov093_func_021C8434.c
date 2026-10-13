/*
 * function: func_021C8434
 * address: 0x021C8434
 * packet: pkt_ov093_021C8434
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C845C 0x021C845C thumb ov093
 *   BTL_SERVER_FLOW_PushMoveQueue 0x021BE52C thumb ov093
 */
#include "../include/Obj21121.h"
typedef unsigned char u8;
extern int func_021C845C(u8 *, int);
extern void BTL_SERVER_FLOW_PushMoveQueue(u8 *, int, int, int);
void func_021C8434(u8 *p, int a, int b)
{
    int c = func_021C845C(p + 0x1ab8, b);
    BTL_SERVER_FLOW_PushMoveQueue(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}

/*
 * function: func_0216D0E8
 * address: 0x0216D0E8
 * packet: pkt_ov010_0216D0E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216D0F6, then labelled 0x0216D0F8.
 * symbols:
 *   func_02164304 0x02164304 thumb ov010
 */
#include "../include/Obj09310.h"
typedef unsigned char u8;
extern void func_02164304(int, u8 *);
void func_0216D0E8(int a, u8 *p) {
    if (((struct Obj09310 *)p)->f18 == 1) func_02164304(a, p);
}

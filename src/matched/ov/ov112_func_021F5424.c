/*
 * function: func_021F5424
 * address:  0x021F5424
 * packet:   pkt_ov112_021F5424
 * region:   ov112
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * ov112_func_021F80B0.  The +8 word is loaded once and shared by both arms
 * (the two identical loads CSE, which schedules the load before the branch).
 *
 * symbols:
 *   func_021F626C  0x021F626C  thumb  ov112
 *   func_021F6280  0x021F6280  thumb  ov112
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13831.h"

typedef unsigned char  u8;
extern void func_021F626C(u8 *p);
extern void func_021F6280(u8 *p);

void func_021F5424(int a0, int a1)
{
    if (a1 == 1)
        func_021F626C((u8 *)(((struct Obj13831 *)a0)->f8));
    else
        func_021F6280((u8 *)(((struct Obj13831 *)a0)->f8));
}

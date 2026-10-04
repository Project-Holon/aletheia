/*
 * unit:     yes
 * function: func_021F36E0, func_021F36EC
 * address:  0x021F36E0
 * packet:   pkt_ov051_021F36E0
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two accessors over the result of func_021F36C0.
 *
 * symbols:
 *   func_021F36C0  0x021F36C0  thumb  ov051
 */
#include "../include/Obj20552.h"
#include "../include/Obj20553.h"

int func_021F36E0(int a)
{
    void *func_021F36C0(int a);
    return ((struct Obj20552 *)((char *)func_021F36C0(a)))->f8;
}

int func_021F36EC(int a)
{
    void *func_021F36C0(int a);
    return ((struct Obj20553 *)((char *)func_021F36C0(a)))->f4;
}

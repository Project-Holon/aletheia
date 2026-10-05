/*
 * function: func_021BE0C4
 * address:  0x021BE0C4
 * packet:   pkt_021BE0C4
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj25312.h"

extern int func_0204B1CC(int);
extern void func_0204A5AC(int);
extern void func_02082BCC(void *, int, int);

void func_021BE0C4(char *a)
{
    func_0204A5AC(func_0204B1CC(((struct Obj25312 *)a)->f0));
    func_02082BCC(a, 0, 4);
}
/*
 * function: func_02205BAC
 * address:  0x02205BAC
 * packet:   pkt_02205BAC
 * region:   ov195
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
#include "../include/Obj24953.h"

extern int func_0204B1CC(int);
extern void func_0204A5AC(int);
extern void func_02082BCC(void *, int, int);

void func_02205BAC(char *a)
{
    func_0204A5AC(func_0204B1CC(((struct Obj24953 *)a)->f0));
    func_02082BCC(a, 0, 4);
}
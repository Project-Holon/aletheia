/*
 * function: func_021F4CB0
 * address:  0x021F4CB0
 * packet:   pkt_021F4CB0
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../include/Obj14512.h"

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(int, int, int);
extern int func_0204B100(int, int, int);
typedef unsigned int   u32;
struct Bank;
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_021F4CB0(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C(0x021F55B4, a, b);
    *(int *)&((struct Obj14512 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14512 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

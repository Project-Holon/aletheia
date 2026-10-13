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
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../include/Obj14512.h"

extern void func_02082BCC(void *, int, int);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
typedef unsigned int   u32;
struct Bank;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_021F4CB0(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021F55B4, a, b);
    *(int *)&((struct Obj14512 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14512 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

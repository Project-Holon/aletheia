/*
 * function: func_021BD7D0
 * address:  0x021BD7D0
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24105.h"

typedef unsigned int u32;

extern u32  func_0204B1CC(u32 p);
extern void func_0204A5AC(u32 p);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);

void func_021BD7D0(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    func_0204A5AC(func_0204B1CC(((struct Obj24105 *)a0)->f1AC));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}

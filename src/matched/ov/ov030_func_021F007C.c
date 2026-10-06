/*
 * function: func_021F007C
 * address:  0x021F007C
 * packet:   pkt_ov030_021F007C
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * (followed by an unlabelled 2-byte `bx lr` stub at 0x021F00C4)
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 */
#include "../include/Obj20401.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 a, u32 b);

void func_021F007C(char *p)
{
    u32 v = ((struct Obj20401 *)p)->f14;

    func_0203FB44(6, (u16)v, (u16)(v >> 16));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02043598(0x10, 0);
}

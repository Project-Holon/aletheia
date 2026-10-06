/*
 * function: func_021B709C
 * address:  0x021B709C
 * packet:   pkt_ov067_021B709C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021B6284  0x021B6284  thumb  ov067
 *   func_020452E8  0x020452E8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj07677.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);

void func_021B709C(u8 *p)
{
    u8 i;
    u32 v;

    for (i = 0; i < 4; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0xa0)));
    }
    func_021B6284((unsigned int *)(p + 0xb0));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f88));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f8C));
    v = ((struct Obj07677 *)p)->f84;
    func_0203FB44(p[0x14], (u16)v, (u16)(v >> 16));
    func_020307B0(p);
}

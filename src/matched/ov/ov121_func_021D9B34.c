/*
 * function: func_021D9B34
 * address: 0x021D9B34
 * packet: pkt_ov121_021D9B34
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021D9B9A.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj02179.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
int func_021D9B34(u8 *p)
{
    u32 q;
    if (((struct Obj02179 *)p)->f24 == 0) {
        q = ((struct Obj02179 *)p)->f8;
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj02179 *)p)->f0);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)(((struct Obj02179 *)p)->f8), (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}

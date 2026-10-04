/*
 * function: func_021C0FF8
 * address: 0x021C0FF8
 * packet: pkt_ov217_021C0FF8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C1036, not a follower.
 * symbols:
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06716.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Descriptor *);
extern void func_020456F8(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021C0FF8(u8 *p,int visible)
{
    if (((struct Obj06716 *)p)->f1C==0 && visible!=0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_02045334(d);
        func_02045374(d);
        func_02041B6C(func_02045730(d));
    } else if (((struct Obj06716 *)p)->f1C!=0 && visible==0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_020456F8(d);
        func_02041B6C(func_02045730(d));
    }
    ((struct Obj06716 *)p)->f1C=visible;
}

/*
 * function: func_021F94B0
 * address: 0x021F94B0
 * packet: pkt_ov132_021F94B0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj03817.h"
typedef unsigned char u8;
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021F94B0(u8 *p)
{
    if (((struct Obj03817 *)p)->fD8) {
        func_0201CE48(((struct Obj03817 *)p)->fD8);
        ((struct Obj03817 *)p)->fD8 = 0;
    }
    if (((struct Obj03817 *)p)->fE0) {
        func_02045808(((struct Obj03817 *)p)->fE0);
        ((struct Obj03817 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03817 *)p)->fD0), 0);
    func_02045334(((struct Obj03817 *)p)->fD0);
}

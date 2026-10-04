/*
 * function: func_021BA0B0
 * address: 0x021BA0B0
 * packet: pkt_ov214_021BA0B0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021BA0DA.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj14700.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor; struct Cfg; struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021BA0B0(int unused, char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(((struct Obj14700 *)p)->f6C), 15);
    d = ((struct Obj14700 *)p)->f6C;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
}

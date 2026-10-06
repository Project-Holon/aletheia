/*
 * function: func_021FD1E0
 * address:  0x021FD1E0
 * packet:   pkt_021FD1E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202940  0x02202940  thumb  ov135
 *   sub_020452E8   0x020452E8  arm
 *   sub_020456F8   0x020456F8  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *
 * Tears down the p+0xd90 array of sixteen window handles, each a 020456F8/
 * 02045730/020409B4/020452E8 group, plus the two p+0xd50/p+0xd54 handles
 * and the p+0xd40 window when *(u32 *)(p + 0x12fc) is clear.
 */
#include "../include/Obj03069.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct Obj;
extern void func_02202940(struct Obj *p);
struct Descriptor;
extern u32 sub_020452E8(struct Descriptor *d);
extern void sub_020456F8(struct Descriptor *d);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);

void func_021FD1E0(u8 *p)
{
    u32 h;
    s32 i;

    func_02202940((struct Obj *)(p + 0xfa0));
    sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD40));
    if (((struct Obj03069 *)p)->f12FC == 0) {
        h = ((struct Obj03069 *)p)->fD54;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        h = ((struct Obj03069 *)p)->fD50;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD54));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD50));
    }
    for (i = 0; i < 0x10; i++) {
        h = *(u32 *)(p + i * 4 + 0xd90);
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(*(u32 *)(p + i * 4 + 0xd90)));
    }
}

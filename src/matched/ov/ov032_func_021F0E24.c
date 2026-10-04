/*
 * function: func_021F0E24
 * address:  0x021F0E24
 * packet:   pkt_ov032_021F0E24
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0E24  0x021F0E24  thumb
 *   func_0204B878  0x0204B878  arm
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;

typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021F0E24(char *p)
{
    if (((struct Obj00007 *)p)->f7C == 0) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0x10);
    } else {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2CC), 0xd);
    }
    if (((struct Obj00007 *)p)->f7C + ((struct Obj00007 *)p)->f7D < ((struct Obj00007 *)p)->f7B) {
        func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x11);
        return;
    }
    func_0204B878((struct Obj *)(((struct Obj00007 *)p)->f2D0), 0x14);
}

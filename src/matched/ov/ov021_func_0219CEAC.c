/*
 * function: func_0219CEAC
 * address:  0x0219CEAC
 * packet:   pkt_ov021_0219CEAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219CB24  0x0219CB24  thumb  ov021
 */
#include "../include/Obj03117.h"
#include "../include/Obj07477.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);

void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < ((struct Obj07477 *)t)->f6)) {
            return;
        }
        for (; i < ((struct Obj07477 *)t)->f6; i++, p += 5) {
            if (p[4] != 0 && ((struct Obj03117 *)p)->f0 == 1) {
                ((struct Obj03117 *)p)->f0 = 0;
                func_0219CB24((u8 *)obj, p[4], ((struct Obj03117 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}

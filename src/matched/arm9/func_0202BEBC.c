/*
 * function: func_0202BEBC
 * address:  0x0202BEBC
 * packet:   pkt_0202BEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls func_0202BFF0 when the object's +0 word is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEBC.c \
 *       --func func_0202BEBC --addr 0x0202BEBC --thumb --cc 1.1p1
 */
#include "../include/Obj02602.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void func_0202BFF0(struct Obj *o);

void func_0202BEBC(u8 *p)
{
    if (((struct Obj02602 *)p)->f0 != 0) {
        func_0202BFF0((struct Obj *)p);
    }
}

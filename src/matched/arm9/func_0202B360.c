/*
 * function: func_0202B360
 * address:  0x0202B360
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +4 pointer and then the object itself through the heap
 * release.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B360.c \
 *       --func func_0202B360 --addr 0x0202B360 --thumb --cc 1.1p1
 */
#include "../include/Obj15832.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);

void func_0202B360(u8 *p)
{
    func_020307B0(((struct Obj15832 *)p)->f4);
    func_020307B0(p);
}

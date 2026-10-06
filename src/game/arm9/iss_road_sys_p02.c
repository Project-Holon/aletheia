/*
 * file:     iss_road_sys_p02.c
 * unit:     yes
 * function: func_0202B20C
 * address:  0x0202B20C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When the object is idle, marks it started, clears its +4 value and
 * refreshes it through func_0202B2BC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B20C.c \
 *       --func func_0202B20C --addr 0x0202B20C --thumb --cc 1.1p1
 */
#include "../../matched/include/Obj08802.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202B2BC(u8 *p);

void func_0202B20C(u8 *p)
{
    if (((struct Obj08802 *)p)->f0 == 0) {
        ((struct Obj08802 *)p)->f0 = 1;
        ((struct Obj08802 *)p)->f4 = 0;
        func_0202B2BC(p);
    }
}

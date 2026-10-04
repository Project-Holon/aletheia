/*
 * function: func_0202B230
 * address:  0x0202B230
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object is active, polls it and either advances or retreats.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B230.c \
 *       --func func_0202B230 --addr 0x0202B230 --thumb --cc 1.1p1

 * Closed by the `matched` class: 0x0202B254 was filed as an EXACT entry this wave (pkt_0202B230).
 */
#include "../include/Obj03001.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202B254(u8 *p);
extern void func_0202B28C(u8 *p);
extern void func_0202B2A4(u8 *p);

void func_0202B230(u8 *p)
{
    if (((struct Obj03001 *)p)->f0 == 0) {
        return;
    }
    if (func_0202B254(p) != 0) {
        func_0202B28C(p);
    } else {
        func_0202B2A4(p);
    }
}

/*
 * function: func_0202B404
 * address:  0x0202B404
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object is active and its +0x10 and +0x12 halfwords differ,
 * latches the new value and re-resolves the current record.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B404.c \
 *       --func func_0202B404 --addr 0x0202B404 --thumb --cc 1.1p1
 */
#include "../include/Obj02009.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0202B49C(u8 *p, u32 id);

void func_0202B404(u8 *p)
{
    u16 a;
    u16 b;

    if (((struct Obj02009 *)p)->fC == 0) {
        return;
    }
    a = ((struct Obj02009 *)p)->f10;
    b = ((struct Obj02009 *)p)->f12;
    if (a == b) {
        return;
    }
    ((struct Obj02009 *)p)->f10 = b;
    func_0202B49C(p, ((struct Obj02009 *)p)->f10);
}

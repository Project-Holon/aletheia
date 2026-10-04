/*
 * function: func_0217FD88
 * address:  0x0217FD88
 * packet:   pkt_ov019_0217FD88
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217FCA4  0x0217FCA4  thumb  ov019
 */
#include "../include/Obj04188.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_0217FCA4(u8 *p);

u8 *func_0217FD88(u8 *base)
{
    int i;
    int best = 0;
    u8 *e;

    for (i = 0; i < 10; i++) {
        e = base + i * 20;
        if (*(int *)&((struct Obj04188 *)e)->fC == 0)
            return e;
        if (((struct Obj04188 *)e)->f10 < *(u16 *)(base + best * 20 + 16))
            best = i;
    }
    e = base + best * 20;
    func_0217FCA4(e);
    return e;
}

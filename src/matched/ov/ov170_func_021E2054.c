/*
 * function: func_021E2054
 * address: 0x021E2054
 * packet: pkt_ov170_021E2054
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov170/box2_seq.c and filed here.
 */

#include "../include/Obj12157.h"

struct BoxCountWork {
    char pad[0xA18C];
    int count;
};

int func_021E2054(void *p);

int func_021E2054(void *p)
{
    struct BoxCountWork *w = (struct BoxCountWork *)((struct Obj12157 *)p)->f2C;
    int v = w->count;
    if (v == 0)
        return ((struct Obj12157 *)p)->f28;
    w->count = v - 1;
    return 4;
}

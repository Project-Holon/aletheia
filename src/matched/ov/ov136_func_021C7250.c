/*
 * function: func_021C7250
 * address: 0x021C7250
 * packet: pkt_ov136_021C7250
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 021C7296 halfword is zero alignment padding.
 */
#include "../include/Obj00412.h"
typedef unsigned char u8;
struct Control {
    u8 enabled : 1;
    u8 mode : 7;
    u8 action : 4;
    u8 phase : 4;
    u8 a, b;
};
int func_021C7250(u8 *p, int v, int w)
{
    struct Control *q = (struct Control *)(*(u8 * *)&((struct Obj00412 *)p)->f8 + 0x300);
    q->enabled = 0;
    q->mode = (u8)v;
    q->action = 1;
    q->phase = 0;
    q->a = 0;
    q->b = 0;
    *(int *)&((struct Obj00412 *)p)->f28 = w;
    return 5;
}

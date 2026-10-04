/*
 * function: func_021EA65C
 * address:  0x021EA65C
 * packet:   pkt_ov093_021EA65C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA55C  0x021EA55C  thumb  ov093
 *   func_021EA758  0x021EA758  thumb  ov093
 */
#include "../include/Obj13561.h"
typedef unsigned int u32;

struct H;

extern void func_021EA55C(struct H *p, int a);
extern void func_021EA758(u32 *p, u32 a2);

void func_021EA65C(char *p, struct H *h)
{
    func_021EA55C(h, *(int *)&((struct Obj13561 *)p)->fAC);
    func_021EA758((u32 *)p, ((struct Obj13561 *)p)->fAC);
}

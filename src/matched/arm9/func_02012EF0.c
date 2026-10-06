/*
 * function: func_02012EF0
 * address:  0x02012EF0
 * packet:   pkt_02012EF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: sub_020071CC(*p, 0x3a).
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *func_02012EF0(void **p)
{
    return sub_020071CC(*p, 0x3a);
}

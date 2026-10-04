/*
 * function: func_02012EFC
 * address:  0x02012EFC
 * packet:   pkt_02012EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: sub_020071CC(*p, 0x3b).
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 */

extern void *sub_020071CC(void *ctrl, unsigned int id);

void *func_02012EFC(void **p)
{
    return sub_020071CC(*p, 0x3b);
}

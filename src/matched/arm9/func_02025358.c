/*
 * function: func_02025358
 * address:  0x02025358
 * packet:   pkt_02025358
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: func_020307B0(p).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02025358(void *p)
{
    func_020307B0(p);
}

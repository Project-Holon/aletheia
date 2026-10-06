/*
 * function: func_0201A364
 * address:  0x0201A364
 * packet:   pkt_0201A364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb argument-shuffling tail-call thunk: func_02048F4C(b, 0x69, a).
 *
 * symbols:
 *   func_02048F4C  0x02048F4C  arm
 */

typedef unsigned int   u32;
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);

void func_0201A364(int a, unsigned int b)
{
    func_02048F4C((void *)b, 0x69, a);
}

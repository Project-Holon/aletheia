/*
 * function: func_02034FE8
 * address:  0x02034FE8
 * packet:   pkt_02034FE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   func_02034FD4 0x02034FD4  arm
 *
 * byte-correct (28 bytes) but capped at MATCH: same unlabelled-leaf tail
 * target as func_02034F84, at 0x02034FD4 (the bit-test accessor, sibling of
 * 0x02034F74).  Needs a layout/function_starts.txt seed.
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern void func_02034FD4(void *p, u32 v);

void func_02034FE8(u32 v)
{
    func_02034FD4((void *)d_021469BC[0], v);
}

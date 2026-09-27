/*
 * function: func_02034FB8
 * address:  0x02034FB8
 * packet:   pkt_02034FB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   func_02034FA0 0x02034FA0  arm
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern void func_02034FA0(void *p, u32 v);

void func_02034FB8(u32 v)
{
    func_02034FA0((void *)d_021469BC[0], v);
}

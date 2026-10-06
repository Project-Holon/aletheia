/*
 * function: func_0204D53C
 * address:  0x0204D53C
 * packet:   pkt_0204D510
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020643A4  0x020643A4  arm
 *
 * The same 0xc-biased tail call to the other callee of the pair.
 */

typedef unsigned char  u8;

struct CellAnim;
extern void func_020643A4(struct CellAnim *anim);

void func_0204D53C(u8 *a0)
{
    func_020643A4((struct CellAnim *)(a0 + 0xc));
}

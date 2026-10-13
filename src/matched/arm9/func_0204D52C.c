/*
 * unit:     no
 * function: CLACT_ResetCellAnim
 * address:  0x0204D52C
 * packet:   pkt_0204D510
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 */

struct CellAnim;
extern void func_020643A4(struct CellAnim *anim);
void CLACT_ResetCellAnim(void *p){ func_020643A4((struct CellAnim *)((char *)p + 0xc)); }


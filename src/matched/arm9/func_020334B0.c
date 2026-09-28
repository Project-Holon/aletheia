/*
 * function: func_020334B0
 * address:  0x020334B0
 * packet:   pkt_020334B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020337B8  0x020337B8  arm
 *
 * Tail-call accessor, the sibling of func_02033478: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r1 plus that word
 * as the third argument of func_020337B8.  The loaded word lands in r2
 * (not r3 like func_02033494), which is what fixes the arity at three.
 * Unlabelled in the listing (it saves no lr), so it is invisible to
 * `sole-ref/code` until this entry exists; it is the witness that
 * unblocks the thumb caller func_021DFE00.
 */

extern void func_020337B8(int, int, int);
void func_020334B0(int a0, int a1){ func_020337B8((int)a0, (int)a1, (int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520))); }

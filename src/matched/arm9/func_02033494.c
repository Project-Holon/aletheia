/*
 * function: func_02033494
 * address:  0x02033494
 * packet:   pkt_02033494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020336B8  0x020336B8  arm
 *
 * Tail-call accessor, the sibling of func_02033478: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r2 plus that word
 * as the fourth argument of func_020336B8.  Unlabelled in the listing (it
 * saves no lr), so it is invisible to `sole-ref/code` until this entry
 * exists; it is the witness that unblocks the thumb caller func_021DFE00.
 */

typedef unsigned int   u32;
extern int func_020336B8(u32 a0, u32 a1, u32 a2, void *a3);
void func_02033494(int a0, int a1, int a2, int a3){ func_020336B8((int)a0, (int)a1, (int)a2, (void *)((int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520)))); }

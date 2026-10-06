/*
 * function: func_0202C0C0
 * address:  0x0202C0C0
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk into func_0202C204, with the callee's ISA
 * carried in the low bit of the pool word (docs/idioms/
 * tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the listing and absent
 * from the worklist; filed from the bytes.  src/pending/func_0202B704.c is
 * blocked on this address and now has it as a `matched` witness.
 *
 * symbols:
 *   func_0202C204  0x0202C204  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0C0.c \
 *       --func func_0202C0C0 --addr 0x0202C0C0 --thumb --cc 1.1p1
 */

typedef unsigned int   u32;
extern void func_0202C204(u32 *p);

void func_0202C0C0(u32 *a0)
{
    func_0202C204(a0);
}

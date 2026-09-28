/*
 * function: func_0202C0C8
 * address:  0x0202C0C8
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk into func_0202C218.  Unlabelled in the listing
 * and absent from the worklist; filed from the bytes.  src/pending/
 * func_0202B7E0.c is blocked on this address and now has it as a `matched`
 * witness.
 *
 * symbols:
 *   func_0202C218  0x0202C218  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0C8.c \
 *       --func func_0202C0C8 --addr 0x0202C0C8 --thumb --cc 1.1p1
 */

extern void func_0202C218(void);

void func_0202C0C8(void)
{
    func_0202C218();
}

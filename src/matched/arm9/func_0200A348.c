/*
 * function: func_0200A348
 * address:  0x0200A348
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four bytes of code and a pool word: the plain Thumb tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  It carries no label in the
 * generated listing (it saves nothing), so it was read out of the bytes; it
 * sits between func_0200A338 and func_0200A350 at the end of its packet.
 * Because the pool word is loaded into r3 to be branched through, the callee
 * can take at most r0..r2, which is what the pass-through declares.
 */

extern void func_0200A400(void *a0, void *a1, void *a2);

void func_0200A348(void *a0, void *a1, void *a2)
{
    func_0200A400(a0, a1, a2);
}

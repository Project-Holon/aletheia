/*
 * function: func_021C88A4
 * address:  0x021C88A4
 * packet:   pkt_ov093_021C88A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * BLOCKER: byte-identical (MATCH), one wildcarded ABS32: the tail-call pool
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).
 *
 * symbols:
 *   func_021CC9AC   0x021CC9AC  thumb  ov093
 */

extern void *func_021CC9AC(char *p, int a, int b);

void *func_021C88A4(char *p, int a, int b)
{
    return func_021CC9AC(p + 0x1D74, a, b);
}

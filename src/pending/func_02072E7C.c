/*
 * function: func_02072E7C
 * address:  0x02072E7C
 * packet:   pkt_02072D20
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02073438   0x02073438  arm
 *
 * blocker:  own-pool.  +000C ABS32 func_02073438
 *           -> unresolved: 02073438 (arm, from name) has no witness outside
 *              02072E7C..02072E8C
 *           A raw word scan of the whole arm9 region finds 0x02073438 exactly
 *           once, at 0x02072E88 - this function's own pool word, inside the
 *           compared range - so `literal` has no witness to offer, `label`
 *           needs a branch from outside the range and the only `bx ip` that
 *           reaches the callee is the one in this body, and `matched` needs an
 *           EXACT entry reproducing the callee's own bytes, which is a 76-byte
 *           function outside this band.  Nothing in the C changes when that
 *           entry lands; this file graduates for free.
 *
 * One field load and a tail call: `func_02073438(*p)`.  The two instructions
 * after the pool load are the original's order - target address into ip
 * first, then the argument - and it is only reproduced under the
 * `compiler: ../2.0/sp2` pin above.  dsi/1.1p1 emits the same three
 * instructions in the other order (`ldr r0, [r0]` / `ldr ip, [pc]`), a
 * 5-byte DIFF recorded in docs/notes/lane6_band0_64_residues.c.txt; the pin
 * is the same "kept constants"/scheduling family already in force for
 * src/matched/func_02074A6C.c in this region.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02072E7C.c \
 *       --func func_02072E7C --addr 0x02072E7C --arm --cc ../2.0/sp2
 *   -> MATCH, compiled 16 = original 16, 0 concrete differences, 1 wildcard
 */

extern void func_02073438(int v);

void func_02072E7C(int *p)
{
    func_02073438(*p);
}

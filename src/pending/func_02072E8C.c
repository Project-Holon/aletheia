/*
 * function: func_02072E8C
 * address:  0x02072E8C
 * packet:   pkt_02072D20
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02073484   0x02073484  arm
 *
 * blocker:  own-pool.  +000C ABS32 func_02073484
 *           -> unresolved: 02073484 (arm, from name) has no witness outside
 *              02072E8C..02072E9C
 *           Raw word scan: 0x02073484 occurs exactly once in the arm9 region,
 *           at 0x02072E98, this function's own pool word.  Same wall as its
 *           twin func_02072E7C at 0x02072E7C.  Nothing in this C changes when
 *           0x02073484 gets a manifest entry.
 *
 * THIS FILE IS THE BLOCKER NAMED IN src/pending/func_02005DE4.c
 * ============================================================
 * That park is capped on `+000E THM_CALL func_02072E8C -> unresolved: 02072E8C
 * (arm, from name) has no witness outside 02005DE4..02005DF8`, and the pair is
 * a WALL, not a promotion: this function is byte-correct but can never reach
 * EXACT, because its own single relocation site (the ABS32 to its callee) has
 * no outside witness - see the blocker line above.  A MATCH park is not a
 * witness for the `matched` class (docs/AGENT-BRIEF.md section 5), so filing
 * 0x02072E8C cannot resolve 0x02005DE4's site, and the park at
 * src/pending/func_02005DE4.c stays parked.  Reported in this lane's report
 * under parked[] with this evidence.
 *
 * One field load and a tail call: `func_02073484(*p)`.  The instruction order
 * (pool load into ip first, argument second) reproduces only under the
 * `compiler: ../2.0/sp2` pin; dsi/1.1p1 emits the argument load first, a
 * 5-byte DIFF that docs/notes/lane6_band0_64_residues.c.txt already records
 * for this address and its twin.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02072E8C.c \
 *       --func func_02072E8C --addr 0x02072E8C --arm --cc ../2.0/sp2
 *   -> MATCH, compiled 16 = original 16, 0 concrete differences, 1 wildcard
 */

extern void func_02073484(int v);

void func_02072E8C(int *p)
{
    func_02073484(*p);
}

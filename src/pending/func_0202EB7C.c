/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0202EB7C
 * address:  0x0202EB7C
 * packet:   pkt_0202EB7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * All 30 concrete bytes are right; the call to func_0202EB9C is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when func_0202EB9C itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing (disasm.py only labels a prologue
 * that saves lr, and this one's first instruction is not visible from here).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202EB7C.c \
 *       --func func_0202EB7C --addr 0x0202EB7C --cc 1.1p1 --thumb
 */

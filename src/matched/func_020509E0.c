/*
 * function: func_020509E0
 * address:  0x020509E0
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The second arm of the four-entry handler table func_02050984 dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/func_02050984.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E0.c \
 *       --func func_020509E0 --addr 0x020509E0 --cc 1.1p1 --arm
 */

int func_020509E0(void)
{
    return 1;
}

/*
 * function: BILLBOARD_ACT_CmdEnd
 * address:  0x020509E0
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The second arm of the four-entry handler table BILLBOARD_ACT_GetControlHandler dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/BILLBOARD_ACT_GetControlHandler.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdEnd.c \
 *       --func BILLBOARD_ACT_CmdEnd --addr 0x020509E0 --cc 1.1p1 --arm
 */

int BILLBOARD_ACT_CmdEnd(void)
{
    return 1;
}

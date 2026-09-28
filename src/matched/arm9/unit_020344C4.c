/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020344C4
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020344C4
 *
 * A single instruction: `bx lr`. An empty function body, kept as a real
 * entry point because it is called through a pointer field elsewhere in
 * this packet (sub_020344C8 calls it once per loop iteration).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020344C4.c \
 *       --addr 0x020344C4 --arm
 */

void sub_020344C4(void)
{
}

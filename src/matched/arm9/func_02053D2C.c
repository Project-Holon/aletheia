/*
 * function: SPL_EMITTER_Noop
 * address:  0x02053D2C
 * packet:   pkt_02053218
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm7tdmi
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A do-nothing handler row of the 3D rig: four bytes, a bare `bx lr` and no
 * frame at all.  It is one of the table rows that src/pending/SPL_EMITTER_UpdateSubX.c
 * and src/pending/SPL_EMITTER_UpdateSubB.c name in their pool words, which is why it
 * is reached only through a pool word and never by a direct branch.
 *
 * The -proc arm7tdmi in flags: is the documented hint for this packet
 * (layout/proc_hints.txt); it is the whole flags line the header carries and
 * the one match.py/csrc.py compile with.  The empty body has no epilogue to
 * distinguish the two procs, so the hint is taken from the packet rather
 * than re-measured here.
 */

void SPL_EMITTER_Noop(void)
{
}

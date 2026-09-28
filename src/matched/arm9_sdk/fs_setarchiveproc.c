/*
 * function: FS_SetArchiveProc
 * address:  0x0207A5A8
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (32 bytes, no relocation):
 *   cmp  r2, #0
 *   moveq r1, #0
 *   beq  +8
 *   cmp  r1, #0
 *   moveq r2, #0
 *   str  r1, [r0, #0x54]
 *   str  r2, [r0, #0x58]
 *   bx   lr
 *
 * A zero flag clears the proc; a zero proc clears the flag.  The two are
 * stored as a complementary pair.
 */

typedef unsigned int u32;

void FS_SetArchiveProc(void *arc, u32 proc, u32 flags)
{
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    *(u32 *)((char *)arc + 0x54) = proc;
    *(u32 *)((char *)arc + 0x58) = flags;
}

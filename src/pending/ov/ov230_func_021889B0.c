/*
 * function: func_021889B0
 * address:  0x021889B0
 * packet:   pkt_ov230_021889B0
 * region:   ov230
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 * blocked:  every concrete byte matches; the one PC24 site (bne at +0x08)
 *           targets 0x02188A48, an unlabelled ARM decoder in ov230 (the
 *           follower recorded in ov230_func_02188A0C.c's extent line). No
 *           listing labels it (sole-ref/code and label refuse a loc_), so it
 *           stays wildcarded until 0x02188A48 is filed as its own leaf
 *           (pkt_ov230_02188A48). The extent's other 40 bytes are the data
 *           table the decoder walks, not code (hence the *).
 * blocker:  0x02188A48 (ov230, ARM, 256 B incl. pool, unlabelled; outside
 *           wave 82 lane R3's write set, so not filed). Best C so far is
 *           scratchpad/retry-pass-20261004/w82/R3/leaf_ov230_02188A48.c.txt:
 *           DIFF 113 B, 248/256. Levers found: the pool word 0x021899A0 is
 *           ov230's bss start (a symbol, d_021899A0, also pooled at
 *           0x02188BCC/0x02188C5C), not a constant (as a constant it folds
 *           with -0x1600); computing p = t[0]-0x1600 before size splits the
 *           ldm into ldr [t,#4]; ldr [t]. Residue: case 1/3's tail
 *           (str r1,[p]; bic key) cross-jumps into default's identical tail
 *           (-8 B), and p/size/key/d_021899A0 sit in r4/r6/r7/r8 instead of
 *           r8/r4/r6/r7. Permuter (300, --types) found nothing valid.
 * note:     position-independent entry: r0 = pc + 4 (0x021889BC, the
 *           descriptor table that follows the code), always nonzero, so the
 *           bne always reaches the unlabelled decoder at 0x02188A48 with r0
 *           naming the table. The 40 bytes after the bne are that table
 *           (four {0x02189EC0+k*0x3C, 0x0218AFC4} pairs and a zero word pair),
 *           data rather than code.
 * symbols:
 *   func_02188A48  0x02188A48  arm  ov230
 */

extern void func_02188A48(void);

asm void func_021889B0(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     func_02188A48
}

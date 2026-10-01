/*
 * function: func_021552DC
 * address:  0x021552DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 *
 * symbols:
 *   func_0205CCD8  0x0205CCD8  arm
 */

extern int func_0205CCD8(void);

int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}

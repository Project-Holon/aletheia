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
 * Returns three less the word the ARM veneer at 0x0205CCD8 returns.
 *
 * symbols:
 *   veneer_0205CCD8  0x0205CCD8  arm
 */

extern int veneer_0205CCD8(void);

int func_021552DC(void)
{
    return 3 - veneer_0205CCD8();
}

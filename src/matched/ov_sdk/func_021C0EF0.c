/*
 * function: DWCi_Flag
 * address:  0x021C0EF0
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_Flag   0x021C0EF0  arm
 *
 * Test the argument against bits 4.. of the word at +0x08.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_Flag.c \
 *       --func DWCi_Flag --addr 0x021C0EF0 --region ov016 --cc dsi/1.1p1 --arm
 */

int DWCi_Flag(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    return (v & (p[2] >> 4)) != 0;
}

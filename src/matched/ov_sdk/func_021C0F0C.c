/*
 * function: DWCi_EndUtility
 * address:  0x021C0F0C
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EndUtility   0x021C0F0C  arm
 *
 * Set byte +0x01 of the global object to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_EndUtility.c \
 *       --func DWCi_EndUtility --addr 0x021C0F0C --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_EndUtility(void)
{
    unsigned char *p = (unsigned char *)0x021DE56C;
    p[1] = 1;
}

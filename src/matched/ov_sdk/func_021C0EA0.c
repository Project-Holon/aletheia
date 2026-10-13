/*
 * function: DWCi_GetParam2_
 * address:  0x021C0EA0
 * packet:   pkt_021C0E64
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GetParam2_   0x021C0EA0  arm
 *
 * Hand back fields +0x18 and +0x1c through two optional out pointers.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_GetParam2_.c \
 *       --func DWCi_GetParam2_ --addr 0x021C0EA0 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_GetParam2_(unsigned int *a, unsigned int *b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    if (a)
        *a = p[6];
    if (b)
        *b = p[7];
}

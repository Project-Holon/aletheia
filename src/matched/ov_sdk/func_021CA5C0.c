/*
 * function: DWCi_SetListReturn
 * address:  0x021CA5C0
 * packet:   pkt_021CA5C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SetListReturn   0x021CA5C0  arm
 *
 * Store a byte at 0x021DE5EC + 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SetListReturn.c \
 *       --func DWCi_SetListReturn --addr 0x021CA5C0 --region ov016 --cc dsi/1.1p1 --arm
 */

void DWCi_SetListReturn(unsigned char v)
{
    unsigned char *p = (unsigned char *)0x021DE5EC;
    p[1] = v;
}

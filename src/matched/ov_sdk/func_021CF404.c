/*
 * function: DWCi_SETTIGNlGet
 * address:  0x021CF404
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTIGNlGet   0x021CF404  arm
 *
 * Address of the object behind the global pointer, +0x400.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTIGNlGet.c \
 *       --func DWCi_SETTIGNlGet --addr 0x021CF404 --region ov016 --cc dsi/1.1p1 --arm
 */

char *DWCi_SETTIGNlGet(void)
{
    return *(char **)0x021DE644 + 0x400;
}

/*
 * function: DWCi_WINlGet
 * address:  0x021D1568
 * packet:   pkt_021D1568
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_WINlGet   0x021D1568  arm
 *
 * Signed byte at +0x1b of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_WINlGet.c \
 *       --func DWCi_WINlGet --addr 0x021D1568 --region ov016 --cc dsi/1.1p1 --arm
 */

signed char DWCi_WINlGet(void)
{
    return *(signed char *)(*(char **)0x021DE658 + 0x1b);
}

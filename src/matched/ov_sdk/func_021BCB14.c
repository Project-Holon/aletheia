/*
 * function: DWCi_BTNlGet
 * address:  0x021BCB14
 * packet:   pkt_021BCB14
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlGet   0x021BCB14  arm
 *
 * Signed byte at +0x16 of a two-level global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_BTNlGet.c \
 *       --func DWCi_BTNlGet --addr 0x021BCB14 --region ov016 --cc dsi/1.1p1 --arm
 */

signed char DWCi_BTNlGet(void)
{
    return *(signed char *)(*(char **)0x021DE508 + 0x16);
}

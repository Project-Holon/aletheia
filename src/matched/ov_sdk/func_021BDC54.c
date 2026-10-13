/*
 * function: DWCi_KBlGet
 * address:  0x021BDC54
 * packet:   pkt_021BDC54
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_KBlGet   0x021BDC54  arm
 *
 * Unsigned byte at +0x11c of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_KBlGet.c \
 *       --func DWCi_KBlGet --addr 0x021BDC54 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char DWCi_KBlGet(void)
{
    return *(unsigned char *)(*(char **)0x021DE55C + 0x11c);
}

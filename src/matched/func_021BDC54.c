/*
 * function: func_021BDC54
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
 *   func_021BDC54   0x021BDC54  arm
 *
 * Unsigned byte at +0x11c of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC54.c \
 *       --func func_021BDC54 --addr 0x021BDC54 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char func_021BDC54(void)
{
    return *(unsigned char *)(*(char **)0x021DE55C + 0x11c);
}

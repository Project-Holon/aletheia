/*
 * function: func_021CE998
 * address:  0x021CE998
 * packet:   pkt_021CE6F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CE998   0x021CE998  arm
 *
 * Read the byte at +0x1d of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE998.c \
 *       --func func_021CE998 --addr 0x021CE998 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned char func_021CE998(void)
{
    return *(unsigned char *)(*(char **)0x021DE63C + 0x1d);
}

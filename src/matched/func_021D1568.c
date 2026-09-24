/*
 * function: func_021D1568
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
 *   func_021D1568   0x021D1568  arm
 *
 * Signed byte at +0x1b of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D1568.c \
 *       --func func_021D1568 --addr 0x021D1568 --region ov016 --cc dsi/1.1p1 --arm
 */

signed char func_021D1568(void)
{
    return *(signed char *)(*(char **)0x021DE658 + 0x1b);
}

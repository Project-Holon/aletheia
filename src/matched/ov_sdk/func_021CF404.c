/*
 * function: func_021CF404
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
 *   func_021CF404   0x021CF404  arm
 *
 * Address of the object behind the global pointer, +0x400.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CF404.c \
 *       --func func_021CF404 --addr 0x021CF404 --region ov016 --cc dsi/1.1p1 --arm
 */

char *func_021CF404(void)
{
    return *(char **)0x021DE644 + 0x400;
}

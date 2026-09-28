/*
 * function: func_021CF418
 * address:  0x021CF418
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CF418   0x021CF418  arm
 *
 * Store a byte at +0x4f5 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CF418.c \
 *       --func func_021CF418 --addr 0x021CF418 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021CF418(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE644 + 0x4f5) = v;
}

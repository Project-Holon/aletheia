/*
 * function: func_021CF42C
 * address:  0x021CF42C
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CF42C   0x021CF42C  arm
 *
 * Store a byte at +0x4f6 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CF42C.c \
 *       --func func_021CF42C --addr 0x021CF42C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021CF42C(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE644 + 0x4f6) = v;
}

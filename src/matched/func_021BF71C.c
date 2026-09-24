/*
 * function: func_021BF71C
 * address:  0x021BF71C
 * packet:   pkt_021BF6E0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BF71C   0x021BF71C  arm
 *
 * Store a byte at +0x68 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BF71C.c \
 *       --func func_021BF71C --addr 0x021BF71C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021BF71C(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE560 + 0x68) = v;
}

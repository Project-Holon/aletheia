/*
 * function: func_021BDC68
 * address:  0x021BDC68
 * packet:   pkt_021BDC54
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BDC68   0x021BDC68  arm
 *
 * Store a byte at +0x123 of a global object pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC68.c \
 *       --func func_021BDC68 --addr 0x021BDC68 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021BDC68(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE55C + 0x123) = v;
}

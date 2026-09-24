/*
 * function: func_021BDC7C
 * address:  0x021BDC7C
 * packet:   pkt_021BDC7C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BDC7C   0x021BDC7C  arm
 *
 * Store a byte at +0x124 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC7C.c \
 *       --func func_021BDC7C --addr 0x021BDC7C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021BDC7C(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE55C + 0x124) = v;
}

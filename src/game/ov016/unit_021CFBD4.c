/*
 * file:     unit_021CFBD4.c
 * function: func_021CFBD4
 * address:  0x021CFBD4
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CFBD4   0x021CFBD4  arm
 *
 * The global pointer at 0x021DE644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CFBD4.c \
 *       --func func_021CFBD4 --addr 0x021CFBD4 --region ov016 --cc dsi/1.1p1 --arm
 */

char *func_021CFBD4(void)
{
    return *(char **)0x021DE644;
}

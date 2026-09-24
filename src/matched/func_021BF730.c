/*
 * function: func_021BF730
 * address:  0x021BF730
 * packet:   pkt_021BF6E0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BF730   0x021BF730  arm
 *
 * True when the global pointer at 0x021DE560 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BF730.c \
 *       --func func_021BF730 --addr 0x021BF730 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021BF730(void)
{
    return *(void **)0x021DE560 != 0;
}

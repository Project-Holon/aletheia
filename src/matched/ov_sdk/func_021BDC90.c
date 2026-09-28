/*
 * function: func_021BDC90
 * address:  0x021BDC90
 * packet:   pkt_021BDC7C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BDC90   0x021BDC90  arm
 *
 * True when the global pointer at 0x021DE55C is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BDC90.c \
 *       --func func_021BDC90 --addr 0x021BDC90 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021BDC90(void)
{
    return *(void **)0x021DE55C != 0;
}

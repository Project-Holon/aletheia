/*
 * function: func_021BCB14
 * address:  0x021BCB14
 * packet:   pkt_021BCB14
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BCB14   0x021BCB14  arm
 *
 * Signed byte at +0x16 of a two-level global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BCB14.c \
 *       --func func_021BCB14 --addr 0x021BCB14 --region ov016 --cc dsi/1.1p1 --arm
 */

signed char func_021BCB14(void)
{
    return *(signed char *)(*(char **)0x021DE508 + 0x16);
}

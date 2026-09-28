/*
 * function: func_021D157C
 * address:  0x021D157C
 * packet:   pkt_021D1568
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D157C   0x021D157C  arm
 *
 * True when the global pointer at 0x021DE658 is non-null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D157C.c \
 *       --func func_021D157C --addr 0x021D157C --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021D157C(void)
{
    return *(void **)0x021DE658 != 0;
}

/*
 * function: func_021C11B8
 * address:  0x021C11B8
 * packet:   pkt_021C11B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C11B8   0x021C11B8  arm
 *
 * True when the global pointer at 0x021DE590 is null.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C11B8.c \
 *       --func func_021C11B8 --addr 0x021C11B8 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021C11B8(void)
{
    return *(void **)0x021DE590 == 0;
}

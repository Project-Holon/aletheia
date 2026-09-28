/*
 * function: func_021D2780
 * address:  0x021D2780
 * packet:   pkt_021D276C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D2780   0x021D2780  arm
 *
 * Read the halfword at the head of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D2780.c \
 *       --func func_021D2780 --addr 0x021D2780 --region ov016 --cc dsi/1.1p1 --arm
 */

unsigned short func_021D2780(void)
{
    return *(unsigned short *)(*(char **)0x021DE65C);
}

/*
 * function: func_021CE6F0
 * address:  0x021CE6F0
 * packet:   pkt_021CE6F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CE6F0   0x021CE6F0  arm
 *
 * Set the byte at +0x604 of the object behind the global pointer to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE6F0.c \
 *       --func func_021CE6F0 --addr 0x021CE6F0 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021CE6F0(void)
{
    *(unsigned char *)(*(char **)0x021DE630 + 0x604) = 1;
}

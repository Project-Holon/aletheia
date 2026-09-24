/*
 * function: func_021BCB44
 * address:  0x021BCB44
 * packet:   pkt_021BCB44
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BCB44 0x021BCB44 arm
 *
 * Store the low byte of the argument at +0x16 of the object behind the global pointer at 0x021DE508.
 * Addresses are Black-image addresses.
 */

void func_021BCB44(int a)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x16) = a;
}

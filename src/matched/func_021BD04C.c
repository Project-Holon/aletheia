/*
 * function: func_021BD04C
 * address:  0x021BD04C
 * packet:   pkt_021BD04C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BD04C 0x021BD04C arm
 *
 * Clear the byte at 0x021DE50C.
 * Addresses are Black-image addresses.
 */

void func_021BD04C(void)
{
    *(unsigned char *)0x021DE50C = 0;
}

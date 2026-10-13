/*
 * function: DWCi_BTNlEnable
 * address:  0x021BCB84
 * packet:   pkt_021BCB84
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlEnable 0x021BCB84 arm
 *
 * Clear the byte at +0x18 of the object behind the global pointer at 0x021DE508.
 * Addresses are Black-image addresses.
 */

void DWCi_BTNlEnable(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 0;
}

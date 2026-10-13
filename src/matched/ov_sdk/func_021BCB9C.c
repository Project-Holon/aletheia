/*
 * function: DWCi_BTNlDisable
 * address:  0x021BCB9C
 * packet:   pkt_021BCB9C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlDisable 0x021BCB9C arm
 *
 * Set the byte at +0x18 of the object behind the global pointer at 0x021DE508.
 * Addresses are Black-image addresses.
 */

void DWCi_BTNlDisable(void)
{
    *(unsigned char *)(*(char **)0x021DE508 + 0x18) = 1;
}

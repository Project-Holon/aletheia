/*
 * function: DWCi_BTNlIsEnd
 * address:  0x021BCB58
 * packet:   pkt_021BCB58
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlIsEnd 0x021BCB58 arm
 *
 * Report whether +0x19 of the object behind the global pointer at 0x021DE508 is clear (or the pointer is null).
 * Addresses are Black-image addresses.
 */

int DWCi_BTNlIsEnd(void)
{
    unsigned char *p = *(unsigned char **)0x021DE508;

    if (p == 0)
        return 1;
    if (p[0x19] == 0)
        return 1;
    return 0;
}

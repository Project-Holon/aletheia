/*
 * function: DWCi_HLlEnd
 * address:  0x021BD660
 * packet:   pkt_021BD660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HLlEnd 0x021BD660 arm
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE554.
 * Addresses are Black-image addresses.
 */

extern void DWCi_HEAPlFree_(void **mem);

void DWCi_HLlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE554);
}

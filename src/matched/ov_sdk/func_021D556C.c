/*
 * function: DWCi_EFFlEnd
 * address:  0x021D556C
 * packet:   pkt_021D556C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlEnd 0x021D556C arm
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE67C.
 * Addresses are Black-image addresses.
 */

extern void DWCi_HEAPlFree_(void **mem);

void DWCi_EFFlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE67C);
}

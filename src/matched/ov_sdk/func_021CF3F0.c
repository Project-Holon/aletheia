/*
 * function: DWCi_SETTIGNlEnd
 * address:  0x021CF3F0
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTIGNlEnd   0x021CF3F0  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTIGNlEnd.c \
 *       --func DWCi_SETTIGNlEnd --addr 0x021CF3F0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_HEAPlFree_(void **mem);

void DWCi_SETTIGNlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE644);
}

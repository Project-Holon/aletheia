/*
 * function: DWCi_MSGlEnd
 * address:  0x021C0F98
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MSGlEnd   0x021C0F98  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE58C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MSGlEnd.c \
 *       --func DWCi_MSGlEnd --addr 0x021C0F98 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_HEAPlFree_(void **mem);

void DWCi_MSGlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE58C);
}

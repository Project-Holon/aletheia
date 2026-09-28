/*
 * function: func_0208F644
 * address:  0x0208F644
 * packet:   pkt_0208F644
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   DWCi_IsSendableReliable 0x0208F5C8 arm
 */

extern int DWCi_IsSendableReliable(unsigned char aid, unsigned short type);

int func_0208F644(unsigned char aid)
{
    return DWCi_IsSendableReliable(aid, 1);
}

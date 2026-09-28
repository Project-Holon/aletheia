/*
 * function: func_021DF490
 * address:  0x021DF490
 * packet:   pkt_ov175_021DF490
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_ScGetLoginCertificate (TwlDWC/libdwcsc.TWL.HYB.a,
 * dwc_sc.o), ov175.  Store the certificate pointer and report success.
 *
 * symbols:
 *   d_021E4F34  0x021E4F34  data
 */

extern char d_021E4F34[];

int func_021DF490(void **p)
{
    *p = d_021E4F34;
    return 0;
}

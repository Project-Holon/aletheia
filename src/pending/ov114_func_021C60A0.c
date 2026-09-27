/*
 * function: DWCi_Ndi_getDecodeLenBASE64
 * address:  0x021C60A0
 * packet:   pkt_ov114_021C60A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 268, param len.
 */
typedef unsigned long u32;

u32 DWCi_Ndi_getDecodeLenBASE64(int len)
{
    return (len >> 2) * 3;
}

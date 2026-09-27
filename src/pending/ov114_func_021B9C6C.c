/*
 * function: DWCi_Http_CPSCallback
 * address:  0x021B9C6C
 * packet:   pkt_ov114_021B9C6C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcauth.TWL.HYB.a(dwc_http.o).  decl_line 769, param result.
 */
int DWCi_Http_CPSCallback(int result)
{
    if (result & 0x8000)
        result &= ~0x8000;
    return result;
}

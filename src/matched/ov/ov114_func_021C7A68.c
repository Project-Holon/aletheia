/*
 * function: DWCi_Ndi_intToStr
 * address:  0x021C7A68
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_intToStr  0x021BA4E4  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTPi_intToStr(char *p_p, unsigned long n);

void DWCi_Ndi_intToStr(char *p, u32 n)
{
    NHTTPi_intToStr(p, n);
}

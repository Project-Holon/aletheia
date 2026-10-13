/*
 * function: DWCi_Ndi_strToInt
 * address:  0x021C7A5C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_strToInt  0x021BA448  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTPi_strToInt(void);

void DWCi_Ndi_strToInt(void)
{
    NHTTPi_strToInt();
}

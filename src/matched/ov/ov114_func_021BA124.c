/*
 * function: NHTTPi_strnlen
 * address:  0x021BA124
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 *
 * symbols:
 *   STD_GetStringNLength  0x0208CCFC  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void STD_GetStringNLength(void);

void NHTTPi_strnlen(void)
{
    STD_GetStringNLength();
}

/*
 * function: NHTTPi_strcmp
 * address:  0x021BA130
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
 *   STD_CompareString  0x0208CD94  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void STD_CompareString(void);

void NHTTPi_strcmp(void)
{
    STD_CompareString();
}

/*
 * function: NHTTPi_SocRecvRaw
 * address:  0x021BA014
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
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0215F590(void);

void NHTTPi_SocRecvRaw(void)
{
    func_0215F590();
}

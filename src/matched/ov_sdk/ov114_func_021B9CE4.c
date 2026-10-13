/*
 * function: NHTTPi_SocOpen
 * address:  0x021B9CE4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk: g(2, 1, 0) via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0215F428(int, int, int);

void NHTTPi_SocOpen(void)
{
    func_0215F428(2, 1, 0);
}

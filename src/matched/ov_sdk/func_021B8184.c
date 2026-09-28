/*
 * function: func_021B8184
 * address:  0x021B8184
 * packet:   pkt_021B816C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8184   0x021B8184  thumb
 *   func_021DCE2C   0x021DCE2C  data  ov016

 *
 * Forward b to the handler in the global function pointer at 0x021DCE2C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B8184.c \
 *       --func func_021B8184 --addr 0x021B8184 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void (*func_021DCE2C)(int);

void func_021B8184(int a, int b)
{
    func_021DCE2C(b);
}

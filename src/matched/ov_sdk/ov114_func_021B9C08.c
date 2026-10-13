/*
 * function: NHTTPi_kickCommThread
 * address:  0x021B9C08
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk: g(a, 0, 0) via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02085DBC(int, int, int);

void NHTTPi_kickCommThread(int a)
{
    func_02085DBC(a, 0, 0);
}

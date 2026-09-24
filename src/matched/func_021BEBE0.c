/*
 * function: func_021BEBE0
 * address:  0x021BEBE0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEAB8  0x021BEAB8  arm  ov114
 *
 *
 * ov114 tail-call thunk: func_021BEAB8(a, b, 1) via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BEAB8(int, int, int);

void func_021BEBE0(int a, int b)
{
    func_021BEAB8(a, b, 1);
}

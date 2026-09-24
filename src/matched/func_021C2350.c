/*
 * function: func_021C2350
 * address:  0x021C2350
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C1210  0x021C1210  arm  ov114
 *
 *
 * Tail-call thunk to func_021C1210 via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C1210(void);

void func_021C2350(void)
{
    func_021C1210();
}

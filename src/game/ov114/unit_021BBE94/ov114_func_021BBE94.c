/*
 * function: func_021BBE94
 * address:  0x021BBE94
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BBEAC  0x021BBEAC  arm  ov114
 *
 *
 * Tail-call thunk to the unnamed ARM setter at 0x021BBEAC.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BBEAC(void);

void func_021BBE94(u8 *a0)
{
    func_021BBEAC();
}

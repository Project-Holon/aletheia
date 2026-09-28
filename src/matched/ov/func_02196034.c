/*
 * function: func_02196034
 * address:  0x02196034
 * packet:   pkt_02196034
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02196030 with no argument change.
 *
 * symbols:
 *   func_02196030  0x02196030  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02196030();

void func_02196034(void)
{
    func_02196030();
}

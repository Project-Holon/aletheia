/*
 * function: func_021659F0
 * address:  0x021659F0
 * packet:   pkt_ov010_021659F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Ring index of the 30-slot queue (func_021658D4): head byte at +0xB04
 * plus a signed offset, wrapped mod 30 (a negative offset is biased by
 * 30 first). Filed as the callee of 02165A10.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned char u8;

extern int _s32_div_f(int a, int b);

int func_021659F0(u8 *q, int delta)
{
    int h = q[0xB04];

    if (delta < 0)
        return (h + delta + 30) % 30;
    return (h + delta) % 30;
}

/*
 * function: func_021E3E60
 * address:  0x021E3E60
 * packet:   pkt_ov119_021E3E60
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A48C  0x0204A48C  arm
 *   d_021E7CC8     0x021E7CC8  data  ov119  a4
 *   d_021E7D40     0x021E7D40  data  ov119  a4
 *
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of func_021DFDA0's preamble.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int d_021E7CC8;
extern int d_021E7D40;
extern void func_0204A48C(void *, void *, int);

void func_021E3E60(void *p)
{
    func_0204A48C(&d_021E7CC8, &d_021E7D40, *(u16 *)((char *)p + 0x5f4));
}

/*
 * function: func_021BC5A0
 * address:  0x021BC5A0
 * packet:   pkt_ov021_021BC5A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD120  0x021BD120  thumb  ov021
 *   func_021BCBC8  0x021BCBC8  thumb  ov021
 *   func_021BCA64  0x021BCA64  thumb  ov021
 */

typedef unsigned short u16;

extern void func_021BD120(void *p, u16 v);
extern void func_021BCBC8(void *p);
extern void func_021BCA64(void *p);

void func_021BC5A0(void *p, int v)
{
    func_021BD120(p, (u16)v);
    func_021BCBC8(p);
    func_021BCA64(p);
}

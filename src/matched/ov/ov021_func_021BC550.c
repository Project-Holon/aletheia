/*
 * function: func_021BC550
 * address:  0x021BC550
 * packet:   pkt_ov021_021BC550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD120  0x021BD120  thumb  ov021
 *   func_021BD140  0x021BD140  thumb  ov021
 *   func_021BCBC8  0x021BCBC8  thumb  ov021
 *   func_021BCA78  0x021BCA78  thumb  ov021
 */

typedef unsigned short u16;

extern void func_021BD120(void *p, u16 v);
extern int func_021BD140(u16 v);
typedef unsigned char  u8;
extern void func_021BCBC8(char *p);
extern void func_021BCA78(u8 *p);

void func_021BC550(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA78(p);
    }
}

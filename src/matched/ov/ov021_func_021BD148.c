/*
 * function: func_021BD148
 * address:  0x021BD148
 * packet:   pkt_ov021_021BD148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD214  0x021BD214  thumb  ov021
 *   func_021BD234  0x021BD234  thumb  ov021
 *   func_021BD2BC  0x021BD2BC  thumb  ov021
 *   func_021BD250  0x021BD250  thumb  ov021
 *   func_021BD278  0x021BD278  thumb  ov021
 *   func_021BD5F8  0x021BD5F8  thumb  ov021
 */

extern void *func_021BD214(int a);
extern void func_021BD234(void *p);
typedef unsigned char  u8;
extern void func_021BD2BC(u8 *p, int v);
extern void func_021BD250(void *p);
extern void func_021BD278(void *p, int a, int b, int c);
extern void func_021BD5F8(void *p, unsigned int a);

void *func_021BD148(int a0, int a1, int a2, int a3)
{
    void *p = func_021BD214(a0);
    func_021BD234(p);
    func_021BD2BC(p, a0);
    func_021BD250(p);
    func_021BD278(p, a1, a2, a3);
    func_021BD5F8(p, 0);
    return p;
}

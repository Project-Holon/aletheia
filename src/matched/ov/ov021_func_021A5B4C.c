/*
 * function: func_021A5B4C
 * address:  0x021A5B4C
 * packet:   pkt_ov021_021A5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A6738  0x021A6738  thumb  ov021
 *   func_021A672C  0x021A672C  thumb  ov021
 */

typedef unsigned int u32;

void func_021A3AC4(u32 a, u32 v);
void func_021A6738(void *a);
void func_021A672C(void *a);

void func_021A5B4C(u32 *p, int a, int mode)
{
    func_021A3AC4(p[5], a);
    func_021A6738(p);
    if (mode == 2)
        func_021A672C(p);
}

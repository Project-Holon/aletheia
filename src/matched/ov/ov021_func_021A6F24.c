/*
 * function: func_021A6F24
 * address:  0x021A6F24
 * packet:   pkt_ov021_021A6F24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CA4  0x02188CA4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   d_021DDF38  0x021DDF38  data  a4
 */

typedef unsigned int u32;

extern u32 *func_02188CA4(u32 a);
extern void (*const d_021DDF38[])(u32 a, u32 *p);
extern void func_021A3038(u32 a, int *v);

void func_021A6F24(u32 a, int *v)
{
    u32 *p = func_02188CA4(a);
    d_021DDF38[p[0]](a, p);
    func_021A3038(p[1], v);
}

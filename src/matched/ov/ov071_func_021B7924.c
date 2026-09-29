/*
 * function: func_021B7924
 * address:  0x021B7924
 * packet:   pkt_ov071_021B7924
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 */

typedef unsigned int u32;

extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201F548(u32 a);
extern void func_020215EC(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void *func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, u32 v);
extern void func_02045374(void *p);
extern void func_0201F73C(void *p, u32 a, u32 b, u32 c);

void func_021B7924(void **p, void **q)
{
    func_0201F554(5, 1, 0, 0x61);
    func_020215EC(q[0], 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    p[0] = func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(p[0]), 0xff);
    func_02045374(p[0]);
    func_0201F73C(p[0], 0, 1, 0xb);
}

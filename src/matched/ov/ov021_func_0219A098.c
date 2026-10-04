/*
 * function: func_0219A098
 * address:  0x0219A098
 * packet:   pkt_ov021_0219A098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219B0F0  0x0219B0F0  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   d_021D4FA4     0x021D4FA4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 *func_0216D684(u32, u32);
extern u16 func_0219B0F0(void *, int);
extern void func_0216D674(void *p, u16 v);
extern int func_0216DA50(u32);
extern u8 d_021D4FA4[];

int func_0219A098(u32 a, u32 b)
{
    u16 *p;
    int k = 8;
    p = func_0216D684(a, 8);
    p[1] = func_0219B0F0(d_021D4FA4, k - 9);
    *(u32 *)(p + 2) = b;
    func_0216D674((void *)a, 0);
    return func_0216DA50(a);
}

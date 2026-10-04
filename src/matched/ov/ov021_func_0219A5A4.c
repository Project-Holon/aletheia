/*
 * function: func_0219A5A4
 * address:  0x0219A5A4
 * packet:   pkt_ov021_0219A5A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D684(u32, u32);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);
extern void func_02163F10(u32);

void func_0219A5A4(u32 a, u8 b)
{
    u8 *p = func_0216D684(a, 8);
    *p = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
    func_02163F10(a);
}

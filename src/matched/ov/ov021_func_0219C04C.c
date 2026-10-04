/*
 * function: func_0219C04C
 * address:  0x0219C04C
 * packet:   pkt_ov021_0219C04C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern u16 func_0216D608(void *p);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);

int func_0219C04C(u32 a, s8 *s)
{
    u32 o;
    if (s[1] == 9) {
        o = (u32)func_0216DEE0(func_0216D67C((void *)a));
        if (o != 0) {
            s[1] = func_0216D608((void *)o);
        }
    }
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    s[0] = 3;
    return 1;
}

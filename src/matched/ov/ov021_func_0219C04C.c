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
extern u32 func_0216D67C(u32);
extern u32 func_0216DEE0(u32);
extern u16 func_0216D608(u32 o);
extern void func_0216DA50(u32);
extern void func_0216DA7C(u32);

int func_0219C04C(u32 a, s8 *s)
{
    u32 o;
    if (s[1] == 9) {
        o = func_0216DEE0(func_0216D67C(a));
        if (o != 0) {
            s[1] = func_0216D608(o);
        }
    }
    func_0216DA50(a);
    func_0216DA7C(a);
    s[0] = 3;
    return 1;
}

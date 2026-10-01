/*
 * function: func_0219D780
 * address:  0x0219D780
 * packet:   pkt_ov021_0219D780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216DA5C(u32);
extern int func_0216D57C(u32, u32);
extern void func_0216D5A0(u32);

int func_0219D780(u32 a)
{
    if (func_0216DA5C(a) == 1) {
        return 1;
    }
    if (func_0216D57C(a, 0x800) == 0) {
        return 1;
    }
    func_0216D5A0(a);
    return 1;
}

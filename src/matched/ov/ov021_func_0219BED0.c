/*
 * function: func_0219BED0
 * address:  0x0219BED0
 * packet:   pkt_ov021_0219BED0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219BEB4  0x0219BEB4  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0219BEB4(u32 a, u32 b);
extern void func_0219BF3C(int a, u32 v);
extern void func_0216DA50(u32);
extern void func_0216DA7C(u32);

int func_0219BED0(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0219BF3C(a, func_0219BEB4(a, s[1]));
    }
    func_0216DA50(a);
    func_0216DA7C(a);
    s[0]++;
    return 0;
}

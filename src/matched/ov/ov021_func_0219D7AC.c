/*
 * function: func_0219D7AC
 * address:  0x0219D7AC
 * packet:   pkt_ov021_0219D7AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0219D85C  0x0219D85C  thumb  ov021
 *   func_0216DA70  0x0216DA70  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D57C(u32, u32);
extern int func_0219D85C(u32);
extern void func_0216DA70(u32);

void func_0219D7AC(u32 a)
{
    if (func_0216D57C(a, 0x800) != 0 && func_0219D85C(a) == 1) {
        func_0216DA70(a);
    }
}

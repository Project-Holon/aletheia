/*
 * function: func_0219C13C
 * address:  0x0219C13C
 * packet:   pkt_ov021_0219C13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DA50  0x0216DA50  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216DA50(u8 *p);

int func_0219C13C(u32 a, u8 *s)
{
    func_0216DA50((u8 *)a);
    s[0]++;
    return 1;
}

/*
 * function: func_0219C5D0
 * address:  0x0219C5D0
 * packet:   pkt_ov021_0219C5D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219D2F4  0x0219D2F4  thumb  ov021
 *   func_0219CC80  0x0219CC80  thumb  ov021
 *   func_0219CAF4  0x0219CAF4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0216D51C  0x0216D51C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(void *p);
extern void func_0219D2F4(u8 *s);
extern void func_0219CC80(u8 *o);
extern void func_0219CAF4(u8 *s);
extern void func_020307B0(void *p);
extern void func_0216D51C(u8 *p, u32 v);

void func_0219C5D0(u32 a)
{
    u32 s = func_0216D520((void *)a);
    func_0219D2F4((u8 *)s);
    func_0219CC80((u8 *)s);
    func_0219CAF4((u8 *)s);
    func_020307B0((void *)s);
    func_0216D51C((u8 *)a, 0);
}

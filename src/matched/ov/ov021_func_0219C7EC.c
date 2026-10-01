/*
 * function: func_0219C7EC
 * address:  0x0219C7EC
 * packet:   pkt_ov021_0219C7EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C74C  0x0219C74C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D67C(u32);
extern u32 func_0216D520(u32);
extern int func_0219CBD4(u32, u32, u16 *, u16 *);
extern void func_0219C74C(u32 a, u16 e);

void func_0219C7EC(u32 a, u32 b)
{
    u16 t[2];
    func_0219CBD4(func_0216D520(func_0216D67C(a)), b, &t[1], &t[0]);
    func_0219C74C(a, t[1]);
}

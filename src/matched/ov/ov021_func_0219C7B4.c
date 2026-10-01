/*
 * function: func_0219C7B4
 * address:  0x0219C7B4
 * packet:   pkt_ov021_0219C7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219C780  0x0219C780  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } V3;
extern u32 func_0216D67C(u32);
extern u8 *func_0216E3C4(u32);
extern void func_02197CCC(u32, V3 *);
extern u32 func_0219C780(u32 a, V3 *b, int c, u32 d, u16 e, u16 g);

void func_0219C7B4(u32 a, u16 e, u16 g)
{
    u32 o = func_0216D67C(a);
    u8 *d = func_0216E3C4(a);
    V3 v;
    func_02197CCC(a, &v);
    func_0219C780(o, &v, d[7], d[9], e, g);
}

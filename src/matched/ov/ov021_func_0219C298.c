/*
 * function: func_0219C298
 * address:  0x0219C298
 * packet:   pkt_ov021_0219C298
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0219C180  0x0219C180  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void func_0216D88C(u32 a, Vec *v);
extern int func_0219C180(u32 a, Vec *p, int b, int c);

int func_0219C298(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C(a, &v);
    return func_0219C180(a, &v, b, c);
}

/*
 * function: func_0219C2BC
 * address:  0x0219C2BC
 * packet:   pkt_ov021_0219C2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0219C20C  0x0219C20C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_0219C20C(u32 a, Vec *p, int b, int c);

int func_0219C2BC(u32 a, int b, int c)
{
    Vec v;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    return func_0219C20C(a, &v, b, c);
}

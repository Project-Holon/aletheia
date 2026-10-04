/*
 * function: func_02199F50
 * address:  0x02199F50
 * packet:   pkt_ov021_02199F50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   d_021D4ACC     0x021D4ACC  data  a4
 */
#include "../include/Obj12643.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4ACC;
extern u16 *func_0216D6BC(u32, u32);
extern void func_0216D8C0(u32, const Vec *);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u32);

int func_02199F50(u32 a)
{
    u16 *p;
    Vec t = d_021D4ACC;
    p = func_0216D6BC(a, 6);
    *p = 0;
    ((struct Obj12643 *)p)->f2 = 0;
    func_0216D8C0(a, &t);
    func_0216D674((void *)a, 10);
    func_0216D7CC(a);
    return 1;
}

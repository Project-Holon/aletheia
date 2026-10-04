/*
 * function: func_02199D8C
 * address:  0x02199D8C
 * packet:   pkt_ov021_02199D8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */
#include "../include/Obj09499.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D6BC(u32, u32);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u32);

int func_02199D8C(u32 a)
{
    u8 *p = func_0216D6BC(a, 16);
    ((struct Obj09499 *)p)->f4 = 0x2000;
    ((struct Obj09499 *)p)->f8 = 0;
    p[10] = 0;
    func_0216D674((void *)a, 11);
    func_0216D7CC(a);
    return 1;
}

/*
 * function: func_0203508C
 * address:  0x0203508C
 * packet:   pkt_0203508C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469BC    0x021469BC  data
 *   func_02035080 0x02035080  arm
 *   func_02035120 0x02035120  arm
 */
#include "../include/Obj08822.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_021469BC;
extern void func_02035080(u8 *g, u32 a, u32 c);
extern void func_02035120(u8 *g, u32 b, u32 c);

void func_0203508C(u32 a, u32 b, u32 c)
{
    u8 *g = g_021469BC;

    if (g[0x41] != 0) {
        if (((struct Obj08822 *)g)->f18 != 0) {
            ((void (*)(u32)) * (u32 *)(g + 0x18))(((struct Obj08822 *)g)->f2C);
        }
        if (a != 0) {
            ((void (*)(u32))a)(c);
        }
    }
    func_02035080(g_021469BC, a, c);
    func_02035120(g_021469BC, b, c);
}

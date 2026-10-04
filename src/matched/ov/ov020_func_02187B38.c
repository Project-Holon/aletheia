/*
 * function: func_02187B38
 * address:  0x02187B38
 * packet:   pkt_ov020_02187B38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0209BE04  0x0209BE04  arm
 *   func_0209CE10  0x0209CE10  arm
 *   func_0209C77C  0x0209C77C  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 */
#include "../include/Obj01651.h"

typedef unsigned int u32;

u32 func_0209BE04(u32 x);
u32 func_0209CE10(u32 a, u32 b);
u32 func_0209C77C(u32 a, u32 b);
u32 func_0209C95C(u32 a, u32 b);
u32 func_0209CB8C(u32 a, u32 b);
u32 func_0209C494(u32 x);
void func_0207D658(u32 addr, int plane, int brightness);

void func_02187B38(char *o, int st)
{
    u32 a, b;

    if (st == 2) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209C95C(0xC1800000, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    } else if (st == 4) {
        a = func_0209BE04(((struct Obj01651 *)o)->f18);
        b = func_0209BE04(((struct Obj01651 *)o)->f1C);
        b = func_0209CE10(a, b);
        b = func_0209C77C(0x41800000, b);
        b = func_0209CB8C(0, b);
        func_0207D658(0x04000050, 8, func_0209C494(b));
    }
}

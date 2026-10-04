/*
 * function: func_021F4174
 * address:  0x021F4174
 * packet:   pkt_ov055_021F4174
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021F42AC  0x021F42AC  thumb  ov055
 *   func_021F3DD4  0x021F3DD4  thumb  ov055
 *   func_021F3DBC  0x021F3DBC  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D454();
extern void func_0216D410(void *a0, u16 a1);
extern int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e);
extern void func_021F3DD4(u8 *a, u32 b);
extern void func_021F3DBC(u8 *a);

void func_021F4174(u8 *a, u32 b)
{
    u32 loc;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, 2, 0)) {
            func_021F3DD4(a, loc);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}

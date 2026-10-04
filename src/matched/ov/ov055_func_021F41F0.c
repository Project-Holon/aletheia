/*
 * function: func_021F41F0
 * address:  0x021F41F0
 * packet:   pkt_ov055_021F41F0
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
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021F4318  0x021F4318  thumb  ov055
 *   func_021F42AC  0x021F42AC  thumb  ov055
 *   func_021F3DD4  0x021F3DD4  thumb  ov055
 *   func_021F3DBC  0x021F3DBC  thumb  ov055
 *   func_021F3D90  0x021F3D90  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D454();
extern void func_0216D410(void *a0, u16 a1);
extern void func_0216D5B4(void *p, u16 v);
extern void *func_021A3074(unsigned char *p);
extern int func_021F4318(const u8 *a, void *b, u16 c, u16 d);
extern int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e);
extern void func_021F3DD4(u8 *a, u32 b);
extern void func_021F3DBC(u8 *a);
extern void func_021F3D90(u8 *a);

void func_021F41F0(u8 *a, u32 b, u32 c)
{
    u32 loc;
    void *x;

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
        x = (void *)func_021A3074((void *)c);
        c = 1;
        if (func_021F4318(a, x, 1, 1)) {
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), ((struct Obj00204 *)a)->f6);
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, c, 0)) {
            func_021F3DD4(a, loc);
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
            func_021F3D90(a);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}

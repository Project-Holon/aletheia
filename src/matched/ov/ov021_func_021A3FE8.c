/*
 * function: func_021A3FE8
 * address:  0x021A3FE8
 * packet:   pkt_ov021_021A3FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021D05D8  0x021D05D8  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 */
#include "../include/Obj05025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(u8 *p);
extern u16 func_0216D598(void *p);
extern void func_021A3AD8(u8 *p, int a);
extern u32 func_021A398C(u8 *);
extern u16 func_021A3190(int, int);
extern u32 func_021A3974(u8 *p);
extern void func_021A3980(u8 *p, u32 a1);
extern u32 func_021A3AD4(u8 *);
extern void func_021A3AD0(u8 *, u32);
extern u32 func_02188CD0(u8 *p);
extern u16 func_0216D5F8(void *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_021ACB38(u32, u32, u32 *, void *, int);
extern void func_021D05D8(void *a, void *b);
extern void func_021ACBC8(u32, int);

int func_021A3FE8(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;
    u32 e;

    e = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 3);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 3) {
        func_021A3980(p, 3);
    }
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    func_021D05D8((void *)(((struct Obj05025 *)p)->f1C), (void *)e);
    if (((struct Obj05025 *)p)->f28 != 0) {
        func_021ACBC8(((struct Obj05025 *)p)->f28, 0);
    }
    ((struct Obj05025 *)p)->f32 = 1;
    return 0;
}

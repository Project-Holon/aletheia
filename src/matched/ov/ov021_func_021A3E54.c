/*
 * function: func_021A3E54
 * address:  0x021A3E54
 * packet:   pkt_ov021_021A3E54
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
 *   func_021A4114  0x021A4114  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 */
#include "../include/Obj12732.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(u8 *p);
extern u16 func_0216D598(void *p);
extern void func_021A3AD8(u8 *p, int a);
extern u32 func_021A398C(u8 *);
extern u16 func_021A3190(int, int);
extern int func_021A3974(u8 *);
extern void func_021A3980(u8 *, int);
extern void func_021A4114(u32 *p);
extern u32 func_021A3AD4(u8 *);
extern void func_021A3AD0(u8 *, u32);
extern u32 func_02188CD0(u8 *p);
extern u16 func_0216D5F8(void *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_021ACB38(u32, u32, u32 *, void *, int);

int func_021A3E54(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 2);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 2) {
        func_021A3980(p, 2);
    }
    func_021A4114((u32 *)p);
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj12732 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    ((struct Obj12732 *)p)->f32 = 1;
    return 0;
}

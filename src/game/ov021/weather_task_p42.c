/*
 * file:     weather_task_p42.c
 * unit:     yes
 * function: func_021A3D08, func_021A3D50, func_021A3D6C, func_021A3DA0
 * address:  0x021A3D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3B78  0x021A3B78  thumb  ov021
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A3B94  0x021A3B94  thumb  ov021
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_021A4114  0x021A4114  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 */
#include "../../matched/include/Obj09562.h"
#include "../../matched/include/Obj19780.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3D6C;

extern void *func_021A3960(u8 *p);
extern u16 func_0216D598(void *p);
extern int func_021A3B78(u8 *);
extern void func_021A3AD8(u8 *p, int a);
extern u32 func_021A398C(u8 *);
extern u16 func_021A3190(int, int);
int func_021A3B94(u32 *p);
extern void func_021A3980(u8 *p, u32 a1);
extern void func_021A4114(u32 *p);
extern u32 func_021A3AD4(u8 *);
extern void func_021A3AD0(u8 *, u32);
extern void func_021AC154(u32 a);
extern void func_0216D8E0(void *, u32 *);
int func_021A3D08(u8 *p, u32 v);
int func_021A3D50(u32 a, u32 b);
int func_021A3D6C(Obj021A3D6C *p, int a);
int func_021A3DA0(u8 *p);


int func_021A3D08(u8 *p, u32 v)
{
    if (v == func_0216D598(func_021A3960(p))) {
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    if (func_021A3B78(p) == 1) {
        func_021A3AD8(p, v);
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    func_021A3AD8(p, func_021A3190(func_021A398C(p), 0));
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3D50(u32 a, u32 b)
{
return func_021A3D08((u8 *)a, func_021A3190(func_021A398C((u8 *)a), b));
}


int func_021A3D6C(Obj021A3D6C *p, int a)
{
    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        func_021A3AD8((u8 *)p, func_021A3190(func_021A398C((u8 *)p), a));
        p->done = 1;
        return 1;
    }
    return 0;
}


int func_021A3DA0(u8 *p)
{
    u32 buf[3] = { 0, 0, 0 };
    u32 a;
    void *b;
    u32 o;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 0);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    func_021A3980(p, 0);
    func_021A4114((u32 *)p);
    if ((o = func_021A3AD4(p)) != 0) {
        func_021AC154(o);
        func_021A3AD0(p, 0);
    }
    func_0216D8E0(b, buf);
    ((struct Obj19780 *)p)->f32 = 1;
    return 0;
}
